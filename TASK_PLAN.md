# Push_swap — İki Kişilik Görev Paylaşımı ve Çakışmasız Çalışma Planı

Bu belge, **Ali (mmetin)** ve **Emirhan (emirhyil)**'ın Push_swap projesini Git üzerinde **merge conflict (çakışma) yaşamadan**, paralel ve bağımsız şekilde tamamlayabilmeleri için hazırlanmış iş bölümü protokolüdür.

---

## 1. Temel İlke: Modüler Ayrım (Decoupling)

Proje mantıksal olarak iki bağımsız ana katmana ayrılmıştır:
- **Girdi & Bellek Katmanı (Parsing & Memory):** Dış dünyadan gelen veriyi alır, doğrular, stack'e doldurur veya hata basıp temizler. Sıralama algoritmasının nasıl çalıştığını bilmesine gerek yoktur.
- **Sıralama Motoru (Sorting Engine):** Stack A'da hazır bulunan tamsayıları en az hamleyle sıralar. Sayıların `argv`'den nasıl geldiğini bilmesine gerek yoktur.

Bu sayede iki geliştirici birbirini beklemeden, mevcut `test_main.c` altyapısı sayesinde kodlarını bağımsızca test edebilir.

---

## 2. Görev Dağılımı ve Dosya Sahiplikleri

> [!IMPORTANT]
> **Kural 1 (Dosya İzolasyonu):** Hiçbir geliştirici, diğer geliştiricinin sorumlu olduğu dosyayı düzenlemez. Yeni bir yardımcı fonksiyon gerekirse kendi dosyasına yazar.

```
┌───────────────────────────────────────┐       ┌───────────────────────────────────────┐
│     GELİŞTİRİCİ 1: ALİ (mmetin)       │       │    GELİŞTİRİCİ 2: EMİRHAN (emirhyil)  │
│      Girdi, Parsing & Bellek          │       │         Sıralama Algoritmaları        │
├───────────────────────────────────────┤       ├───────────────────────────────────────┤
│ • argv / string split                 │       │ • Stack indeksleme (0..N-1)           │
│ • Sayı / karakter doğrulama           │       │ • 2 ve 3'lü sıralama (sort_three)     │
│ • INT_MIN / INT_MAX taşma kontrolü    │       │ • 4 ve 5'li sıralama (sort_five)      │
│ • Duplicate (mükerrer) kontrolü       │       │ • Büyük dizi algoritması (Turk / Kost)│
│ • Error yönetimi (fd 2 "Error\n")     │       │ • Hedef pozisyon & maliyet hesabı     │
│ • free_stack ve bellek sızıntısı yok  │       │ • Optimal hamle yürütme (ra+rb/rr..)  │
├───────────────────────────────────────┤       ├───────────────────────────────────────┤
│ 📁 Sahiplik:                          │       │ 📁 Sahiplik:                          │
│   - parsing.c                         │       │   - sort_small.c                      │
│   - parsing_utils.c                   │       │   - sort_large.c                      │
│   - free_utils.c                      │       │   - sort_utils.c                      │
│   - (varsa split.c)                   │       │   - cost_utils.c                      │
└───────────────────────────────────────┘       └───────────────────────────────────────┘
```

---

## 3. Ortak Alanlar ve Çakışmayı Önleme Kuralları

En sık conflict çıkan dosyalar `push_swap.h`, `Makefile` ve `main.c`'dir. Bunlar için şu protokol uygulanacaktır:

### A. `push_swap.h` Yönetimi
Başlık dosyasında herkes yalnızca kendi ayrılmış bölümüne fonksiyon prototipi ekler. Araya karışık ekleme yapılmaz:

```c
/* ========================================================================== */
/*                       ORTAK TEMEL STACK YAPILARI                           */
/* ========================================================================== */
// (Zaten tamamlandı: t_node, t_stack, swap, push, rotate, reverse rotate)

/* ========================================================================== */
/*             BÖLÜM 1: PARSING & MEMORY (Ali'nin Alanı)                      */
/* ========================================================================== */
int     parse_args(int argc, char **argv, t_stack *a);
void    free_stack(t_stack *stack);
void    free_split(char **split);
int     print_error(t_stack *a);

/* ========================================================================== */
/*             BÖLÜM 2: SORTING & ALGORITHMS (Emirhan'ın Alanı)              */
/* ========================================================================== */
int     is_sorted(t_stack *a);
void    sort_three(t_stack *a);
void    sort_five(t_stack *a, t_stack *b);
void    sort_large(t_stack *a, t_stack *b);
void    assign_indices(t_stack *a);
```

### B. `main.c` Yönetimi
`main.c` dosyasına her iki taraf da işini bitirip test edene kadar **dokunulmaz**. En son aşamada iki modül birleştirilirken ortaklaşa yazılır:

```c
int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);
    init_stack(&a);
    init_stack(&b);
    if (!parse_args(argc, argv, &a))
        return (print_error(&a));
    if (!is_sorted(&a))
    {
        if (a.size <= 3)
            sort_three(&a);
        else if (a.size <= 5)
            sort_five(&a, &b);
        else
            sort_large(&a, &b);
    }
    free_stack(&a);
    free_stack(&b);
    return (0);
}
```

---

## 4. Git Çalışma Akışı (Branch Stratejisi)

1. **Ana Entegrasyon Dalı:** `dev`
2. **Kişisel Branch İsimleri:**
   - Ali: `feature/parsing-and-validation`
   - Emirhan: `feature/sorting-algorithms`

### Adım Adım Git Kuralları:
```bash
# 1. Kendi dalınızı oluşturup ona geçin
git checkout -b feature/parsing-and-validation   # Ali için
git checkout -b feature/sorting-algorithms      # Emirhan için

# 2. Çalışma sırasında düzenli commit atın
git add <yalnizca_kendi_dosyalariniz>
git commit -m "feat(parsing): add ft_atol with overflow check"

# 3. Dev branch'ini güncellemek ve kendi branch'inize rebase etmek:
git checkout dev
git pull origin dev
git checkout feature/kendi-branchiniz
git rebase dev

# 4. İş bittiğinde dev branch'ine merge:
git checkout dev
git merge --no-ff feature/kendi-branchiniz
git push origin dev
```

---

## 5. Bağımsız Test Protokolü (Birbirini Beklemeden Test Etme)

- **Ali (Parsing):**
  Algoritmaya ihtiyaç duymadan, geçici bir test main ile şunları dener:
  - `./push_swap 42 13 88` -> Stack doğru doluyor mu?
  - `./push_swap "42 13 88"` -> Tek string halinde gelirse split edip doluyor mu?
  - `./push_swap 42 42` -> Duplicate hatası ("Error\n") veriyor mu?
  - `./push_swap 2147483648` -> Overflow hatası veriyor mu?
  - `./push_swap 1 a 3` -> Harf kontrolünde hata veriyor mu?
  - Bellek temizliği kontrolü: `leaks --atExit -- ./push_swap ...` veya Valgrind.

- **Emirhan (Sorting):**
  Parsing'e ihtiyaç duymadan, mevcut [test_main.c](file:///Users/alimetin/Desktop/push_swap/test_main.c) dosyasındaki gibi stack'e elle sayıları ekleyerek algoritmaları dener:
  - 3 rastgele sayı: Maksimum 2 hamlede sıralanıyor mu?
  - 5 rastgele sayı: Maksimum 12 hamlede sıralanıyor mu?
  - 100 rastgele sayı: < 700 hamle (5 puan için)
  - 500 rastgele sayı: < 5500 hamle (5 puan için)
  - Sıralama bittiğinde `is_sorted(&a)` true mu ve stack B boş mu?

---

## 6. Yol Haritası ve Kontrol Noktaları (Milestones)

| Aşama | Görev | Sorumlu | Teslim Kriteri |
|---|---|---|---|
| **Faz 1** | Bellek temizleme (`free_stack`) | Ali | `valgrind` / `leaks` ile 0 leak teyidi |
| **Faz 1** | `is_sorted` ve `sort_three`, `sort_five` | Emirhan | 3 ve 5 eleman için hamle sınırlarının aşılmaması |
| **Faz 2** | Girdi parse etme, split ve taşma kontrolleri | Ali | Tüm hatalı senaryolarda `Error\n` ve temiz çıkış |
| **Faz 2** | Büyük sıralama (Turk Algorithm / Radix / Chunk) | Emirhan | 100 ve 500 eleman için test senaryolarının geçmesi |
| **Faz 3** | Entegrasyon (`main.c` + `Makefile`) | Ortak | `./push_swap` binary'sinin tam çalışır hale gelmesi |
| **Faz 4** | Norminette, Checker & Optimizasyon | Ortak | 0 Norm error, 42 checker ile %100 "OK" |

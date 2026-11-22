# Push_swap — Geliştirme Durumu

## Projenin amacı

Bu proje, **42 müfredatı** kapsamında geliştirilmektedir. Amaç, Stack A'daki tam sayıları Stack B'den ve izin verilen stack işlemlerinden yararlanarak mümkün olduğunca az işlemle sıralamaktır.

**Mevcut durum:** Stack veri yapısı ve temel yardımcı fonksiyonlar yazıldı. Sıralama algoritmalarına henüz başlanmadı.

## Veri yapısı

Stack'leri temsil etmek için **çift yönlü bağlı liste (Doubly Linked List)** seçildi.

- `t_node`: `value` (sayı), `next` (sonraki düğüm), `prev` (önceki düğüm)
- `t_stack`: `head` (stack'in üstündeki ilk düğüm), `tail` (en alttaki son düğüm), `size` (eleman sayısı)

Bu yapı, özellikle stack'in başından düğüm çıkarma ve başına düğüm ekleme işlemlerini bağlantıları güncelleyerek yapmamızı sağlar.

## Yazılan fonksiyonlar

| Fonksiyon | Görevi |
|---|---|
| `init_stack` | Boş stack'i başlatır (`head`/`tail = NULL`, `size = 0`). |
| `create_node` | Yeni düğüm için bellek ayırır ve alanlarını başlatır. |
| `add_back` | Düğümü listenin sonuna (`tail` tarafına) ekler. |
| `pop_front` | İlk düğümü (`head`) listeden ayırır ve adresini döndürür; `free` etmez. |
| `pop_back` | Son düğümü (`tail`) listeden ayırır ve adresini döndürür; `free` etmez. |
| `add_front` | Düğümü listenin başına (`head` tarafına) ekler. |
| `compute_disorder` | Stack'in sıralı olmama (düzensizlik) oranını çiftleri karşılaştırarak hesaplar. |
| `swap_nodes` | Stack'in ilk iki elemanının bağlantılarını takas eden yardımcı fonksiyon. |
| `sa` / `sb` / `ss` | Stack A, Stack B veya her ikisinin ilk iki elemanını yer değiştirir. |
| `pa` / `pb` | Stack'in en üstündeki elemanı diğer stack'in en üstüne taşır. |
| `rotate_nodes` | Baştaki elemanı sona ekleyerek yukarı kaydırma yapan yardımcı fonksiyon (`pop_front` + `add_back`). |
| `ra` / `rb` / `rr` | Stack A, Stack B veya her ikisini 1 yukarı kaydırır (ilk eleman son eleman olur). |
| `reverse_rotate_nodes` | Sondaki elemanı başa ekleyerek aşağı kaydırma yapan yardımcı fonksiyon (`pop_back` + `add_front`). |
| `rra` / `rrb` / `rrr` | Stack A, Stack B veya her ikisini 1 aşağı kaydırır (son eleman ilk eleman olur). |

## Dosya düzeni

- `push_swap.h` — Struct tanımları ve kütüphane bildirimleri
- `create_node.c` — `create_node` (1/5)
- `stack_init.c` — `init_stack` (1/5)
- `stack_utils.c` — `add_back`, `pop_front`, `pop_back`, `add_front`, `compute_disorder` (5/5)
- `push_operations.c` — `pb`, `pa`, `sa`, `sb`, `ss` (5/5)
- `swap_operations.c` — `swap_nodes` (1/5)
- `rotate_operations.c` — `ra`, `rb`, `rotate_nodes`, `rr`, `reverse_rotate_nodes`, `rra`, `rrb`, `rrr`

Dosya düzeni, **42 Norminette'in `.c` dosyası başına en fazla 5 fonksiyon** sınırına göre planlandı. Gerçek dosya konumları repoda kontrol edilmelidir.

## Yapılacaklar

- [x] Stack veri yapısını seçmek ve struct'ları tasarlamak
- [x] Stack başlatma ve düğüm oluşturma fonksiyonlarını yazmak
- [x] Başa/sona ekleme ve baştan/sondan çıkarma yardımcı fonksiyonlarını yazmak (`pop_back` dahil)
- [x] Push (`pa`, `pb`) işlemlerini yazmak
- [x] Swap (`sa`, `sb`, `ss`) işlemlerini yazmak
- [x] Rotate (`ra`, `rb`, `rr`) işlemlerini yazmak
- [x] Reverse rotate (`rra`, `rrb`, `rrr`) işlemlerini tamamlamak
- [ ] Bellek temizliği ve sızıntı yönetimi (`free_stack`)
- [ ] Norminette dosya ve satır sınırları optimizasyonu (örn. `compute_disorder` taşınması)
- [ ] Girdi doğrulama ve parsing (sayı kontrolü, int taşması, duplicate kontrolü, split)
- [ ] Hata yönetimi (`write(2, "Error\n", 6)`)
- [ ] Sıralama algoritmalarını (küçük sayılar ve büyük sayılar için) geliştirmek
- [ ] Makefile hazırlığı, testler ve optimizasyon

## Nerede kaldık?

**Son tamamlanan işlemler:** Tüm temel push_swap hareketleri (`pa`/`pb`, `sa`/`sb`/`ss`, `ra`/`rb`/`rr`, `rra`/`rrb`/`rrr`), stack yardımcıları (`pop_front`, `pop_back`, `add_front`, `add_back`) ve `compute_disorder`.

**Bir sonraki adım:** Bellek temizliği (`free_stack`) fonksiyonunu yazmak, ardından girdi ayrıştırma (parsing) ve hata kontrollerine geçmek.

> **Not:** Bu belge tamamlanmış ve test edilmiş bir projeyi değil, çalışma sırasında ulaşılan noktayı özetler. Fonksiyonlar mantıksal olarak incelendi; derleme, Norminette ve otomatik test sonuçları henüz doğrulanmadı.

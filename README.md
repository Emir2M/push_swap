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
| `pop_front` | İlk düğümü listeden ayırır ve adresini döndürür; `free` etmez. |
| `add_front` | Düğümü listenin başına (`head` tarafına) ekler. |

## Dosya düzeni

- `push_swap.h` — Struct tanımları ve fonksiyon prototipleri
- `stack_init.c` — `init_stack`, `create_node` (2/5)
- `stack_utils.c` — `add_back`, `pop_front`, `add_front` (3/5)

Dosya düzeni, **42 Norminette'in `.c` dosyası başına en fazla 5 fonksiyon** sınırına göre planlandı. Gerçek dosya konumları repoda kontrol edilmelidir.

## Yapılacaklar

- [x] Stack veri yapısını seçmek ve struct'ları tasarlamak
- [x] Stack başlatma ve düğüm oluşturma fonksiyonlarını yazmak
- [x] Başa/sona ekleme ve baştan çıkarma yardımcı fonksiyonlarını yazmak
- [ ] Yardımcı fonksiyonları derleyip test etmek; Norminette kontrolü yapmak
- [ ] `pa` ve `pb` işlemlerini yazmak
- [ ] Diğer push_swap işlemlerini tamamlamak
- [ ] Sıralama algoritmalarını ve strateji seçimini geliştirmek
- [ ] Benchmark, hata kontrolleri, bütünleşik testler ve optimizasyon

## Nerede kaldık?

**Son tamamlanan fonksiyon:** `add_front` (`stack_utils.c`).

**Bir sonraki adım:** `pop_front` ve `add_front` yardımcılarını kullanarak `pa` ve `pb` işlemlerini yazmak. Bu işlemler, bir stack'in üstündeki düğümü diğer stack'in üstüne taşır; yeni düğüm oluşturulmaz.

> **Not:** Bu belge tamamlanmış ve test edilmiş bir projeyi değil, çalışma sırasında ulaşılan noktayı özetler. Fonksiyonlar mantıksal olarak incelendi; derleme, Norminette ve otomatik test sonuçları henüz doğrulanmadı.

# Push_swap — Geliştirme Durumu

42 müfredatı kapsamında geliştirilen bu proje, Stack A'daki tam sayıları Stack B ve izin verilen işlemlerle mümkün olduğunca az hamlede sıralamayı amaçlar.

**Güncel durum:** `dev` — 25 Kasım 2026, `987d499`. Proje geliştirme aşamasındadır; henüz teslim edilebilir değildir.

## Veri yapısı

Çift yönlü bağlı liste (Doubly Linked List) kullanılır.

- `t_node`: `value`, `next`, `prev`.
- `t_stack`: `head` (üst), `tail` (alt), `size`.
- Sabit sıralama indeksi (`index`) henüz eklenmemiştir.

## Dosyalar ve mevcut durum

| Dosya | Fonksiyonlar / durum |
|---|---|
| `create_node.c`, `stack_init.c` | `create_node`, `init_stack` |
| `stack_utils.c` | `add_back`, `pop_front`, `pop_back`, `add_front`, `compute_disorder` |
| `push_operations.c` | `pa`, `pb` |
| `swap_operations.c` | `swap_nodes`, `sa`, `sb`, `ss` |
| `rotate_operations.c` | `rotate_nodes`, `ra`, `rb`, `rr` |
| `reverse_rotate_operations.c` | `reverse_rotate_nodes`, `rra`, `rrb`, `rrr` |
| `free_operations.c`, `error_operations.c` | `free_stack`, `free_split`, `error` |
| `ft_split.c` | Boşlukla ayrılmış girdilerin parçalanması |
| `push_swap.c` | `get_number`, `is_valid_number`, `parse_args`, `main`; parsing kısmen tamamlandı |
| `simple_sort.c` | `find_min_position`, `move_min_to_top`, `simple_sort` |
| `medium_sort.c` | `get_index`, `copy_values`, `sort_array`, `get_sorted_index`; hazırlık aşaması |
| `medium_sort_utils.c` | `merge_sort`, `merge`; tamamlanmamış deneysel kod |
| `push_swap.h` | Ortak veri yapıları ve prototipler; düzenleme gerekli |
| `Makefile`, `test_main.c` | Ana program ve bağımsız Simple Sort testleri |

## Sıralama algoritmaları

- **Simple Sort:** Selection Sort / Min Extraction. Minimum elemanlar B'ye taşınır, ardından A'ya geri alınır. Mevcut bağımsız testler başarılıdır. O(n²) yaklaşımı.
- **Medium Sort:** Chunk-Based Sorting planlanmaktadır. Dizi kopyalama, Insertion Sort ve indeks arama yardımcıları yazıldı. Chunk taşıma ve geri toplama henüz yazılmadı. Merge Sort denemesi tamamlanmadı ve kullanılmıyor. İndeks hazırlama ve hamle karmaşıklığı yeniden değerlendirilecek.
- **Complex Sort:** Henüz başlanmadı. Radix Sort adaydır; kesin seçim proje subject'ine göre yapılacaktır.
- **Adaptive seçim:** `compute_disorder` yazıldı ancak algoritma seçimine bağlanmadı.

## Derleme ve doğrulama

```sh
make
make test
make fclean
```

25 Kasım 2026 arşiv incelemesi:

- `make`: başarılı (`-Wall -Wextra -Werror`). Medium dosyaları mevcut Makefile'a dahil değildir; ayrı derlemeleri başarılıdır.
- `make test`: 5, 10 ve 100 elemanlı mevcut Simple Sort testleri OK. Bunlar kapsamlı rastgele testler değildir.
- Geçersiz harf ve 2147483648 girdileri hata üretir.
- Duplicate ve boş string girdileri hatalı biçimde kabul edilir.
- UBSan ile INT_MIN dönüşümünde ve çok uzun sayı doğrulamasında signed overflow tespit edildi.
- Ana program henüz sıralama çağırmaz ve başarılı parsing sonrasında stack belleğini temizlemez.
- Norminette, Valgrind ve resmi checker doğrulanmadı.

## Yapılacaklar

- [x] Stack veri yapısı ve temel yardımcılar
- [x] 11 stack operasyonunun implementasyonu
- [x] Disorder hesaplama fonksiyonu
- [x] Simple Sort ve mevcut bağımsız testler
- [x] Bellek temizleme ve hata fonksiyonlarının implementasyonu
- [ ] Header prototiplerini ve tekrarları düzenleme
- [ ] Parsing: duplicate, boş girdi, allocation kontrolü ve güvenli sayı dönüşümü
- [ ] Ana programda bellek temizliği ve sıralama entegrasyonu
- [ ] Medium Sort tasarımını kesinleştirme ve tamamlama
- [ ] Complex Sort ve adaptive seçim
- [ ] Makefile'a tamamlanan algoritmaları ekleme
- [ ] Norminette, bellek, checker ve hamle sayısı testleri

## İş bölümü ve sıradaki adım

Parsing ve bellek yönetimi ile sıralama motoru ayrı geliştirilir. Ortak dosyalar koordineli değiştirilir. Ayrıntılar için [TASK_PLAN.md](TASK_PLAN.md).

Önce header temizliği ve parsing güvenliği; paralel olarak Medium Sort için ortak indeksleme tasarımı. Sonrasında Complex Sort, entegrasyon ve kapsamlı testler.

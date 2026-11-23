#include "push_swap.h"
#include <stdio.h>

/* Yardımcı: Stack'i ekrana yazdır */
static void	print_stack(const char *name, t_stack *s)
{
	t_node	*curr;

	printf("%s (size: %d): [ ", name, s->size);
	curr = s->head;
	while (curr)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}
	printf("]\n");
}

/* Çift yönlü bağlı listenin prev/next bütünlüğünü doğrula */
static int	verify_integrity(t_stack *s)
{
	t_node	*curr;
	int		count;

	if (!s->head && !s->tail)
		return (s->size == 0);
	if (!s->head || !s->tail)
		return (0);
	if (s->head->prev != NULL || s->tail->next != NULL)
		return (0);

	curr = s->head;
	count = 0;
	while (curr)
	{
		count++;
		if (curr->next && curr->next->prev != curr)
			return (0);
		if (!curr->next && curr != s->tail)
			return (0);
		curr = curr->next;
	}
	return (count == s->size);
}

/* Stack belleğini temizle */
static void	free_stack(t_stack *s)
{
	t_node	*curr;
	t_node	*next;

	curr = s->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	init_stack(s);
}

int	main(void)
{
	t_stack	a;
	t_stack	b;
	int		test_vals[] = {2, 1, 3, 6, 5, 8};
	int		n = sizeof(test_vals) / sizeof(test_vals[0]);
	int		i;

	init_stack(&a);
	init_stack(&b);

	printf("===========================================\n");
	printf("      PUSH_SWAP FONKSİYON TEST SİSTEMİ     \n");
	printf("===========================================\n\n");

	/* 1. Stack A'yı başlat ve doldur */
	printf("--- 1. Stack A Oluşturuluyor ---\n");
	for (i = 0; i < n; i++)
		add_back(&a, create_node(test_vals[i]));
	print_stack("Stack A", &a);
	print_stack("Stack B", &b);
	printf("Bütünlük Kontrolü (A): %s\n", verify_integrity(&a) ? "OK" : "HATA");
	printf("Düzensizlik (Disorder) Oranı: %.2f%%\n\n", compute_disorder(&a) * 100);

	/* 2. Swap Testi */
	printf("--- 2. sa (Swap A) Testi ---\n");
	sa(&a);
	print_stack("Stack A", &a);
	printf("Bütünlük Kontrolü (A): %s\n\n", verify_integrity(&a) ? "OK" : "HATA");

	/* 3. Push Testi */
	printf("--- 3. pb (Push to B) Testi (2 eleman) ---\n");
	pb(&a, &b);
	pb(&a, &b);
	print_stack("Stack A", &a);
	print_stack("Stack B", &b);
	printf("Bütünlük Kontrolü (A): %s, (B): %s\n\n",
		verify_integrity(&a) ? "OK" : "HATA",
		verify_integrity(&b) ? "OK" : "HATA");

	/* 4. Rotate Testi */
	printf("--- 4. ra & rb & rr (Rotate) Testi ---\n");
	ra(&a);
	print_stack("Stack A (ra sonrası)", &a);
	rb(&b);
	print_stack("Stack B (rb sonrası)", &b);
	rr(&a, &b);
	print_stack("Stack A (rr sonrası)", &a);
	print_stack("Stack B (rr sonrası)", &b);
	printf("Bütünlük Kontrolü (A): %s, (B): %s\n\n",
		verify_integrity(&a) ? "OK" : "HATA",
		verify_integrity(&b) ? "OK" : "HATA");

	/* 5. Reverse Rotate Testi */
	printf("--- 5. rra & rrb & rrr (Reverse Rotate) Testi ---\n");
	rra(&a);
	print_stack("Stack A (rra sonrası)", &a);
	rrb(&b);
	print_stack("Stack B (rrb sonrası)", &b);
	rrr(&a, &b);
	print_stack("Stack A (rrr sonrası)", &a);
	print_stack("Stack B (rrr sonrası)", &b);
	printf("Bütünlük Kontrolü (A): %s, (B): %s\n\n",
		verify_integrity(&a) ? "OK" : "HATA",
		verify_integrity(&b) ? "OK" : "HATA");

	/* 6. pa Testi (B'deki tüm elemanları geri A'ya at) */
	printf("--- 6. pa (Push to A) Testi ---\n");
	while (b.size > 0)
		pa(&a, &b);
	print_stack("Stack A", &a);
	print_stack("Stack B", &b);
	printf("Bütünlük Kontrolü (A): %s, (B): %s\n\n",
		verify_integrity(&a) ? "OK" : "HATA",
		verify_integrity(&b) ? "OK" : "HATA");

	/* Bellek temizliği */
	free_stack(&a);
	free_stack(&b);
	printf("Bellek başarıyla temizlendi.\n");
	printf("===========================================\n");
	printf("          TÜM TESTLER TAMAMLANDI           \n");
	printf("===========================================\n");

	return (0);
}

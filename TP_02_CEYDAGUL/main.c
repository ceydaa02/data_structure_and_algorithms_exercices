#include<stdio.h>
#include<stdlib.h>
#define N 8
#include"ceydatp02.h"



int main() {

	int secim2 = 0;

	while (1) {
		printf("\nSecim yapiniz:\n\t1.Statik listede stack yapisi\n\t2.Statik listede queue yapisi\n\t3.Linked list'te stack yapisi\n\t4.Linked list'te queue yapisi\n\t5.Cikis yap!\n");
		scanf("%d", &secim2);
		if (secim2 == 1) {
			int liste[N];
			int sayac = 0;
			int secim = 0;
			while (1) {
				printf("\n\tSecim yapiniz:\n\t1.Listenin sonuna eleman ekleme\n\t2.Listenin sonundan eleman cikarma\n\t3.Listenin elemanlarini ekrana yazdir\n\t4.Listeyi temizle.\n\t5.Cikis yap!\n\n");
				scanf("%d", &secim);
				if (secim == 1) {
					int deger;
					printf("\nBir sayi giriniz: ");
					scanf("%d", &deger);
					sayac = push_list(liste, deger, sayac);
				}
				else if (secim == 2) {
					sayac = pop_list(liste, sayac);
				}
				else if (secim == 3) {
					printStack_list(liste, sayac);
				}
				else if (secim == 4) {
					sayac = clearStack_list(liste, sayac);
				}
				else if (secim == 5) break;

				else printf("Sayiyla eslesen komut bulunamadi. Lutfen tekrar deneyiniz!\n");
			}

		}

		else if (secim2 == 2) {
			int liste[N];
			int head = 0, tail = 0;
			int* head_ptr = &head;
			int* tail_ptr = &tail;
			int secim = 0;

			while (1) {
				printf("\n\tSecim yapiniz:\n\t1.Listenin sonuna eleman ekleme\n\t2.Listenin basindan eleman cikarma\n\t3.Listenin elemanlarini ekrana yazdir\n\t4.Listeyi temizle.\n\t5.Cikis yap!\n\n");
				scanf("%d", &secim);
				if (secim == 1) {
					int deger;
					printf("\nBir sayi giriniz: ");
					scanf("%d", &deger);
					enqueue_list(liste, deger, head_ptr, tail_ptr);
				}
				else if (secim == 2) {
					dequeue_list(liste, head_ptr, tail_ptr);
				}
				else if (secim == 3) {
					printQueue_list(liste, head_ptr, tail_ptr);
				}
				else if (secim == 4) {
					clearQueue_list(head_ptr, tail_ptr);
				}
				else if (secim == 5) break;

				else printf("Sayiyla eslesen komut bulunamadi. Lutfen tekrar deneyiniz!\n");
			}
		}

		else if (secim2 == 3) {
			ptr_ll_stack bag = (ptr_ll_stack)malloc(sizeof(struct linked_list));
			bag->head = NULL;
			int secim = 0;
			while (1) {
				printf("\n\tSecim yapiniz:\n\t1.Listenin sonuna eleman ekleme\n\t2.Listenin sonundan eleman cikarma\n\t3.Listenin elemanlarini ekrana yazdir\n\t4.Listeyi temizle.\n\t5.Cikis yap!\n\n");
				scanf("%d", &secim);
				if (secim == 1) {
					int deger;
					printf("Deger giriniz: ");
					scanf("%d", &deger);
					push_stack(bag, deger);
				}
				else if (secim == 2)
					pop_stack(bag);

				else if (secim == 3)
					printStack_ll(bag);

				else if (secim == 4)
					clearStack_ll(bag);
				else if (secim == 5) break;

				else printf("Sayiyla eslesen komut bulunamadi. Lutfen tekrar deneyiniz!\n");
			}

		}
		else if (secim2 == 4) {
			ptr_ll_queue bag = (ptr_ll_queue)malloc(sizeof(struct linked_list));
			bag->head = NULL;
			bag->tail = NULL;
			int secim = 0;
			while (1) {
				printf("\n\tSecim yapiniz:\n\t1.Listenin sonuna eleman ekleme\n\t2.Listenin basindan eleman cikarma\n\t3.Listenin elemanlarini ekrana yazdir\n\t4.Listeyi temizle.\n\t5.Cikis yap!\n\n");
				scanf("%d", &secim);
				if (secim == 1) {
					int deger;
					printf("Deger giriniz: ");
					scanf("%d", &deger);
					enqueue_ll(bag, deger);
				}
				else if (secim == 2)
					dequeue_ll(bag);

				else if (secim == 3)
					printQueue_ll(bag);

				else if (secim == 4)
					clearQueue_ll(bag);
				else if (secim == 5) break;

				else printf("Sayiyla eslesen komut bulunamadi. Lutfen tekrar deneyiniz!\n");
			}
		}
		else if (secim2 == 5) break;
		else printf("Sayiyla eslesen komut bulunamadi. Lutfen tekrar deneyiniz!\n");
	}

	return 0;

}
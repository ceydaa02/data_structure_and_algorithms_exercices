#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 25

#include "ceyda.h"


int main() {


	int secim = 0;
	int secim2 = 0;



	while (1) {

		printf("\nSecim yapiniz:\n\t1.singly linked list\n\t2.circular singly linked list\n\t3.doubly linked list\n\t4.doubly circular linked list\n\t5.Cikis yap!\n");
		scanf("%d", &secim2);

		if (secim2 == 1) {
			printf("\nSINGLY LINKED LIST:");
			Liste_SL bag_SL = (Liste_SL)malloc(sizeof(struct liste_SL));
			bag_SL->head = NULL;

			char eser[N];
			char yazar[N];
			int yayin, baski;
			while (1) {
				printf("\nSecim yapiniz:\n\t1.Kitap Ekle\n\t2.Kitap Sil\n\t3.Kitap Bul\n\t4.Kitaplari listele\n\t5.Cikis Yap\n");
				scanf("%d", &secim);

				if (secim == 1) {
					printf("\nKitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Yazarin adini giriniz: ");
					scanf("\n%[^\n]%*c", yazar);
					printf("Kitabin yayin yilini giriniz: ");
					scanf("%d", &yayin);
					printf("Kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);

					bag_SL = kitapEkle_SL(bag_SL, eser, yazar, yayin, baski);
				}

				else if (secim == 2) {
					printf("Silinmesini istediginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Silinmesini istediginiz kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);
					kitapSil_SL(bag_SL, eser, baski);
				}

				else if (secim == 3) {
					printf("Aradiginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					kitapAra_SL(bag_SL, eser);
				}

				else if (secim == 4) {
					yazdir_SL(bag_SL);
				}

				else if (secim == 5)
					break;

				else
					printf("Sayiyla eslesen komut bulunamadi.");

			}
		}

		else if (secim2 == 2) {

			Liste_CSL bag_CSL = (Liste_CSL)malloc(sizeof(struct liste_CSL));
			bag_CSL->tail = NULL;

			char eser[N];
			char yazar[N];
			int yayin, baski;

			while (1) {
				printf("\nSecim yapiniz:\n\t1.Kitap Ekle\n\t2.Kitap Sil\n\t3.Kitap Bul\n\t4.Kitaplari listele\n\t5.Cikis Yap\n");
				scanf("%d", &secim);

				if (secim == 1) {
					printf("Kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Yazarin adini giriniz: ");
					scanf("\n%[^\n]%*c", yazar);
					printf("Kitabin yayin yilini giriniz: ");
					scanf("%d", &yayin);
					printf("Kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);

					bag_CSL = kitapEkle_CSL(bag_CSL, eser, yazar, yayin, baski);
				}

				else if (secim == 2) {
					printf("Silinmesini istediginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Silinmesini istediginiz kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);
					kitapSil_CSL(bag_CSL, eser, baski);
				}

				else if (secim == 3) {
					printf("Aradiginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					kitapAra_CSL(bag_CSL, eser);
				}

				else if (secim == 4) {
					yazdir_CSL(bag_CSL);
				}

				else if (secim == 5) {
					break;
				}
				else
					printf("Sayiyla eslesen komut bulunamadi.");

			}
		}

		else if (secim2 == 3) {

			Liste_DL bag_DL = (Liste_DL)malloc(sizeof(struct liste_DL));
			bag_DL->head = NULL;

			char eser[N];
			char yazar[N];
			int yayin, baski;
			while (1) {
				printf("\nSecim yapiniz:\n\t1.Kitap Ekle\n\t2.Kitap Sil\n\t3.Kitap Bul\n\t4.Kitaplari listele\n\t5.Cikis Yap\n");
				scanf("%d", &secim);

				if (secim == 1) {
					printf("Kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Yazarin adini giriniz: ");
					scanf("\n%[^\n]%*c", yazar);
					printf("Kitabin yayin yilini giriniz: ");
					scanf("%d", &yayin);
					printf("Kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);

					bag_DL = kitapEkle_DL(bag_DL, eser, yazar, yayin, baski);
				}

				else if (secim == 2) {
					printf("Silinmesini istediginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Silinmesini istediginiz kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);
					kitapSil_DL(bag_DL, eser, baski);
				}

				else if (secim == 3) {
					printf("Aradiginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					kitapAra_DL(bag_DL, eser);
				}

				else if (secim == 4) {
					yazdir_DL(bag_DL);
				}

				else if (secim == 5) {
					break;
				}
				else
					printf("Sayiyla eslesen komut bulunamadi.");

			}
		}

		else if (secim2 == 4) {
			Liste_CDL bag_CDL = (Liste_CDL)malloc(sizeof(struct liste_CDL));
			bag_CDL->head = NULL;

			char eser[N];
			char yazar[N];
			int yayin, baski;
			while (1) {
				printf("\nSecim yapiniz:\n\t1.Kitap Ekle\n\t2.Kitap Sil\n\t3.Kitap Bul\n\t4.Kitaplari listele\n\t5.Cikis Yap\n");
				scanf("%d", &secim);

				if (secim == 1) {
					printf("Kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Yazarin adini giriniz: ");
					scanf("\n%[^\n]%*c", yazar);
					printf("Kitabin yayin yilini giriniz: ");
					scanf("%d", &yayin);
					printf("Kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);

					bag_CDL = kitapEkle_CDL(bag_CDL, eser, yazar, yayin, baski);
				}

				else if (secim == 2) {
					printf("Silinmesini istediginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					printf("Silinmesini istediginiz kitabin baski numarasini giriniz: ");
					scanf("%d", &baski);
					kitapSil_CDL(bag_CDL, eser, baski);
				}

				else if (secim == 3) {
					printf("Aradiginiz kitabin adini giriniz: ");
					scanf("\n%[^\n]%*c", eser);
					kitapAra_CDL(bag_CDL, eser);
				}

				else if (secim == 4) {
					yazdir_CDL(bag_CDL);
				}

				else if (secim == 5) {
					break;
				}
				else
					printf("Sayiyla eslesen komut bulunamadi.");

			}
		}
		else if (secim2 == 5) {
			break;
		}
		else 
			printf("Sayiyla eslesen komut bulunamadi.");


	}

	return 0;
}
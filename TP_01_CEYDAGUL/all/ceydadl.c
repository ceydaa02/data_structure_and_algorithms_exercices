#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ceydadl.h"


ptrKitap_DL yeniKitap_DL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {

	ptrKitap yeni = (ptrKitap_DL)malloc(sizeof(struct kitap_DL));
	if (!yeni) {
		return 0;
	}

	yeni->yayinYili = yayinYili;
	yeni->baskiSayisi = baskiSayisi;
	strcpy((yeni->eserAdi), eserAdi);
	strcpy((yeni->yazarAdi), yazarAdi);

	return yeni;
}

Liste_DL kitapEkle_DL(Liste_DL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {
//insert at end
	ptrKitap_DL node = yeniKitap_DL(eserAdi, yazarAdi, yayinYili, baskiSayisi);
	ptrKitap_DL current = l->head;
	if (l->head == NULL) {
		l->head = node;
		node->ileri = NULL;
		node->geri = NULL;
	}

	else {
		while (current->ileri != NULL) {
			current = current->ileri;
		}
		current->ileri = node;
		node->geri = current;
		node->ileri = NULL;
	}
	return l;
}

void kitapSil_DL(Liste_DL l, char eserAdi[], int baskiSayisi) {
	ptrKitap_DL current = l->head;
	while (current != NULL) {
		if ((!strcmp((current->eserAdi), eserAdi)) && (baskiSayisi == (current->baskiSayisi))) {
			if (current == l->head) {
				if (current->ileri == NULL)
					l->head = NULL;
				else {
					l->head = l->head->ileri;
					l->head->geri = NULL;
				}
				free(current);
				break;
			}
			else {
				if (current->ileri == NULL) 
					current->geri->ileri = NULL;

				else {
					current->geri->ileri = current->ileri;
					current->ileri->geri = current->geri;
				}
				free(current);
				break;

			}
		}
		else 
			current = current->ileri;
	}

}
ptrKitap_DL kitapAra_DL(Liste_DL l, char eserAdi[]) {
	ptrKitap_DL current = l->head;
	while (current != NULL) {
		if (!strcmp((current->eserAdi), eserAdi)) {
			printf("\nEser Adi: %s\n", current->eserAdi);
			printf("Yazar Adi: %s\n", current->yazarAdi);
			printf("Yayin Yili: %d\n", current->yayinYili);
			printf("Baski sayisi: %d\n", current->baskiSayisi);
			return current;
		}
		else {
			current = current->ileri;
		}
	}
	printf("\nARADIGINIZ KITAP BULUNAMADI!!!!\n\n");
}

void yazdir_DL(Liste_DL l) {
	ptrKitap_DL ix = l->head;
	if (!(l->head)) return;
	while (ix != NULL) {
		printf("\n\tEser adi: %s\n", ix->eserAdi);
		printf("\tYazar adi: %s\n", ix->yazarAdi);
		printf("\tEserin yayin yili: %d\n", ix->yayinYili);
		printf("\tEserin baski sayisi: %d\n", ix->baskiSayisi);


		ix = ix->ileri;
	}
}

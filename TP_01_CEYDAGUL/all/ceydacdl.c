#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ceydacdl.h"


ptrKitap_CDL yeniKitap_CDL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {

	ptrKitap_CDL yeni = (ptrKitap_CDL)malloc(sizeof(struct kitap_CDL));
	if (!yeni) {
		return 0;
	}

	yeni->yayinYili = yayinYili;
	yeni->baskiSayisi = baskiSayisi;
	strcpy((yeni->eserAdi), eserAdi);
	strcpy((yeni->yazarAdi), yazarAdi);

	return yeni;
}

Liste_CDL kitapEkle_CDL(Liste_CDL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {
	//insert at end
	ptrKitap_CDL current = l->head;
	ptrKitap_CDL node = yeniKitap_CDL(eserAdi, yazarAdi, yayinYili, baskiSayisi);
	if (l->head == NULL) {
		l->head = node;
		node->ileri = node;
		node->geri = node;
	}
	else if((l->head->ileri)==(l->head)){
		l->head->ileri = node;
		l->head->geri = node;
		node->ileri = l->head;
		node->geri = l->head;
	}

	else {
		l->head->geri->ileri = node;
		node->geri = l->head->geri;
		l->head->geri = node;
		node->ileri = l->head;

	}
	return l;
}

Liste_CDL kitapSil_CDL(Liste_CDL l, char eserAdi[], int baskiSayisi) {
	ptrKitap_CDL current = l->head;
	
	if (current == NULL) return l;
	else if (l->head == l->head->ileri) {
		if ((!strcmp((current->eserAdi), eserAdi)) && (baskiSayisi == (current->baskiSayisi))) {
			l->head = NULL;
			free(current);
		}
		return l;
	}
	else {
		do {
			current = current->ileri;
			if ((!strcmp((current->eserAdi), eserAdi)) && (baskiSayisi == (current->baskiSayisi))) {
				if (current == l->head) {
					l->head = current->ileri;
				}
				current->ileri->geri = current->geri;
				current->geri->ileri = current->ileri;
				free(current);
				break;
			}

		} while (current != l->head);
		return l;
	}
}

ptrKitap_CDL kitapAra_CDL(Liste_CDL l, char eserAdi[]) {
	ptrKitap_CDL current = l->head;
	do {
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
	} while (current != l->head);

	printf("\nARADIGINIZ KITAP BULUNAMADI!!!!\n\n");

}

void yazdir_CDL(Liste_CDL l) {
	ptrKitap_CDL ix = l->head;
	if (!(l->head)) return;
	do{
		printf("\n\tEser adi: %s\n", ix->eserAdi);
		printf("\tYazar adi: %s\n", ix->yazarAdi);
		printf("\tEserin yayin yili: %d\n", ix->yayinYili);
		printf("\tEserin baski sayisi: %d\n", ix->baskiSayisi);


		ix = ix->ileri;
	} while (ix != l->head);
}
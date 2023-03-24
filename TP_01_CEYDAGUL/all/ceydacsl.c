#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ceydacsl.h"

//CIRCULAR SINGLY LINKED LIST


ptrKitap_CSL yeniKitap_CSL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {

	ptrKitap_CSL yeni = (ptrKitap_CSL)malloc(sizeof(struct kitap_CSL));
	if (!yeni) {
		return 0;
	}

	yeni->yayinYili = yayinYili;
	yeni->baskiSayisi = baskiSayisi;
	strcpy((yeni->eserAdi), eserAdi);
	strcpy((yeni->yazarAdi), yazarAdi);

	return yeni;
}

Liste_CSL kitapEkle_CSL(Liste_CSL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {
	//insert at head
	ptrKitap_CSL node = yeniKitap_CSL(eserAdi, yazarAdi, yayinYili, baskiSayisi);
	if (l->tail == NULL) {
		l->tail = node;
		node->ileri = node;
	}
	else {
		 node->ileri = l->tail->ileri;
		 l->tail->ileri = node;
	}
	return l;
}


Liste_CSL kitapSil_CSL(Liste_CSL l, char eserAdi[], int baskiSayisi) {
	ptrKitap_CSL current = l->tail;
	ptrKitap_CSL head = l->tail->ileri;
	ptrKitap_CSL prev;

	if (l->tail == NULL) return l;
	else if (l->tail == l->tail->ileri) {
		if ((!strcmp((current->eserAdi), eserAdi)) && (baskiSayisi == (current->baskiSayisi))) {
			l->tail = NULL;
			free(current);
		}
		return l;
	}
	else {
		do {
			prev = current;
			current = current->ileri;
			if ((!strcmp((current->eserAdi), eserAdi)) && (baskiSayisi == (current->baskiSayisi))) {
				prev->ileri = current->ileri;
				if (current == l->tail)
					l->tail = prev;
				free(current);
				//current = prev->ileri;
				break;

			}
		} while (current != l->tail);
		return l;
	}
	return l;
}


ptrKitap_CSL kitapAra_CSL(Liste_CSL l, char eserAdi[]) {
	ptrKitap_CSL current = l->tail->ileri;
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
	}
	while(current!=l->tail->ileri);

	printf("\nARADIGINIZ KITAP BULUNAMADI!!!!\n\n");

}

void yazdir_CSL(Liste_CSL l) {
	ptrKitap_CSL ix = l->tail->ileri;
	if (!(l->tail->ileri)) return;
	do {
		printf("\n\tEser adi: %s\n", ix->eserAdi);
		printf("\tYazar adi: %s\n", ix->yazarAdi);
		printf("\tEserin yayin yili: %d\n", ix->yayinYili);
		printf("\tEserin baski sayisi: %d\n", ix->baskiSayisi);


		ix = ix->ileri;

	} 
	while (ix != l->tail->ileri);
}
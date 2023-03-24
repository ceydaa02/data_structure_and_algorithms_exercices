#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ceyda.h"

/**
*SINGLY LINKED LIST
*/
ptrKitap_SL yeniKitap_SL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {

	ptrKitap_SL yeni = (ptrKitap_SL)malloc(sizeof(struct kitap_SL));
	if (!yeni) {
		return 0;
	}

	yeni->yayinYili = yayinYili;
	yeni->baskiSayisi = baskiSayisi;
	strcpy((yeni->eserAdi), eserAdi);
	strcpy((yeni->yazarAdi),yazarAdi);
	yeni->ileri = NULL;

	return yeni;
}

Liste kitapEkle_SL(Liste_SL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi) {
	//insert at end
	ptrKitap_SL node = yeniKitap_SL(eserAdi, yazarAdi, yayinYili, baskiSayisi);
	ptrKitap_SL current = l->head;
	if (current == NULL) {
		l->head = node;
	}
	else {
		//current = l->head;
		while (current->ileri != NULL) 
			current = current->ileri;
			current->ileri = node;
		
	}

	return l;
}

void kitapSil_SL(Liste_SL l, char eserAdi[], int baskiSayisi) {
	ptrKitap_SL current = l->head;
	ptrKitap_SL prev;
	while (current!=NULL){ 
		if ((!strcmp((current->eserAdi), eserAdi))&&(baskiSayisi==(current->baskiSayisi))) {
			if (current == l->head) {
				l->head = l->head->ileri;
				free(current);
				//current = l->head;
				break;

			}
			else {
				prev->ileri = current->ileri;
				free(current);
				break;

			}
		}
		else {
			prev = current;
			current = current->ileri;
		}

	}
}

ptrKitap_SL kitapAra_SL(Liste_SL l, char eserAdi[]) {
	ptrKitap_SL current = l->head;
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

void yazdir_SL(Liste_SL l) {
	ptrKitap_SL ix = l->head;
	if (!(l->head)) return;
	while (ix != NULL) {
		printf("\n\tEser adi: %s\n", ix->eserAdi);
		printf("\tYazar adi: %s\n", ix->yazarAdi);
		printf("\tEserin yayin yili: %d\n", ix->yayinYili);
		printf("\tEserin baski sayisi: %d\n", ix->baskiSayisi);


		ix = ix->ileri;
	}
}


/**
* CIRCULAR SINGLY LINKED LIST
*/

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
	} while (current != l->tail->ileri);

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

	} while (ix != l->tail->ileri);
}

/**
* DOUBLY LINKED LIST
*/

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

/**
* CIRCULAR DOUBLY LINKED LIST
*/

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
	else if ((l->head->ileri) == (l->head)) {
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
	do {
		printf("\n\tEser adi: %s\n", ix->eserAdi);
		printf("\tYazar adi: %s\n", ix->yazarAdi);
		printf("\tEserin yayin yili: %d\n", ix->yayinYili);
		printf("\tEserin baski sayisi: %d\n", ix->baskiSayisi);


		ix = ix->ileri;
	} while (ix != l->head);
}
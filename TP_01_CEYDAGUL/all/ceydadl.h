#ifndef CEYDADL_H_
#define CEYDADL_H_

//DOUBLY LINKED LIST

struct kitap_DL {
	char eserAdi[25];
	char yazarAdi[25];
	int yayinYili;
	int baskiSayisi;
	struct kitap_DL* ileri;
};
typedef struct kitap_DL* ptrKitap_DL;

struct liste_DL {
	ptrKitap_DL head;
};
typedef struct liste_DL* Liste_DL;

//parametrelerin degerleriyle doldurulmuş kitap_SL struct'ı dondurur.
ptrKitap_DL yeniKitap_DL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//linked list'in sonuna yeni kitap verisini ekler.
Liste_DL kitapEkle_DL(Liste_DL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//verilen parametrelere uyan veriyi linked list'ten siler.
void kitapSil_DL(Liste_DL l, char eserAdi[], int baskiSayisi);

//parametreye uyan kitabin degerlerini basar.
ptrKitap_DL kitapAra_DL(Liste_DL l, char eserAdi[]);

//linked list'in butun elemanlarini yazdirir.
void yazdir_DL(Liste_DL l);

#endif
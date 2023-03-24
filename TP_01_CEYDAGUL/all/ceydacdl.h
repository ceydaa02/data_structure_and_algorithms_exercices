#ifndef CEYDACDL_H_
#define CEYDACDL_H_

//DOUBLY LINKED LIST

struct kitap_CDL {
	char eserAdi[25];
	char yazarAdi[25];
	int yayinYili;
	int baskiSayisi;
	struct kitap_CDL* ileri;
};
typedef struct kitap_CDL* ptrKitap_CDL;

struct liste_CDL {
	ptrKitap_CDL tail;
};
typedef struct liste_CDL* Liste_CDL;


//parametrelerin degerleriyle doldurulmuş kitap_SL struct'ı dondurur.
ptrKitap_CDL yeniKitap_CDL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//linked list'in basina yeni kitap verisini ekler.
Liste_CDL kitapEkle_CDL(Liste_CDL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//verilen parametrelere uyan veriyi linked list'ten siler.
void kitapSil_CDL(Liste_CDL l, char eserAdi[], int baskiSayisi);

//parametreye uyan kitabin degerlerini basar.
ptrKitap_CDL kitapAra_CDL(Liste_CDL l, char eserAdi[]);

//linked list'in butun elemanlarini yazdirir.
void yazdir_CDL(Liste_CDL l);

#endif
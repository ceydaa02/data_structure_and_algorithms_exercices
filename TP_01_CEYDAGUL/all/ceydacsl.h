#ifndef CEYDACSL_H_
#define CEYDACSL_H_

//CIRCULAR SINGLY LINKED LIST

struct kitap_CSL {
	char eserAdi[25];
	char yazarAdi[25];
	int yayinYili;
	int baskiSayisi;
	struct kitap_CSL* ileri;
};
typedef struct kitap_CSL* ptrKitap_CSL;

struct liste_CSL {
	ptrKitap_CSL tail;
};
typedef struct liste_CSL* Liste_CSL;


//parametrelerin degerleriyle doldurulmuş kitap_SL struct'ı dondurur.
ptrKitap_CSL yeniKitap_CSL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//linked list'in basina yeni kitap verisini ekler.
Liste_CSL kitapEkle_CSL(Liste_CSL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//verilen parametrelere uyan veriyi linked list'ten siler.
void kitapSil_CSL(Liste_CSL l, char eserAdi[], int baskiSayisi);

//parametreye uyan kitabin degerlerini basar.
ptrKitap_CSL kitapAra_CSL(Liste_CSL l, char eserAdi[]);

//linked list'in butun elemanlarini yazdirir.
void yazdir_CSL(Liste_CSL l);

#endif
#ifndef CEYDA_H_
#define CEYDA_H_

/**
* SINGLY LINKED LIST
*/

struct kitap_SL {
	char eserAdi[25];
	char yazarAdi[25];
	int yayinYili;
	int baskiSayisi;
	struct kitap_SL* ileri;
};
typedef struct kitap_SL* ptrKitap_SL;

struct liste_SL {
	ptrKitap_SL head;
};
typedef struct liste_SL* Liste_SL;

//parametrelerin degerleriyle doldurulmuş kitap_SL struct'ı dondurur.
ptrKitap_SL yeniKitap_SL(char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//linked list'in sonuna yeni kitap verisini ekler.
Liste_SL kitapEkle_SL(Liste_SL l, char eserAdi[], char yazarAdi[], int yayinYili, int baskiSayisi);

//verilen parametrelere uyan veriyi linked list'ten siler.
void kitapSil_SL(Liste_SL l, char eserAdi[], int baskiSayisi);

//parametreye uyan kitabin degerlerini basar.
ptrKitap_SL kitapAra_SL(Liste_SL l, char eserAdi[]);

//linked list'in butun elemanlarini yazdirir.
void yazdir_SL(Liste_SL l);



/**
* CIRCULAR SINGLY LINKED LIST
*/
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


/**
* DOUBLY LINKED LIST
*/

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

/**
* CIRCULAR DOUBLY LINKED LIST
*/


#endif


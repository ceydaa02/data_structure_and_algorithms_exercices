#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"hash.h"
#define MULTIPLIER 29 

/* Stringler icin basit bir hash hesaplama fonksiyonu.
 * Her harfin ASCII degeri, onceki hash degerinin bir
 * carpanina ekleniyor.
 * Ornegin: "abcde" stringi icin:
 * ascii degerleri : a=97, b=98,c=99,d=100,e=101 
 *  h0 = 0 * 29 + 97 = 97
 *  h1 = h0 * 29 + 98 = 2911
 *  h2 = h1 * 29 + 99 = 84518
 *  h3 = h2 * 29 + 100 = 2451122
 *  h4 = h3 * 29 + 101 = 71082639
 *  71082639 % MAXBUCKETS (1000) = 639
 */
unsigned long hash_compute(const char *str){
  // TODO: Yukaridaki aciklamalara gore fonksiyonu yazin
	unsigned long hash = 0, prev = 0;
	for (int i = 0; str[i] != '\0';i++) {
		hash = prev * MULTIPLIER + str[i];
		prev = hash;
	}
	return hash % MAXBUCKETS;
}

/* Her elemani bir bagli liste gostericisi olan table
 * dizisi parametre olarak veriliyor. Bu table dizisi
 * aslinda hash veriyapisini temsil eder.
 *
 * str ile verilen string hash'te var ise adresi
 * dondurulur. Yoksa ve create == 1 ise, hash
 * veriyapisina bu string eklenir.
*/
Key* hash_lookup(Key **table,const char *str,int create){
  // TODO: str icin hash fonksiyonu cagirin 
	unsigned long hash = hash_compute(str);
	Key* tail = table[hash];
  // table hash tablosunda degeri arayin
  // deger bulunursa o degiskeni geri dondurun.
  // deger yoksa ve ekleme yapilacaksa 
	while (tail) {
		if (!strcmp(tail->word, str)) {
			return tail;
		}
		else {
			if (tail->next != NULL) tail = tail->next;
			else break;
		}
	}
	if (create) {

		// Hafizada eklenecek deger icin yer acin
		Key* value = (Key*)malloc(sizeof(Key));
		value->word = (char*)malloc(strlen(str)+1);
		// hafizada yer acildiysa  
		if ((value)&&(value->word)) {
			value->count = 0;
			strcpy(value->word, str);
			//printf("%s\n", value->word);
			if (!tail) table[hash] = value;
			else {
				tail->next = value;
			}
			value->next = NULL;
			return value;
			free(value);
		}
		else { printf("Memory couldn't be alocated."); }
		// yeni eleman icin count,word,next atamalari yapin
		// yeni eklenen elemani geri dondurun
	}

	return NULL;

}


/* table ile verilen hash veriyapisini
 * isletim sistemine iade eden fonksiyon.
 * Temizlerken, her bagli listenin dugumlerini
 * ve bu dugumlerdeki "word" uyesini free()
 * etmeniz gerekiyor.
*/
void hash_free(Key **table){
  // TODO
	for (int i = 0; i < MAXBUCKETS; i++) {
		Key* ptr = table[i];
		Key* prev = NULL;
		if (ptr) {
			do {
				prev = ptr;
				ptr = ptr->next;
				free(prev->word);
				free(prev);
			} while (ptr);
		}
	}
}


/* count parametresi >= n olan kelimeleri ekrana
 * yazdiran fonksiyon. Ekrana yazdirirken
 * "%30s-->%5ld\n" formatini kullanin.
 * %ld: unsigned long icin gerekiyor.
*/
void hash_dump(Key **table,int n){
  // TODO 
	for (int i = 0;i < MAXBUCKETS;i++) {
		if (table[i]) {
			Key* head = table[i];
			do {
				if (head->count >= n) {
					printf("%30s-->%5ld\n", head->word, head->count);
				}
				head= head->next;
			} while (head);
		}
	}
}

/*
 * tp05.c
 *
 *  Created on: 15 Kas 2022
 *      Author: pinar
 */

#include <stdio.h>
#include <limits.h>
#include <assert.h>

/* swap islemi icin macro, ayrica fonksiyon yazmaniza gerek yok */
static int _temp;
#define SWAP(a,b) do { \
  _temp = a; \
  a = b; \
  b = _temp; \
} while (0)

/* heap'i temsil eden dizinin uzunlugu */
static int SIZE = 10;

/* heap taklidi yapan dizinin elemanlarini ekrana bastiran fonksiyon
 * array: heap, size: heap'teki mevcut eleman sayisi */
void print_heap(int* arr, int size);

/* algoritmasi TP dosyasinda verilmis olan ve heap ozelligi bozulmus bir diziyi heap haline getiren fonksiyon, yonu: kokten yapraga
 * array: heap, index: heap ozelligini bozan elemanin asagi iteklenecek indeksi, size: heap'teki mevcut eleman sayisi */
void max_heapify_recursive(int* arr, int index, int size);

/* parametre olarak aldigi bir diziden max-heap ozelligini koruyan binary heap olusturan rekursif fonksiyon
 * array: heap, size: heap'teki mevcut eleman sayisi */
void build_max_heap(int* arr, int size);

/* oncelikli kuyruktaki maksimum oncelikli elemani donduren ve de elemani kuyruktan cikarip heap ozelliginin korunmasini da saglayan fonksiyon
 * arr: heap, size: heap'teki mevcut eleman sayisi */
int extractMax(int* arr, int size);

/* heap ozelligi bozulmus bir diziyi heap haline getiren fonksiyon, yonu: yapraktan koke
 * arr: heap, index: heap ozelligini bozan elemanin yukari iteklenecek indeksi */
void bubbleUp(int* arr, int index);

/* oncelikli kuyruga eleman ekleyen ve heap ozelligini korumasini saglayan fonksiyon
 * arr: heap, data: eklenecek elemanin degeri (ya da onceligi, bizim durumumuzda ikisi de ayni) */
void insertData(int* arr, int data);

/* oncelikli kuyruktan verilen indeksteki elemani cikaran ve heap ozelligini korumasini saglayan fonksiyon
 * arr: heap, index: cikarilacak elemanin indeksi */
void removeIndex(int* arr, int index);

/* oncelikli kuyrukta indeksi verilen elemanin degerini (onceligini) degistiren fonksiyon
 * arr: heap, index: onceligi guncellenecek elemanin indeksi, priority: yeni oncelik degeri */
void changePriority(int* arr, int index, int priority);

int main() {
	int arr1[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
	int arr2[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int heap[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };

	printf("\n>> arr1 icin max_heapify_recursive cagrildi\n");
	// max_heapify_recursive fonksiyonunu arr1'in max-heap ozelligini bozan elemani icin cagirin
	for (int i = 0; i < SIZE/2; i++) {
		if (arr1[i] < arr1[i * 2 + 1] || arr1[i] < arr1[i * 2 + 2]) {
			max_heapify_recursive(arr1, i, sizeof(arr1) / sizeof(arr1[0]));
		} 
	}

	// guncellenmis heap'i ekrana bastirin
	print_heap(arr1, SIZE);

	int i;
	// max_heapify_recursive icin test durumu
	for (i = 0; i < SIZE; i++)
		assert(arr1[i] == heap[i]);
	printf("\n>> max_heapify_recursive sorunsuz calisiyor, yola devam...\n");

	printf("\n>> arr2 icin build_max_heap cagrildi\n");
	// build_max_heap ile arr2'yi heap haline getirin
	build_max_heap(arr2, SIZE);

	// heap'i ekrana bastirin
	print_heap(arr2, SIZE);


	// build_max_heap icin test durumu
	for (i = 0; i < SIZE; i++)
		assert(arr2[i] == heap[i]);
	printf("\n>> build_max_heap sorunsuz calisiyor, yola devam...\n");

	// bundan sonraki islemleri heap dizisi uzerinde oncelikli kuyruk fonksiyonlarini kullanarak yerine getirecegiz
	printf("\n----Oncelikli kuyruk----\n\n");
	// oncelikli kuyruktaki en yuksek oncelikli elemani kuyruktan cekin, guncellenmis kuyruk yapisini ve cektiginiz eleman degerini ekrana bastirin
	int max = extractMax(heap, SIZE);
	printf(">> extracted max = %d", max);
	print_heap(heap, SIZE);
	printf("\n");
	// bir onceki islemi tekrarlayin
	max = extractMax(heap, SIZE);
	printf(">> extracted max = %d", max);
	print_heap(heap, SIZE);
	printf("\n");
	// oncelikli kuyruga degeri (onceligi) 35 olan bir eleman ekleyin ve kuyrugu ekrana bastirin
	insertData(heap, 35);
	printf(">> 35 eklendi");
	print_heap(heap, SIZE);
	// oncelikli kuyruktan 5 indeksli elemani cikarin ve kuyrugu ekrana bastirin
	removeIndex(heap, 5);
	printf("\n>>onceligi 5 olan eleman kuyruktan cikarildi");
	print_heap(heap, SIZE);


	// oncelikli kuyrugun 3 indeksli elemaninin onceligini 41 yapin ve kuyrugu ekrana bastirin
	changePriority(heap, 3, 41);
	printf("\n>>onceligi 3 olan eleman güncellendi\n");
	print_heap(heap, SIZE);

	return 0;
}

void print_heap(int *arr, int size) {
	printf("\n\t");
	for (int i = 0;i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void max_heapify_recursive(int *arr, int index, int size) {
	// index'in sol cocugunun dizi indeksini hesapla
	int i_left = 2 * index + 1;
	// index'in sag cocugunun dizi indeksini hesapla
	int i_right = 2 * index + 2;
	// en buyuk elemanin indeksini index kabul et (parent)
	int max_index = index;
	// sol cocuk parent'tan buyukse kaydet
	if (i_left < size && arr[i_left]>arr[index])
	max_index = i_left;
	else
		max_index = index;
	// sag cocuk kayitli buyukten buyukse kaydet
	if (i_right<size && arr[i_right]>arr[max_index])
		max_index = i_right;
	// Cocuklardan biri buyuk olarak kaydedildiyse parent ile onu degistirip, yeni buyuk icin rekursif cagri yap
	if (max_index != index) {
		SWAP(arr[index], arr[max_index]);
		max_heapify_recursive(arr, max_index, size);
	}
}

void build_max_heap(int *arr, int size) {
	// ders notlarindaki algoritma (slide no: 110)
	int node_to_begin_with = (size / 2) - 1;
	for (int i = node_to_begin_with; i >= 0; i--) {
		max_heapify_recursive(arr, i, size);
	}
}

int extractMax(int *arr, int size) {
	// kok degerini yedekle
	int max = arr[0];

	// kokun degerini, en son siradaki en sagdaki yaprak degeri ile degistir ve eleman sayisini guncelle
	SWAP(arr[0], arr[size - 1]);
	SIZE--;

	// heap ozelligini korumak icin heapify ile yeni koku agacta olmasi gereken yere gonder
	max_heapify_recursive(arr, 0, size - 1);

	// kok degerini gonder
	return max;

}

void bubbleUp(int *arr, int index) {
	// ders notlarindaki algoritma (slide no: 97)
	if (index < 0) return;
	int index_parent = (index - 1) /2;
	if (index_parent >= 0 && arr[index_parent] < arr[index]) {
		SWAP(arr[index_parent], arr[index]);
		bubbleUp(arr, index_parent);
	}
	else return;
}

void insertData(int *arr, int data) {	
	// heap'in uzunlugunu artir
	SIZE++;

	// en son indekse yeni eleman degerini ekle
	arr[SIZE - 1] = data;
	
	// heap ozelligini korumak icin bubbleUp'i cagir
	bubbleUp(arr, SIZE - 1);
}

void removeIndex(int *arr, int index) {
	// cikarilacak index'teki eleman degerine sonsuz veremiyoruz, INT_MAX veriyoruz
	arr[index] = INT_MAX;

	// bu yuksek degerli elemani koke dogru itekle
	bubbleUp(arr, index);

	// kokten cikar
	extractMax(arr, SIZE);
}

void changePriority(int *arr, int index, int priority) {
	// onceki priority'si yenisinden buyukse koke dogru , degilse yapraklara dogru itekle
	if (arr[index] > priority) {
		arr[index] = priority;
		max_heapify_recursive(arr, index, SIZE);
	}
	else {
		arr[index] = priority;
		bubbleUp(arr, index);

	}
}

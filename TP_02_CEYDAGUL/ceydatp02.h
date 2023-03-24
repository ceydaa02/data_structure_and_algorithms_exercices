#ifndef CEYDATP02_H_
#define CEYDATP02_H_

struct linked_list {
	int data;
	struct linked_list* ileri;
};
typedef struct linked_list* ptr_ll;

struct liste_stack {
	ptr_ll head;
};
typedef struct liste_stack* ptr_ll_stack;

struct liste_queue {
	ptr_ll head;
	ptr_ll tail;
};
typedef struct liste_queue* ptr_ll_queue;

/**
*LIFO IN ARRAY
*/
//yigit yapisindaki statik listenin sonuna eleman ekler.
int push_list(int liste[], int deger, int sayac);

//yigit yapisindaki statik listenin sonundan eleman cikarir.
int pop_list(int liste[], int sayac);

//yigit yapisindaki statik listenin butun elemanlarini ekrana yazdirir.
void printStack_list(int liste[], int sayac);

//yigit yapisindaki statik listeyi temizler.
int clearStack_list(int liste[], int sayac);

/**
*FIFO IN ARRAY
*/
//sira yapisindaki statik listenin sonuna eleman ekler.
void enqueue_list(int liste[], int deger, int* head, int* tail);

//sira yapisindaki statik listenin basindan eleman cikarir.
void dequeue_list(int liste[], int* head, int* tail);

//sira yapisindaki statik listenin butun elemanlarini ekrana yazdirir.
void printQueue_list(int liste[], int* head, int* tail);

//sira yapisindaki statik listeyi temizler.
void clearQueue_list(int* head, int* tail);

/**
*LIFO IN LINKED LIST
*/
//degiskenleri doldurulmus linked list dondurur.
ptr_ll yeniVeri(int veri);

//yigit yapisindaki dinamik listenin sonuna eleman ekler.
ptr_ll_stack push_stack(ptr_ll_stack l, int veri);

//yigit yapisindaki dinamik listenin sonundan eleman cikarir.
ptr_ll_stack pop_stack(ptr_ll_stack l);

//yigit yapisindaki dinamik listenin butun elemanlarini ekrana yazdirir.
void printStack_ll(ptr_ll_stack l);

//yigit yapisindaki dinamik listeyi temizler.
void clearStack_ll(ptr_ll_stack l);

/**
*FIFO IN LINKED LIST
*/
//sira yapisindaki dinamik listenin sonuna eleman ekler.
ptr_ll_queue enqueue_ll(ptr_ll_queue l, int veri);

//sira yapisindaki dinamik listenin basindan eleman cikarir.
ptr_ll_queue dequeue_ll(ptr_ll_queue l);

//sira yapisindaki dinamik listenin butun elemanlarini ekrana yazdirir.
void printQueue_ll(ptr_ll_queue l);

//sira yapisindaki dinamik listeyi temizler.
void clearQueue_ll(ptr_ll_queue l);


#endif
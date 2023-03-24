#include<stdio.h>
#include<stdlib.h>
#define N 8
#include"ceydatp02.h"


/**
*STACK IN ARRAY
*/

int push_list(int liste[], int deger, int sayac) {
	if (sayac != N) {
		liste[sayac] = deger;
		sayac++;
	}
	else printf("Listede elemani koyacak alan bulunamadi!\n");
	return sayac;
}

int pop_list(int liste[], int sayac) {
	if (!sayac) {
		printf("Listeden cikarilacak eleman bulunamadi!\n");
		return sayac;
	}
	sayac--;

	return sayac;
}

void printStack_list(int liste[], int sayac) {
	if (!sayac) printf("Gosterilecek eleman bulunamadi!\n");
	for (int i = 0; i < sayac; i++) {
		printf("%d ", liste[i]);
	}
}

int clearStack_list(int liste[], int sayac) {
	sayac = 0;
	return sayac;
}

/**
*QUEUE IN ARRAY
*/

void enqueue_list(int liste[], int deger, int* head, int*tail) {
	if (*head == *tail) {
		liste[(*head)] = deger;
		if ((*tail) == N - 1) *tail = 0;
		else (*tail)++;
	}
	else if ((*head - *tail) == 1 || (*tail - *head)== N - 1) {
		printf("LISTE DOLU!!!YENI ELEMAN EKLEMEK ICIN ONCE LISTEDEN ELEMAN SILMENIZ GEREKMEKTEDIR\n");
	}
	else {
		liste[(*tail)] = deger;
		if (*tail == N - 1) {
			*tail = 0;
		}
		else (*tail)++;
	}
}


void dequeue_list(int liste[], int* head, int* tail) {
	if (*head == *tail) {
		printf("Listeden cikarilacak eleman bulunamadi!\n");
	}
	if (*head == N - 1) {
		*head = 0;
	}
	else (*head)++;
}

void printQueue_list(int liste[], int* head, int* tail) {
	if (*head == *tail) {
		printf("Ekrana yazdirilacak eleman bulunamadi!\n");
	}

	if (*head < *tail){
		for (int i = *head; i < *tail; i++)
			printf("%d ", liste[i]);
		}
	else if (*head > *tail) {
		int i = *head;
		while (i != *tail) {
			printf("%d ", liste[i]);
			if (i == N - 1)
				i = 0;
			else i++;
		}
	}

}
void clearQueue_list(int* head, int* tail) {
	*head = 0;
	*tail = 0;
}

/**
*LINKED LIST
*/

ptr_ll yeniVeri(int veri) {
	ptr_ll yeni = (ptr_ll)malloc(sizeof(struct linked_list));
	if (!yeni) return 0;
	yeni->data = veri;
	yeni->ileri = NULL;
}

/**
*STACK IN LINKED LIST
*/

ptr_ll_stack push_stack(ptr_ll_stack l, int veri) {
	ptr_ll node = yeniVeri(veri);
	ptr_ll current = l->head;
	if (current == NULL) {
		l->head = node;
	}
	else {
		while (current->ileri != NULL)
			current = current->ileri;
		current->ileri = node;
	}
	return l;
}
ptr_ll_stack pop_stack(ptr_ll_stack l) {
	ptr_ll current = l->head;
	if (current == NULL)
		printf("Silinecek veri bulunmamaktadir.\n");
	else if (current->ileri == NULL) {
		l->head = NULL;
		free(current);
	}
	else {
		while (current->ileri->ileri != NULL)
			current = current->ileri;
		free(current->ileri);
		current->ileri = NULL;
		
	}
}

void printStack_ll(ptr_ll_stack l) {
	ptr_ll current = l->head;
	if (!(l->head)) printf("Listede ekrana bastirilacak eleman yok!\n");
	else {
		while (current != NULL) {
			printf("%d ", current->data);
			current = current->ileri;
		}
	}
}
void clearStack_ll(ptr_ll_stack l) {
	l->head = NULL;
}


/**
*QUEUE IN LINKED LIST
*/

ptr_ll_queue enqueue_ll(ptr_ll_queue l, int veri) {
	ptr_ll node = yeniVeri(veri);
	if (!l->head) {
		l->head = node;
		l->tail = node;
	}
	else {
		l->tail->ileri = node;
		l->tail = node;
	}
	return l;

}

ptr_ll_queue dequeue_ll(ptr_ll_queue l) {
	if (!(l->head)) printf("Listede silinecek eleman bulunamadi!");
	else if (!(l->head->ileri))
		l->head = NULL;
	else
		l->head = l->head->ileri;

	return l;
}

void printQueue_ll(ptr_ll_queue l) {
	ptr_ll current = l->head;
	if (!current) printf("Listede ekrana bastirilacak eleman yok!\n");
	else if (l->head == l->tail) {
		printf("%d ", current->data);
	}
	else {
		do {
			printf("%d ", current->data);
			current = current->ileri;
		} while (current != l->tail);
		printf("%d ", current->data);
	}
	
}

void clearQueue_ll(ptr_ll_queue l) {
	l->head = NULL;
	l->tail = NULL;
}



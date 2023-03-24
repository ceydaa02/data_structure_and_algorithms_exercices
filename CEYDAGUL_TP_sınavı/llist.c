#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#include "llist.h"

/* TODO: Yeni bir dugum yaratip adresini donduren fonksiyonu yazin */
struct node* new_node(unsigned char data) {
	struct node* n_node = (struct node*)malloc(sizeof(struct node));
	if (!n_node) {
		printf("Couldn't be created");
		return 0;
	}
	n_node->data = data;
	n_node->next = NULL;
	return n_node;
 }

/* TODO: data parametresiyle verilen sayiyi listenin ilgili yerine 
 * yerlestiren fonksiyonu yazin. 
 * UYARI: Listedeki dugumlerin data degerleri kucukten buyuge 
 * sirali olmalidir! */
struct node* insert(struct node *list, unsigned char data) {
	struct node* n_data = new_node(data);
	struct node* current = list;
	struct node* prev = NULL;
	if (current == NULL) {
		list = n_data;
		return list;
	}

	while(current!=NULL) {
		if (data < current->data) {
			if (current == list) {
				n_data->next = current;
				list = n_data;
				return list;
			}
			else {
				n_data->next = current;
				prev->next = n_data;
				return list;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	prev->next = n_data;
	return list;
}

/* TODO: Parametre olarak aldigi listenin median/ortanca
 * degerini donduren fonksiyonu yazin */
unsigned char get_median(struct node *list) {
	struct node* current = list;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	for (int i = 1; i <= (count / 2), current!=NULL ; i++) {
		if (i == (count / 2)) {
			return current->data;
		}
		else {
			current = current->next;
		}
	}
}

/* TODO: Parametre olarak aldigi listenin elemanlarini bastiran 
 * fonksiyonu yazin */
void print_list(struct node *list) {
	struct node* current = list;
	while (current != NULL) {
		printf("%d ", current->data);
	}
}

/* TODO: Parametre olarak aldigi liste (ve tum elemanlari) icin ayrilan 
 * yeri serbest birakan fonksiyonu yazin */
void free_list(struct node *list) {
	struct node* current = list;
	struct node* prev = NULL;
	while (current != NULL) {
		prev = current;
		current = current->next;
		free(prev);
	}
}

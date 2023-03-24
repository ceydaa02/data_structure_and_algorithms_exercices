#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int vertex;
	struct adjListNode* next;
}adjListNode;

typedef struct adj {
	adjListNode* head; 
}adjList;


typedef struct graph{
	int numVertices;
	adjList* adjLists;
}Graph;

typedef struct sehir {
	int plaka_kodu;
	int uzaklik;
	char sehir[15];
}Sehir;

adjListNode* newAdjListNode(int neighbor) {
	adjListNode* newNode = (adjListNode*)malloc(sizeof(adjListNode));
	newNode->vertex = neighbor;
	newNode->next = NULL;
	return newNode;
}

Graph* createGraph(int v) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->numVertices = v;
	graph->adjLists = (adjList*)malloc(v* sizeof(adjList));

	for (int i = 0; i < v; i++)
		graph->adjLists[i].head = NULL;

	return graph;
}

void addEdge(Graph* g, int center, int neighbor) {
	adjListNode* newNode = newAdjListNode(neighbor);
	newNode->next = g->adjLists[center].head;
	g->adjLists[center].head = newNode;

	newNode = newAdjListNode(center);
	newNode->next = g->adjLists[neighbor].head;
	g->adjLists[neighbor].head = newNode;
}


void find_degree(Graph* graph, int count[80]) {
	for (int v = 0; v < graph->numVertices; ++v) {
		adjListNode* pCrawl = graph->adjLists[v].head;
		while (pCrawl) {
			(count[v])++;
			pCrawl = pCrawl->next;
		}
	}
}

int main() {
	int V = 81;
	int merkez = 33;
	Graph* graph = createGraph(V);
	FILE* fp = fopen("sehir.txt", "r");
	Sehir sehirler [81];
	if (fp == NULL) {
		printf("sehir.txt dosyasi bulunamadi.\n");
		exit(1);
	}
	int i = 0;
	while (i<81) {
		if (fscanf(fp, "%d	%s	%d", &sehirler[i].plaka_kodu, sehirler[i].sehir, &sehirler[i].uzaklik) == -1) {
			break;
		}
		if (sehirler[i].plaka_kodu == 33) {
			i++;
			sehirler[i].plaka_kodu = 34;
			strcpy(sehirler[i].sehir, "istanbul");
			sehirler[i].uzaklik = 0;
		}
		i++;
	}

	if(fclose(fp)!=0) printf("%s\n", strerror(errno));

	for (int k = 0; k < 81;k++) {
		if (sehirler[k].plaka_kodu == 34) continue;
		for (int j = k + 1; j < 81; j++) {
			if (sehirler[j].plaka_kodu == 34) continue;
			if (abs((sehirler[k].uzaklik) - (sehirler[j].uzaklik)) <= 250) {
				addEdge(graph, k, j);
			}
		}
	}

	for (int k = 0; k < 81; k++) {
		if (sehirler[k].uzaklik <= 250) {
			if (sehirler[k].plaka_kodu == 34) continue;
			addEdge(graph, 33, k);
		}
	}
	int counts[81];
	for (int i = 0;i < 81;i++) {
		counts[i] = 0;
	}
	find_degree(graph, counts);

	for (int v = 0; v < graph->numVertices; ++v) {
		adjListNode* pCrawl = graph->adjLists[v].head;
		printf("\n\t Sehrin adi: %s\n\t", sehirler[v].sehir);
		printf(" Sehrin merkeze uzakligi: %d\n\t Komsulari: ", sehirler[v].uzaklik);
		while (pCrawl) {
			printf("%s ", sehirler[pCrawl->vertex].sehir);
			pCrawl = pCrawl->next;
		}
		printf("\n\t Komsu sayisi: %d\n\n", counts[0]);
	}

	return 0;
}
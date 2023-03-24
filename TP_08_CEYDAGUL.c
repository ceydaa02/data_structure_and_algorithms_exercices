#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<limits.h>

#define N 9
int a[N];

void dijkstra(int matrix[N][N], int source) {
	int uzaklik[N], isProcessed[N]; 

	for (int i = 0; i < N; i++)
		uzaklik[i] = INT_MAX, isProcessed[i] = 0;

	uzaklik[source] = 0;

	for (int count = 0; count < N - 1; count++) {

		int min = INT_MAX, min_i;
		for (int v = 0; v < N; v++) {
			if (isProcessed[v] == 0 && uzaklik[v] <= min) {
				min = uzaklik[v];
				min_i = v;
			}
		}

		isProcessed[min_i] = 1;

		for (int v = 0; v < N; v++) {
			if (!isProcessed[v] && matrix[min_i][v] && uzaklik[min_i] != INT_MAX && uzaklik[min_i] + matrix[min_i][v] < uzaklik[v]) {
				uzaklik[v] = uzaklik[min_i] + matrix[min_i][v];
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		a[i] = uzaklik[i];
	}
}

int main() {
	int cost_matrix_1[N][N] = { {0, 10, 0, 0, 0, 0, 0, 40, 0},
						{10, 0, 10, 0, 0, 0, 0, 0, 30},
						{0, 10, 0, 20, 100, 0, 0, 0, 100},
						{0, 0, 20, 0, 30, 0, 0, 0, 0},
						{0, 0, 100, 30, 0, 50, 0, 0, 30},
						{0, 0, 0, 0, 50, 0, 0, 0, 50},
						{0, 0, 0, 0, 0, 0, 0, 30, 70},
						{40, 0, 0, 0, 0, 0, 30, 0, 20},
						{0, 30, 100, 0, 30, 50, 70, 20, 0}
	};

	int cost_matrix_2[N][N] = { {0, 20, 0, 0, 0, 0, 0, 20, 0},
					{20, 0, 40, 0, 0, 0, 0, 0, 30},
					{0, 40, 0, 30, 100, 0, 0, 0, 15},
					{0, 0, 30, 0, 10, 0, 0, 0, 0},
					{0, 0, 100, 10, 0, 30, 0, 0, 20},
					{0, 0, 0, 0, 30, 0, 0, 0, 50},
					{0, 0, 0, 0, 0, 0, 0, 60, 60},
					{20, 0, 0, 0, 0, 0, 60, 0, 20},
					{0, 30, 15, 0, 20, 50, 60, 20, 0}
	};

	for (int i = 0; i < N; i++) {
		dijkstra(cost_matrix_1, i);
		for (int k = 0; k < N; k++) {
			cost_matrix_1[i][k] = a[k];
		}
		dijkstra(cost_matrix_2, i);
		for (int j = 0; j < N;j++) {
			cost_matrix_2[i][j] = a[j];
		}
	}

	printf("Birinci Firma:\n");
	printf("\n\t	1	2	3	4	5	6	7	8	9\n");

	for (int i = 0; i < N; i++) {
		printf("\t%d	", i + 1);
		for (int k = 0; k < N; k++) {
			printf("%d	", cost_matrix_1[i][k]);
		}
		printf("\n");
	}

	printf("\n\n");

	printf("Ikinci Firma:\n");
	printf("\n\t	1	2	3	4	5	6	7	8	9\n");

	for (int i = 0; i < N; i++) {
		printf("\t%d	", i + 1);
		for (int k = 0; k < N; k++) {
			printf("%d	", cost_matrix_2[i][k]);
		}
		printf("\n");
	}



	char* sehirler[9] = { "gaziantep", "adana", "izmir", "eskisehir", "ankara", "antalya", "trabzon", "kars", "istanbul" };

	char kalkis[10], varis[10];
	int k_no, v_no;
	printf("\nHangi iki sehir arasinda seyehat edeceksiniz?\nKalkis noktasi: ");
	scanf("%s", kalkis);
	printf("Varis noktasi: ");
	scanf("%s", varis);

	for (int i = 0;i < strlen(kalkis);i++)
		kalkis[i] = tolower(kalkis[i]);

	for (int i = 0;i < strlen(varis);i++)
		varis[i] = tolower(varis[i]);


	for (int i = 0; i < N; i++) {
		if (!strcmp(kalkis, sehirler[i]))
			k_no = i;
		if (!strcmp(varis, sehirler[i]))
			v_no = i;
	}

	if (cost_matrix_1[k_no][v_no] < cost_matrix_2[k_no][v_no])
		printf("\n%s-%s ucusu icin en iyi secenek 1.firma %d<%d\n", sehirler[k_no], sehirler[v_no], cost_matrix_1[k_no][v_no], cost_matrix_2[k_no][v_no]);
	else if (cost_matrix_1[k_no][v_no] > cost_matrix_2[k_no][v_no])
		printf("\n%s-%s ucusu icin en iyi secenek 2.firma %d<%d\n", sehirler[k_no], sehirler[v_no], cost_matrix_2[k_no][v_no], cost_matrix_1[k_no][v_no]);
	else printf("\n%s-%s ucusu iki firmada da ayni ucrettedir: %d\n", sehirler[k_no], sehirler[v_no], cost_matrix_1[k_no][v_no]);

	return 0;
}


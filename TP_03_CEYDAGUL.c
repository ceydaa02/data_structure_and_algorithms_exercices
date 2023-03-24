#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// BST dugum yapisini tanimlayin
struct node {
	int data;
	struct node* right;
	struct node* left;
};

// Yeni dugum yaratma fonksiyonunu yazin
struct node* newNode(int data) {
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->right = NULL;
	new->left = NULL;
	return new;
}

// Agaca rekursif olarak yeni dugum ekleyen fonksiyonu yazin
struct node* insertNode(struct node* n, int data) {
	if (!n) {
		n = newNode(data);
		return n;
	}

	if (data < n->data) {
		n->left = insertNode(n->left, data);
	}
	else {
		n->right = insertNode(n->right, data);
	}

	return n;
}

// Agactaki en dusuk degeri bulup donduren fonksiyonu yazin
int findMin(struct node *tree) {

	int min = tree->data;
	struct node* current = tree->left;
	while (current) {
		min = current->data;
		current = current->left;
	}
	return min;

}

// Agactaki en buyuk degeri bulup donduren fonksiyonu yazin
int findMax(struct node *tree) {
	int max = tree->data;
	struct node* current = tree->right;
	while (current) {
		max = current->data;
		current = current->right;
	}
	return max;
}

// Agactaki en yuksek degerli dugumun adresini donduren fonksiyonu yazin
struct node* findMaxNode(struct node *tree) {
	int max = findMax(tree);
	struct node* current = tree;
	if (!tree) return NULL;

	if (tree->data == max) return tree;
	else {
		current = current->right;
		findMaxNode(current);

	}
}

// Agactan rekursif olarak dugum silen fonksiyonu yazin, silinecek dugumun 2 cocugu varsa, silinen dugumu sol alt-agacin maksimum degerli dugumu olarak guncelleyin (https://www.cs.usfca.edu/~galles/visualization/BST.html adresindeki Delete fonksiyonu gibi)
struct node* deleteNode(struct node* tree, int data) {
	struct node* temp = NULL;
	if (!tree) return tree;
	if (data < tree->data) {
		tree->left = deleteNode(tree->left, data);
	}
	else if (data > tree->data) {
		tree->right = deleteNode(tree->right, data);
	}
	else {
		if (tree->left == NULL && tree->right == NULL) {
			free(tree);
			tree = NULL;
		}
		else if (tree->left == NULL) {
			struct node* temp = tree;
			tree = tree->right;
			free(temp);
		}
		else if (tree->right == NULL) {
			struct node* temp = tree;
			tree = tree->left;
			free(temp);
		}
		else {
			struct node* temp = findMaxNode(tree->left);
			tree->data = temp->data;
			tree->left = deleteNode(tree->left, temp->data);

		}
		return tree;
	}
	//Merhaba hocam, yukarıdaki kodun çalışıp da aynısının bir benzerini yazmaya çalıştığım aşağıdaki kodun neden çalışmadığını bir türlü kavrayamadım :) 
	//(silinecek leaf'in bulunduğu durum için)
	/*else {
		if (tree->left==NULL) {
			if (tree->right == NULL) {
				//leaf node, no child
				free(tree);
				tree = NULL;
				return tree;
			}
			else {
				//one child at right
				struct node* temp = tree;
				tree = tree->right;
				free(temp);
				return tree;

			}

		}
		else if (tree->right==NULL) {
			struct node* temp = tree;
			tree = tree->left;
			free(temp);
			return tree;
		}
		//sağ yok sol varı incelersin
		else {
			//two children
			struct node* maxNode = findMaxNode(tree->left);
			tree->data = maxNode->data;
			tree->left = deleteNode(tree->left, temp->data);
			return tree;

		}
	}*/

}





// Agaci rekursif olarak "in-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin
void printTreeInOrder(struct node* tree) { //sol node sag
	if (!tree) return;
	printTreeInOrder(tree->left);
	printf("%d ", tree->data);
	printTreeInOrder(tree->right);

}

// Agaci rekursif olarak "pre-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin
void printTreePreOrder(struct node* tree) { //node sol sag
	if (!tree) return;
	printf("%d ", tree->data);
	printTreePreOrder(tree->left);
	printTreePreOrder(tree->right);
}

// Agaci rekursif olarak "post-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin	
void printTreePostOrder(struct node* tree) {//sol sag node
	if (!tree) return;
	printTreePostOrder(tree->left);
	printTreePostOrder(tree->right);
	printf("%d ", tree->data);
}

// Level-order yontemi icin extra fonksiyonlar
// Rekursif olarak agacin yuksekligini hesaplayan fonksiyon
int findHeight(struct node *tree) {
	if (!tree)
		return 0;
	else {
		int h_left = findHeight(tree->left);
		int h_right = findHeight(tree->right);
		if (h_left > h_right)
			return (h_left + 1);
		else
			return (h_right + 1);
	}
}

// Rekursif olarak ayni hizadaki dugumleri bastiran fonksiyon
void printLevel(struct node *tree, int level) {
	if (!tree)
		return;
	if (level == 1)
		printf("%d ", tree->data);
	else if (level > 1) {
		printLevel(tree->left, level - 1);
		printLevel(tree->right, level - 1);
	}
}

// Yukaridaki iki fonksiyonu kullanarak agaci "level-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyonu yazin	
void printTreeLevelOrder(struct node* tree) {
	for (int i = 1; i <= findHeight(tree); i++) {
		printLevel(tree, i);
	}
}


int main(int argc, char *argv[]) {

	// Copy paste icin: 78 85 56 65 13 79 85 86 43
	struct node* agac = (struct node*)malloc(sizeof(struct node));

	// Komut satirindan aldiginiz parametreleri kullanarak bir BST tanimlayin ve olusturun
	int deger = atoi(argv[1]);
	agac = newNode(deger);
	for (int i = 2; i < argc; i++) {
		int deger = atoi(argv[i]);
		insertNode(agac, deger);
	}
	// Agaciniza 97 degerli yeni bir dugum ekleyin
	insertNode(agac, 97);
	
	// Agactaki dugumlerin min ve max degerlerini ekrana bastırın
	printf("Max deger: %d\n", findMax(agac));
	printf("Min deger: %d\n", findMin(agac));
	
	// Sirayla 85 ve 56 degerli dugumleri silin
	deleteNode(agac, 85);
	deleteNode(agac, 56);
	
	// In-order, pre-order, post-order ve level-order yontemleri ile agaci dolasarak dügümlerin degerlerini duzgun bir sekilde ekrana bastirin 
	printf("\nIn order: ");
	printTreeInOrder(agac);
	printf("\nPre order: ");
	printTreePreOrder(agac);
	printf("\nPost order: ");
	printTreePostOrder(agac);
	printf("\nLevel order: ");
	printTreeLevelOrder(agac);
	
	return 0;
}
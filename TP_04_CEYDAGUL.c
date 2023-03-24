#include <stdio.h>
#include <stdlib.h>

// Splay tree dugum yapisi
struct node {
	int data;
	struct node *left;
	struct node *right;
};

// Parametre olarak aldigi veri ile yeni dugum yaratip donduren fonksiyon
struct node* createNode(int data) {
	struct node *n = malloc(sizeof(struct node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

// Hangi rotation olduguna gore fonksiyonun adini duzeltin
struct node* zagRotate(struct node *n) //left rotation 
{
	struct node *temp = n->right;
	n->right = temp->left;
	temp->left = n;
	return temp;
}

// Diger tarafa olan rotation kodunu yazin
struct node* zigRotate(struct node *n) //right rotation
{
	struct node* temp = n->left;
	n->left = temp->right;
	temp->right = n;
	return temp;
}

// Parametre olarak aldigi agacin kokune (root) parametre olarak aldigi yeni veriyi (data) ekleyip agacini guncelleyen ve guncellenmis agacin yeni kokunu donduren fonksiyonu yazin. Aciklamalarinizi yorum satiri olarak eklemeyi unutmayin.
struct node* splay(struct node* root, int data) {
	//tree bo�sa veya root'a koymak istedi�imiz de�er zaten root'taysa hi�bir �ey yapmaz(root'u d�nd�r�r)
	if (!root || root->data == data) return root;
	else {
		
		if (root->data > data) { // arad���m�z data sol alt a�a�ta ise;
			if (root->left == NULL) return root; //solda veri yoksa data tree'de de�ildir
			if (root->left->data == data) {//root'un solundaysa tek sa�a d�n�� hareketi
				root = zigRotate(root);
				return root;
			}
			else if (root->left->data > data) {//aranan data a�ac�n sol alt dallar�ndan birindeyse;
				if (root->left->left) {	//e�er sol torun(sol �ocu�un sol �ocu�u) varsa sol toruna kadar olan daldaki data'y� alt a�ac�n root'u haline getir.
					root->left->left = splay(root->left->left, data);
				}
				//daha sonras�nda zig zig rotation yapar.
				root = zigRotate(root);
				root = zigRotate(root);
			}
			else if (root->left->data < data) {//aranan data a�ac�n root'unun sol alt a�ac�n�n sa��ndaysa;
				if (root->left->right) {//e�er sol �ocu�un sa� �ocu�u varsa aranan datay�, oraya kadar olan daldaki alt a�ac�n root'u haline getir.
					root->left->right = splay(root->left->right, data);
				}
				//�nce sol alt a�ac� sola d�nd�r, daha sonras�nda root'u sa�a d�nd�r.
				root->left = zagRotate(root->left);
				root = zigRotate(root);
			}
		}
		else if(root->data < data) {// arad���m�z data sa� alt a�a�ta ise;
			if (root->right == NULL) return root;//sa�da veri yoksa data tree'de de�ildir
			if (root->right->data == data) {//root'un sa��ndaysa tek sola d�n�� hareketi
				root = zagRotate(root);
				return root;
			}

			else if (root->right->data > data) {//aranan data a�ac�n root'unun sa� alt a�ac�n�n solundaysa;
				if (root->right->left) {//e�er sa� �ocu�un sol �ocu�u varsa aranan datay�, oraya kadar olan daldaki alt a�ac�n root'u haline getir.
					root->right->left = splay(root->right->left, data);
				}
				//�nce sa� alt a�ac� sa�a d�nd�r, daha sonras�nda root'u sola d�nd�r.
				root->right = zigRotate(root->right);
				root = zagRotate(root);
			}
			
			else if (root->right->data < data) {
				if (root->right->right) {//aranan data a�ac�n sa� alt dallar�ndan birindeyse;
					root->right->right = splay(root->right->right, data);//e�er sa� torun(sa� �ocu�un sa� �ocu�u) varsa sa� toruna kadar olan daldaki data'y� alt a�ac�n root'u haline getir.
				}
				//daha sonras�nda zig zig rotation yapar.
				root = zagRotate(root);
				root = zagRotate(root);
			}
		}
		return root;
	}
}

// Parametre olarak aldigi splay agaci kokune (root) parametre olarak aldigi veriyi (data) ekleyip yeni agacin kokunu donduren fonksiyon. Aciklamalarinizi yorum satiri olarak eklemeyi unutmayin.
struct node* insertNode(struct node *root, int data) {
	struct node* temp = root;
	if (!root) { //root bo�sa yeni datay� root'a atar
		root = createNode(data);
		return root;
	}
	while (temp) {
		if (data < temp->data) {//data, root'tan k���kse sol tarafa ekler
			if (!(temp->left)) {
				temp->left = createNode(data);
				break;
			}
			else temp = temp->left;

		}
		else {//data, root'tan b�y�kse vey e�itse sa� tarafa ekler
			if (!(temp->right)) {
				temp->right = createNode(data);
				break;
			}
			else temp = temp->right;
		}
	}
	root = splay(root, data); //splay fonksiyonu ile eklenen data root'a getirtilir ve root return edilir
	return root;
}

// Agaci rekursif olarak "pre-order" yontemi ile dolasip degerleri ekrana bastiran fonksiyon
void printTreePreOrder(struct node *tree) {
	if (tree) {
		printf("%d ", tree->data);
		printTreePreOrder(tree->left);
		printTreePreOrder(tree->right);
	}
}

int main(int argc, char *argv[]) {
	// Derste yaptigimiz ornekteki verileri komut satirindan alip agaca teker teker ekleyerek her seferinde adim adim agaci preorder yontemi ile ekrana bastirin
	// Agaca eklenecek veriler: 15 10 17 7 13 16
	struct node* splay_tree = (struct node*)malloc(sizeof(struct node));
	int sayi = atoi(argv[1]);
	splay_tree = createNode(sayi);
	printTreePreOrder(splay_tree);
	printf("\n");
	for (int i = 2; i < argc; i++) {
		int sayi = atoi(argv[i]);
		splay_tree = insertNode(splay_tree, sayi);
		printTreePreOrder(splay_tree);
		printf("\n");
	}

	return 0;
}

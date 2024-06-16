#include <iostream>
using namespace std;
#define LH -1
#define EH 0
#define RH 1

struct NODE {
	char Data;
	NODE *left; NODE *right;
	int Bal;
};

typedef NODE* AVLtree;

void Init(AVLtree &root) {
	root = NULL;
}

void rotateLL(AVLtree &T) {
	NODE *T1 = T->left;
	T->left = T1->right;
	T1->right = T;
	switch (T1->Bal) {
		case LH: T->Bal = EH;
			T1->Bal = EH; break;
		case EH: T1->Bal = LH;
			T1->Bal = RH; break;
	}
	T = T1;
}

void rotateRR(AVLtree &T) {
	NODE* T1 = T->right;
	T->right = T1->left;
	T1->left = T;
	switch (T1->Bal) {
	case RH: T->Bal = EH; break;
		T1->Bal = EH; break;
	case EH: T1->Bal = RH; break;
		T1->Bal = LH; break;
	}
	T = T1;
}

void rotateLR(AVLtree &T) {
	NODE* T1 = T->left;
	NODE* T2 = T1->right;
	T->left = T2->right;
	T2->right = T;
	switch (T2->Bal) {
	case LH: T->Bal = RH;
		T1->Bal = EH; break;
	case EH: T->Bal = EH; break;
		T1->Bal = EH; break;
	case RH: T->Bal = EH;
		T1->Bal = LH; break;
	}
	T2->Bal = EH;
	T = T2;
}


void rotateRL(AVLtree &T) {
	NODE* T1 = T->right;
	NODE* T2 = T1->left;
	T->right = T2->left;
	T2->left = T;
	T1->left = T2->right;
	T2->right = T1;
	switch (T2->Bal) {
	case LH: T->Bal = LH;
		T1->Bal = EH; break;
	case EH: T->Bal = EH; break;
		T1->Bal = EH; break;
	case RH: T->Bal = EH;
		T1->Bal = RH; break;
	}
	T2->Bal = EH;
	T = T2;
}

int balanceLeft(AVLtree &T) {
	NODE *T1 = T->left;
	switch (T1->Bal) {
	case LH: rotateLL(T); return 2;
	case EH: rotateLL(T); return 1;
	case RH: rotateLR(T); return 2;
	}
}

int balanceRight(AVLtree &T) {
	NODE *T1 = T->right;
	switch (T1->Bal) {
	case LH: rotateRL(T); return 2;
	case EH: rotateRR(T); return 1;
	case RH: rotateRR(T); return 2;
	}
}

int insertNode(AVLtree &T, char x) {
	int res;
	if (T) {
		if (int(T->Data) == int(x)) return 0; // da co
		if (T->Data > x) {
			res = insertNode(T->left, x);
			if (res < 2) return res;
			switch (T->Bal) {
			case RH: T->Bal = EH;
				return 1;
			case EH: T->Bal = LH;
				return 2;
			case LH: balanceLeft(T); return 1;
			}
		}
		else {
			res = insertNode(T->right, x);
			if (res < 2) return res;
			switch (T->Bal) {
			case LH: T->Bal = EH;
				return 1;
			case EH: T->Bal = RH;
				return 2;
			case RH: balanceRight(T); return 1;
			}
		}
	}
	T = new NODE;
	if (T == NULL) return -1; //thieu bo nho
	T->Data = x; T->Bal = EH;
	T->left = T->right = NULL;
	return 2; // chieu cao tang
}

void CreateAVL(AVLtree &T, char *a, int n) {
	for (int i = 0; i < n; i++) {
		if(a[i]) insertNode(T, a[i]);
		
	}
};

void LNR(AVLtree root)
{
	if (root != NULL)
	{
		LNR(root->left);
		std::cout << root->Data << " ";
		LNR(root->right);
	}
}

void NLR(AVLtree root)
{
	if (root != NULL)
	{
		std::cout << root->Data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

int main() {
	AVLtree T;
	Init(T);
	
	char a[10];
	a[0] = 'B';
	a[1] = 'A';
	a[2] = 'F';
	a[3] = 'G';
	a[4] = 'H';
	a[5] = 'K';

	CreateAVL(T, a, 6);
	NLR(T);
	cout << "\n";
	LNR(T);
	return 0;
}
#include <iostream>
using namespace std;

struct NODE {
	int data;
	NODE* left;
	NODE* right;
};

typedef NODE* TREE;


void Init(TREE &root)
{
	root = NULL;
	//  root->data = NULL;
	//  root->left = NULL;
	//  root->right = NULL;
}

//NODE* GetNode(int x)
//{
//	NODE* p = new NODE;
//	if (p != NULL)
//	{
//		p->left = NULL;
//		p->right = NULL;
//		p->data = x;
//	}
//	return (p);
//}

int InsertTree(TREE &T, int x)
{
	if (T != NULL)
	{
		if (T->data == x)
			return 0;
		if (T->data > x)
			return InsertTree(T->left, x);
		else
			return InsertTree(T->right, x);
	}
	else
	{
		T = new NODE;
		if (T == NULL) return -1;
		T->data = x;
		T->left = T->right = NULL;
		return 1;
	}
}



void searchStandFor(TREE &p, TREE &q)
{
	if (q->left)
		searchStandFor(p, q->left);
	else
	{
		p->data = q->data;
		p = q;
		q = q->right;
	}
}


int delNode(TREE &T, int X)
{
	if (T == NULL)	return 0;
	if (T->data > X) return delNode(T->left, X);
	if (T->data < X) return delNode(T->right, X);
	//T->Key == X
	NODE* p = T;
	if (T->left == NULL)
		T = T->right;
	else
		if (T->right == NULL)
			T = T->left;
		else // T có đủ 2 con
			searchStandFor(p, T->right);
	delete p;
}




void NLR(TREE root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(TREE root)
{
	if (root != NULL)
	{
		LNR(root->left);
		cout << root->data << " ";
		LNR(root->right);
	}
}

void LRN(TREE root)
{
	if (root != NULL)
	{
		LRN(root->left);
		LRN(root->right);
		cout << root->data << " ";
	}
}



int main()
{
	TREE T;
	Init(T);
	InsertTree(T, 1);
	InsertTree(T, 9);
	InsertTree(T, 6);
	InsertTree(T, 4);
	InsertTree(T, 0);
	InsertTree(T, 5);
	InsertTree(T, 7);
	cout << "\n";
	NLR(T);
	cout << "\n";
	LNR(T);
	cout << "\n";
	LRN(T);
}


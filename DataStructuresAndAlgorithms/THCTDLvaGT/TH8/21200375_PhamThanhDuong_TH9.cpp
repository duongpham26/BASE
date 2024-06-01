#include <iostream>

#define LH -1
#define EH 0
#define RH 1

struct NODE {
  int Data; 
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
   switch(T1->Bal) {
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
   T1->right = T;
   switch(T1->Bal) {
      case RH: T->Bal = EH; break;
         T1->Bal = EH; break;
      case EH: T1->Bal = RH; break;
         T1->Bal = LH; break;
   }
   T = T1;
}

void rotateLR(AVLtree &T) {
   NODE* T1 = T->left;
   NODE* T2 = T1-> right;
   T->left = T2->right;
   T2->right = T;
   switch(T2->Bal) {
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
   NODE* T2 = T1-> left;
   T->right = T2->left;
   T2->left = T;
   T1->left = T2->right;
   T2->right = T1;
   switch(T2->Bal) {
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

int insertNode(AVLtree &T, int x) {
   int res;
   if(T) {
      if(T->Data == x) return 0; // da co
      if(T->Data > x) {
         res = insertNode(T->left, x);
         if(res < 2) return res;
         switch(T->Bal) {
            case RH: T->Bal = EH;
               return 1;
            case EH: T->Bal = LH;
               return 2;
            case LH: balanceLeft(T); return 1;
         } 
      } else {
         res = insertNode(T->right, x);
         if(res < 2) return res;
         switch(T->Bal) {
            case LH: T->Bal = EH;
               return 1;
            case EH: T->Bal = RH;
               return 2;
            case RH: balanceRight(T); return 1;
         }
      }
   }
   T = new NODE;
   if(T == NULL) return -1; //thieu bo nho
   T->Data = x; T->Bal = EH;
   T->left = T->right = NULL;
   return 2; // chieu cao tang
}

int checkAVLTree(AVLtree root) {
   if (root != NULL)
	{
      if(root->Bal == -1) {
         std::cout << "\nCay lech trai\n";
         return -1;
      };
      if(root->Bal == 1) {
         std::cout << "\nCay lech phai\n";
         return 1;
      };
      checkAVLTree(root->left);
      checkAVLTree(root->right);
	}
   return 0;
}

int searchStandFor(AVLtree &p, AVLtree &q, AVLtree &T) {
   int res;
   if(q->left) {
      res = searchStandFor(p, q->left, T);
      if(res < 2) return res;
      switch (q->Bal) {
         case LH: q->Bal = EH;
            return 2;
         case EH: q->Bal = RH;
            return 1;
         case RH: return balanceRight(T);
      }
   } else {
      p->Data = q->Data;
      p = q;
      q = q->right;
      return 2;
   }
}

int delNode(AVLtree &T, int x) {
   int res;
   if(T == NULL) return 0;
   if(T->Data > x) {
      res = delNode(T->left, x);
      if(res < 2) return res;
      switch(T->Bal) {
         case LH: T->Bal = EH;
            return 2;
         case EH: T->Bal = RH;
            return 1;
         case RH: return balanceRight(T);
      }
   }
   if(T->Data < x) {
      res = delNode(T->right, x);
      if(res < 2) return res;
      switch(T->Bal) {
         case RH: T->Bal = EH;
            return 2;
         case EH: T->Bal = LH;
            return 1;
         case LH: return balanceLeft(T);
      }
   } else {
      NODE* p = T;
      if(T -> left == NULL) {
         T = T->right; res = 2;
      } else if(T->right == NULL) {
         T = T->left; res = 2;
      } else {
         res = searchStandFor(p, T->right, T);
         if(res < 2) return res;
         switch (T->Bal) {
            case RH:
               T->Bal = EH;
               return 2;
            case EH: T->Bal = EH;
               return 1;
            case LH: return balanceLeft(T);
         }
      }
      delete p;
      return res;
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

void LNR(AVLtree root)
{
	if (root != NULL)
	{
		   LNR(root->left);
		   std::cout << root->Data << " ";
		   LNR(root->right);
	}
}

int main() {

   // cai dat cay nhi phan bang danh sach lien ket
   AVLtree T;
   Init(T);

   // ham them node co gia tri ngau nhien
   insertNode(T, 7);
   insertNode(T, 10);
   insertNode(T, 5);
   insertNode(T, 4);
   insertNode(T, 8);
   insertNode(T, 12);
   insertNode(T, 6);

   // ham xac dinh loai lech
   if(checkAVLTree(T) == 0) {
      std::cout << "\nCay can bang\n";
   };

   // ham hien thi cay nhi phan
   LNR(T);

   // ham xoa phan tu va can bang lai cay
   delNode(T, 7);

   std::cout << "\n";

   // ham hien thi cay nhi phan
   LNR(T);

   return 0;
}
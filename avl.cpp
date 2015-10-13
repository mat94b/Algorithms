/*
* autor: Mateusz Buczynski
* data: 29.IV.2015
*
* strony pomocnicze:
*      -www.cs.uah.edu
*      -ILO Tarnow
*      -Geeksforgeek.com
*
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct Node
{
  Node *Parent;
  Node *Left;
  Node *Right;
  int value;
  int BF;
};

class AvlTree
{
  public:
    Node *root;  
    Node *maxNode(Node * x);
    Node *PreviousOne(Node * x);
    Node *RemoveIndexNode(Node * x);
    Node *RightRight(Node * A);
    Node *LeftLeft(Node * A);
    Node *RightLeft(Node * A);
    Node *LeftRight(Node * A);
    Node *FindIndexNode(int value);
    
    bool AddAndBalance(Node * n);
    void PrinterAvlTree();
    int counter;  

// metody do zadeklarowania *************************
    AvlTree();
    void Insert(int pValue);
    void Remove(int pValue);
    bool Find (int pValue);
    void Print(Node * pRoot);
};


AvlTree::AvlTree()
{
  root = NULL;
  counter = 0;
}


AvlTree * AVL = new AvlTree();
AvlTree o;
Node *korzen;
Node *y;
Node *z;
Node *p;
Node *nowy;
Node *efect;
bool checker;
int key;
Node *B;
Node *C;
Node *P;


// rotacje **************************************************************
Node * AvlTree::RightRight(Node * A)
{
  B = A->Right; 
  P = A->Parent;

  A->Right = B->Left;
  if(A->Right) A->Right->Parent = A;
  B->Left = A;
  B->Parent = P;
  A->Parent = B;
  if(P)
  {
    if(P->Left == A) P->Left = B; else P->Right = B;
  }
  else root = B;

  if(B->BF == -1)
  {
    A->BF = B->BF = 0;
  }
  else
  {
    A->BF = -1; B->BF = 1;
  }
  return B;
}

Node * AvlTree::LeftLeft(Node * A)
{
  Node * B = A->Left, * P = A->Parent;
  A->Left = B->Right;
  if(A->Left) A->Left->Parent = A;
  B->Right = A;
  B->Parent = P;
  A->Parent = B;
  if(P)
  {
    if(P->Left == A) P->Left = B; else P->Right = B;
  }
  else root = B;

  if(B->BF == 1)
  {
    A->BF = B->BF = 0;
  }
  else
  {
    A->BF = 1; B->BF = -1;
  }

  return B;
}


Node * AvlTree::RightLeft(Node * A)
{
  B = A->Right;
  C = B->Left;
  P = A->Parent;

  B->Left = C->Right;
  if(B->Left) B->Left->Parent = B;
  A->Right = C->Left;
  if(A->Right) A->Right->Parent = A;
  C->Left = A;
  C->Right = B;
  A->Parent = B->Parent = C;
  C->Parent = P;
  if(P)
  {
    if(P->Left == A) P->Left = C; else P->Right = C;
  }
  else root = C;

  A->BF = (C->BF == -1) ?  1 : 0;
  B->BF = (C->BF ==  1) ? -1 : 0;
  C->BF = 0;

  return C;
}



Node *AvlTree::LeftRight(Node * A)
{
  Node * B = A->Left, * C = B->Right, * P = A->Parent;

  B->Right = C->Left;
  if(B->Right) B->Right->Parent = B;
  A->Left = C->Right;
  if(A->Left) A->Left->Parent = A;
  C->Right = A;
  C->Left = B;
  A->Parent = B->Parent = C;
  C->Parent = P;
  if(P)
  {
    if(P->Left == A) P->Left = C; else P->Right = C;
  }
  else root = C;

  A->BF = (C->BF ==  1) ? -1 : 0;
  B->BF = (C->BF == -1) ?  1 : 0;
  C->BF = 0;

  return C;
}
//****************************************************************************



bool controlerFunctionFalse(Node *root, Node *n)
{
  while(root)  {
    if(root->value == n->value)
    {
      delete n;
      return false;
    }
    y = root;
    root = (n->value < root->value) ? root->Left : root->Right;
  }
}



Node *AvlTree::FindIndexNode(int value)
{
  korzen=root;

  while((korzen) && (korzen->value != value))
    korzen = (value < korzen->value) ? korzen->Left : korzen->Right;
    efect=korzen;
  return efect;  
}




Node * AvlTree::maxNode(Node * x)
{
  p=x;
  while(p->Right) 
	p = p->Right;
  return p;
}


Node * AvlTree::PreviousOne(Node * korzen)
{
  if(korzen->Left) return maxNode(korzen->Left);

  do
  {
    y = korzen;
    korzen = korzen->Parent;
  } while(korzen && (korzen->Right != y));
  Node *res=korzen;
  return res;  
}




Node * AvlTree::RemoveIndexNode(Node * x)
{

  if((x->Left) && (x->Right))
  {
    y = RemoveIndexNode(PreviousOne(x));
    counter++;
    checker = false;
  }
  else
  {
    if(x->Left)
    {
      y = x->Left; x->Left = NULL;
    }
    else
    {
      y = x->Right; x->Right = NULL;
    }
    x->BF = 0;
    checker = true;
  }

  if(y)
  {
    y->Parent = x->Parent;
    if(y->Left  = x->Left)  y->Left->Parent  = y;
    if(y->Right = x->Right) y->Right->Parent = y;
    y->BF = x->BF;
  }
    
  if(x->Parent)
  {
    if(x->Parent->Left == x) x->Parent->Left = y; else x->Parent->Right = y;
  }
  else root = y;
    
  if(checker)
  {
    z = y;
    y = x->Parent;
    while(y)
    {
      if(!(y->BF))
      {
        y->BF = (y->Left == z) ? -1 : 1;
        break;
      }
      else
      {
        if(((y->BF ==  1) && (y->Left  == z)) || ((y->BF == -1) && (y->Right == z)))
        {
          y->BF = 0;
          z = y; y = y->Parent;
        }
        else
        {
          p = (y->Left == z) ? y->Right : y->Left;
          if(!(p->BF))
          {


            if(y->BF == 1) LeftLeft(y); else RightRight(y);
            break;                      
          }
          else if(y->BF == p->BF)
          {

            if(y->BF == 1) LeftLeft(y); else RightRight(y);
            z = p; y = p->Parent;            
          }
          else
          {
            if(y->BF == 1) LeftRight(y); else RightLeft(y);
            z = y->Parent; y = z->Parent;              
          }
        }
      }
    }
  }
  counter--;
  return x;
}



void AvlTree::Print(Node * pRoot)
{
   cout<<"----------------------------WYPISYWANIE----------------------------\n\n";
   if(pRoot != NULL)
   {
      cout<<"Wezel: " << pRoot->value << " balanceFactor wynosi: " << pRoot->BF << "\n";
      if(pRoot->Left != NULL)
      {
         cout<<"\t Poruszenie na lewo\n";
         Print(pRoot->Left);
         cout<<"Powrot do wezla" << pRoot->value << " lewe poddrzewo\n";
      }
      else
      {
         cout<<"\t lewe poddrzewo jest puste \n";
      }
      cout<<"Wezel: " << pRoot->value << " balanceFactor wynosi " <<
         pRoot->BF << "\n";
      if(pRoot->Right != NULL)
      {
         cout<<"\t Poruszanie w prawo\n";
         Print(pRoot->Right);
         cout<<"Powrot do wezla" << pRoot->value << " prawe poddrzewo\n";
      }
      else
      {
         cout<<"\t prawe poddrzewo jest puste\n";
      }
   }
}



void AvlTree::PrinterAvlTree()
{
  AvlTree avlTreeObject;
  avlTreeObject.Print(AVL->root);	
}



void AvlTree::Insert(int pValue)
{
    nowy = new Node;
    nowy->value=pValue;
    AVL->AddAndBalance(nowy);      
  
    cout<<"----------------------------- WSTAWIANIE ---------------------------- \n";
    cout<<"Wstawianie nowego wezla przebieglo pomyslnie\n";
    cout<<"Wstawiono wezel: "<<pValue;
    cout<<"\n\n";
}

void conditionalerRemover(Node *toCheck, int key)
{
  p = AVL->RemoveIndexNode(toCheck);
  if (toCheck)
  {
    delete p;
    cout<<"----------------------------- USUWANIE ---------------------------- \n";
    cout<<"Usuwanie wezla przebieglo pomyslnie!\n";
    cout<<"Usunieto wezel: "<< key;
    cout<<"\n\n";
   }
   if(!toCheck){
    cout<<"--------------------------- NIEPOWODZENIE ------------------------- \n";
    cout<<"Usuwanie elementu zakonczone niepowodzeniem!\n";
    cout<<"Nie udalo sie usunac wezla: "<< key;
    cout<<"\n\n";
  }
}



void AvlTree::Remove(int pValue)
{
  y = AVL->FindIndexNode(pValue);
  conditionalerRemover(y, pValue);
}

bool conditionalerFinder(int key, Node *toCheck)
{
  if(toCheck){
    cout<<"----------------------------- SZUKANIE ---------------------------- \n";
    cout<<"Szukanie wezla zakonczone powodzeniem! Wezel znajduje sie w drzewie\n";
    cout<<"Odnaleziono wezel: "<< key <<" w drzewie";
    cout<<"\n\n";
    return true;
  }
  else {
    cout<<"--------------------------- NIEPOWODZENIE ------------------------- \n";
    cout<<"Odnalezienie elementu w drzewie nie powiodla sie!\n";
    cout<<"Wezla: "<< key <<" nie ma obecnie w drzewie..";
    cout<<"\n\n";
    return false;
  }
}

bool AvlTree::Find(int pValue)
{
  p=AVL->FindIndexNode(pValue);
  checker = conditionalerFinder(pValue, p);
  switch (checker)
  {
   case true: return true;
   case false: return false;
  }
}



bool AvlTree::AddAndBalance(Node * n)
{
  korzen=root;

  y = n->Left = n->Right = NULL;
  n->BF = 0;


  controlerFunctionFalse(korzen, n);
  
  if(!(n->Parent = y))
  {
    root = n;
    return true;
  }
  if(n->value < y->value) y->Left = n; else y->Right = n;
  if(y->BF)
  {
    y->BF = 0;
    return true;
  }
  y->BF = (y->Left == n) ? 1 : -1;
  z = y->Parent;
  while(z)
  {
    if(z->BF) break;
    z->BF = (z->Left == y) ? 1 : -1;
    y = z; z = z->Parent;
  }

  if(!z) return true;

  if(z->BF == 1)
  {
    if(z->Right == y)
    {
      z->BF = 0;
      return true;
    }
    if(y->BF == -1) LeftRight(z); else LeftLeft(z);
    return true;
  }
  else
  {
    if(z->Left == y)
    {
      z->BF = 0;
      return true;
    }
    if(y->BF == 1)
	RightLeft(z); 
    else 
	RightRight(z);
    return true;
  }
  counter++;
}


void InsertTest()
{
  o.Insert(24);
  o.Insert(13);
  o.Insert(1);
  o.Insert(29);
  o.Insert(2);
  o.Insert(3);
  o.Insert(22);
  o.Insert(26);
  o.Insert(25);
  o.Insert(12);
  cout<<"TEST WSTAWIANIA ZOSTAL PRZEPROWADZONY\n\n\n";
}

void RemoveTest()
{
 o.Remove(1);
 o.Remove(2);
 o.Remove(3); 
 cout<<"TEST USUWANIA ZOSTAL PRZEPROWADZONY\n\n\n";
}

void FindTest()
{
 o.Find(24);
 o.Find(13);
 o.Find(23);
 cout<<"TEST WYSZUKIWANIA ZOSTAL PRZEPROWADZONY\n\n\n";
}


int main(void)
{
  cout<<"\n\n*********************************************************************\n";
  cout<<"***** autor: *********************************** data: **************\n";
  cout<<"***** Mateusz Buczynski ************************ 29.IV.2015 *********\n";
  cout<<"*********************************************************************\n";
  cout<<"*********************************************************************\n";
  cout<<"***** MATERIALY POMOCNICZE: *****************************************\n";
  cout<<"****************************     -www.cs.uah.edu     ****************\n";
  cout<<"****************************     -ILO Tarnow         ****************\n";
  cout<<"****************************     -Geeksforgeek.com   ****************\n";
  cout<<"*********************************************************************\n";
  cout<<"*********************************************************************\n\n";

//Testy ***************************************

  InsertTest();
  RemoveTest();
  FindTest();
  o.PrinterAvlTree(); // mozna tez o.Print(AVL->root); 

  cout<<"*********************************************************************\n\n";
  cout<<"*************************** KONIEC **********************************\n\n";
  cout<<"*********************************************************************\n\n";
  return 0;
}


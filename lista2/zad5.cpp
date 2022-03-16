#include <iostream>
using namespace std;

// Podstawowa struktura listy jednokierunkowej

struct node
{
  int key;
  node* next;
 
  node(int k, node* n):key(k),next(n){}
};

typedef node* list;

void push(list & l,int k) // wkładanie na początek listy
{ 
  l=new node(k,l);
}

int pop(list &l) // wyciąganie pierwszego
{ 
    list tmp=l;
    int res=l->key;
    l=l->next;
    delete tmp;
    return res;
}  

bool empty(list l) // sprawdzanie czy lista jest pusta
{ 
  return l==NULL;
}

void destroy(list& l) //usuwa wszystkie elementy z listy  
{ 
  while(l)
    {
      list l1=l;
      l=l->next;
      delete l1;
    }
}

void wypisz(list l)
{
    for(;l;l=l->next)
      cout<<l->key<<" ";
    cout<<endl;  
}

void reverse(list& L){
  list temp = nullptr;
  list poprzedni = nullptr;

  while (L != nullptr)
  {
    temp = L->next;
    L->next = poprzedni;
    poprzedni = L;
    L = temp;
  }
  L = poprzedni;
}


 int main()
 {
    list l=nullptr;
    for(int i=1;i<=5;i++)
    {
      push(l,i);
      
    }

    wypisz(l);
    reverse(l);
    wypisz(l);
 }

/*
Pierwsza iteracja:

temp = 4 3 2 1
head -> next = NULL
poprzedni = 5
head = 4 3 2 1

Druga iteracja:
temp = 3 2 1
head -> next = 5
poprzedni = 4 5
head = 3 2 1

Trzecia iteracja:
temp = 2 1
head -> next = 4 5
poprzedni = 3 4 5
head = 2 1

Czwarta iteracja:
temp = 1
head -> next = 3 4 5
poprzedni = 2 3 4 5
head = 1

Piąta iteracja:
temp = NULL
head -> next = 2 3 4 5
poprzedni = 1 2 3 4 5
head = NULL -> koniec.
*/
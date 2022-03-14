#include <iostream>
#include <cassert>
using namespace std;

// Operacje na drzewie BST 
// Przykłady do wykładu z Algorytmów i Struktur Danych 
// C. Juszczak (2020)
//             8
//          5       9
//        3   6   8   10                     
//      1                11
//     0
//	-1   

//   l->8

/// 1 3 5 6 7 8 8 9 10 
struct node  // drzewo BST bez wskaźnika na rodzica
{ 
	int key;
	node* left;
	node* right;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:key(x0), left(l), right(r)
	{}
};

node* t=nullptr;
void insert_recursive(node *& t, int x) // wstawianie (rekurencyjnie)
{
	if(!t)
		t=new node(x);
	else
		insert_recursive( x < t->key ? 
		                      t->left : 
							  t->right, 
						  x); // tail recursion 
}  

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)  // znajdź wskaźnik na null, gdzie należy podczepić x
		 t1= x < (*t1)->key ?
				&(*t1)->left:
				&(*t1)->right;
	*t1=new node(x);
}  

node* find(node* t,int x)  // wyszukiwanie klucza 
{
	while(t && t->key!=x)
		t=  x < t->key ? 
				t->left : 
				t->right; 
	return t;
}


void inorder(node *t)  // wypisanie kluczy w porządku "in order"
{
	if(t)
	{
		inorder(t->left);
		std::cout<<t->key<<" ";
		inorder(t->right);
	}
}

void prerder(node *t) // wypisanie kluczy w porządku "pre order"  
{
	if(t)
	{
		std::cout<<t->key<<" ";
		prerder(t->left);
		prerder(t->right);
	}
}

void postorder(node *t) // wypisanie kluczy w porządku "post order"  
{
	if(t)
	{
		postorder(t->left);
		postorder(t->right);
		std::cout<<t->key<<" ";
	}
}

void display(node *t,char z1=' ',char z2=' ') // in order z nawiasami 
{
	if(t)
	{
		std::cout<<z1;
		display(t->left,'(',')');
		std::cout<<t->key;
		display(t->right,'[',']');
		std::cout<<z2;
	}
}

void display2(node *t,int d=0) // in order w wiwlu liniach
{
	if(t)
	{
		display2(t->right,d+1);
		for(int i=0;i<d;i++)
			std::cout<<"  ";
		std::cout<<t->key<<endl;
		display2(t->left,d+1);
	}
}


int n(node* t)   // ilość kluczy w drzewie (rekurencyjnie)
{
	return  t ?  // jeśli drzewo nie jest puste
			1 + n(t->left) + n(t->right): // korzeń + lewe + prawe
			0 ;  // puste drzewo ma 0 kluczy
}

int H(node* t)  // wysokość drzwa BST (rekurencyjnie)
{
	if(!t) return 0;
	int hL=H(t->left);
	int hR=H(t->right);	 
	return 1+ (hR > hL ? hR : hL);
}

int h(node* t) // wysokość drzwa BST (to samo krócej)
{
	return t ? 
		   1+std::max(h(t->left),h(t->right)):
		   0;
}


int min (node* t)  // minimalny klucz
{
	assert(t);
	while(t->left)
		t=t->left;
	return t->key;
}

int max (node* t)   // maksymalny klucz
{
	assert(t);
	while(t->right)
		t=t->right;
	return t->key;
}

void remove(node *&t, int x)  // usuwanie elementu z drzewa (bez rekurencji)
{
	node **t1=&t;
	while (*t1 && (*t1)->key!=x) // znajdź wskaźnik na węzeł zawierający x
		t1= x < (*t1)->key ?
			&(*t1)->left : 
			&(*t1)->right; 

	if(*t1) // jeśli znaleziono 
	{
		if((*t1)->right && (*t1)->left) // jeśli ma dwóch synów
		{                               
			node **t2=&(*t1)->right; // zaczynając od prawego syna
			while ((*t2)->left)      // idź w lewo póki można
				t2=&(*t2)->left;     // docelowo t2 to minimum prawego poddrzewa 
			(*t1)->key=(*t2)->key;   // skopiuj klucz do "usuwanego" węzła 
			t1=t2;                   // i zamiast niego przeznacz ten do usunięcia
		}	
		// tutaj *t1 ma już co najwyżej jednego syna 
		node *son = (*t1)->right ? 
					(*t1)->right : 
					(*t1)->left;
		delete *t1;  // usuwamy węzeł
		*t1=son;     // i zastępujemy synem
	}
}

void destroy(node*&t) // usunięcie drzwa i zwolnienie pamięci (rekurencyjnie)
{
	if(t)
	{	destroy(t->left);
		destroy(t->right);
		delete t;
		t=nullptr;
	}
}

int main()
{
	node* t=nullptr; // tworzymy puste drzewo BST
	
	// dodajemy klucze

	insert(t,3);
	insert(t,4); 
	insert(t,1);
	insert(t,7);
	insert(t,-4);
	insert(t,9);
	insert(t,2);
	
	cout<<"struktura:\n"; display2(t);
	cout<<"kolejność inorder :"; inorder(t); cout<<endl;
	cout<<"kolejność prerder :"; prerder(t); cout<<endl;
	cout<<"kolejność postrder:"; postorder(t);cout<<endl;
	//cout<<"struktura         :"; display(t);cout<<endl;
	cout<<"Ilość węzłow    = "<<n(t)<<endl;
	cout<<"Wysokość drzewa = "<<h(t)<<endl;
	cout<<"min = "<<min(t)<<" max = "<< max(t)<<endl;
	cout<<"wyszukaj 9: "<<find(t,9)->key<<endl;
	cout<<"usuń korzeń ("<<t->key<<"): \n"; remove(t,t->key); display2(t);
	cout<<"usuń 9:\n"; remove(t,9); display2(t); 
	cout<<"Usuń drzewo:\n";destroy(t); display2(t);
	int x=0;

	while(cout<<"podaj liczbę ",cin>>x )
	{	if(x<0)
			remove(t,-x);
		if(x>0)
			insert(t,x);
		if(x==0)
			if(cout<<"Jaką liczbę wyszukać: ",cin >>x)
			{
				display2(find(t,x));
				cout<<"============================"<<endl;
			}
		display2(t);
	}

	destroy(t);

}


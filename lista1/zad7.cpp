#include<iostream>

using namespace std;

struct lnode {
    int key;
    lnode *next;

    lnode(int key0, lnode* next0=nullptr): key(key0), next(next0) {}
};

typedef lnode* list;


// podpunkt A
void wypisz(list l){
    for(;l;l=l->next){
        cout << l->key << " ";
    }
    cout << endl;
}

// podpunkt B
int suma(list l){
    int result = 0;
    for(;l;l=l->next){
        result += l->key;
    }
    return result;
}

// podpunkt C
int nty(int n, list L){
    int result = 0;
    for(int i = 0; i < n-1; i++){
        L = L->next;
        if(L == nullptr)
            return 0;
    }
    return L->key;
}


// podpunkt d
void insert(list &l,int k)
{ 
  l=new lnode(k,l);
}


// podpunkt e
void insert_after_smaller(list &L, int x) {
    list l = L;
    while (l != nullptr) {
        if (l->key < x) {
            l->next = new lnode(x, l->next);
        }
        l = l->next;
    }
}


//podpunkt f
void remove(list &L, int x){
    list l = L;
    while (l != nullptr) {
        if (l->key == x) {
            l->next = new lnode(x, l->next);
        }
        l = l->next;
    }
}

// podpunkt g
void filter(lnode* &L, bool(*cond)(int)){

}

bool is_even(int x){
    return !(x % 2);
}

//podpunkt h
void destroy(lnode* &L) {
    while (L != nullptr) {
        lnode* l1 = L;
        L = L->next;
        delete l1;
    }
}





int main(){
    list l = nullptr;
    for(int i = 10; i >= 1; i--){
        insert(l, i);
        // wypisz(l);
    }

    

    wypisz(l);
    insert_after_smaller(l, 3);
    wypisz(l);

    cout << nty(7, l) << endl;
    cout << nty(13, l) << endl;

    destroy(l);

    wypisz(l);
    
}
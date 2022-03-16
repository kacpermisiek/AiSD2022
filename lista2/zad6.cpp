#include <iostream>

struct lnode{
    int key;
    lnode* next = nullptr;
    lnode(int x) : key(x), next(nullptr){}
};

void put_front(lnode* &L, int key)
{
    lnode* new_element = new lnode(key);
    new_element->next = L;
    L = new_element;
}

void print(lnode* L)
{
    if (L == nullptr) return;

    while (L != nullptr){
        std::cout << L->key << ' ';
        L = L->next;
    }
    std::cout << '\n';
}

lnode* merge_list(lnode* L1, lnode* L2)
{
    lnode *dummy = new lnode(-1);
    lnode *prevNode = dummy;

    while(L1 != NULL && L2 != NULL){
      
      if(L1->key < L2->key){
        prevNode->next = L1;
        L1 = L1->next;
      }
      else{
        prevNode->next = L2;
        L2 = L2->next;
      }
      prevNode = prevNode->next;
    }

    if(L1 != NULL)
      prevNode->next = L1;
    if(L2 != NULL)
      prevNode->next = L2;
    
    lnode *res = dummy->next;
    return res;
}

int main()
{
    struct lnode* L1 = new lnode(18);
    put_front(L1, 7);
    put_front(L1, 2);
    put_front(L1, 1);
    std::cout << "L1: ";
    print(L1);

    struct lnode* L2 = new lnode(40);
    put_front(L2, 30);
    put_front(L2, 10);
    put_front(L2, 9);
    put_front(L2, 8);
    put_front(L2, 1);
    std::cout << "L2: ";
    print(L2);

    std::cout << "\nListy L1 + L2: \n";
    struct lnode* new_list = merge_list(L1, L2);
    print(new_list);
}
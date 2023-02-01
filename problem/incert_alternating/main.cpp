#include <iostream>

using namespace std;

struct node {
    int data ;
    node *next = nullptr;
    node(int data) : data(data){}
};

class linked_list {
private:
    node *head = nullptr;
    node *tail = nullptr;
    int lenght = 0;


public:
    void incert (int data){
        ++lenght;
        node *item = new node(data);
        if(!head)
            head = tail = item ;
        else{
            tail->next = item;
            tail = item ;
            tail->next =nullptr;
        }


    }




    void print (){
        for (node *temp = head ; temp  ;temp =temp->next)
            cout<<temp->data;
    }


    int find_by_idx(int idx){
       node *temp = head;
       for(int i = 0 ; idx > i ; ++i){
           temp = temp->next;
           if(!temp)
             return 0;
       }
       return temp->data;
   }

   void alternating(linked_list b){
       node *prv = head;
       node *next = head->next;
       if (lenght >= b.lenght){
           for(int i = 0 ; i< b.lenght ; ++i){
               int data = b.find_by_idx(i);
               node *new_item = new node(data);
               prv->next = new_item;
               new_item->next = next;
               prv = next ;
               next =next->next;
           }
       }
       else{
           int i = 0;
           for( ; i< lenght-1 ; ++i){
               int data = b.find_by_idx(i);
               node *new_item = new node(data);
               prv->next = new_item;
               new_item->next = next;
               prv = next ;
               next =next->next;
               //print();
           }

           for(;i < b.lenght ;++i){
              int data = b.find_by_idx(i);
              incert(data);
           }
       }

   }
















};

int main()
{
    linked_list a ;
    linked_list b ;
    a.incert(1);
    a.incert(2);
    a.incert(3);
    b.incert(4);
    b.incert(5);
    b.incert(6);
    b.incert(7);
    a.alternating(b);
    a.incert(8);


    a.print();

    return 0;
}


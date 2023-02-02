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



   void remove_repeated(){//this functune remove all repeated values form sorted linked list

       for (node *temp = head ; temp != tail ; temp = temp->next){
           if(temp == head && temp->data == temp->next->data){
              head = head->next ;
           }

           else if(temp->data == temp->next->data){
              node *next =temp->next;

              node *prv =head;
              for( ; prv->next->data != temp->data ; prv =prv->next ){
              }
              prv->next =next;
           }
       }

   }


};

int main()
{
    linked_list a ;
    a.incert(1);
    a.incert(1);
    a.incert(1);
    a.incert(2);
    a.incert(2);
    a.incert(2);
    a.incert(3);
    a.incert(5);
    a.incert(8);
    a.incert(8);
    a.incert(8);
    a.remove_repeated();
    //a.incert(8);


    a.print();

    return 0;
}


#include <iostream>

using namespace std;

struct node{
    int data{} ;
    node *next {} ;// this pointer point for the next node
    node(int data) : data(data){}
};

class linkedList{
private:
   node *head {} ;
   node *tail {} ;
   int length = 0;
public:
   void print(){
       for(node *temp = head; temp != nullptr ;temp = temp ->next){
          cout<<temp->data ;
       }
   }

   void incert(int n){
       ++length;
       node *item = new node(n);
       if(!head)
         head =tail = item;// here we make the three look for the same memory
       else
         tail->next = item;// her we say for the frist node point to he next item
         tail = item;// her we make the tail look for the item

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


   void incert_front(int vall){// any vall will enter will be the frist element
       ++length;

       node *item = new node(vall);
       if(!head)
         head = tail = item;
       else
         item->next = head;
         head = item;
   }


   void delete_front(){//delete the frist element in the node
       --length;

       node *cur = head->next ;
       delete head;
       head = cur;
   }



   int find_by_idx_from_back(int idx1){//the frist element from back is 1

       int x = -idx1+length;
       return find_by_idx(x);
   }





};

int main()
{
    linkedList a ;

    a.incert(1);
    a.incert(2);
    a.incert(3);
    a.incert_front(7);
    a.incert(4);


    a.delete_front();

    a.print();
    cout<<endl;
    cout<<a.find_by_idx_from_back(2);
    cout<<a.find_by_idx(1);


    return 0;
}

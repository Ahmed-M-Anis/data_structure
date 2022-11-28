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
       int i = 0;
       for(node *temp = head; temp != nullptr ;temp = temp ->next){
          cout<<temp->data ;

          ++i;

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

   void left_rotate(){//that will make the first elenimt in linked list the last one
       node *temp = head;
       head = head->next ;
       tail->next = temp ;
       temp->next = nullptr ;
       tail = temp;
   }

   void left_rotate_for_n(int n){
       for(int counter = 0 ; counter< n ; ++counter){
           left_rotate();
       }
   }







};

int main()
{
    linkedList a ;

    a.incert(1);
    a.incert(2);
    a.incert(3);
    a.incert(4);
    a.incert(5);
    a.incert(6);
    a.left_rotate_for_n(3);

    a.print();

    return 0;
}

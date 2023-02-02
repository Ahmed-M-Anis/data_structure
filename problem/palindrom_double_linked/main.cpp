#include <iostream>

using namespace std;

struct node{
    int data{};
    node *next {};
    node *prv {};
    node(int data) : data(data){}
};

class double_linked_list{
private:

    node *head {};
    node *tail {};
    int length = 0;
public:

    void insert_normaly(int vall){
        node *item = new node(vall);
        ++length;
        if(!head)
            head =tail =item;
        else{
            tail->next = item;
            item->prv = tail;
            tail = item ;
            tail->next = nullptr;
        }
    }

   void forward_print(){
       for(node *temp = head; temp != nullptr ;temp = temp ->next){
          cout<<temp->data ;
       }
   }


   bool palindrom(){
       node *front1 = head;
       node *end1 = tail;
       int x ;
       for(int i = 0 ; length/2>i ; ++i){
           if(front1->data == end1->data)
              x = 1;
           else{
              x = 0 ;
              return x;
           }
           front1 = front1->next ;
           end1 = end1->prv;
       }
   }







};

int main()
{
    double_linked_list a ;


    a.insert_normaly(0);
    a.insert_normaly(1);
    a.insert_normaly(2);
    //a.insert_normaly(3);
    a.insert_normaly(2);
    a.insert_normaly(1);
    a.insert_normaly(0);

    cout<<a.palindrom();



    //a.insert_normaly(6);



    //a.forward_print();
    return 0;
}



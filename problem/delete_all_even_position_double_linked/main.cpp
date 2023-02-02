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

   void delete_even_position(){
       node *cur = head;
       float length2 = length /2.0;
       for(int i = 0; i<(length2-1);++i){
           //cout<<length2;
           if (cur->next == tail){
               cur->next = nullptr;
               tail = cur;
               return;
           }
           node *next = cur->next->next;
           cur->next = next;
           next->prv = cur;
           cur = next;
       }
   }





};

int main()
{
    double_linked_list a ;


    a.insert_normaly(0);
    a.insert_normaly(1);
    a.insert_normaly(2);
    a.insert_normaly(3);
    a.insert_normaly(4);
    a.insert_normaly(5);
    a.insert_normaly(6);


    a.delete_even_position();
    //a.insert_normaly(6);



    a.forward_print();
    return 0;
}


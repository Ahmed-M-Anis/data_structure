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


   void delete_by_vall(int vall){

       node *temp = head;
       for(; temp->data != vall; temp = temp->next){
       }


       if(temp == head){
          head =head->next;
          head ->prv = nullptr;
          delete temp;
          return;
       }
       if (temp == tail){
          tail = tail->prv ;
          tail->next = nullptr;
          delete temp;
          return;
       }
       if (temp->data == vall){
           node *temp2 = temp->prv;
           node *temp3 = temp->next;
           temp2->next = temp3;
           temp3->prv = temp2 ;
           delete temp;
       }
   }

   void delete_by_vall_all_num(int vall){//delete all node that have that number
        int counter = 0 ;
       for(node *temp1 = head ; temp1 ; temp1=temp1->next){
          if (temp1->data == vall)
             ++counter;
       }
       if(counter == 0)
         return;
       for(int i = 0 ; i<counter ; ++i){
            delete_by_vall(vall);
       }

   }


};

int main()
{
    double_linked_list a ;


    a.insert_normaly(1);
    a.insert_normaly(1);
    a.insert_normaly(2);
    a.insert_normaly(3);
    a.insert_normaly(4);

    //a.delete_by_vall(1);
    //a.delete_by_vall(3);
    a.delete_by_vall_all_num(1);

    a.forward_print();
    return 0;
}

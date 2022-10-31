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



   void delete_by_vall(int vall){
       node *temp = head;
       if (vall == head->data){
            head=head->next;
            --length;
            return;
       }
       if (vall == tail->data){
          while (temp ->next != tail){
               temp = temp->next;
          }
          delete tail;

          tail = temp;
          tail->next = nullptr;
          --length;
          return;
       }

        while (temp->next->data != vall ){
              temp = temp->next;
       }
           temp -> next = temp->next->next;
           --length;
       }


    void reverse_the_list(){//that reverse all the linked_list
       tail = head;
       node* prv = head;
       head = head->next;
       while(head){
            node *n = head->next;
            head->next = prv ;

            prv = head;
            head = n;
       }
       head=prv;
       tail->next = nullptr;

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


   void incert_sorted(int vall){

       node *temp = head;
       int y = vall;
       int counter = 5;
       for(int i = 0 ; i<length ; ++i){
          int x = temp->data;
          temp =temp->next;
          if(y < x){
            y = x;
            cout<<counter<<endl;
            break;
          }
       }
       if(vall == y){
         incert(vall);
         return;
       }


       if(counter == 0){
          incert_front(vall);
          return;
       }
       ++length;
       node*item2 = new node(vall);
       node*temp2 = head;
       for (int i = 0 ; i<counter-1 ; ++i){
          temp2 = temp2->next;
       }
       node *temp3 = temp2->next;
       temp2->next = item2;
       item2->next = temp3;
   }

};

int main()
{
    linkedList a ;

    //a.incert(1);
    //a.incert(2);
    //a.incert(3);
    //a.incert(4);
    //a.reverse_the_list();

    //a.delete_by_vall(1);
    //a.incert(3);
    //a.swap_pairs();
    a.incert_sorted(5);
    a.incert_sorted(10);
    a.incert_sorted(15);
    a.incert_sorted(20);
    a.incert_sorted(17);



    a.print();
    return 0;
}

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




    void make_odd_position_in_first(){
        float lenght2 =lenght/2.0;
        node *item = head->next ;
        node *temp = head->next ;
        node *item2 = head ;

        for(int i = 1 ; i< lenght2 ; ++i){

            item2 ->next = item2->next->next;
            item2 = item2 ->next;

            if(int(lenght2) != lenght2 && int(lenght2) == i){

               if (item2 == tail){

                   item2 ->next = temp;
                   item->next = nullptr;
                   tail = item;
                   return;
               }
            }

            item ->next = item->next->next;
            item = item ->next;

            if (item == tail){
                item2->next = temp;
                return;
            }
        }

    }






};

int main()
{
    linked_list a ;
    a.incert(1);
    a.incert(2);
    a.incert(3);
    a.incert(4);
    a.incert(5);
    a.incert(6);
    a.incert(7);
    //a.incert(8);

    a.make_odd_position_in_first();
    //a.incert(1);
    a.print();

    return 0;
}

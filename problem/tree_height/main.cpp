#include <iostream>
#include <vector>

using namespace std;



class binary_tree{
private:
    struct node{
        int data { };
        node *left{ } ;
        node *right { };
        node(int data) :
            data(data){ }

    };
    node *root{ };

    void print1(node *current){
        if(!current)
            return ;
        print1(current -> left);
        cout<<current->data<<' ';
        print1(current -> right);
    }



    void height1(node *current ,int L ,int &H){
        if(!current){
            return ;
        }
        ++L;
        height1(current -> left , L , H);
        if( H < L)
            H = L;
        height1(current -> right , L , H);
        --L;
    }


public:
    binary_tree(int root_vall) :
        root(new node(root_vall)){ }


    void add(int vall , vector<char> direction){
        node *cur = root;
        for (int i = 0 ; i<direction.size() ; ++i){
            if(direction[i] == 'l' || direction[i] =='L'){
                if(!cur->left){
                    node *item = new node(vall);
                    cur->left = item ;
                    item->left = nullptr;
                    item->right = nullptr;
                }
                else
                    cur = cur->left;

            }
            else{
                if(!cur->right){
                    node *item = new node(vall);
                    cur->right = item ;
                    item->left = nullptr;
                    item->right = nullptr;
                }
                else
                    cur = cur->right;

            }
        }

        }



    void print(){
        print1(root);
        cout<<endl;
    }

    int height(){
        int level =-1;
        int h = 0;
        height1(root , level , h);
        return h;
    }





};












int main()
{
    binary_tree a(1);
    a.add(2 ,{'l'});
    a.add(4 ,{'l' ,'l'});
    a.add(7 ,{'l','l','l'});
    a.add(14 ,{'l' ,'r'});
    a.add(9 ,{'l' ,'r' ,'r'});
    a.add(8 ,{'l' ,'l' ,'r'});
    a.add(12 ,{'r'});
    a.add(6 ,{'r' ,'r'});
    a.add(10 ,{'r' ,'r' ,'l'});
    //a.add(10 ,{'l' ,'l' ,'l' ,'l'});


    //a.print();


    //cout<<a.height();



    return 0;
}

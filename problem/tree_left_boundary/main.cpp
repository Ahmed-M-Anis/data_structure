#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class BinaryTree {
private:
	int data { };
	BinaryTree* left { };
	BinaryTree* right { };

public:
	BinaryTree(int data) :
			data(data) {
	}



	void print_inorder() {
		if(left)
			left->print_inorder();
		cout << data << " ";
		if(right)
			right->print_inorder();
	}





    void add(int vall , vector<char> direction){
        BinaryTree *cur = this;
        for (int i = 0 ; i<direction.size() ; ++i){
            if(direction[i] == 'l' || direction[i] =='L'){
                if(!cur->left){
                    BinaryTree *item = new BinaryTree(vall);
                    cur->left = item ;
                    item->left = nullptr;
                    item->right = nullptr;
                }
                else
                    cur = cur->left;

            }
            else{
                if(!cur->right){
                    BinaryTree *item = new BinaryTree(vall);
                    cur->right = item ;
                    item->left = nullptr;
                    item->right = nullptr;
                }
                else
                    cur = cur->right;

            }
        }

        }



        void tree_left_boundary(){ // get the longest chain in the left tree
            cout<<data<<' ';
            if(left)
                left->tree_left_boundary();
            if(right && !left)
                right->tree_left_boundary();
        }


};

int main() {
	BinaryTree tree(2);
	tree.add(10 ,{'r'});
	tree.add(3 ,{'l'});
	tree.add(5 ,{'l' ,'l'});
	tree.add(8 ,{'l' ,'l' ,'r'});
	tree.add(6 ,{'l' ,'l' ,'r' ,'r'});
	tree.add(7 ,{'l' ,'l' ,'r' ,'r' ,'l'});
	tree.add(15 ,{'l' ,'l' ,'r' ,'r' ,'l' ,'r'});

	//tree.print_inorder();
	tree.tree_left_boundary();

	return 0;
}


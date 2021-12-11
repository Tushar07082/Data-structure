#include <iostream>
using namespace std;
struct Node{
        int data;
        Node * left,*right;
        Node(int val){
                data = val;
                left = NULL;
                right = NULL;
        }
};
bool isidentical(Node * root1,Node * root2){
        if(root1== NULL && root2 == NULL){
                return true;
        }
        if(root1 != NULL && root2 != NULL && root1->data == root2->data && isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right)){
                return true;
        }
        return false;
}
int main(){
        Node * root1 = new Node(2);
        root1->left = new Node(1);
        root1->right =  new Node(3);
        Node * root2 = new Node(2);
        root2->left = new Node(1);
        root2->right =  new Node(9);
        if(isidentical(root1,root1)){
                cout<<"Identical!";
        }else{
                cout<<"Different!";
        }

}
#include <iostream>
#include <limits.h>
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
bool isBST(Node * root,int min,int max){
        if(root==NULL){
                return true;
        }
        if(root->data > min && root->data < max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
                return true;
        }
        return false;
}
/*
           4
        /     \
       3       5
     /   \   /   \
    2     6 3     6
*/
int main(){
        Node * root1 = new Node(4);
        root1->left = new Node(3);
        root1->right =  new Node(5);
        root1->left->left = new Node(2);
        root1->left->right = new Node(6);
        root1->right->left = new Node(3);
        root1->right->right = new Node(6);
        if(isBST(root1,INT_MIN,INT_MAX)){
                cout<<"Valid"<<endl;
        }
        else cout<<"Not Valid"<<endl;

}
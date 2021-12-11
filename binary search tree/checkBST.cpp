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
int main(){
        Node * root1 = new Node(2);
        root1->left = new Node(1);
        root1->right =  new Node(3);
        if(isBST(root1,INT_MIN,INT_MAX)){
                cout<<"Valid"<<endl;
        }
        else cout<<"Not Valid"<<endl;

}
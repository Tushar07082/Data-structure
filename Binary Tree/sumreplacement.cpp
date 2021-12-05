#include <bits/stdc++.h>
using namespace std;
class Node {
        public:
        int data;
        Node * left;
        Node * right;
        Node(int x){
                data=x;
                left=NULL;
                right=NULL;
        }
};
void sumreplace(Node * a){
        if(a==NULL){
                return;
        }
        sumreplace(a->left);
        sumreplace(a->right);
        if(a->left != NULL){
                a->data += a->left->data;
        }
        if(a->right != NULL){
                a->data += a->right->data;
        }
}
void preorder(Node * a){
        if(a!=NULL){
                cout<<a->data<<" ";
                preorder(a->left);
                preorder(a->right);
        }
}
int main(){
       Node * a = new Node(1);
       a->left = new Node(2);
       a->right = new Node(3);
       a->left->left= new Node(4);
       a->left->right = new Node(5);
       a->right->left = new Node(6);
       a->right->right = new Node(7);
       sumreplace(a);
       preorder(a);

}
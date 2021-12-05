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
//           1
//         /   \
//         2    3
//        / \  / \
//       4   5 6  7
void flatten(Node * root){
        if(root==NULL || ((root->left == NULL)&&(root->right==NULL))){
                return;
        }
        if(root->left != NULL){
                flatten(root->left);
                Node * temp = root->right;
                root->right = root->left;
                root->left = NULL ;
                Node * t  = root->right;
                while(t->right != NULL ){
                        t = t->right;
                }
                t->right = temp;
        }
        flatten(root->right);
}
void print(Node * a){
        while(a != NULL){
                cout<<a->data<<"->";
                a = a->right;
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
       Node * b = new Node(1);
       b->left = new Node(2);
       b->left->left = new Node(3);
       flatten(b);
       print(b);

}
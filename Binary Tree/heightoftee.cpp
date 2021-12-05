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
int heightoftree(Node * root){
        if(root == NULL){
                return 0;
        }
        return 1  + max(heightoftree(root->left),heightoftree(root->right));
}
int main(){
       Node * a = new Node(1);
       a->left = new Node(2);
       a->right = new Node(3);
       a->left->left= new Node(4);
       a->left->right = new Node(5);
       a->right->left = new Node(6);
       a->right->right = new Node(7);
       cout<<heightoftree(a);

}
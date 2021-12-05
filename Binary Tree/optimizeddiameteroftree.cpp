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
int odoftree(Node * root, int * height){
        if(root==NULL){
                *height =0;
                return 0;
        }
        int lh =0,rh=0;
        int ld = odoftree(root->left,&lh);
        int rd = odoftree(root->right,&rh);
        *height = max(lh,rh) + 1;
        return max(lh + rh + 1,max(ld,rd));
}
int main(){
       Node * a = new Node(1);
       a->left = new Node(2);
       a->right = new Node(3);
       a->left->left= new Node(4);
       a->left->right = new Node(5);
       a->right->left = new Node(6);
       a->right->right = new Node(7);
       int height=0;
       cout<<odoftree(a,&height);

}
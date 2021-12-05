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
bool isbalanced(Node * a,int * height){
        if(a==NULL){
                *height =0;
                return true;
        }
        int lh =0,rh =0;
        if(isbalanced(a->left,&lh) && isbalanced(a->right,&rh) && (abs(lh - rh) <= 1)){
                *height = max(lh,rh) + 1;
                return true;
        }
        *height = max(lh,rh) + 1;
        return false;
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
       int height =0;
       cout<<isbalanced(b,&height);

}
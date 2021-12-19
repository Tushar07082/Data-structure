#include <iostream>
#include <stack>
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
void zigzag(Node * root){
        if(root==NULL){
                return;
        }
        stack <Node*> currlevel;
        stack <Node*> nextlevel;
        bool ltor= true;
        currlevel.push(root);
        while(!currlevel.empty()){
                Node * a = currlevel.top();
                currlevel.pop();
                if(a!=NULL){
                        cout<<a->data<<" ";
                        if(ltor){
                                if(a->left){
                                        nextlevel.push(a->left);
                                }
                                if(a->right){
                                        nextlevel.push(a->right);
                                }
                        }else{
                                if(a->right){
                                        nextlevel.push(a->right);
                                }
                                if(a->left){
                                        nextlevel.push(a->left);
                                }

                        }
                }
                if(currlevel.empty()){
                        ltor = !ltor;
                        swap(currlevel,nextlevel);
                }
        }
}
Node * insertBST(Node * root,int val){
        if(root == NULL){
                return new Node(val);
        }
        if(val< root->data){
                root->left = insertBST(root->left,val);
        }else {
                root->right = insertBST(root->right,val);
        }
        return root;
}
int main(){
        /*
                  5
                 / \
                1   7
                 \
                  3
                 /  \
               2      4
                
        */
       Node * root = new Node(1);
       root->left = new Node(2);
       root->left->left = new Node(4);
       root->right = new Node(3);
       root->right->right = new Node(5);
//        root->left->right->left = new Node(2);
//        root->left->right->right = new Node(4);
        zigzag(root);
        cout<<endl; 
}

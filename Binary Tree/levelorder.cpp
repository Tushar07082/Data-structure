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
void levelorder(Node * a){
        if(a==NULL){
                cout<<"Empty Tree";
                return;
        }
        queue <Node *> q;
        q.push(a);
        q.push(NULL);
        while(!q.empty()){
                Node * node = q.front();
                q.pop();
                if(node != NULL){
                        cout<<node->data<<" ";
                        if(node->left){
                                q.push(node->left);
                        }
                        if(node->right){
                                q.push(node->right);
                        }

                }else if(!q.empty()) {
                        q.push(NULL);
                }
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
       levelorder(a);

}
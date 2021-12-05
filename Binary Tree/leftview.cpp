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
void leftview(Node * a){
        if(a==NULL){
                cout<<"empty tree\n";
                return;
        }
        queue <Node *> q;
        q.push(a);
        while(!q.empty()){
                int n = q.size();
                for(int i=0;i<n;i++){
                        Node * node = q.front();
                        q.pop();
                        if(i==0){
                                cout<<node->data<<"\n";
                        }
                        
                        if(node->left!=NULL){
                                q.push(node->left);
                        }
                        if(node->right!=NULL){
                                q.push(node->right);
                        }

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
       leftview(a);

}
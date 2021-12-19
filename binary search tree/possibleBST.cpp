#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
        int val;
        TreeNode * left,*right;
        TreeNode(int val){
                this->val = val;
                left = NULL;
                right = NULL;
        }
};
vector <TreeNode * > constructBST(int start,int end){
        vector <TreeNode *> trees;
        if(start > end){
                trees.push_back(NULL);
                return trees;
        }
        for(int i=start;i<=end;i++){
                vector<TreeNode*>leftsubtrees = constructBST(start,i-1);
                vector<TreeNode*>rightsubtrees = constructBST(i+1,end);
                for(int j=0;j<leftsubtrees.size();j++){
                        TreeNode * left = leftsubtrees[j];
                        for(int k=0;k<rightsubtrees.size();k++){
                                TreeNode* right = rightsubtrees[k];
                                TreeNode * a = new TreeNode(i);
                                a->left = left;
                                a->right = right;
                                trees.push_back(a);
                        }
                }
        }
        return trees;
}
void printpreorder(TreeNode * root){
        if(root!=NULL){
                cout<<root->val<<" ";
                printpreorder(root->left);
                printpreorder(root->right);
        }
}

int main(){
        vector <TreeNode *> trees = constructBST(1,19);
        for(int i=0;i<trees.size();i++){
                cout<<i+1<<": ";
                printpreorder(trees[i]);
                cout<<endl;
        }

}
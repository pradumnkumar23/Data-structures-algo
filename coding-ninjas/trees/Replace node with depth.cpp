/*Replace node with depth
Send Feedback
In a given Generic Tree, replace each node with its depth value. You need to just update the data of each node, no need to return or print anything.
Input format :

Line 1 : Elements in level order form separated by space (as per done in class). Order is -

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 : (Level wise, each level in new line)
0 
1 1 1 
2 2*/

void update(TreeNode<int>* root,int depth){
    if(root==NULL) return ;
    root->data=depth;
    for (int i=0;i<root->numChildren();i++){
        update(root->getChild(i),depth+1);
    }
}
void replaceWithDepthValue(TreeNode<int> *root){   
    update(root,0);
}

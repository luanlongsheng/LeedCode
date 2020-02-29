/*************************************************************************
	> File Name: Leetcode226.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月29日 星期六 18时45分41秒
 ************************************************************************/

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

/*************************************************************************
	> File Name: Leetcode104.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月29日 星期六 16时15分09秒
 ************************************************************************/

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int l = maxDepth(root->left), r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

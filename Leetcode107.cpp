/*************************************************************************
	> File Name: Leetcode107.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月29日 星期六 16时30分23秒
 ************************************************************************/

int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

void getcnt(struct TreeNode *root, int k, int *cnt) {
    if (root == NULL) return ;
    cnt[k] += 1;
    getcnt(root->left, k - 1, cnt);
    getcnt(root->right, k - 1, cnt);
    return ;
}

void getresult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if (root == NULL) return ;
    ret[k][cnt[k]++] = root->val;
    getresult(root->left, k - 1, cnt, ret);
    getresult(root->right, k - 1, cnt, ret);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int n = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * n);
    int *cnt = (int *)calloc(n, sizeof(int));
    getcnt(root, n - 1, cnt);
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;//节约空间
    }
    getresult(root, n - 1, cnt, ret);
    *returnSize = n;
    *returnColumnSizes = cnt;
    return ret;
}

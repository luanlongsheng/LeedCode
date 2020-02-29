/*************************************************************************
	> File Name: Leetcode257.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月29日 星期六 20时27分06秒
 ************************************************************************/

int getpathcnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getpathcnt(root->left) + getpathcnt(root->right);
}

int getresult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    } 
    len += sprintf(buff + len, "->");
    int cnt = getresult(root->left, len, k, ret, buff);
    cnt += getresult(root->right, len, k + cnt, ret, buff);
    return cnt;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathcnt = getpathcnt(root);
    char **ret = (char **)malloc(sizeof(char *) * pathcnt);
    int max_len = 1024;
    char *buff = (char *)malloc(sizeof(char) * max_len);
    getresult(root, 0, 0, ret, buff);
    *returnSize = pathcnt;
    return ret;
}

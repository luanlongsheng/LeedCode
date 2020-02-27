/*************************************************************************
	> File Name: Leetcode20.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月27日 星期四 19时22分15秒
 ************************************************************************/

bool isValid(char * s){
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1, flag = 1;
    while (s[0]) {
        switch (s[0]) {
            case '(' :
            case '[' :
            case '{' : stack[++top] = s[0]; break;
            case ')' : flag = (top != -1 && stack[top--] == '('); break;
            case ']' : flag = (top != -1 && stack[top--] == '['); break;
            case '}' : flag = (top != -1 && stack[top--] == '{'); break;
        }
        if (!flag) break;
        s++;
    }
    free(stack);
    return (flag && top == -1);
}

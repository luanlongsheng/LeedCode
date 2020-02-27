/*************************************************************************
	> File Name: Leetcode206.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月27日 星期四 15时25分24秒
 ************************************************************************/

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode ret, *p, *q;
    if (head == NULL) return head;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

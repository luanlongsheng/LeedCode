/*************************************************************************
	> File Name: Leetcode24.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月25日 星期二 21时41分40秒
 ************************************************************************/

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = &ret;
    q = head;
    while (p->next && p) {
        p->next = q->next;
        q->next = q->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }
    return ret.next;
}

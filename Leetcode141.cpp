/*************************************************************************
	> File Name: Leetcode141.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月25日 星期二 21时43分58秒
 ************************************************************************/

bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if (p == NULL) return false;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return false;
        q = q->next;
    } while ( p != q);
    return true;
}

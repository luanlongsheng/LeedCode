/*************************************************************************
	> File Name: Leetcode160.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月25日 星期二 21时44分39秒
 ************************************************************************/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int cntA = 0, cntB = 0;
    struct ListNode *p = headA, *q = headB;
    while (p) cntA++, p = p->next;
    while (q) cntB++, q = q->next;
    int m = cntA - cntB;
    p = headA, q = headB;
    if (m > 0) {
        while (m--) p = p->next;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
    } else {
        while (m++) q = q->next;
        while (q != p) {
            p = p->next;
            q = q->next;
        }
    }
    return p;
}

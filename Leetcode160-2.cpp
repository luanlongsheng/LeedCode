/*************************************************************************
	> File Name: Leetcode160-2.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年05月21日 星期四 19时33分14秒
 ************************************************************************/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while (p != q) {//判断p和q的地址是否一致,当两者地址一致说明到达了交汇处，若同为NULL，则无交汇点
        p = p ? p->next : headB;//p向下走，走完了本链表再q链表开始走
        q = q ? q->next : headA;//q向下走，走完了本链表再从p链表开始走
    }
    return p;
}

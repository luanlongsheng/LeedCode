/*************************************************************************
	> File Name: 19.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月25日 星期二 21时40分31秒
 ************************************************************************/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = q = &(ret);
    n++;//为了下一步循环时p指向的是倒数第n－１个节点
    while (n--) q = q->next;
    //q = q->next;//为了下一步循环时p指向的是倒数第n－１个节点
    while (q) {//当q到达NULL时，此时p应指向倒数第n+1个节点处
        p = p->next;
        q = q->next;
    }
    q = p->next;//让q指向倒数第n个节点位置
    p->next = q->next;//删除节点操作
    free(q);
    return ret.next;
}

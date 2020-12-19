//leetcode 206
struct ListNode* reverseList(struct ListNode* head) {
	//新链表的头指针
	struct ListNode* newhead = NULL;
	//需要头插的结点
	struct ListNode* cur = head;

	while (cur)
	{
		//保存需要头插结点的下一个节点
		struct ListNode* next = cur->next;
		//将cur头插到新链表
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* pre = NULL;
	//需要反转指向的结点
	struct ListNode* cur = head;

	while (cur)
	{
		//保存需要头插结点的下一个节点
		struct ListNode* next = cur->next;
		//将cur头插到新链表
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
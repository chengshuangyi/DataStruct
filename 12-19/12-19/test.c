//leetcode 206
struct ListNode* reverseList(struct ListNode* head) {
	//�������ͷָ��
	struct ListNode* newhead = NULL;
	//��Ҫͷ��Ľ��
	struct ListNode* cur = head;

	while (cur)
	{
		//������Ҫͷ�������һ���ڵ�
		struct ListNode* next = cur->next;
		//��curͷ�嵽������
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* pre = NULL;
	//��Ҫ��תָ��Ľ��
	struct ListNode* cur = head;

	while (cur)
	{
		//������Ҫͷ�������һ���ڵ�
		struct ListNode* next = cur->next;
		//��curͷ�嵽������
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
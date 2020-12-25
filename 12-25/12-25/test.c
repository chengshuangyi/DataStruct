struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			struct ListNode *pre = head;
			while (slow != pre)
			{
				slow = slow->next;
				pre = pre->next;
			}
			return slow;
		}
	}
	return NULL;
}
bool hasCycle(struct ListNode *head) {
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}
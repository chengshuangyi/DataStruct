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

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		ListNode* slow = A;
		ListNode* fast = A;
		ListNode* pre = NULL;
		while (fast && fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		pre->next = NULL;
		slow = reverseList(slow);

		while (A)
		{
			if (A->val != slow->val)
				return false;
			A = A->next;
			slow = slow->next;
		}
		return true;
	}
};
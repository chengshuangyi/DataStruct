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
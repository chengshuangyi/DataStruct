//class Solution {
//public:
//	ListNode* deleteDuplication(ListNode* pHead)
//	{
//		if (pHead == NULL || pHead->next == NULL)
//		{
//			return pHead;
//		}
//		ListNode *pre = NULL;
//		ListNode *cur = pHead;
//		ListNode *newhead = (ListNode *)malloc(sizeof(ListNode));
//		pre = newhead;
//		newhead->next = pHead;
//		while (cur)
//		{
//			if (cur->next && cur->val == cur->next->val)
//			{
//				cur = cur->next;
//				while (cur->next && cur->val == cur->next->val)
//				{
//					cur = cur->next;
//				}
//				cur = cur->next;
//				pre->next = cur;
//			}
//
//			else
//			{
//				//pre->next = cur;
//				pre = cur;
//				cur = cur->next;
//			}
//
//		}
//		return newhead->next;
//
//	}
//};
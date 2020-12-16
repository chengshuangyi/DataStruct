#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a = (int *)malloc(sizeof(int));
	*a = 11;
	free(a);
	a = NULL;
	return 0;
}

//leetcode 203
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* newlist = (struct ListNode*)malloc(sizeof(struct ListNode));
	newlist->next = head;
	struct ListNode* pre = newlist;
	struct ListNode* cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			pre->next = cur->next;
		}
		else
		{
			pre = cur;
		}
		cur = cur->next;
	}
	return (newlist->next);
}

//leetcode 206
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;

	while (cur)
	{
		struct ListNode* next = cur->next;
		//next =cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}

//leetcode 147
struct ListNode* insertionSortList(struct ListNode* head) {
	if ((head == NULL) || (head->next == NULL))
		return head;
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->next = head;
	struct ListNode* sortlast = head;
	struct ListNode* cur = head->next;

	while (cur)
	{
		if (cur->val >= sortlast->val)
		{
			sortlast->next = cur;
			sortlast = cur;
		}
		else
		{
			struct ListNode* pre = newnode;
			while (pre->next->val < cur->val)
			{
				pre = pre->next;
			}
			sortlast->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
		}
		cur = sortlast->next;

	}
	return newnode->next;

}
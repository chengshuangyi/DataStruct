#include<stdio.h>
//ɾ�������е��ڸ���ֵ val �����нڵ㡣

struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return head;
	head->next = removeElements(head ->next, val);
	return head->data == val ? head->next : head;
}

typedef struct ListNode 
{
	int  data;
	ListNode *next;
}ListNode;

int main()
{
	int val = 9;
	struct ListNode* removeElements()
	return 0;
}
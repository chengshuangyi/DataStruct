#include<stdio.h>
//删除链表中等于给定值 val 的所有节点。

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
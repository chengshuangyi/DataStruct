/*

*/
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));//开辟空间
	pHead->next = head;//链接起来
	struct ListNode* prev = pHead;//前驱指针，开始指向头
	struct ListNode* p = head;//p指针，往前走
	while (p != NULL)
	{
		if (p->val == val)//想等了，就开始释放
		{
			prev->next = p->next;
			free(p);
			p = prev->next;
			continue;//这里是因为，避免prev还在pHead处的情况，就会造成错误
		}
		prev = p;//不相等，会走到这里，前驱改变
		p = p->next;//p指向下一个
	}
	head = pHead->next;//返回 pHead的下一个
	free(pHead);//释放该指针
	pHead = NULL;
	return head;
}

/*  leetcode 876
给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
*/
struct ListNode* middleNode(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	struct ListNode* temp = fast->next;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		// temp=fast->next;
		continue;
	}
	return slow;
}

/*  leetcode 206
反转一个单链表。
示例:
输入: 1->2->3->4->5->NULL
输出 : 5->4->3->2->1->NULL*/

struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL)
		return head;
	struct ListNode* pre = NULL;
	struct ListNode* cur = head;
	while (cur != NULL)
	{
		struct ListNode* nexttemp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nexttemp;
	}
	return pre;
}
/*

*/
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	struct ListNode* pHead = (struct ListNode*)malloc(sizeof(struct ListNode));//���ٿռ�
	pHead->next = head;//��������
	struct ListNode* prev = pHead;//ǰ��ָ�룬��ʼָ��ͷ
	struct ListNode* p = head;//pָ�룬��ǰ��
	while (p != NULL)
	{
		if (p->val == val)//����ˣ��Ϳ�ʼ�ͷ�
		{
			prev->next = p->next;
			free(p);
			p = prev->next;
			continue;//��������Ϊ������prev����pHead����������ͻ���ɴ���
		}
		prev = p;//����ȣ����ߵ����ǰ���ı�
		p = p->next;//pָ����һ��
	}
	head = pHead->next;//���� pHead����һ��
	free(pHead);//�ͷŸ�ָ��
	pHead = NULL;
	return head;
}

/*  leetcode 876
����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣
����������м��㣬�򷵻صڶ����м��㡣
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
��תһ��������
ʾ��:
����: 1->2->3->4->5->NULL
��� : 5->4->3->2->1->NULL*/

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
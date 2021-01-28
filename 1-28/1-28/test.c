typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
		return NULL;
	Node *cur = head;
	//在原链表后拷贝一份
	while (cur)
	{
		Node *copyNode = (Node *)malloc(sizeof(Node));
		copyNode->val = cur->val;
		copyNode->next = NULL;
		copyNode->random = NULL;


		Node *next = cur->next;
		copyNode->next = next;
		cur->next = copyNode;
		cur = next;
	}
	cur = head;
	//拷贝random
	while (cur)
	{
		Node *copyNode = cur->next;
		if (cur->random)
			copyNode->random = cur->random->next;
		else
			copyNode->random = NULL;
		cur = cur->next->next;
	}
	cur = head;
	Node *newnode = head->next;
	//分开链接
	while (cur)
	{
		Node *copyNode = cur->next;
		Node *next = copyNode->next;
		cur->next = next;
		if (next)
			copyNode->next = next->next;
		else
			copyNode->next = NULL;
		cur = next;
	}
	return newnode;
}
#include"BinaryTree.h"
#include"Queue.h"

//�����¶������ڵ�
BTNode *CreatNode(BTDataType a)
{
	BTNode *node = (BTNode *)malloc(sizeof(BTNode));
	node->_data = a;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

// ����������
void BTDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BTDestory(root->_left);
	BTDestory(root->_right);
	free(root);
}

 //ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BTCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}

	BTNode *root = (BTNode *)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	++(*pi);
	root->_left = BTCreate(a, pi);
	root->_right = BTCreate(a, pi);

	return root;
}

// �������ڵ����
int BTSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BTSize(root->_left) + BTSize(root->_right);
}

// ������Ҷ�ӽڵ����
int BTLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return  BTLeafSize(root->_left) + BTLeafSize(root->_right);
}

// ��������k��ڵ����
int BTLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return  BTLevelKSize(root->_left,k-1) + BTLevelKSize(root->_right,k-1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BTFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode *node = BTFind(root->_left, x);
	if (node)
		return node;
	node = BTFind(root->_right, x);
	if (node)
		return node;
	return NULL;
}

// ������ǰ����� 
void BTPrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BTPrevOrder(root->_left);
	BTPrevOrder(root->_right);
}
// �������������
void BTInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BTInOrder(root->_left);
	printf("%c ", root->_data);
	BTInOrder(root->_right);
}

// �������������
void BTPostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BTPostOrder(root->_left);
	BTPostOrder(root->_right);
	printf("%c ", root->_data);
}

// �������
void BTLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return;
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->_data);
		if(front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
}

// �ж϶������Ƿ�����ȫ������
int BTComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return 1;
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;
		if (root->_left)
			QueuePush(&q, front->_left);
		if (root->_right)
			QueuePush(&q, front->_right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		if (front)
			return 0;
		QueuePop(&q);
	}
	return 1;
}
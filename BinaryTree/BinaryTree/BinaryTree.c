#include"BinaryTree.h"
#include"Queue.h"

//创建新二叉树节点
BTNode *CreatNode(BTDataType a)
{
	BTNode *node = (BTNode *)malloc(sizeof(BTNode));
	node->_data = a;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

// 二叉树销毁
void BTDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BTDestory(root->_left);
	BTDestory(root->_right);
	free(root);
}

 //通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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

// 二叉树节点个数
int BTSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BTSize(root->_left) + BTSize(root->_right);
}

// 二叉树叶子节点个数
int BTLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	
	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return  BTLeafSize(root->_left) + BTLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BTLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return  BTLevelKSize(root->_left,k-1) + BTLevelKSize(root->_right,k-1);
}

// 二叉树查找值为x的节点
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

// 二叉树前序遍历 
void BTPrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BTPrevOrder(root->_left);
	BTPrevOrder(root->_right);
}
// 二叉树中序遍历
void BTInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BTInOrder(root->_left);
	printf("%c ", root->_data);
	BTInOrder(root->_right);
}

// 二叉树后序遍历
void BTPostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BTPostOrder(root->_left);
	BTPostOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
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

// 判断二叉树是否是完全二叉树
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
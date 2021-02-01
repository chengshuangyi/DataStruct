#include"BinaryTree.h"
#include"Queue.h"

void test()
{
	BTNode *A = CreatNode('A');
	BTNode *B = CreatNode('B');
	BTNode *C = CreatNode('C');
	BTNode *D = CreatNode('D');
	BTNode *E = CreatNode('E');
	BTNode *F = CreatNode('F');
	//BTNode *G = CreatNode('G');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	C->_left = F;
	//D->_left = G;

	/*BTPrevOrder(A);
	int size1 = BTSize(A);
	printf("BTSize = %d \n", size1);
	int size2 = BTLeafSize(A);
	printf("BTLeafSize = %d\n", size2);
*/
	/*int size3 = BTLevelKSize(A,2);
	printf("BTLevelKSize = %d\n", size3);*/

	//BTDataType *arr = {"ABD##E#H##CF##G##"};
	//int i = 0;
	//BTNode* root = BTCreate(arr, &i);
	/*int size3 = BTLevelKSize(root, 4);
	printf("BTLevelKSize = %d\n", size3);
	BTInOrder(root);*/
	//BTLevelOrder(A);
	int ret = BTComplete(A);
	printf("%d\n", ret);
	BTDestory(A);
}
int main()
{
	test();
	return 0;
}
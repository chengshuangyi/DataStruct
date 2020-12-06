#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
int main()
{
	SeqList list;
	SeqListInit(&list);
	ElemType item = 0;
	int select = 1;
	do
	{
		printf("**********************************\n");
		printf("*   [1]PushBack     [2]PopBack   *\n");
		printf("*   [3]PushFront    [4]PopFront  *\n");
		printf("*   [5]Show_List    [6]Find      *\n");
		printf("*   [7]Insert_Pos   [8]Erase_Pos *\n");
		printf("*             [0]Quit            *\n");
		printf("**********************************\n");
		printf("请输入-> ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入要尾部插入的数据，以<-1>结束\n");
			while (scanf("%d", &item),item != -1)
			{
				SeqListPushBack(&list, item);
			}
			printf("尾部插入成功....\n");
			break;
		case 2:
			SeqListPopBack(&list);
			printf("尾部删除成功....\n");
			break;
		case 3:
			printf("请输入要头部插入的数据，以<-1>结束\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&list, item);
			}
			printf("头部插入成功....\n");
			break;
		case 4:
			SeqListPopFront(&list);
			printf("头部删除成功....\n");
			break;
		case 5:
			SeqListPrint(&list);
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 0:
			printf("退出程序.....\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (select);
	return 0;
}

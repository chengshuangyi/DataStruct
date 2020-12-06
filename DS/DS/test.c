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
		printf("������-> ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������Ҫβ����������ݣ���<-1>����\n");
			while (scanf("%d", &item),item != -1)
			{
				SeqListPushBack(&list, item);
			}
			printf("β������ɹ�....\n");
			break;
		case 2:
			SeqListPopBack(&list);
			printf("β��ɾ���ɹ�....\n");
			break;
		case 3:
			printf("������Ҫͷ����������ݣ���<-1>����\n");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&list, item);
			}
			printf("ͷ������ɹ�....\n");
			break;
		case 4:
			SeqListPopFront(&list);
			printf("ͷ��ɾ���ɹ�....\n");
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
			printf("�˳�����.....\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (select);
	return 0;
}

#include"Stack.h"
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (Stack *)malloc(sizeof(Stack));
	ps->_top = 0;
	ps->_capacity = 4;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top >= ps->_capacity)
	{
		ps->_capacity *= 2;
		Stack *temp = (Stack *)realloc(ps->_a, sizeof(Stack)*(ps->_capacity));
		if (temp == NULL)
		{
			printf("�����ڴ�ʧ��\n");
			exit(-1);
		}
		ps->_a = temp;
	}
	ps->_a[ps->_top] = data;
	++(ps->_top);
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	--(ps->_top);
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
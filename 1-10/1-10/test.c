#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType *)malloc(sizeof(STDataType) * 4);
	ps->_top = 0;
	ps->_capacity = 4;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		ps->_capacity *= 2;
		STDataType *temp = (STDataType *)realloc(ps->_a, sizeof(STDataType) * ps->_capacity);
		if (temp == NULL)
		{
			printf("�����ڴ�ʧ��\n");
			exit(-1);
		}
		else
		{
			ps->_a = temp;
		}
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

char paris(char ch)
{
	if (ch == ')')
		return '(';
	else if (ch == ']')
		return '[';
	else if (ch == '}')
		return '{';
	return 0;
}

int isValid(char * s) 
{
	int len = strlen(s);
	if (len % 2 == 1)
		return 0;
	Stack st;
	StackInit(&st);
	
	while ((*s) != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		else
		{
			if (StackSize(&st) != 0)
			{
				if (paris(*s) != StackTop(&st))
				{
					return 0;
				}
				else
				{
					StackPop(&st);
				}
			}
			else
			{
				return 0;
			}
		}
		s++;
	}
	if(StackEmpty(&st))
		return 1;
	return 0;
}

int main()
{
	//(){}{},
	char *s = "(){}}[";
	int ret = isValid(s);
	printf("%d ", ret);
	return 0;
} 

	

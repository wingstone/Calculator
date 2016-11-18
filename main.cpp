#include "Linear_Stack.h"
#include <string.h>

Linear_Stack S1;	//中缀转后缀表达式使用
Linear_Stack S2;	//计算后缀表达式使用
char num[100];		//存储后缀表达式

//判断符号等级
int judge(char m)
{
	switch(m)
		{
		case'+':
		case'-':return 1;
		case'*':
		case'/':return 2;
		case'(':
		case')':return 3;
		}
}	

//中缀表达式转为后缀表达式
int Convert(char* mid)
{
	int Len = strlen(mid);
	int i = 0, k = 0;
	for(; i <= Len; i++)
	{
		if(mid[i] == '\0' )
		{
			while(!S1.Stack_Empty())
			{
				num[k++] =  S1.Get_Top();
				S1.Pop();
			}
		}
		else if(mid[i] <= '9' && mid[i] >= '0')	//处理数字
			num[k++] = mid[i];
		else	//处理符号
		{
			num[k++] = ' ';
			
			if(S1.Stack_Empty() || judge(mid[i]) > judge(S1.Get_Top()) && mid[i] != ')')
			{
				S1.Push(mid[i]);
			}
			else if(mid[i] == ')')
			{
				while(S1.Get_Top() != '(')
				{
					num[k++] = S1.Get_Top();
					S1.Pop();
				}
				S1.Pop();
			}
			else
			{
				while(!S1.Stack_Empty() && judge(mid[i]) <= judge(S1.Get_Top()) && S1.Get_Top() != '(')
				{
					num[k++] = S1.Get_Top();
					S1.Pop();	

				}
			//	if(S1.Get_Top() == '(')
					S1.Push(mid[i]);
				
			}
		}
	}
	return k;
}



//计算后缀表达式
int  Calcu(int k)
{
	int NUM = 0;
	for(int i = 0; i < k; i++)
	{
		if(num[i] >= '0' && num[i] <= '9')	//处理数字
		{
			NUM = NUM * 10 + (num[i] - 48);
			if(num[i+1] < '0' || num[i+1] > '9')
			{
				S2.Push(NUM);
				NUM = 0;
			}
		}
		else	//处理符号
		{
			switch(num[i])
			{
				case ' ':break;
				case '+':
						{
							NUM = S2.Get_Top();
							S2.Pop();
							NUM = NUM + S2.Get_Top();
							S2.Pop();
							S2.Push(NUM);
							break;
						}
				case '-':
						{
							NUM = S2.Get_Top();
							S2.Pop();
							NUM =  S2.Get_Top() - NUM;
							S2.Pop();
							S2.Push(NUM);
							break;
						}
				case '*':
						{
							NUM = S2.Get_Top();
							S2.Pop();
							NUM = NUM * S2.Get_Top();
							S2.Pop();
							S2.Push(NUM);
							break;
						}
				case '/':
						{
							NUM = S2.Get_Top();
							S2.Pop();
							NUM = S2.Get_Top() / NUM;
							S2.Pop();
							S2.Push(NUM);
							break;
						}
			}
			NUM = 0;
		}
	}
	return S2.Get_Top();
}
int main()
{
	int n = 0, resault = 0;
	S1.Init_Stack();
	S2.Init_Stack();
	char a[] = "2-2-3*(6+9)+1";	//待计算表达式
	n = Convert(a);
	for(int i=0; i<=n;i++)
		cout<< num[i] << endl;	//输出后缀表达式，用于检查
	resault = Calcu(n);
	cout << "resault is " << resault << endl;
	return 0;
}

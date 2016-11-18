#include "Linear_Stack.h"

void Linear_Stack::Init_Stack()
{
	this->Top = -1;
}

void Linear_Stack::Destroy_Stack()
{
	this->Top = -1;
}

void Linear_Stack::Clear_Stack()
{
	this->Top = -1;

}

bool Linear_Stack::Stack_Empty()
{
	if(this->Top == -1)
		return true;
	else
		return false;
}

Type Linear_Stack::Get_Top()
{
	if(this->Top != -1)
		return this->Stack[this->Top];
	else
	{
		cout << "get top error" << endl;
		return error;
	}
}

void Linear_Stack::Push(Type a)
{
	if(this->Top == Max_Size - 1)
		cout << "error! can't push element" << endl;
	else
		this->Stack[++this->Top] = a;
}

void Linear_Stack::Pop()
{
	if(this->Top == -1)
		cout << " error! can't pop element" << endl;
	else
		this->Top--;
}

int Linear_Stack::Stack_Length()
{
	return this->Top + 1;
}

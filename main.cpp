#include "Linear_Stack.h"

int main()
{
	Linear_Stack S1;
	S1.Init_Stack();
	S1.Push(23);
	cout << S1.Get_Top() << endl;
	return 0;
}

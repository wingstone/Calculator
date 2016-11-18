#include <iostream>
using namespace std;

#define Max_Size 1000
typedef char Type;
#define error -1

class Linear_Stack
{
public:
	void Init_Stack();
	void Destroy_Stack();
	void Clear_Stack();
	bool Stack_Empty();
	Type Get_Top();
	void Push(Type a);
	void Pop();
	int Stack_Length();

private:
	int Top;
	Type Stack[Max_Size];
};

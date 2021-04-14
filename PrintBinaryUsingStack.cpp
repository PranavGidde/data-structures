#include<iostream>
#define MAX 20
using namespace std;
class stack
{
	int data[MAX];
	int top;
	public:
		stack()
		{
			top = -1;
		}
		int empty();
		void push(int x);
		int pop();
		int full();
};
int stack::full()
{
	if(top==MAX-1)
	{
		return 1;
	}
	return 0;
}
int stack::empty()
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}
int stack::pop()
{
	if(empty())
	{
		cout<<"Stack is Empty\n";
		return -1;
	}
	else
	{
		int x;
		x = data[top];
		top--;
		return x;
	}
}
void stack::push(int x)
{
	if(full())
	{
		cout<<"\n Cant push...stack is full\n";
	}
	else
	{
		top++;
		data[top]=x;
	}
}
int main()
{
	int n,x;
	cout<<"Enter Number\n";
	cin>>n;
	stack s;
	while(n>0)
	{
		s.push(n%2);
		n = n/2;
	}
	while(s.empty()==0)
	{
		x = s.pop();
		cout<<x<<" ";
	}
	
}

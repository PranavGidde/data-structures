#include<iostream>
#define MAX 20
using namespace std;
class stack
{
	public:
		int data[MAX];
		int top;
		stack()
		{
			top = -1;
		}
		int empty()
		{
			if(top==-1)
			{
				return 1;
			}
			return 0;
		}
		int full()
		{
			if(top==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void push(int ch)
		{
			if(full())
			{
				cout<<"\nStack is full cant push\n";
				return;
			}
			top++;
			data[top]=ch;
		}
		int pop()
		{
			if(empty())
			{
				cout<<"nStack is Empty cant pop\n";
				return -1;
			}
			else
			{
				int ch;
				ch = data[top];
				top--;
				return ch;
			}	
			
		}
};
int priority(char ch)
{
	if(ch == '+' || ch == '-')
	{
		return 1;
	}
	else if(ch == '*' || ch == '/')
	{
		return 2;
	}
}
int main()
{
	stack s;
	char infix[20];
	cout<<"Enter Expression\n";
	cin.getline(infix,19);
	
	char postfix[20];
	int i=0,j=0;
	char exp,st;
	while(infix[i] != '\0')
	{
		if(infix[i] =='+' || infix[i] =='-' || infix[i] =='/' || infix[i] =='*')
		{
			exp = infix[i];
			if(s.empty())
			{
				s.push(exp);
			}
			else
			{
				while(!s.empty())
				{
					st = s.pop();
					if(priority(st) >= priority(exp))
					{
						postfix[j] = st;
						j++;
					}
					else
					{
						s.push(st);
						break;
					}
				}
				s.push(exp);	
			}	
		}
		else
		{
			postfix[j] = infix[i];
			j++;
		}
		i++;
	}
	while(!s.empty())
	{
		postfix[j] = s.pop();
		j++;
	}	
	cout<<"\nPostfix expression after convertion : "<<postfix;
}

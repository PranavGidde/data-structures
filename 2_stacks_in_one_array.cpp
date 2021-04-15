#include<iostream>
#define MAX 10
using namespace std;
class stack
{
	int data[MAX];
	int top1,top2;
	public:
		stack()
		{
			top1 = -1;
			top2 = MAX;
		}
		int empty(int stno)
		{
			if(top1==-1 && stno==1)
			{
				return 1;
			}
			else if(top2==MAX && stno==2)
			{
				return 1;
			}
			return 0;
		}
		int full()
		{
			if(top2==top1+1)
			{
				return 1;
			}
			return 0;
		}
		void push(int stno,int x)
		{
			if(!full())
			{
				if(stno == 1)
				{
					top1++;
					data[top1]=x;
				}
				else if(stno == 2)
				{
					top2--;
					data[top2]=x;
				}
				else
				{
					cout<<"\nInvalid Stack Number\n";
				}
			}
			else
			{
				cout<<"\nStack is Full\n";
			}
		}
		int pop(int stno)
		{
			int x = -1;
			if(!empty(stno))
			{
				if(stno==1)
				{
					x=data[top1];
					top1--;
				}
				else if(stno==2)
				{
					x=data[top2];
					top2++;
				}
				return x;
			}
			else
			{
				cout<<"\nStack is Empty\n";
				return x;
			}
		}
};
int main()
{
	stack s;
	int stno,d,x,y;
	while(1)
	{
		cout<<"\n1.Push data\n"<<"2.Pop data\n"<<"3.Stop\n";
		cin>>x;
		switch(x)
		{
			case 1: cout<<"\nEnter Data and stack no. to push\n";
					cin>>d>>stno;
					s.push(stno,d);
					break;
			
			case 2: cout<<"\nEnter stack no. to pop\n";
					cin>>stno;
					y=s.pop(stno);
					cout<<"\nPoping = "<<y;
					break;
						
			case 3: exit(0);
			
			default: cout<<"\nEnter Valid Option\n";
				
		}
	}
}


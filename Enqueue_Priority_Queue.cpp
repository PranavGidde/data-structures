#include<iostream>
using namespace std;
#define MAX 10
class EPQueue
{
	int data[MAX];
	int front,rear;
	public:
	EPQueue()
	{
		front = rear = -1;
	}
	int empty()
	{
		if(front == -1)
		{
			return 1;
		}
		return 0;
	}
	int full()
	{
		if(rear == MAX-1)
		{
			return 1;
		}
		return 0;
	}
	void enqueueP(int x)  		//by Priority
	{
		if(!full())
		{
			if(empty())
			{
				front = rear = 0;
				data[rear] = x;
			}
			else
			{
				int i;
				for(i=rear;i>=front && data[i]<x;i--)
				{
					data[i+1] = data[i];
				}
				data[i+1] = x;
				rear++;
			}
		}
		else
		{
			cout<<"Queue is Full\n";
		}
	}
	int dequeue()		//Normal
	{
		if(!empty())
		{
			int x = data[front];
			if(front==rear)
			{
				front = rear = -1;
			}
			else
			{
				front++;
			}
			return x;
		}
		else
		{
			cout<<"Queue Empty\n";
			return -1;
		}	
	}
	void show()
	{
		if(!empty())
		{   cout<<"\n";
			int i;
			for(i = front;i<=rear;i++)
			{
				cout<<data[i]<<" ";
			}
		}
		else
		{
			cout<<"Queue Empty\n";
		}
	}
};
int main()
{
	EPQueue Q;
	Q.enqueueP(14);
	Q.enqueueP(56);
	Q.enqueueP(220);
	Q.enqueueP(50);
	Q.show();
	int x;
	x = Q.dequeue();
	cout<<"\nDequeue = "<<x;
	x = Q.dequeue();
	cout<<"\nDequeue = "<<x;
	Q.show();
}

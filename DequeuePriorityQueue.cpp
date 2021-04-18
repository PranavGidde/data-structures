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
	void enqueue(int x)  		//Normal
	{
		if(!full())
		{
			if(empty())
			{
				front++;
			}
			rear++;
			data[rear]=x;
		}
		else
		{
			cout<<"Queue is Full\n";
		}
	}
	int dequeueP()		//by Priority
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
				int i,ind;
				ind = largest();
				x = data[ind];
				for(i=ind;i<rear;i++)
				{
					data[i]=data[i+1];
				}
				rear--;
			}
			return x;
		}
		else
		{
			cout<<"Queue Empty\n";
			return -1;
		}	
	}
	int largest()
	{
		int i,ind,max;
		max = data[0];
		ind = front;
		for(i=front;i<=rear;i++)
		{
			if(data[i]>max)
			{
				max = data[i];
				ind = i;
			}
		}
		return ind;
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
	Q.enqueue(14);
	Q.enqueue(56);
	Q.enqueue(220);
	Q.enqueue(50);
	Q.show();
	int x;
	x = Q.dequeueP();
	cout<<"\nDequeue = "<<x;
	x = Q.dequeueP();
	cout<<"\nDequeue = "<<x;
	Q.show();
}

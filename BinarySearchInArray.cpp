#include<iostream>
using namespace std;
int main()
{
	int num[10];
	int x,i,up,low,mid,flag=0;
	for(i=0;i<10;i++)
	{
		num[i] = i * 2;
	}
	cout<<"Number List\n";
	for(i=0;i<10;i++)
	{
		cout<<num[i]<<" ";
	}	
	cout<<"\nEnter No. for search\n";
	cin>>x;
	low = 0;
	up = 9;
	for(mid=(up+low)/2;low<=up;mid=(up+low)/2)
	{
		if(x == num[mid])
		{
			cout<<"\nFOUND\n";
			flag=1;
			break;
		}
		else
		{
			if(x < num[mid])
			{
				up = mid-1;
			}
			else if(x > num[mid])
			{
				low = mid+1;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\nNOT FOUND\n";
	}
}

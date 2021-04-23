#include<iostream>
using namespace std;
int main()
{
	int x,i,j,temp;
	cout<<"How Many Integers\n";
	cin>>x;
	int * p = new int(x);
	cout<<"Enter integers\n";
	for(i=0;i<x;i++)
	{
		cin>>*(p+i);
	}
	cout<<"\nBefore Sorting - ";
	for(i=0;i<x;i++)
	{
		cout<<*(p+i)<<" ";
	}
	for(i=0;i<x;i++)
	{
		for(j=i+1;j<x;j++)
		{
			if(*(p+i) > *(p+j))
			{
				temp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
	cout<<"\nAfter Sorting - ";
	for(i=0;i<x;i++)
	{
		cout<<*(p+i)<<" ";
	}
}

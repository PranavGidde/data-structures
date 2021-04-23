#include<iostream>
using namespace std;
int main()
{
	int x,i,j,temp;
	cout<<"How Many Integers\n";
	cin>>x;
	int * p = new int(x);
	for(i=0;i<x;i++)
	{
		cout<<"Enter Integers\n";
		cin>>*(p+i);	
	}
	cout<<"Before Sorting - \n";
	for(i=0;i<x;i++)
	{
		cout<<*(p+i)<<" ";	
	}
	for(i=1;i<x;i++)
	{
		for(j=0;j<x-1;j++)
		{
			if(*(p+j)>*(p+(j+1)))
			{
				temp = *(p+(j+1));
				*(p+(j+1)) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
	cout<<"After Sorting - \n";
	for(i=0;i<x;i++)
	{
	
		cout<<*(p+i)<<" ";	
	}
}

#include<iostream>
using namespace std;
int i=0;
void TOH(int n,char source, char dest, char inter)
{
	if(n>0)
	{
		TOH(n-1,source,inter,dest);
		cout<<"\n"<<source<<" -> "<<dest;
		i++;
		TOH(n-1,inter,dest,source);
	}
}
int main()
{
	int n;
	cout<<"Enter How Many Disks\n";
	cin>>n;
	TOH(n,'S','D','I');
	cout<<"\n\nTotal Moves = "<<i;
}

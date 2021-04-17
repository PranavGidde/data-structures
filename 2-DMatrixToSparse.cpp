#include<iostream>
using namespace std;
void printmatrix(int mat[10][10],int row,int col)
{
	int i,j;
	cout<<"\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void createsparse(int num[10][10],int sparse[10][3],int row,int col)
{
	sparse[0][0]=row;
	sparse[0][1]=col;
	int k=1,i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(num[i][j]!=0)
			{
				sparse[k][0]=i;
				sparse[k][1]=j;
				sparse[k][2]=num[i][j];
				k++;
			}
		}
	}
	sparse[0][2]=k-1;
}
void printsparse(int sparse[10][3])
{
	int i,j,row,col;
	row = sparse[0][2] + 1;
	col = sparse[0][1];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<sparse[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main()
{
	int num[10][10];
	int row,col,i,j;
	cout<<"Enter row and column no.\n";
	cin>>row>>col;
	cout<<"Enter Your Matrix\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>num[i][j];
		}
	}
	//Creating Simple Transpose Matrix
	int trans[10][10];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			trans[i][j] = num[j][i];
		}
	}
	cout<<"\nPrint Simple Matrix\n";
	printmatrix(num,row,col);
	cout<<"\nPrint Transpose Matrix\n";
	printmatrix(trans,col,row);
	int sparse[10][3];
	createsparse(num,sparse,row,col);
	cout<<"\nPrint Sparse Matrix\n";
	printsparse(sparse);
}

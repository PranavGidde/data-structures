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
void slowtranspose(int sparse[10][3], int strans[10][3])  	//create slow transpose
{
	strans[0][0]=sparse[0][1];
	strans[0][1]=sparse[0][0];
	strans[0][2]=sparse[0][2];
	int k=1,i,j;
	for(i=0;i<strans[0][0];i++)
	{
		for(j=1;j<=sparse[0][2];j++)
		{
			if(i==sparse[j][1])
			{
				strans[k][0]=sparse[j][1];
				strans[k][1]=sparse[j][0];
				strans[k][2]=sparse[j][2];
				k++;
			}
		}
	}
}
void printsparse(int sparse[10][3])
{
	cout<<sparse[0][0]<<" "<<sparse[0][1]<<" "<<sparse[0][2]<<" - info row";
	for(int i=1;i<=sparse[0][2];i++)
	{
		cout<<"\n"<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2];
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
//	cout<<"\nPrint Transpose Matrix\n";
//	printmatrix(trans,col,row);
	int sparse[10][3];
	createsparse(num,sparse,row,col);
	cout<<"\nPrint Sparse Matrix\n";
	printsparse(sparse);
	int strans[10][3];
	slowtranspose(sparse,strans); //create slow transpose
	cout<<"\nSlow Transpose - \n";
	printsparse(strans);
}

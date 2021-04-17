#include<iostream>
using namespace std;
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
void createftrans(int sparse[10][3],int ftrans[10][3])
{
	ftrans[0][0]=sparse[0][1];
	ftrans[0][1]=sparse[0][0];
	ftrans[0][2]=sparse[0][2];
	int i,j,r,c,pos,v,rno,row;
	row = sparse[0][1];
	int *total,*index;
	total = new int[row];
	index = new int[row];
	for(i=0;i<row;i++)
	{
		total[i]=0;
	}
	for(j=1;j<=sparse[0][2];j++)
	{
		rno = sparse[j][1];
		total[rno]++;
	}
	index[0]=1;
	for(i=1;i<row;i++)
	{
		index[i]=index[i-1] + total[i-1];
	}
	for(j=1;j<=sparse[0][2];j++)
	{
		r = sparse[j][1];
		c = sparse[j][0];
		v = sparse[j][2];
		
		pos = index[r];
		index[r]++;
		ftrans[pos][0]=r;
		ftrans[pos][1]=c;
		ftrans[pos][2]=v;
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
	int sparse[10][3];
	createsparse(num,sparse,row,col);
	cout<<"\nPrint Sparse Matrix\n";
	printsparse(sparse);
	int ftrans[10][3];
	createftrans(sparse,ftrans);  //create fast transpose
	cout<<"\nFast Transpose - \n";
	printsparse(ftrans);
}

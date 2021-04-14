#include <stdio.h>
#define MAX_SIZE 100 
int add(int arr[], int start, int len)
{
    if(start >= len)
    {
    	return 0;
	}  
    return (arr[start] + add(arr, start + 1, len));
}
int main()
{
    int arr[MAX_SIZE];
    int num, i, sum;
    printf("How many elements\n");
    scanf("%d", &num);
    printf("Enter elements\n");
    for(i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
 
 
    sum = add(arr, 0, num);
    printf("Sum of array elements: %d", sum);
 
    return 0;
}


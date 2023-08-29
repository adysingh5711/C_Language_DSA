#include<stdio.h>
int len(int n)
{
	int l=0;
	while(n!=0)
	{
		l++;
		n/=10;
	}
	return l;
}
int main()
{
    int n,m,i,num=0;
    printf("Enter the length of the number.\n");
    scanf("%d",&n);
   
    int arr[n],new_arr[m];
    printf("Enter the digits of the number.\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        num= num*10+arr[i];
    }
    
    
    num++;
    m= len(num);
    
    
   // printf("num: %d  n:%d  m:%d\n",num,n,m);
    i=m-1;
    while(num!=0)
    {
        new_arr[i--]=num%10;
        
        num/=10;
    }
    
    printf("\nThe new array of digits is:\n ");
    for(i=0;i<m;i++)
    printf(" %d\t",new_arr[i]);
    
    return 0;
    
    
}

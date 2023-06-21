#include<stdio.h>
int main()
{
    int a[25],i,n;
    int evensum=0,oddsum=0;
    printf("enter the array size");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            evensum=evensum+a[i];
        }
        else 
        {
            oddsum=oddsum+a[i];
        }
    }
    printf("%d\n",evensum);
    printf("%d\n",oddsum);
    return 0;
}
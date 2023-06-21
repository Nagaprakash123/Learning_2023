#include<stdio.h>
int main()
{
    int a[10],n,i,sum=0,avg=0;
    printf("enter the number");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=1;i<=n;i++)
    {
        sum = sum+a[i];
        avg=sum/n;
    }
    printf("%d\n",sum);
    printf("%d\n",avg);
    return 0;
}
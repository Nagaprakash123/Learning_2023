#include<stdio.h>
int main()
{
    int a[100],i,n,max,min;
    printf("enter the number");
    scanf("%d",&n);
    printf("enter the array");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    min=max=a[0];
    for (i=1;i<n;i++)
    {
        if(min>a[i]){
            min =a[i];
        }
        if (max<a[i]){
            max=a[i];
        }
        
    }
    printf("%d\n",min);
    printf("%d\n",max);
    return 0;
}
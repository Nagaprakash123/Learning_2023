#include<stdio.h>    
#include<stdlib.h>  
int main(){  
int a[10],n,i;    
printf("Enter the number to convert: ");    
scanf("%d",&n);    
for(i=0;n>0;i++)    
{    
a[i]=n%2;    
n=n/2;    
}    
printf("\nBinary of Given Number is=");    
for(i=i-1;i>=0;i--)    
{    
printf("%d",a[i]);    
}    
return 0;  
}  

/**
we can be able to do in short for also the above program

like add simple word in printset
int n;
printf("%b"&n);
this is short for for dec to bin.
**/
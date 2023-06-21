#include <stdio.h>
int main() 
{
    int number;
    printf("\n Please Enter the Number You want to Convert  :  ");
    scanf("%d", &number);
    
    printf("\n Octal Number of a Given Number =  %o", number);

    return 0;
}



/**
the above code is to print decimal to octal in the short form.
we can be able to do it in formula base also like,
int a[i],n;
a[i]=n%8;
n=n/8;
**/
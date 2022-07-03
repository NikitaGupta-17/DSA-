#include<stdio.h>

void max(int *a,int *b,int *c)
{
    int temp;
    if((*b > *a) && (*b > *c))
    {
        temp =*a;
        *a=*b;
        *b=temp;
    }
    else if((*c > *a) && (*c>*b))
    {
        temp=*a;
        *a=*c;
        *c=temp;
    }

}

int main()
{
    int sidea,sideb,sidec;
    printf("Enter the sides:");
    scanf("%d%d%d",&sidea,&sideb,&sidec);
    if((sidea + sideb >sidec) && (sideb + sidec > sidea) && (sidea + sidec > sideb))
    {
        if(sidea == sideb && sideb == sidec)
        printf("Equilateral Triangle");
        else if(sidea == sideb || sidea == sidec || sideb == sidec)
        printf("Isoceles Trianlge");
        else
        {
            max(&sidea ,&sideb , &sidec);
            if(sidea*sidea != (sideb*sideb + sidec*sidec))
            printf("Scalene Triangle");
            else
            printf("Right angle Triangle");
        }
    }
    return 0;
}
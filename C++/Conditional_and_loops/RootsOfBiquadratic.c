#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c,D,temp;
    float root1,root2;
    printf("Enter the Coefficients of x*x ,x and constnt term :");
    scanf("%d%d%d",&a,&b,&c);
    D = b*b-4*a*c;
    
    if(D>0)
    {
        root1 = (-b+sqrt(D))/(2*a);
        root2 = (-b-sqrt(D))/(2*a);
        printf("Roots are real and distinct : %.2f ,%.2f",root1,root2);
    }
    else if(D ==0)
    {
        root1 = -b/(2*a);
        root2 = root1;
        printf("Roots are real and equal : %.2f ,%.2f",root1,root2);
    }
    else{
        temp=sqrt(-D);
        printf("Roots are Imaginary \n");
        printf("1st Root : -%d + %di\n",b/(2*a),temp/(2*a));
        printf("2nd Root : -%d - %di\n",b/(2*a),temp/(2*a));
    }
    return 0; 
}
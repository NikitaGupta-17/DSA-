#include<stdio.h>

int main(){
    int i,j,n,sum=0;;
    printf("Enter a number : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        if(i==0)
        {
            sum=sum+i+1;
            printf("%d + ",i+1);
        }
        else
        {
            if(i==n-1){
                sum=sum+((i+1)*i);
                printf("%d*%d = ",i+1,i);
                break;
            }
            sum=sum+((i+1)*i);
            printf("%d*%d + ",i+1,i);
        }
    }
    printf(" %d",sum);
    return 0;
}
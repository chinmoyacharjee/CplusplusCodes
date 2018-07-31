#include<stdio.h>

int main(){

    int i,j;
    
    printf("1st num= ");
    scanf("%d",&i);
    printf("2nd num= ");
    scanf("%d",&j);
    
    printf("i<j %d\n",i<j);
    printf("i<=j %d\n",i<=j);
    printf("i==j %d\n",i==j);
    printf("i>j %d\n",i>j);
    printf("i>=j %d\n",i>=j);


    printf("i && j %d\n",i && j);
    printf("i || j %d\n",i || j);
    
    
     
    printf("!i !j %d %d\n",!i, !j);
    
    return 0;




}

#include<stdio.h>

int main(){

    float a;
    int choice;
    
    printf("feets to meters press 1\n or press 2 for meters to feets\n");
    scanf("%d",&choice);
    
    if(choice==1){
    
        printf("enter de value of feet= ");
        scanf("%f",&a);
        printf("meters= %f", a/3.28);
    
    }else{
    
        printf("enter de value of meter= ");
        scanf("%f",&a);
        printf("feets= %f", a*3.28);
    }
    














    return 0;

}

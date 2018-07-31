#include<stdio.h>
int get_sqr(void);

int main(){

    int sqr;
    sqr  = get_sqr();
    printf("square: %d",sqr);

}
int get_sqr(void){

    int num;
    printf("enter a num: ");
    scanf("%d",&num);
    return num*num;
    


}



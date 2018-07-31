#include<stdio.h>

int main(){

    int a,b,choice,add,sub;
    
    printf("1:addition\n2:substraction\n");
    scanf("%d",&choice);
    
    if(choice==1){
        printf("u choosed addition\nthen input two integer value for addition\n");
        scanf("%d%d",&a,&b);
        add=a+b;
        printf("%d",add);    
    }else if(choice==2){
       printf("u choosed substraction\nthen input two integer value for substraction\n");
       scanf("%d%d",&a,&b);
       sub=a-b; 
       printf("%d",sub);
    
    
    }


















return 0;

}

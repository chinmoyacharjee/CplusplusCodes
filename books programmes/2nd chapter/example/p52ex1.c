#include<stdio.h>

int main(){

    int ans,count;
    for(count=1;count<11;count++){
    
        printf("%d + %d\n",count,count);
        scanf("%d",&ans);
        
        if(ans==count+count) printf("Right!!!!!!!!!!!!!!!\n");
        else {printf("wrong!!!!!!!!!!!!!\n");
        printf("the r8 ans is %d\n",count+count);
        }
   }








return 0;
}

#include<stdio.h>

int xor(int a,int b);

int main(){

    int p,q;
    scanf("%d%d",&p,&q);
    printf("P && Q %d\n",p && q);
    printf("P || Q %d\n",p || q);
    printf("P xor Q %d\n",xor(p,q));

}int xor(int a,int b){
    return (a||b) && !(a&&b);
}




























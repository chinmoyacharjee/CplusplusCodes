#include<stdio.h>
int main() 
{

    char a;
    printf("Give me a letter: ");
    scanf("%c",&a);
    if(a=='a'||'e'||'i'||'o'||'u'||'A'||'E'||'I'||'O'||'U')
    {
    printf("It is a vowel\n");
    }
    else
    {
    printf("it is consonant\n");
    }
    return 0;
    



}

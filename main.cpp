#include <stdio.h>
#include <assert.h>

// exo 5.1 utiliser gets()
void passer_majuscule1()
{
    char t[100];
    printf("Veuillez entrer une chaine de caractere : \n");
    gets(t);
    for (int i = 0; i < 100 ; ++i) {
        if (t[i] >= 'a' && t[i] <= 'z')
            t[i] = t[i]-32;
    }
    puts(t);
}

// exo 5.1 utiliser regular expression
void passer_majuscule2() {
    char t[100];
    printf("Veuillez entrer une chaine de caractere : \n");
    scanf("%[^\n]", t);
    for (int i = 0; i < 100; ++i) {
        if (t[i] >= 'a' && t[i] <= 'z')
            t[i] = t[i] - 32;
    }
    printf("%s\n", t);
}

// exo 5.2
/* 算法的关键是当两个指针相遇或擦肩而过时就停止 */
void reverse_string(char *string)
{
    char *p;
    /* 把p设置为指向字符串的最后一个字符 */
    for(p=string;*p!='\0';p++);
    p--;
    /* 交换p和string所指向的字符，然后string前进一步，p后退一步，在两个指针相遇或擦肩而过之前重复整个过程 */
    while(string<p)
    {
        char temp;
        temp=*string;
        *string++=*p;
        *p--=temp;
    }
}

/*
 * 四、字符串比较strcmp

函数strcmp的原型是int strcmp(const char *s1,const char *s2)。

若s1==s2，返回零；
若s1>s2，返回正数；
若s1<s2，返回负数。
即：两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇\0为止。
 * */
/*
 * 四、字符串比较strcmp

函数strcmp的原型是int strcmp(const char *s1,const char *s2)。

若s1==s2，返回零；
若s1>s2，返回正数；
若s1<s2，返回负数。
即：两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇\0为止。
 * */
// Exo 5.3 solution1
int strcmp_reproduit(const char *s1, const char *s2)
{
    assert((s1 != NULL) && (s2 != NULL));
    while (*s1 == *s2)
    {
        if (*s1 == '\0')
            return 0;

        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

// Exo 5.3 solution2
int strcmp_reproduit2(char* source, char* dest)
{
    assert(source !=NULL && dest !=NULL);
    while (*source++==*dest++)
    {
        if(*source == '\0' && *dest == '\0')
            return 0;
    }
    return -1;
}
// Exo 5.3 solution3
int strcmp_reproduit3(const char* src, const char* dst)
{
    int flag=0;
    while (!(flag=*(unsigned char*)src - *(unsigned char*)dst) && *dst)
    ++src,++dst;
    if (flag<0)
        flag =-1;
    else if (flag > 0)
        flag =1;
    return flag;
}


int main(){
    //passer_majuscule1(); //test 5.1
    //passer_majuscule2(); // test 5.1

    // test 5.2
/*    char str[100];
    printf("Veuillez entrer une chaine de caractere : \n");
    scanf("%[^\n]", str);
    reverse_string(str);
    printf("after reversed:%s\n",str);*/

    /*
     * test 5.3
     * */
    char str1[]="sajhdkjsh";
    char str2[]="ioueqdjkha";
    //printf("egal? : %d \n", strcmp_reproduit(str1,str2));
    printf("egal? : %d \n", strcmp_reproduit2(str1,str2));
    printf("egal? : %d \n", strcmp_reproduit2(str1,str2));
    return 0;
}

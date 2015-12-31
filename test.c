/*
* @Author: tuo
* @Date:   2015-12-20 21:31:39
* @Last Modified by:   tuo
* @Last Modified time: 2015-12-20 22:02:12
*/

/* Write a program to count blanks, tabs and newlines */

#include<stdio.h>

int main() {
	FILE *fp;
    char c;
    if((fp=fopen("string.txt","rt"))==NULL){
        printf("Cannot open file strike any key exit!");
    }
    int nl, nt, ns;
    nl = 0;
    nt = 0;
    ns = 0;
    c = fgetc(fp);
    while (c!= EOF) {
    	putchar(c);
    	c=fgetc(fp);
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++ns;
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", ns, nt, nl);
    fclose(fp);
}

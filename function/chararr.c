/* 函数与字符数组 */

#include <stdio.h>
#include <stdlib.h>

char *mystrcpy(char * dest, const char *src ) {
    if(dest != NULL && src != NULL)
        while((*dest++ = *src++) != '\0');
    return dest;;
}

char *mystrncpy(char *desc, const char *src, size_t n) {
   int i;
   for (i = 0; i < n && (desc[i] = src[i]); i++) 
       ;
   for(; i<n ;i++)
        desc[i] = '\0';
   return desc;
}

int main() {
    char str1[] = "helloworld";
    char str2[128];

    // mystrcpy(str2, str1);
    mystrncpy(str2, str1, 5);
    puts(str2);

    exit(0);
}

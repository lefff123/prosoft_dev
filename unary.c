#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
 
    
    char MESSAGE[101] = "";
    fgets(MESSAGE, sizeof(MESSAGE)-1, stdin);
    int l = strlen(MESSAGE);

    while (l > 0 && MESSAGE[l-1] == '\n') {
        MESSAGE[l-1] = '\0';
        l--;
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    int len = strlen(MESSAGE);

    char *str = malloc(sizeof(char)*1000);
    unsigned n=0;
    for (unsigned i=0; i<len; i++){
        for (char k=6; k>=0; k--){
            *(str+n++) = (MESSAGE[i]>>k)&1;
        }
    }

    
    for (unsigned i=0; i<n; i++){
        *(str+i)==0?printf("00 0"):printf("0 0");
        while (*(str+i)==*(str+i+1)&&i<n-1){
                printf("0");
                i++;
            }
        i<n-1?printf(" "):1;
    }

    free(str);
    return 0;
}

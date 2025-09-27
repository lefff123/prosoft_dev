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
    // the number of temperatures to analyse
    
    int n;
    scanf("%d", &n);

    int *nums = malloc(sizeof(int)*n);
    int *temp = nums;

    for (int i = 0; i < n; i++) {
        // a temperature expressed as an integer ranging from -273 to 5526
        int t;
        scanf("%d", &t);
        
        *temp++ = t;
    }

    temp=nums;
    int tempnum=10000;
    for (char i=0; i<n; i++){
        if (abs(*(temp+i))<abs(tempnum))
            tempnum = *(temp+i);
        if (abs(*(temp+i))==abs(tempnum)){
            if (*(temp+i)>tempnum)
                tempnum = *(temp+i);
        }
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    tempnum==10000?(tempnum=0):0;
    printf("%d\n", tempnum);
    free(nums);
    return 0;
}

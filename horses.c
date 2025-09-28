#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int compare( const void* a, const void* b ){
    return *(int*)a-*(int*)b;
}


int main()
{
    int N;
    scanf("%d", &N);

    int *horses= malloc(sizeof(int)* N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &horses[i]);
    }

    int min=10000;
    qsort(horses, N, sizeof(int), compare );

    for (int i=1; i<N; i++){
        int dif = abs(horses[i]-horses[i-1]);
        dif<min?(min=dif):1;   
    }


    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", min);

    free(horses);

    return 0;
}

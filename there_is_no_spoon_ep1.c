#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    // the number of cells on the X axis
    int width;
    scanf("%d", &width);
    // the number of cells on the Y axis
    int height;
    scanf("%d", &height); fgetc(stdin);


    char str[30][30]={0};
    for (int i = 0; i < height; i++) {
        scanf("%s", str[i]);
    }

    for (char y=0; y<height; y++){
        for(char x=0; x<width; x++){

            if (str[y][x]=='0'){
                printf("%d %d ", x,y);

                char x1=x+1, y1=y+1;
                bool isx=false, isy=false;

                while (x1<width&&str[y][x1]!='\0'){
                    if (str[y][x1]=='0'){
                        printf("%d %d ", x1, y);
                        isx=true;
                        break;
                    }
                    x1++;
                }

                if (!isx) {
                        printf("-1 -1 ");

                    }
                

                while (y1<height&&str[y1][x]!='\0'){
                    if (str[y1][x]=='0'){
                        printf("%d %d ", x, y1);
                        isy=true; 
                        break;
                    }
                    y1++;
                }
                if (!isy) {
                    printf("-1 -1");
                   
                }
                printf("\n");
            }
            
        }
        
    }



    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    



    return 0;
}

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
    // width of the building.
    int W;
    // height of the building.
    int H;
    scanf("%d%d", &W, &H);
    // maximum number of turns before game over.
    int N;
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    int x_r=W-1, y_up=H-1;
    int x_l=0,y_d=0;
    // game loop
    while (1) {
        // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4] = "";
        scanf("%s", bomb_dir);

        bool U=0,D=0,L=0,R=0;

        for (char i=0; i<4; i++){
            switch(bomb_dir[i]){
                case 'U':
                    U=true;
                    break;
                case 'D':
                    D=true;
                    break;
                case 'L':
                    L=true;
                    break;
                case 'R':
                    R=true;
                    break;
            };

        }

        if (U){
            y_up=Y0-1;
        }
        else
            if (D){
                y_d=Y0+1;
            }
        
        if (R){
            x_l=X0+1;
        }
        else if (L){
                x_r=X0-1;
            
        }
        
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        X0 = (x_l+x_r)/2;
        Y0=(y_up+y_d)/2;
        // the location of the next window Batman should jump to.
        printf("%d %d\n", X0, Y0);
        

    }

    return 0;
}

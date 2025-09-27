#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/


int main()
{
    // the X position of the light of power
    int x;
    // the Y position of the light of power
    int y;
    // Thor's starting X position
    int tx;
    // Thor's starting Y position
    int ty;
    scanf("%d%d%d%d", &x, &y, &tx, &ty);

    // game loop
    while (1) {
        // The remaining amount of turns Thor can move. Do not remove this line.
        int remaining_turns;
        scanf("%d", &remaining_turns);

        if ((ty-y>0&&ty<18)&&ty>=0){
            printf("N");
            ty-=1;
        }

        if ((ty-y<0&&ty<18)&&ty>=0){
            printf("S");
            ty+=1;
        }
        if ((tx-x>0&&tx<40)&&tx>=0){
            printf("W");
            tx-=1;
        }
        if ((tx-x<0&&tx<40)&&tx>=0){
            printf("E");
            tx+=1;
        }
        
        printf("\n");

        

        // A single line providing the move to be made: N NE E SE S SW W or NW
    }

    return 0;
}

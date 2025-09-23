#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>



int main()
{
    typedef struct {
        double lat;
        double lon;
        char name[100];
    }defib;

    

    char LON[51] = "";
    scanf("%s", LON);
    char LAT[51] = "";
    scanf("%s", LAT);

    *(strchr(LON, ','))='.';
    *(strchr(LAT, ','))= '.';

    double lon = atof(LON), lat = atof(LAT);

    int N;
    scanf("%d", &N);

    double *dist=malloc(sizeof(double)*N);
    defib *list = malloc(sizeof(defib)*N); 

    for (int i = 0; i < N; i++) {
        char DEFIB[257] = "";
        scanf("%s", DEFIB); 

        char *ptr_t = strrchr(DEFIB, ';')+1;
        *(strchr(ptr_t, ','))='.';
        //записываем долготу
        list[i].lat=atof(ptr_t);

        ptr_t=strrchr(ptr_t-1,';')+1;
        *(strchr(ptr_t, ','))='.';
        //записываем широту
        list[i].lon=atof(ptr_t);

        ptr_t+=2;
        //записываем название улицы
        ptr_t=strchr(DEFIB,';')+1;
        
        int num=0;
        while(*ptr_t!=';'){
            list[i].name[num++] = *ptr_t++;
        }

        //Считаем расстояние до дефибриллятора
        double x = list[i].lon-lon*cos((lon+list[i].lon)/2.);
        double y = list[i].lat-lat;
        double d = sqrt(x*x+y*y)*6371;

        dist[i] = d;

    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    int max=0;
    for (int i = 0;i<N; i++ ){
        dist[max]>dist[i]?(max=i):1;
    }
    
    printf("%s", list[max].name);
    free(dist);
    free(list);
    return 0;
}

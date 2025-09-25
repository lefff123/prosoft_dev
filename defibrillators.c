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
        scanf(" %[^\n]", DEFIB); 
 
        char *ptr_t = strchr(DEFIB, ';')+1;
        //name of street
        char *t=strchr(ptr_t,';');
       
        strncpy(list[i].name, ptr_t, t-ptr_t);

        //latitude
        ptr_t=strrchr(DEFIB,';');
        *ptr_t++='\0';  
        *(strchr(ptr_t, ','))='.';
        list[i].lat=atof(ptr_t);
       

        //longtitude
        ptr_t=strrchr(DEFIB, ';')+1;
        *(strchr(ptr_t, ','))='.';
        list[i].lon=atof(ptr_t);


        //Считаем расстояние до дефибриллятора
        double x = (list[i].lon-lon)*cos((lat+list[i].lat)/2.);
        double y = list[i].lat-lat;
        double d = sqrt(x*x+y*y)*6371.;

        dist[i] = d;

    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    int min=0;
    for (int i = 0;i<N; i++ ){
        dist[min]>dist[i]?(min=i):1;
    }
    
    printf("%s", list[min].name);
    free(dist);
    free(list);
    return 0;
}

//РЕШЕНИЕ НЕ ПРОШЛО ПОСЛЕДНИЙ ТЕСТ


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    setvbuf(stdout, NULL, _IOFBF, 8192);  // Буфер 8KB
    
    struct data_type{
        char type[12];
        char mime[51];
    };

    // Number of elements which make up the association table.
    int N;
    scanf("%d", &N);
    // Number Q of file names to be analyzed.
    int Q;
    scanf("%d", &Q);fgetc(stdin);

    struct data_type *mime=malloc(sizeof(struct data_type)*N);
    int num_of_mimes=0;

    for (int i = 0; i < N; i++) {
        // file extension
        char EXT[11] = "";
        // MIME type.
        char MT[51] = "";
        scanf("%s%s", EXT, MT);
        
        for (int n=0;EXT[n];n++){
            EXT[n]=tolower(EXT[n]);
        }
        

        mime[i].type[0]='.';
        strcat(mime[i].type, EXT);
        strcpy(mime[i].mime, MT);
    }

    

    for (int i = 0; i < Q; i++) {
        // One file name per line.
        char FNAME[257] = "";
        
        
        
        scanf("%s", FNAME);

        char *n=strchr(FNAME, '.');
        
        if (n!=NULL){
            
            for (int div = n-FNAME;FNAME[div];div++){
                        FNAME[div]=tolower(FNAME[div]);
                    }
        }
        
        

       
        bool is_word=false;
        
        for (int k=0; k<N;k++){
            char* ptr_t=strrchr( FNAME, '.');
            if (ptr_t!=NULL&&strcmp(ptr_t, mime[k].type)==0){
                printf("%s\n", mime[k].mime);
                is_word=true;
                break;
                
            }
        }
        if (!is_word){
            puts("UNKNOWN");
        }
        
        
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    

    return 0;
}

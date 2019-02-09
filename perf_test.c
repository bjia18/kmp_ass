#include "string_matching.h"

#define min 10000
#define max 1000000
#define m 400

void perf_test (){
    clock_t start, end;
    double total;
    int len=min;
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL));   // Initialization, should only be called once.
    FILE *fp;
    fp=fopen("timer3.csv","w+");
    fprintf(fp,"naive, kmp, n size");

    while (len<=max) { 
        char *text = malloc(len);
        for (int i=0; i<len; i++){
            int pos = rand() % (int)(sizeof(charset) -1);
            text[i] = charset[pos];
            if (i==(len-1))
                text[i]='\0';      
        }
        char *pattern=malloc(m);
        for (int i=0; i<m; i++){
            int pos = rand() % (int)(sizeof(charset) -1);
            pattern[i] = charset[pos];
            if (i==(m-1))
                text[i]='\0';       
        }
        start= clock();
        string_matching_naive(text, len, pattern, m);
        end = clock();
        total= ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%f",total);
        fprintf(fp,"\n%f",total);
        start=clock();
        string_matching_kmp(text, len, pattern, m);
        end = clock();
        total = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(fp,", %f, %d",total,len);
	    free(text);
        free(pattern);
        len+=10000;
    }
    fclose(fp);
}
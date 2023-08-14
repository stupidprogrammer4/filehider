#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_FILE_LEN 250
#define MAX_FILE_SIZE 1024*1024*10

int main(int argc, char **argv) {
    int key;
    char *path = malloc(MAX_NAME_FILE_LEN);
    char *buffer = malloc(MAX_FILE_SIZE);



    scanf("%s %i", path, &key);

    FILE *fptr;

    fptr = fopen(path, "rb");

    int i=0; 

    while (!feof(fptr)) {
        buffer[i++] = fgetc(fptr);
    }

    fclose(fptr);

    fptr = fopen(path, "wb");

    for (int j=0; j<i-1; j++) {
        fputc(buffer[j]^key, fptr);
    }

    fclose(fptr);
    free(path);
    free(buffer);

}
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *file = fopen("sample.txt", "w");

    if (!file) {
        printf("El archivo no existe.");
        return 0;
    }

    fprintf(file, "this is a sample");

    fclose(file);

    return 0;
}

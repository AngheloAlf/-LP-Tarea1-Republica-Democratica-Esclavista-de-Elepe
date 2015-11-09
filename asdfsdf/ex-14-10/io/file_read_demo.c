#include <stdio.h>

void read_buffer(FILE *file)
{
    char buffer[256];
    fscanf(file, "%s", buffer);
    printf("%s\n", buffer);
}

void read_stream(FILE *file)
{
    char buffer[64];
    while (fscanf(file, "%s", buffer) != EOF) {
        printf("%s ", buffer);
    }

    if (feof(file)) {
        printf("\n\nArchivo completamente leido.\n");
    }
}

int main(int argc, char const *argv[])
{
    FILE *file = fopen("sample.txt", "r");

    if (!file) {
        printf("El archivo no existe.");
        return 0;
    }

    // read_buffer(file);
    // read_stream(file);
    // TODO: investigar forma de guardar todo el texto del archivo en un string.

    fclose(file);

    return 0;
}

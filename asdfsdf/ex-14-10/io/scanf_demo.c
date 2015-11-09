#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &i);
    printf("El numero es: %d\n", i);

    char name[256];
    printf("Ingrese su nombre: ");
    scanf("%s", name);
    printf("Su nombre es: %s\n", name);

    printf("Ingrese su nombre y luego su edad: ");
    scanf("%s %d", name, &i);
    printf("Su nombre es %s y su edad %d\n", name, i);

    return 0;
}

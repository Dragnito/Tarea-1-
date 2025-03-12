#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("ventas_pizzas.csv", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char line[1024]; // Buffer para cada línea
    fgets(line, sizeof(line), file); // Leer la primera línea (encabezados) y descartarla

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ","); // Primer dato
        while (token != NULL) {
            printf("%s | ", token);
            token = strtok(NULL, ","); // Siguiente dato
        }
        printf("\n"); // Nueva línea después de cada fila
    }

    fclose(file); // Cerrar archivo
    return 0;
}

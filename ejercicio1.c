#include <stdio.h>

#define MAXLINE 1000

int main() {
    int c;
    int i = 0;
    char line[MAXLINE];

    while ((c = getchar()) != EOF) {

        line[i] = c;
        i++;

        /* Si llega a salto de línea o al límite del buffer */
        if (c == '\n' || i >= MAXLINE - 1) {

            line[i] = '\0';   /* cerrar string */

            printf("Linea completa leida: %s", line);

            i = 0;   /* reiniciar buffer */
        }
    }

    return 0;
}

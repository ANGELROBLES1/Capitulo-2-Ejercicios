# Capitulo-2-Ejercicios
# Ejercicio 1 – Lectura por líneas completas
# Descripción

El ejemplo 2-3 del libro procesa los caracteres uno por uno.  
Podría pensarse que una solución simple sería utilizar el patrón:

^.*\n

para capturar líneas completas. Sin embargo, el operador `.*` es
**greedy**, lo que significa que intenta consumir la mayor cantidad
de texto posible. Esto puede provocar que el lexer capture más texto
del esperado y afecte el funcionamiento de otras reglas.

Por esta razón se utiliza el patrón:

[^\n]*\n

Este patrón significa:

- `[^\n]*` : cualquier carácter excepto salto de línea
- `\n` : final de línea

De esta forma se captura exactamente una línea completa sin consumir
texto adicional.


# Código del lexer


```lex
%{
#include <stdio.h>
int lineno = 1;
%}

%%

[^\n]*\n   {
            printf("%4d: %s", lineno++, yytext);
          }

.          { }

%%

int main() {
    yylex();
    return 0;
}
``` 

# Compilación
flex ejercicio1.l
gcc lex.yy.c -o ejercicio1 -lfl

# Ejecución
./ejercicio1 < entrada.txt

# Resultado
El programa imprime cada línea del archivo de entrada numerada.
<img width="636" height="269" alt="image" src="https://github.com/user-attachments/assets/ffd66f43-1bb8-44d6-9f85-ffc01d3c163a" />
<img width="592" height="157" alt="image" src="https://github.com/user-attachments/assets/ac29c143-8d29-488c-b917-16a0ac4f6ed4" />
<img width="588" height="132" alt="image" src="https://github.com/user-attachments/assets/158e31a0-c127-44dc-b080-2e8b16fe0817" />



# Ejercicio 2 – Concordancia sin distinguir mayúsculas y minúsculas
# Descripcion
El programa de concordancia del capítulo trata las palabras en mayúsculas y minúsculas como diferentes.
MORA
mora
MOrA
MORA
mora
Habilidad
HABILIDAD
HaBiLiDad
Pick
PicK
PICK
pick
son almacenadas como tres entradas distintas.
El ejercicio pide modificar el programa para que estas palabras sean tratadas como una sola.
# Normalización en la función hash
Se modifica la función hash() para convertir cada carácter a minúscula usando tolower().
hashval = tolower(*s) + 31 * hashval;
Esto garantiza que palabras que solo difieren en capitalización generen el mismo valor hash.
# Comparación de cadenas
Se reemplaza strcmp() por strcasecmp() en la función lookup().
strcasecmp(s, np->word) == 0
Esto permite comparar palabras ignorando diferencias entre mayúsculas y minúsculas.
# Compilación
flex ejercicio2.l
gcc lex.yy.c -o ejercicio2 -lfl
# Ejecución
./ejercicio2 < intro.txt
# Resultado
El programa cuenta correctamente las palabras sin distinguir mayúsculas o minúsculas.
<img width="674" height="149" alt="image" src="https://github.com/user-attachments/assets/fb2af24a-26fa-4c1d-b76b-d8de4d98c748" />
<img width="674" height="149" alt="image" src="https://github.com/user-attachments/assets/fb329ce5-abdb-49f9-b3c4-70bf5a05b820" />
<img width="669" height="107" alt="image" src="https://github.com/user-attachments/assets/10a2fafc-1db7-49b3-a922-c7b60eba0f73" />


# Ejercicio 3 – Verificación y elección entre Chaining y Rehashing




















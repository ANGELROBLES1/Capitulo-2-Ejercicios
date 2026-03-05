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
# Requerimientos
1. Archivos necesarios
El programa requiere los siguientes archivos ubicados en la misma carpeta:
ejercicio2.c
Entrada.txt
El archivo Entrada.txt debe contener al menos 10 líneas.
Cada línea puede contener palabras que serán analizadas por el programa de concordancia.
2. Abrir la terminal
Abrir la terminal en Ubuntu (VirtualBox).
3. Navegar hasta la carpeta del programa
Usar comandos para cambiar al directorio donde se encuentran los archivos:
cd Capitulo-2-KR-Ejercicios
4. Compilar el programa
Ejecutar el siguiente comando:
gcc ejercicio2.c -o ejercicio2
5. Ejecutar el programa
Una vez compilado, ejecutar:
./ejercicio2 < Entrada.txt
6. Salida del programa
El programa mostrará en consola cada palabra encontrada junto con el número de veces que aparece.
Ejemplo de entrada:
<img width="145" height="274" alt="image" src="https://github.com/user-attachments/assets/cd80fdd7-c1e0-45d5-9057-5b7be3655857" />
<img width="559" height="91" alt="image" src="https://github.com/user-attachments/assets/ce06706f-a082-4a71-9122-7d31222e3ad5" />
Prueba de error:
<img width="137" height="200" alt="image" src="https://github.com/user-attachments/assets/bee3b535-dca8-4890-9525-174d5ad7dbef" />
<img width="561" height="61" alt="image" src="https://github.com/user-attachments/assets/7f0c3adf-021a-46cc-a52f-dba6ef40e879" />

# Funcionamiento

El programa utiliza:
- Una tabla hash de tamaño fijo (HASHSIZE)
- Listas enlazadas para manejar colisiones (chaining)
- malloc() para memoria dinámica
- tolower() en la función hash() para normalizar el cálculo
- Una función strcasecmp_local() para comparar palabras sin distinguir mayúsculas
- No se crean copias adicionales de las palabras en minúsculas, cumpliendo con el requerimiento del ejercicio.

# Ejercicio 3 – Verificación y elección entre Chaining y Rehashing
# Planteamiento
El programa de concordancia utiliza una tabla hash para almacenar palabras. Cuando dos palabras generan el mismo valor hash, ocurre una colisión.

Existen dos técnicas para manejar este problema:
- Chaining (encadenamiento)
- Rehashing (rehash dinámico)
Se debe elegir cuál técnica es más adecuada para este programa y demostrar su funcionamiento.

# Procedimiento realizado
Para comprobar cómo el programa maneja colisiones, se realizaron las siguientes pruebas:
Forzar colisiones
Se modificó el tamaño de la tabla hash en el archivo ejercicio2.c:
<img width="202" height="194" alt="image" src="https://github.com/user-attachments/assets/3300a0c2-5fe1-4dcf-937e-13b95d5f042d" />

Al reducir la tabla a solo 3 posiciones, múltiples palabras necesariamente caerán en la misma posición del arreglo.

# Compilacion
Se compiló nuevamente el programa:
gcc ejercicio2.c -o ejercicio2
La compilación se realizó sin errores.

# Ejecución con múltiples palabras
Se ejecutó el programa con un archivo que contenía varias palabras diferentes:
./ejercicio2 < Entrada.txt

# Salida obtenida
<img width="702" height="465" alt="image" src="https://github.com/user-attachments/assets/f1658f01-b1c1-4ae8-88bf-2e672ce5b8f9" />

# Análisis de la prueba
Aunque la tabla solo tiene 3 posiciones, todas las palabras fueron almacenadas correctamente.
Esto significa que:
- Las palabras no se sobrescribieron.
- No se perdieron datos.
- Cada colisión generó un nuevo nodo enlazado.
El comportamiento observado confirma que el programa maneja colisiones mediante listas enlazadas.
En el código, esto ocurre en el fragmento:
np->next = hashtab[hashval];
hashtab[hashval] = np;
Este fragmento enlaza el nuevo nodo al inicio de la lista correspondiente a la posición calculada por la función hash.

# Comparación con Rehashing
Rehashing requeriría:
- Crear una nueva tabla más grande.
- Recalcular el hash de todos los elementos.
- Reinsertar cada palabra.
- Liberar la tabla anterior.
El programa actual no realiza este procedimiento.

# Decisión
Se elige la técnica de Chaining porque:
- Ya está implementada en el diseño actual.
- Maneja correctamente colisiones.
- No requiere reconstruir la tabla.
- Mantiene el código simple y coherente con el capítulo 2.


# Conclusión
La prueba práctica demuestra que el programa utiliza encadenamiento (chaining) para resolver colisiones en la tabla hash.
La reducción del tamaño de la tabla permitió verificar el comportamiento bajo múltiples colisiones, confirmando que la estructura es estable y funcional.
Por lo tanto, chaining es la técnica adecuada para este programa.






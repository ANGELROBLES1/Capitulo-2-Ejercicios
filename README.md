# Capitulo-2-Ejercicios
# Ejercicio 1 – Lectura por líneas completas
# Descripción

El programa original del capítulo procesa caracteres uno por uno utilizando getchar().
Se modificó el comportamiento para almacenar los caracteres en un arreglo hasta detectar un salto de línea (\n).

Cuando se detecta el fin de línea o se alcanza el límite del buffer, la línea completa se imprime en pantalla.

# Funcionamiento
Se utiliza:
- getchar() para leer caracteres
- Un arreglo char line[MAXLINE]
- Un contador i
- La constante EOF para detectar fin de archivo
- El programa continúa leyendo mientras:
"while ((c = getchar()) != EOF)"

# Pruebas realizadas
Se realizaron pruebas para intentar generar errores:

- Línea normal
Resultado: Se imprime correctamente.

- Texto muy largo (más de 1000 caracteres)
Resultado: Se trunca al tamaño máximo definido por MAXLINE.

- Entrada finalizada con CTRL+D
Resultado: El programa termina correctamente.

- Entrada vacía
Resultado: No imprime nada y no genera errores.
<img width="1213" height="604" alt="image" src="https://github.com/user-attachments/assets/e8bf0e35-3ba6-4adc-bba1-a9efa3810927" />

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











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

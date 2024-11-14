# Práctica 1 - Elementos Básicos, Operadores y Expresiones

- Ésta es la primera práctica evaluable (del bloque de prácticas obligatorias) que cuentan un 40% de la nota final. 
- Habrá 3 prácticas obligatorias pertenecientes a dicho bloque. 
- En el documento adjunto tenéis el enunciado de la primera práctica y los detalles de lo que tenéis que hacer. 
- Una vez realizada la entrega, se procederá a la realización de la tarea asociada a este ejercicio evaluable. Esta tarea consistirá en la realización de un programa (o varios) inspirado en uno de los realizados en el ejercicio evaluable.
- La calificación del ejercicio evaluable saldrá de esta tarea y la entrega de los programas será imprescindible para su calificación.

### Consideraciones y Formato de la entrega

- El alumno realizará la práctica de forma individual. Cualquier indicio de copia supondrá el suspenso directo de la práctica y repercutir directamente en el aprobado de la asignatura.
- Para la realización de los programas se puede utilizar cualquier editor, tipo NotePad++. Aplicar los conocimientos básicos adquiridos acerca de las buenas prácticas en la programación con una estructura de los programas correcta. Se debe cuidar también la indentación de las instrucciones para dar claridad y legibilidad del código escrito.  
Los archivos generados deben incluirse en un fichero .zip que es el que el alumno debe entregar y subir a BB y que deberá estar nombrado de la siguiente manera:

  **NombreAlumno_Apellidos_Practica1_IPR1.zip**

- La entrega debe realizarse en BB antes del **21/10/2024 a las 23:59**. No se admitirán entregas que no sigan el formato descrito anteriormente o que se realicen después de la fecha indicada. Si no se realiza la entrega el ejercicio se considerará suspenso con una calificación de 0.

Cualquier duda que tengáis podremos resolverla los días de clase de la semana que viene.

# Ejercicio Evaluable 1

La práctica 1 estará formada por los siguientes 5 ejercicios:

A. Clave de tres caracteres  
B. Calificaciones alumnos  
C. Entero de tres cifras  
D. Operaciones aritméticas, lógicas y relacionales  
E. Descomposición de un Número Entero de 32 Bits en Partes de 8 Bits  

A continuación, encontrarás los detalles de cada enunciado para escribir el código correspondiente. En todos ellos debes realizar el análisis del problema que se plantea, estudiando los datos de entrada que necesitas, plantea a continuación las sentencias de ejecución en base a las operaciones que debes realizar y finalmente muestra el resultado.

Se valorará si se ejecuta correctamente, así como la estructura general, la claridad y la legibilidad. Recuerda siempre utilizar identificadores que sean adecuados y el uso de comentarios. El uso de bucles no es necesario.

# Ejercicio A. Clave de tres caracteres

El programa deberá pedir una clave de 3 caracteres separados por guiones al usuario.  

La clave deberá contener una letra mayúscula, una letra minúscula y un dígito, escritos en cualquier orden.

El programa deberá comprobar si la clave es válida o no y mostrar el mensaje correspondiente:  
“Clave correcta” o “Clave incorrecta”.

### Ejemplo de ejecución:

```bash
$ ./clave.exe
Introduce la clave: u-6-F
La clave es correcta.

$ ./clave.exe
Introduce la clave: 7-6-F
La clave es incorrecta.

$ ./clave.exe
Introduce la clave: u6F
La clave es incorrecta.
```

# Ejercicio B - Calificaciones alumnos

Realiza un programa que determine si un estudiante aprueba o suspende una asignatura en función de sus calificaciones en tres pruebas, su examen y su asistencia a clase. 

### El programa debe solicitar:
- **Nota de primera prueba** (0-10)
- **Nota de segunda prueba** (0-10)
- **Nota de tercera prueba** (0-10)
- **Nota examen final** (0-10)
- **Asistencia a clase** (0%-100%)

### Cálculo de la nota final:
- **Pruebas** (40% del total):
  - Prueba 1 (20%)
  - Prueba 2 y 3 (40%) cada una
- **Examen final** (55%)
- **Asistencia** (5%)

### Criterios para aprobar:
- Nota de examen superior o igual a 4
- Media de las pruebas superior o igual a 5
- Nota final superior o igual a 5
- Asistencia mayor al 80%

Si se suspende algún apartado, se debe informar al usuario mediante la consola.

### Ejemplos de ejecución:

```bash
$ ./notas.exe
Nota de la primera prueba: 4.5
Nota de la segunda prueba: 4.7
Nota de la tercera prueba: 5.0
Nota del examen final: 5.0
Nota de asistencia: 0.9
El alumno ha suspendido.
Las pruebas no han superado la nota mínima.
```

```bash
$ ./grades.exe
Nota de la primera prueba: 7.0
Nota de la segunda prueba: 6.7
Nota de la tercera prueba: 5.0
Nota del examen final: 5.0
Nota de asistencia: 0.9
El alumno ha aprobado.
```

# Ejercicio C - Entero de tres cifras

Desarrolla un programa que pida al usuario un número entero positivo de tres cifras. El programa debe clasificar el número en función de sus dígitos.

### Reglas:
- Si el número tiene **tres dígitos diferentes**, debe mostrar:  
  `"El número tiene tres dígitos únicos."`
- Si el número tiene **dos dígitos iguales**, debe mostrar:  
  `"El número tiene dos dígitos iguales."`
- Si los **tres dígitos son iguales**, debe mostrar:  
  `"El número tiene tres dígitos iguales."`

### Ejemplo de ejecución:

```bash
$ ./digits.exe
Introduce un número entero positivo de 3 dígitos: 100
El número tiene dos dígitos iguales.
```

```bash
$ ./digits.exe
Introduce un número entero positivo de 3 dígitos: 123
El número tiene tres dígitos únicos.
```

# Ejercicio D - Operaciones aritméticas, lógicas y relacionales

Escriba un programa en **C** que solicite al usuario que ingrese dos números enteros. Luego, el programa debe usar operadores relacionales y lógicos para realizar lo siguiente:

1. Verificar e imprimir si el primer número es mayor o igual que el segundo número.
2. Verificar e imprimir si el primer número es menor que 100 y el segundo número es mayor que 50.
3. Verificar e imprimir si alguno de los números es igual a 0 o si ambos números son pares.
4. Verificar e imprimir si los dos números no son iguales.
5. Verificar e imprimir si los dos números son pares.

### Ejemplo de ejecución:

#### Entrada:
```bash
Introduce el primer número: 75
Introduce el segundo número: 60
```

#### Salida:

```bash
El primer número es mayor o igual que el segundo número: Sí
El primer número es menor que 100 y el segundo número es mayor que 50: Sí
Uno de los números es 0 o ambos son pares: No
Los dos números son diferentes: Sí
Los dos números son pares: No
```

# Ejercicio E - Descomposición de un Número Entero de 32 Bits en Partes de 8 Bits

- Escribe un programa en **C** que solicite al usuario un número entero de 32 bits y luego imprima las cuatro partes de 8 bits de ese número. 
- El programa debe utilizar desplazamientos de bits y operaciones AND para extraer y mostrar cada parte de 8 bits por separado. 
- Usa la función printBinary proporcionada para imprimir cada parte en binario.

### Requisitos:
1. Solicitar al usuario que ingrese un número entero de 32 bits.
2. Descomponer el número en cuatro partes de 8 bits utilizando desplazamientos de bits y operaciones AND.
3. Usar la función `printBinary` para imprimir cada parte en binario.

### Función Proporcionada:
```c
/*
    Asignar 8 al parámetro positions, si se desean mostrar los 8
    bits menos significativos (primeros). Asignar 32 si se desea ver el número
    de 32 bits completo.
*/
void printBinary(int number, int positions) {
    // Assuming a 32-bit integer
    unsigned int mask = 1 << (positions - 1); // Start with the leftmost bit
    int i = 0;
    while (i < positions) {
        // Print '1' or '0' based on the current bit
        if (number & mask) {
            printf("1");
        } else {
            printf("0");
        }
        // Shift the mask to the right by one bit
        mask >>= 1;
        i++;
    }
    printf("\n");
}
```

### Ejemplo de Ejecución:

#### Entrada:

```bash
Ingrese un número entero de 32 bits: 305419896
```

#### Salida:

```bash
Parte 1 (bits 31-24): 00010010
Parte 2 (bits 23-16): 00101100
Parte 3 (bits 15-8): 01001101
Parte 4 (bits 7-0): 01101000
```
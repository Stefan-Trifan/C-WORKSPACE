# Practica 1 - Elementos Basicos, Operadores y Expresiones

- esta es la primera practica evaluable (del bloque de practicas obligatorias) que cuentan un 40% de la nota final. 
- Habra 3 practicas obligatorias pertenecientes a dicho bloque. 
- En el documento adjunto teneis el enunciado de la primera practica y los detalles de lo que teneis que hacer. 
- Una vez realizada la entrega, se procedera a la realizacion de la tarea asociada a este ejercicio evaluable. Esta tarea consistira en la realizacion de un programa (o varios) inspirado en uno de los realizados en el ejercicio evaluable.
- La calificacion del ejercicio evaluable saldra de esta tarea y la entrega de los programas sera imprescindible para su calificacion.

### Consideraciones y Formato de la entrega

- El alumno realizara la practica de forma individual. Cualquier indicio de copia supondra el suspenso directo de la practica y repercutir directamente en el aprobado de la asignatura.
- Para la realizacion de los programas se puede utilizar cualquier editor, tipo NotePad++. Aplicar los conocimientos basicos adquiridos acerca de las buenas practicas en la programacion con una estructura de los programas correcta. Se debe cuidar tambien la indentacion de las instrucciones para dar claridad y legibilidad del codigo escrito.  
Los archivos generados deben incluirse en un fichero .zip que es el que el alumno debe entregar y subir a BB y que debera estar nombrado de la siguiente manera:

  **NombreAlumno_Apellidos_Practica1_IPR1.zip**

- La entrega debe realizarse en BB antes del **21/10/2024 a las 23:59**. No se admitiran entregas que no sigan el formato descrito anteriormente o que se realicen despues de la fecha indicada. Si no se realiza la entrega el ejercicio se considerara suspenso con una calificacion de 0.

Cualquier duda que tengais podremos resolverla los dias de clase de la semana que viene.

# Ejercicio Evaluable 1

La practica 1 estara formada por los siguientes 5 ejercicios:

A. Clave de tres caracteres  
B. Calificaciones alumnos  
C. Entero de tres cifras  
D. Operaciones aritmeticas, logicas y relacionales  
E. Descomposicion de un Numero Entero de 32 Bits en Partes de 8 Bits  

A continuacion, encontraras los detalles de cada enunciado para escribir el codigo correspondiente. En todos ellos debes realizar el analisis del problema que se plantea, estudiando los datos de entrada que necesitas, plantea a continuacion las sentencias de ejecucion en base a las operaciones que debes realizar y finalmente muestra el resultado.

Se valorara si se ejecuta correctamente, asi como la estructura general, la claridad y la legibilidad. Recuerda siempre utilizar identificadores que sean adecuados y el uso de comentarios. El uso de bucles no es necesario.

# Ejercicio A. Clave de tres caracteres

El programa debera pedir una clave de 3 caracteres separados por guiones al usuario.  

La clave debera contener una letra mayuscula, una letra minuscula y un digito, escritos en cualquier orden.

El programa debera comprobar si la clave es valida o no y mostrar el mensaje correspondiente:  
“Clave correcta” o “Clave incorrecta”.

### Ejemplo de ejecucion:

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

Realiza un programa que determine si un estudiante aprueba o suspende una asignatura en funcion de sus calificaciones en tres pruebas, su examen y su asistencia a clase. 

### El programa debe solicitar:
- **Nota de primera prueba** (0-10)
- **Nota de segunda prueba** (0-10)
- **Nota de tercera prueba** (0-10)
- **Nota examen final** (0-10)
- **Asistencia a clase** (0%-100%)

### Calculo de la nota final:
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

Si se suspende algun apartado, se debe informar al usuario mediante la consola.

### Ejemplos de ejecucion:

```bash
$ ./notas.exe
Nota de la primera prueba: 4.5
Nota de la segunda prueba: 4.7
Nota de la tercera prueba: 5.0
Nota del examen final: 5.0
Nota de asistencia: 0.9
El alumno ha suspendido.
Las pruebas no han superado la nota minima.
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

Desarrolla un programa que pida al usuario un numero entero positivo de tres cifras. El programa debe clasificar el numero en funcion de sus digitos.

### Reglas:
- Si el numero tiene **tres digitos diferentes**, debe mostrar:  
  `"El numero tiene tres digitos unicos."`
- Si el numero tiene **dos digitos iguales**, debe mostrar:  
  `"El numero tiene dos digitos iguales."`
- Si los **tres digitos son iguales**, debe mostrar:  
  `"El numero tiene tres digitos iguales."`

### Ejemplo de ejecucion:

```bash
$ ./digits.exe
Introduce un numero entero positivo de 3 digitos: 100
El numero tiene dos digitos iguales.
```

```bash
$ ./digits.exe
Introduce un numero entero positivo de 3 digitos: 123
El numero tiene tres digitos unicos.
```

# Ejercicio D - Operaciones aritmeticas, logicas y relacionales

Escriba un programa en **C** que solicite al usuario que ingrese dos numeros enteros. Luego, el programa debe usar operadores relacionales y logicos para realizar lo siguiente:

1. Verificar e imprimir si el primer numero es mayor o igual que el segundo numero.
2. Verificar e imprimir si el primer numero es menor que 100 y el segundo numero es mayor que 50.
3. Verificar e imprimir si alguno de los numeros es igual a 0 o si ambos numeros son pares.
4. Verificar e imprimir si los dos numeros no son iguales.
5. Verificar e imprimir si los dos numeros son pares.

### Ejemplo de ejecucion:

#### Entrada:
```bash
Introduce el primer numero: 75
Introduce el segundo numero: 60
```

#### Salida:

```bash
El primer numero es mayor o igual que el segundo numero: Si
El primer numero es menor que 100 y el segundo numero es mayor que 50: Si
Uno de los numeros es 0 o ambos son pares: No
Los dos numeros son diferentes: Si
Los dos numeros son pares: No
```

# Ejercicio E - Descomposicion de un Numero Entero de 32 Bits en Partes de 8 Bits

- Escribe un programa en **C** que solicite al usuario un numero entero de 32 bits y luego imprima las cuatro partes de 8 bits de ese numero. 
- El programa debe utilizar desplazamientos de bits y operaciones AND para extraer y mostrar cada parte de 8 bits por separado. 
- Usa la funcion printBinary proporcionada para imprimir cada parte en binario.

### Requisitos:
1. Solicitar al usuario que ingrese un numero entero de 32 bits.
2. Descomponer el numero en cuatro partes de 8 bits utilizando desplazamientos de bits y operaciones AND.
3. Usar la funcion `printBinary` para imprimir cada parte en binario.

### Funcion Proporcionada:
```c
/*
    Asignar 8 al parametro positions, si se desean mostrar los 8
    bits menos significativos (primeros). Asignar 32 si se desea ver el numero
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

### Ejemplo de Ejecucion:

#### Entrada:

```bash
Ingrese un numero entero de 32 bits: 305419896
```

#### Salida:

```bash
Parte 1 (bits 31-24): 00010010
Parte 2 (bits 23-16): 00101100
Parte 3 (bits 15-8): 01001101
Parte 4 (bits 7-0): 01101000
```
Password Alfanumérica


Crea un programa que en el que el usuario generará o cambiará una password alfanumérica con unas condiciones determinadas y una vez generada introducirá una password y comprobará que sea correcta



Para ello el programa debe:

Presentar un menú que se repetirá hasta que no se le indique que se desea salir. Las opciones del menú dependerán de si el usuario ha generado una password correcta o no
Si no ha generado una clave correcta el menú será:
1.Generar password
2.Introducir password
3.Salir
Si se ha generado una clave correcta el menú será:
1.⁠ ⁠Cambia password
2.⁠ ⁠Introducir passwork
3.⁠ ⁠Salir


La password debe:
Tener un tamaño de más de 8 y menos de 15 caracteres.
Tener al menos dos letras mayúsculas.


Cuando se selecciona las opciones genera o cambia password se debe comprobar que se cumplen las condiciones y si no se cumplen indicárselo al usuario y volver a pedir que ingrese una password que cumpla las condiciones (tamaño y al menos 2 mayúsculas).


Cuando se introduce una password se debe comprobar que esta coincida con la generada. Tanto si coincide como si no se deber informar al usuario y volver a presentar el menú.


Se deben utilizar las siguientes funciones:



//Función que lee del buffer de entrada y salida una cadena de

//como máximo tam caracteres y devuelve el número de caracteres

int leerCadena (char cadena[], int tam);

// Función que genera la contraseña dejándola en una cadena que se

//pasa como parámetro y devuelve verdadero cuando se ha generado

//cumpliendo las medidas pedidas y falso en caso contrario

int generaPassword(char cadena[]);

// Función que se le pasa como parámetro una cadena y devuelve verdadero si tiene 2 letras mayúsculas

int cadena2Mayusculas(char cadena[]);

// Función que se le pasa como parámetros dos cadenas y devuelve verdadero si son iguales y falso si no lo son

int cadenasIguales(char cadena1[], char cadena2[]);

// Función que se le pasa como parámetro una cadena y devuelve el número de caracteres que tiene

int tamCadena (char cadena[]);



Un ejemplo de ejecución puede ser:



./password_menu_red.exe

 

Menú:

1.⁠ ⁠Genera password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opción: 1

Escribe una password de entre 8 y 15 caracteres y al menos dos mayúsculas: Programacion 

La password no tiene al menos dos mayúsculas.

Escribe una password de entre 8 y 15 caracteres y al menos u os mayúsculas: Progra

La password no tiene entre 8 y 15 caracteres.

Escribe una password de entre 8 y 15 caracteres y al menos os mayúsculas: PRogramacion 

Password generada correctamente.

Menú:

1.⁠ ⁠Cambia password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opción: 2

Introduce la password: PRofra

La password es incorrecta.

Menú:

1.⁠ ⁠Cambia password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opción: 2

Introduce la password: PRogramacion 

La password es correcta.

Menú:

1.⁠ ⁠Cambia password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opción: 3

Saliendo del programa.
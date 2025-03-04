Password Alfanumerica


Crea un programa que en el que el usuario generara o cambiara una password alfanumerica con unas condiciones determinadas y una vez generada introducira una password y comprobara que sea correcta



Para ello el programa debe:

Presentar un menu que se repetira hasta que no se le indique que se desea salir. Las opciones del menu dependeran de si el usuario ha generado una password correcta o no
Si no ha generado una clave correcta el menu sera:
1.Generar password
2.Introducir password
3.Salir
Si se ha generado una clave correcta el menu sera:
1.⁠ ⁠Cambia password
2.⁠ ⁠Introducir passwork
3.⁠ ⁠Salir


La password debe:
Tener un tamaño de mas de 8 y menos de 15 caracteres.
Tener al menos dos letras mayusculas.


Cuando se selecciona las opciones genera o cambia password se debe comprobar que se cumplen las condiciones y si no se cumplen indicarselo al usuario y volver a pedir que ingrese una password que cumpla las condiciones (tamaño y al menos 2 mayusculas).


Cuando se introduce una password se debe comprobar que esta coincida con la generada. Tanto si coincide como si no se deber informar al usuario y volver a presentar el menu.


Se deben utilizar las siguientes funciones:



//Funcion que lee del buffer de entrada y salida una cadena de

//como maximo tam caracteres y devuelve el numero de caracteres

int leerCadena (char cadena[], int tam);

// Funcion que genera la contraseña dejandola en una cadena que se

//pasa como parametro y devuelve verdadero cuando se ha generado

//cumpliendo las medidas pedidas y falso en caso contrario

int generaPassword(char cadena[]);

// Funcion que se le pasa como parametro una cadena y devuelve verdadero si tiene 2 letras mayusculas

int cadena2Mayusculas(char cadena[]);

// Funcion que se le pasa como parametros dos cadenas y devuelve verdadero si son iguales y falso si no lo son

int cadenasIguales(char cadena1[], char cadena2[]);

// Funcion que se le pasa como parametro una cadena y devuelve el numero de caracteres que tiene

int tamCadena (char cadena[]);



Un ejemplo de ejecucion puede ser:



./password_menu_red.exe

 

Menu:

1.⁠ ⁠Genera password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opcion: 1

Escribe una password de entre 8 y 15 caracteres y al menos dos mayusculas: Programacion 

La password no tiene al menos dos mayusculas.

Escribe una password de entre 8 y 15 caracteres y al menos u os mayusculas: Progra

La password no tiene entre 8 y 15 caracteres.

Escribe una password de entre 8 y 15 caracteres y al menos os mayusculas: PRogramacion 

Password generada correctamente.

Menu:

1.⁠ ⁠Cambia password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opcion: 2

Introduce la password: PRofra

La password es incorrecta.

Menu:

1.⁠ ⁠Cambia password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opcion: 2

Introduce la password: PRogramacion 

La password es correcta.

Menu:

1.⁠ ⁠Cambia password

2.⁠ ⁠Introducir password

3.⁠ ⁠Salir

Seleccione una opcion: 3

Saliendo del programa.
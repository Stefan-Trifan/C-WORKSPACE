# Enunciado Password Numerica

Crea un programa en el que el usuario generara o cambiara una password numerica con unas condiciones determinadas  
Una vez generada introducira una password y comprobara que sea correcta.

### Para ello el programa debe:

Presentar un menu que se repetira hasta que no se le indique que se desea salir. Las opciones del menu dependeran de si el usuario ha generado una password correcta o no

### Si no ha generado una clave correcta el menu sera:
    1. Generar password
    2. Introducir password
    3. Salir

### Si se ha generado una clave correcta el menu sera:
    1.⁠ ⁠Cambia password  
    2.⁠ ⁠Introducir password  
    3.⁠ ⁠Salir  

### Las condiciones de password correcta son:
- Ser un numero entero de 7 cifras y
- Al menos 3 cifras deben ser pares.

Cuando se selecciona las opciones genera o cambia password se debe comprobar que se cumplen las condiciones y si no se cumplen indicarselo al usuario y volver a pedir que ingrese una password que cumpla las condiciones (7 cifras y al menos 3 pares).  

Cuando se introduce una password se debe comprobar que esta coincida con la generada. Tanto si coincide como si no se deber informar al usuario y volver a presentar el menu.

### Se deben utilizar las siguientes funciones:

Funcion que no se le pasa ningun parametro y devuelve un entero con una passwod correcta  
- int generaPassword();

Funcion que se le pasa como parametro un entero y devuelve verdadero si tiene 7 cifras y falso si no  
- int esNumero7cifras (int numero);

Funcion que se le pasa como parametro un entero y devuelve verdadero si tiene al menos 3 cifras son pares y falso si no  
- int esNumero3pares (int numero);

Funcion que se le pasa como parametros dos enteros y devuelve verdadero si son iguales y falso si no lo son  
- int sonNumerosIguales (int numero1, int numero2);

### Un ejemplo de ejecucion puede ser:

    ./password_menu_red.exe

    Menu:  
    1.⁠ ⁠Genera password  
    2.⁠ ⁠Introducir password  
    3.⁠ ⁠Salir  
    Seleccione una opcion: 1  
    Genera una password de 7 cifras con al menos 3 pares: 1112222  
    Password generada correctamente. 

    Menu:  
    1.⁠ ⁠Cambia password  
    2.⁠ ⁠Introducir password  
    3.⁠ ⁠Salir  
    Seleccione una opcion: 2  
    Introduce la password: 1112222  
    La password es correcta.

    Menu:  
    1.⁠ ⁠Cambia password  
    2.⁠ ⁠Introducir password
    3.⁠ ⁠Salir  
    Seleccione una opcion: 3  
    Saliendo del programa. 
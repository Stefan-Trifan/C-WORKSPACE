/*
	*	Autor
		Stefan Trifan

	* 	Compilar
		mac     : comp (compilar)
				  run  (ejecutar)
				  brun (compilar y ejecutar)
		windows : gcc main.c -o main.exe
				: ./main.exe

	*   Estado: 

	* 	Enunciado X
		LoremIpsum
*/

/* _________________________________________
   Inicio cabecera */

   #include <stdio.h>
   #include <stdlib.h>
   void clearBuffer();
   
   float strtof(const char *str, char **endptr);
   /* _________________________________________
	  Inicio main() */
   
   	int main(int argc, char *argv[]){
	   printf("\n_________________________________________START\n\n");
   
		float num1      = 0,
		      num2      = 0,
		      num3      = 0,
		      num4      = 0,
		      num5      = 0,
		      numMin    = 0,
		      numMax    = 0,
		      temp      = 0,
		      sumaTotal = 0,
		      contNum   = 0;
		char *endptr; 

		contNum = argc;
   
		if(contNum <= 2 || contNum >= 8)
		{
			printf("Uso %s num1 num2 num3\n", argv[0]);
			printf("\n_________________________________________END\n\n");
			return 1;
		}

		// Guardamos en las variables los parametros
		if(argc >= 3)
			num1 = strtof(argv[1], &endptr);
			num2 = strtof(argv[2], &endptr);
		if(argc >= 4)
			num3 = strtof(argv[3], &endptr);
		if(argc >= 5)
			num4 = strtof(argv[4], &endptr);
		if(argc >= 6)
			num5 = strtof(argv[5], &endptr);

		// Buscamos el maximo y el minimoe ntre los 2 primeros
		numMax = numMin = num1;

		// Recorremos
		for(int i = 1; i < contNum; i++)
		{
			sumaTotal += strtof(argv[i], &endptr);

			temp = strtof(argv[i], &endptr);
			if(temp <= numMin)
				numMin = temp;
			if(temp >= numMax)
				numMax = temp;
		}
	
		printf("El numero minimo es:    %f\n", numMin);
		printf("El numero maximo es:    %f\n", numMax);
		printf("La media de los num es: %f\n", sumaTotal / contNum);

	
		printf("\n_________________________________________END\n\n");
		return 0;
  	}
   
   /* _________________________________________
	  Inicio definicion de funciones */
   
	void clearBuffer(){
		while (getchar() != '\n');
	}
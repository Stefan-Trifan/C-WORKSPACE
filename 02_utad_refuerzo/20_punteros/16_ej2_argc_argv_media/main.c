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

	* 	Enunciado
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
		
		float nums[4]   = {0},
		      num1      = 0,
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
   
		if(contNum < 3 || contNum > 6)
		{
			printf("Uso %s num1 num2 num3\n", argv[0]);
			printf("\n_________________________________________EXIT\n\n");
			return 1;
		}

		// Fijamos maximo y minimo el primer elemento
		numMax = strtof(argv[1], &endptr);
		numMin = strtof(argv[1], &endptr);

		for(int i = 1; i < contNum; i++)
		{
			nums[i - 1] = strtof(argv[i], &endptr);
			sumaTotal += nums[i - 1];

			temp = strtof(argv[i], &endptr);
			if(temp <= numMin)
				numMin = temp;
			if(temp >= numMax)
				numMax = temp;
		}
	
		printf("El numero minimo es:              %f\n", numMin);
		printf("El numero maximo es:              %f\n", numMax);
		printf("La media de los num es:           %f\n", sumaTotal / contNum);
		printf("Elemento que no se pudo converir: %c\n", *endptr);

	
		printf("\n_________________________________________EXIT\n\n");
		return 0;
  	}
   
   /* _________________________________________
	  Inicio definicion de funciones */
   
	void clearBuffer(){
		while (getchar() != '\n');
	}
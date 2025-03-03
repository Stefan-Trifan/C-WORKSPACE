/*
    *   Autor
        Stefan Trifan

    *   Estado
        Done

    *   Enunciado 5 
        Partidos de ping pong

    *   Testing
        
*/

/* _________________________________________
   Inicio cabecera */

   #include <stdio.h>

   #define TAM_STR 13
   #define N_JUG 4
   #define N_PARTIDOS 6
   #define RED "\033[1;31m"
   #define GREEN "\033[1;32m"
   #define YELLOW "\033[1;33m"
   #define RESET "\033[0m"
   
   typedef struct jugador_t
   {
	   char nombre[TAM_STR];
	   char apellidos[TAM_STR];
	   int edad;
   }
   jugador_t;
   
   typedef struct fecha_t
   {
	   int dia;
	   int mes;
	   int ano;
	   int hora;
	   int min;
   }
   fecha_t;
   
   typedef struct partido_t
   {
	   jugador_t jugador1;
	   jugador_t jugador2;
	   fecha_t fecha_inicio;
   }
   partido_t;
   
   // Funciones del programa
   void copiarCadena(char *origen, char *destino);
   
   // Funciones auxiliares
   void pedirCadena(char text[]);
   int pedirEnteroPos();
   void clearBuffer();
   
   /* _________________________________________
	  Inicio main() */
   
   int main()
   {
	   printf("\n_________________________________________START\n\n");
   
	   // todo dar estilos tabla y controlar alineacion
   
	   /// Probar el programa desde 0
		   // jugador_t lista_jugadores[N_JUG]     = {0};
		   // fecha_t   fecha_inicio               = {0};
		   // partido_t lista_partidos[N_PARTIDOS] = {0};
   
	   /// testing
		   jugador_t lista_jugadores[N_JUG]  = 
		   {
			   {"Alejandro", "Jose", 19},
			   {"Antionio", "Megan", 22},
			   {"Pepe", "Diego", 22},
			   {"Andres", "Juan", 22}
		   };
		   fecha_t fecha_inicio  = 
		   {
			   12,9,2025,21,29
		   };
		   partido_t lista_partidos[N_PARTIDOS] = {0};
   
   /*     /// Pedimos los datos para cada jugador (4 en total)
	   printf("===== DATOS JUGADORES =====\n\n");
	   for(int i = 0; i < N_JUG; i++)
	   {
		   // Nombre
		   printf(
			   "JUGADOR %d - Ingrese el nombre\n"
			   "(max. %d caracteres) -> ", i + 1, TAM_STR - 1);
		   pedirCadena((lista_jugadores + i)->nombre);
		   printf("\n");    
		   // Apellido
		   printf(
			   "JUGADOR %d - Ingrese apellidos\n"
			   "(max. %d caracteres) -> ", i + 1, TAM_STR - 1);
		   pedirCadena((lista_jugadores + i)->apellidos);
		   printf("\n");    
		   // Edad
		   printf(
			   "JUGADOR %d - Ingrese la edad\n"
			   "-> ", i + 1);
		   (lista_jugadores + i)->edad = pedirEnteroPos();
		   printf("\n");  
	   }
   
	   printf("===== FECHA DEL TORNEO =====\n\n");
   
	   // Pedimos dia/mes/año/hora/min del primer partido
	   // Dia
	   printf("Ingrese el dia\n-> ");
	   do
	   {
		   fecha_inicio.dia = pedirEnteroPos();
		   if(fecha_inicio.dia > 31)
			   printf(YELLOW"ALERTA: Dia no puede ser superior a 31\n-> "RESET);
	   } 
	   while (fecha_inicio.dia > 31);
	   printf("\n");  
   
	   /// Mes
	   printf("Ingrese el mes\n-> ");
	   do
	   {
		   fecha_inicio.mes = pedirEnteroPos();
		   if(fecha_inicio.mes > 12)
			   printf(YELLOW"ALERTA: Mes no puede ser superior a 12\n-> "RESET);
	   } 
	   while (fecha_inicio.mes > 12);
	   printf("\n");
   
	   /// Anio
	   printf("Ingrese el anio\n-> ");
	   do
	   {
		   fecha_inicio.ano = pedirEnteroPos();
		   if(fecha_inicio.ano < 2025 || fecha_inicio.ano > 2100)
			   printf(YELLOW"ALERTA: Anio no puede ser \ninferior a 2024 o superior a 2100\n-> "RESET);
	   } 
	   while (fecha_inicio.ano < 2025 || fecha_inicio.ano > 2100);
	   printf("\n");
   
	   // /// Hora
	   printf("Ingrese la hora de inicio\n-> ");
	   do
	   {
		   fecha_inicio.hora = pedirEnteroPos();
		   if(fecha_inicio.hora > 21)
			   printf(YELLOW"ALERTA: Horas no puede ser superior a 21\n-> "RESET);
	   } 
	   while (fecha_inicio.hora > 21);
	   printf("\n");
   
	   /// Min
	   printf("Ingrese el min de inicio\n-> ");
	   do
	   {
		   fecha_inicio.min = pedirEnteroPos();
		   if(fecha_inicio.hora == 21 && fecha_inicio.min > 29)
		   {
			   printf(YELLOW"ALERTA: El ultimo partido debe ser antes de las 21:29\n-> "RESET);
		   }
		   else if(fecha_inicio.min >= 60)
		   {
			   printf(YELLOW"ALERTA: Minutos no puede ser superior a 59\n-> "RESET);
		   }
	   } 
	   while (fecha_inicio.min >= 60 || (fecha_inicio.hora == 21 && fecha_inicio.min > 29)); 
	   
	   printf("\n\n"); */
	   
	   // Configuramos los participantes de cada partido
	   // Partido 1
	   copiarCadena(lista_jugadores[0].nombre,    lista_partidos[0].jugador1.nombre);
	   copiarCadena(lista_jugadores[0].apellidos, lista_partidos[0].jugador1.apellidos);
	   copiarCadena(lista_jugadores[1].nombre,    lista_partidos[0].jugador2.nombre);
	   copiarCadena(lista_jugadores[1].apellidos, lista_partidos[0].jugador2.apellidos);
	   // Partido 2
	   copiarCadena(lista_jugadores[0].nombre,    lista_partidos[1].jugador1.nombre);
	   copiarCadena(lista_jugadores[0].apellidos, lista_partidos[1].jugador1.apellidos);
	   copiarCadena(lista_jugadores[2].nombre,    lista_partidos[1].jugador2.nombre);
	   copiarCadena(lista_jugadores[2].apellidos, lista_partidos[1].jugador2.apellidos);
	   // Partido 3
	   copiarCadena(lista_jugadores[0].nombre,    lista_partidos[2].jugador1.nombre);
	   copiarCadena(lista_jugadores[0].apellidos, lista_partidos[2].jugador1.apellidos);
	   copiarCadena(lista_jugadores[3].nombre,    lista_partidos[2].jugador2.nombre);
	   copiarCadena(lista_jugadores[3].apellidos, lista_partidos[2].jugador2.apellidos);
	   // Partido 4
	   copiarCadena(lista_jugadores[1].nombre,    lista_partidos[3].jugador1.nombre);
	   copiarCadena(lista_jugadores[1].apellidos, lista_partidos[3].jugador1.apellidos);
	   copiarCadena(lista_jugadores[2].nombre,    lista_partidos[3].jugador2.nombre);
	   copiarCadena(lista_jugadores[2].apellidos, lista_partidos[3].jugador2.apellidos);
	   // Partido 5
	   copiarCadena(lista_jugadores[1].nombre,    lista_partidos[4].jugador1.nombre);
	   copiarCadena(lista_jugadores[1].apellidos, lista_partidos[4].jugador1.apellidos);
	   copiarCadena(lista_jugadores[3].nombre,    lista_partidos[4].jugador2.nombre);
	   copiarCadena(lista_jugadores[3].apellidos, lista_partidos[4].jugador2.apellidos);
	   // Partido 6
	   copiarCadena(lista_jugadores[2].nombre,    lista_partidos[5].jugador1.nombre);
	   copiarCadena(lista_jugadores[2].apellidos, lista_partidos[5].jugador1.apellidos);
	   copiarCadena(lista_jugadores[3].nombre,    lista_partidos[5].jugador2.nombre);
	   copiarCadena(lista_jugadores[3].apellidos,    lista_partidos[5].jugador2.apellidos);
   
	   // Configuramos la fecha de cada partido
	   lista_partidos[0].fecha_inicio.dia = fecha_inicio.dia;
	   lista_partidos[0].fecha_inicio.mes = fecha_inicio.mes;
	   lista_partidos[0].fecha_inicio.ano = fecha_inicio.ano;
	   lista_partidos[0].fecha_inicio.hora = fecha_inicio.hora;
	   lista_partidos[0].fecha_inicio.min = fecha_inicio.min;
	   for(int i = 1; i < 6; i++)
	   {
		   lista_partidos[i].fecha_inicio.dia = fecha_inicio.dia;
		   lista_partidos[i].fecha_inicio.mes = fecha_inicio.mes;
		   lista_partidos[i].fecha_inicio.ano = fecha_inicio.ano;
   
		   if(lista_partidos[i - 1].fecha_inicio.min + 30 >= 60)
		   {
			   lista_partidos[i].fecha_inicio.hora = lista_partidos[i - 1].fecha_inicio.hora + 1;
			   lista_partidos[i].fecha_inicio.min = lista_partidos[i - 1].fecha_inicio.min + 30 - 60;
		   }
		   else
		   {
			   lista_partidos[i].fecha_inicio.hora = lista_partidos[i - 1].fecha_inicio.hora;
			   lista_partidos[i].fecha_inicio.min = lista_partidos[i - 1].fecha_inicio.min + 30;
		   } 
	   }
   
	   // Imprimimos los partidos
	   printf(
		   "===== PARTIDOS =====\n\n"
		   "+---------+----------------------------+---------------------------------+\n"
		   "| PARTIDO |         JUGADORES          |              FECHA              |\n"
		   "+---------+----------------------------+---------------------------------+\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "|    1    |             vs             |     %2d/%2d/%2d a las %2d:%2d      |\n"                       
		   "|         | %12s  %-12s |                                 |\n"
		   "+---------+----------------------------+---------------------------------+\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "|    2    |             vs             |     %2d/%2d/%2d a las %2d:%2d      |\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "+---------+----------------------------+---------------------------------+\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "|    3    |             vs             |     %2d/%2d/%2d a las %2d:%2d      |\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "+---------+----------------------------+---------------------------------+\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "|    4    |             vs             |     %2d/%2d/%2d a las %2d:%2d      |\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "+---------+----------------------------+---------------------------------+\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "|    5    |             vs             |     %2d/%2d/%2d a las %2d:%2d      |\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "+---------+----------------------------+---------------------------------+\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "|    6    |             vs             |     %2d/%2d/%2d a las %2d:%2d      |\n"
		   "|         | %12s  %-12s |                                 |\n"
		   "+---------+----------------------------+---------------------------------+\n",
		   lista_partidos[0].jugador1.nombre,
		   lista_partidos[0].jugador1.apellidos,
		   lista_partidos[0].fecha_inicio.dia,
		   lista_partidos[0].fecha_inicio.mes,
		   lista_partidos[0].fecha_inicio.ano,
		   lista_partidos[0].fecha_inicio.hora,
		   lista_partidos[0].fecha_inicio.min,
		   lista_partidos[0].jugador2.nombre,
		   lista_partidos[0].jugador2.apellidos,
		   
   
		   lista_partidos[1].jugador1.nombre,
		   lista_partidos[1].jugador1.apellidos,
		   lista_partidos[1].fecha_inicio.dia,
		   lista_partidos[1].fecha_inicio.mes,
		   lista_partidos[1].fecha_inicio.ano,
		   lista_partidos[1].fecha_inicio.hora,
		   lista_partidos[1].fecha_inicio.min,
		   lista_partidos[1].jugador2.nombre,
		   lista_partidos[1].jugador2.apellidos,
   
		   lista_partidos[2].jugador1.nombre,
		   lista_partidos[2].jugador1.apellidos,
		   lista_partidos[2].fecha_inicio.dia,
		   lista_partidos[2].fecha_inicio.mes,
		   lista_partidos[2].fecha_inicio.ano,
		   lista_partidos[2].fecha_inicio.hora,
		   lista_partidos[2].fecha_inicio.min,
		   lista_partidos[2].jugador2.nombre,
		   lista_partidos[2].jugador2.apellidos,
		   
   
		   lista_partidos[3].jugador1.nombre,
		   lista_partidos[3].jugador1.apellidos,
		   lista_partidos[3].fecha_inicio.dia,
		   lista_partidos[3].fecha_inicio.mes,
		   lista_partidos[3].fecha_inicio.ano,
		   lista_partidos[3].fecha_inicio.hora,
		   lista_partidos[3].fecha_inicio.min,
		   lista_partidos[3].jugador2.nombre,
		   lista_partidos[3].jugador2.apellidos,
		   
   
		   lista_partidos[4].jugador1.nombre,
		   lista_partidos[4].jugador1.apellidos,
		   lista_partidos[4].fecha_inicio.dia,
		   lista_partidos[4].fecha_inicio.mes,
		   lista_partidos[4].fecha_inicio.ano,
		   lista_partidos[4].fecha_inicio.hora,
		   lista_partidos[4].fecha_inicio.min,
		   lista_partidos[4].jugador2.nombre,
		   lista_partidos[4].jugador2.apellidos,
		   
   
		   lista_partidos[5].jugador1.nombre,
		   lista_partidos[5].jugador1.apellidos,
		   lista_partidos[5].fecha_inicio.dia,
		   lista_partidos[5].fecha_inicio.mes,
		   lista_partidos[5].fecha_inicio.ano,
		   lista_partidos[5].fecha_inicio.hora,
		   lista_partidos[5].fecha_inicio.min,
		   lista_partidos[5].jugador2.nombre,
		   lista_partidos[5].jugador2.apellidos);
   
	   printf("\n_________________________________________END\n\n");
	   return 0;
   }
   
   /* _________________________________________
	  Inicio definicion de funciones */
   
   // Funciones del programa
   void copiarCadena(char *origen, char *destino)
   {
	   int j = 0;
	   while(origen[j] != '\0')
	   {
		   destino[j] = origen[j];
		   j++;
	   }
	   destino[j] = '\0';
   }
   
   // Funciones auxiliares
   void pedirCadena(char text[])
   {
	   /*  DEBUG
	   entrada:rojo\n
		   i: 4
		   c: o
	   text[i]: o
	   */
	   int esValido, i;
	   char c;
	   do
	   {
		   esValido = 1;
		   i = 0;
		   while(i < TAM_STR - 1)
		   {
			   c = getchar();
   
			   if(c == '\n') break;
		   
			   text[i] = c;
			   i++;
		   }
		   text[i] = '\0';
   
		   if(i == TAM_STR - 1 )
		   {
			   c = getchar();
			   if(c != '\n')
			   {
				   printf(YELLOW
					   "ALERTA: Has superado el limite de %d caracteres\n"
					   "-> "RESET, TAM_STR - 1);
				   clearBuffer();
				   esValido = 0;
			   }
		   }
	   } 
	   while (esValido != 1);
   }
   
   int pedirEnteroPos()
   {
	   int num = 0, esValido = 0;
	   do
	   {
		   esValido = scanf("%d", &num);
		   clearBuffer();
		   if(esValido != 1 || num < 0)
		   {
			   printf(YELLOW
				   "ALERTA: El numero debe ser mayor o igual a 0\n"
				   "-> "RESET);
			   esValido = 0;
		   }
	   } 
	   while (esValido != 1);
	   return num;
   }
   
   void clearBuffer()
   {
	   while (getchar() != '\n');
   }
   
   /* DEBUG LOG
   
	   // DEBUG imprimimos los jugadores
	   printf(
		   "===== DATOS JUGADORES =====\n\n"
		   "lista_jugadores[0].nombre    : %s\n"
		   "lista_jugadores[0].apellidos : %s\n"
		   "lista_jugadores[0].edad      : %d\n\n"
		   "lista_jugadores[1].nombre    : %s\n"
		   "lista_jugadores[1].apellidos : %s\n"
		   "lista_jugadores[1].edad      : %d\n\n"
		   "lista_jugadores[2].nombre    : %s\n"
		   "lista_jugadores[2].apellidos : %s\n"
		   "lista_jugadores[2].edad      : %d\n\n"
		   "lista_jugadores[3].nombre    : %s\n"
		   "lista_jugadores[3].apellidos : %s\n"
		   "lista_jugadores[4].edad      : %d\n\n",
		   lista_jugadores[0].nombre,
		   lista_jugadores[0].apellidos,
		   lista_jugadores[0].edad,
		   lista_jugadores[1].nombre,
		   lista_jugadores[1].apellidos,
		   lista_jugadores[1].edad,
		   lista_jugadores[2].nombre,
		   lista_jugadores[2].apellidos,
		   lista_jugadores[2].edad,
		   lista_jugadores[3].nombre,
		   lista_jugadores[3].apellidos,
		   lista_jugadores[3].edad);
		   
	   // DEBUG imprimimos las fechas
	   printf(
		   "===== FECHA =====\n\n"
		   "Fecha : %d/%d/%d a las %d:%d\n\n",
		   fecha_inicio.dia, fecha_inicio.mes, fecha_inicio.ano, fecha_inicio.hora, fecha_inicio.min);
   
   */
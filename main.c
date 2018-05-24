/*/////////////////////////////////////////////

  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99
  REQUIERE C99

////////////////////////////////////////////////*/

// BIBLIOTECAS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>                                                            // Libreria usada para el Sleep ELIMINAR SI SE USA EN LINUX. SUSTINUIR "Sleep(3000);" por "sleep(3);"

//MACROS
#define resolucion 36                                                           // Define la cantdad de espacio que define un "Limpiado de pantalla 
  // MACROS PARA FUNCIÓN "CINE"
    #define cine_filas_asientos 4
    #define cine_columnas_asientos 4

// Definiciones de funciones principales
void promedios_de_lluvias(void);
void cine(void);
void datos_estadisticos(void);


// Definiciones de funciones miscelaneas

  // FUNCIÓN DISEÑADA PARA LIMPIAR EL BUFFER DE STDIN
  void limpiar_buffer(void);

  // FUNCIÓN DISEÑADA QUE COLOCA UN NUMERO "N" DE ESPACIOS ESPECIFICADO POR EL NUMERO ESPACIO INTRODUCIDO
  void colocar_n_espacios(unsigned int numero_espacios);

  // VERIFICA SI EL INTERO ESTA EN RANGO
  bool verificar_si_entero_esta_en_rango(int numero_a_verificar, int rango_inferior, int rango_superior);


///////////////////////////////////////////////////////////////////////////////
//                        INICIO FUNCIÓN "MAIN"                              //
///////////////////////////////////////////////////////////////////////////////


int main(void)
{
  int decision;
  bool se_limpia_buffer = 0;

  for(;;)                                                                        // CICLO "INFINITO" PARA REPETIR VARIAS VECES EL MENÚ
  {
    if(se_limpia_buffer)                                                        // limpia el buffer solo una vez
      {
        limpiar_buffer();
        colocar_n_espacios(resolucion);
      }
    else
      se_limpia_buffer = true;

    printf("¿Qué número de programa quieres ejecutar?\n"
            "\t1. Programa: PROMEDIOS DE LLUVIAS\n"
            "\t2. Programa: CINE\n"
            "\t3. Programa: DATOS ESTADÍSTICOS\n"
            "\t0. SALIR\n\n"
            "Introduce tu decisión: "
          );

    scanf("%d",&decision);

    switch (decision) {
      case 0:
        printf("\n¡Regresa pronto!\n");
        goto terminar_programa;
      case 1:
        colocar_n_espacios(resolucion);
        printf("EJECUCIÓN DEL PROGRAMA 1: PROMEDIOS DE LLUVIAS\n");
        promedios_de_lluvias();
        break;
      case 2:
        colocar_n_espacios(resolucion);
        printf("EJECUCIÓN DEL PROGRAMA 2: CINE\n");
        cine();
        break;
      case 3:
        colocar_n_espacios(resolucion);
        printf("EJECUCIÓN DEL PROGRAMA 3: DATOS ESTADÍSTICOS\n");
        datos_estadisticos();
        break;
      default:
        printf("¡Opción no válida!¡Intente de nuevo! Presiona una tecla para continuar.\n");
        getchar();
        colocar_n_espacios(resolucion);
        break;                                                                  // Break no necesario, colocado unicamente por fines de código fuente (Se sigue una convecion similar en todo el programa)
    }
  }

  terminar_programa:                                                            // Bandera para terminar programa

  return 0;                                                                     // Fin del programa
}


///////////////////////////////////////////////////////////////////////////////
//                           FIN FUNCIÓN "MAIN"                              //
///////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
//                           FUNCIONES MISCELANEAS                           //
///////////////////////////////////////////////////////////////////////////////

void limpiar_buffer(void)
{
	char c;

	while((c = getchar()) != '\n' && c != EOF)
		;
}

void colocar_n_espacios(unsigned numero_espacios)
{
  for(int i = 0; i < numero_espacios; i++)
    printf("\n");
}

bool verificar_si_entero_esta_en_rango(int numero_a_verificar, int rango_inferior, int rango_superior)
{
  if(numero_a_verificar >= rango_inferior)
    if(numero_a_verificar <= rango_superior)
      return true;
    else
      return false;
  else
    return false;
}


///////////////////////////////////////////////////////////////////////////////
//                           PROGRAMAS A EJECUTAR                            //
///////////////////////////////////////////////////////////////////////////////


void promedios_de_lluvias(void)
{
  float norte[4][7], centro[4][7], sur[4][7], registro_sur[4]={0}, registro_norte[4]={0}, prom_centro, conta_centro=0, conta_norte=0, conta_sur=0, comparador_sur=0, comparador_norte=0; 
	int i, j, k, renglon_menor_registro_sur, renglon_mayor_registro_norte;
	
	printf("\n\n\tCentro Metereologico Nacional\n\tIngrese los registros de lluvias solicitados.");
		for(i=0; i<4; i++)
		{
			for(j=0; j<7; j++)
			{
				if(j==0)
				{
					printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Norte el dia Lunes: ", i+1);
					scanf("%f", &norte[i][j]);
					conta_norte+=norte[i][j];
					printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Centro el dia Lunes: ", i+1);
					scanf("%f", &centro[i][j]);
					conta_centro+=centro[i][j];
					printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Sur el dia Lunes: ", i+1);
					scanf("%f", &sur[i][j]);
					conta_sur+=sur[i][j];
				}
				else
				{
					if(j==1)
					{
						printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Norte el dia Martes: ", i+1);
						scanf("%f", &norte[i][j]);
						conta_norte+=norte[i][j];
						printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Centro el dia Martes: ", i+1);
						scanf("%f", &centro[i][j]);
						conta_centro+=centro[i][j];
						printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Sur el dia Martes: ", i+1);
						scanf("%f", &sur[i][j]);
						conta_sur+=sur[i][j];
					}
					else
					{
						if(j==2)
						{
							printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Norte el dia Miercoles: ", i+1);
							scanf("%f", &norte[i][j]);
							conta_norte+=norte[i][j];
							printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Centro el dia Miercoles: ", i+1);
							scanf("%f", &centro[i][j]);
							conta_centro+=centro[i][j];
							printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion sur el dia Miercoles: ", i+1);
							scanf("%f", &sur[i][j]);
							conta_sur+=sur[i][j];
						}
						else
						{
							if(j==3)
							{
								printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Norte el dia Jueves: ", i+1);
								scanf("%f", &norte[i][j]);
								conta_norte+=norte[i][j];
								printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Centro el dia Jueves: ", i+1);
								scanf("%f", &centro[i][j]);
								conta_centro+=centro[i][j];
								printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Sur el dia Jueves: ", i+1);
								scanf("%f", &sur[i][j]);
								conta_sur+=sur[i][j];
							}
							else
							{
								if(j==4)
								{
									printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Norte el dia Viernes: ", i+1);
									scanf("%f", &norte[i][j]);
									conta_norte+=norte[i][j];
									printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Centro el dia Viernes: ", i+1);
									scanf("%f", &centro[i][j]);
									conta_centro+=centro[i][j];
									printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Sur el dia Viernes: ", i+1);
									scanf("%f", &sur[i][j]);
									conta_sur+=sur[i][j];
								}
								else
								{
									if(j==5)
									{
										printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Norte el dia Sabado: ", i+1);
										scanf("%f", &norte[i][j]);
										conta_norte+=norte[i][j];
										printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Centro el dia Sabado: ", i+1);
										scanf("%f", &centro[i][j]);
										conta_centro+=centro[i][j];
										printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Sur el dia Sabado: ", i+1);
										scanf("%f", &sur[i][j]);
										conta_sur+=sur[i][j];
									}
									else
									{																								
										printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Norte el dia Domingo: ", i+1);
										scanf("%f", &norte[i][j]);
										conta_norte+=norte[i][j];
										printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Centro el dia Domingo: ", i+1);
										scanf("%f", &centro[i][j]);
										conta_centro+=centro[i][j];
										printf("\n\n\tPara la semana %d ingrese la cantidad de lluvia caida en la\n\tRegion Sur el dia Domingo: ", i+1);
										scanf("%f", &sur[i][j]);
										conta_sur+=sur[i][j];
									}
									
								}
							}
						}
					}
				}
			}
		}
//Aqui se respondera el inciso A
	prom_centro=conta_centro/28;
	printf("\n\n\tEl promedio mensual de lluvias de la Region Centro fue de: %.2f", prom_centro);
	
//Aqui se responde el inciso B.
//Contadores para responder incisos B y C	

		for(i=0; i<4; i++)
		{
			if(i==0)
					for(j=0; j<7; j++)
					{
						registro_sur[0]+=sur[i][j];
						registro_norte[0]+=norte[i][j];
					}
			else
			{
				if(i==1)
					for(j=0; j<7; j++)
					{
						registro_sur[1]+=sur[i][j];
						registro_norte[1]+=norte[i][j];
					}
				else
				{
					if(i==2)
						for(j=0; j<7; j++)
						{
							registro_sur[2]+=sur[i][j];
							registro_norte[2]+=norte[i][j];
						}
					else
					{
						if(i==3)
							for(j=0; j<7; j++)
							{
								registro_sur[3]+=sur[i][j];
								registro_norte[3]+=norte[i][j];
							}
					}
						
				}
			}
		}
	
	comparador_sur=conta_sur;
	
	//Condicional para responder inciso B y C
		for(k=0; k<4; k++)
		{
	
			if(comparador_sur>registro_sur[k])
			{
				comparador_sur=registro_sur[k];
				renglon_menor_registro_sur=k;
			}
			if(comparador_norte<registro_norte[k])
			{
				comparador_norte=registro_norte[k];
				renglon_mayor_registro_norte=k;
			}
		}
		//Impresion de los registros solicitados en los incisos B y C
		//Inciso B
		
		printf("\n\n\tLa semana con menor lluvia en la Region Sur fue la semana %d con el siguiente registro:", renglon_menor_registro_sur+1);
			for(i=renglon_menor_registro_sur; i<renglon_menor_registro_sur+1; i++)
			{
				for(j=0; j<7; j++)
				{
					if(j==0)
						printf("\n\tLunes con %.2f mm de lluvia.", sur[i][j]);
					else
					{
						if(j==1)
							printf("\n\tMartes con %.2f mm de lluvia.", sur[i][j]);
						else
						{
							if(j==2)
								printf("\n\tMiercoles con %.2f mm de lluvia.", sur[i][j]);
							else
							{
								if(j==3)
									printf("\n\tJueves con %.2f mm de lluvia.", sur[i][j]);
								else
								{
									if(j==4)
										printf("\n\tViernes con %.2f mm de lluvia.", sur[i][j]);
									else
									{
										if(j==5)
											printf("\n\tSabado con %.2f mm de lluvia.", sur[i][j]);
										else
										{
											printf("\n\tDomingo con %.2f mm de lluvia.", sur[i][j]);
										}
									}
								}
							}
						}
					}
				}
			}
		
		
		//Inciso C
		printf("\n\n\tLa semana con mayor lluvia en la Region Norte fue la semana %d con el siguiente registro:", renglon_mayor_registro_norte+1);
				for(i=renglon_mayor_registro_norte; i<renglon_mayor_registro_norte+1; i++)
				{
					for(j=0; j<7; j++)
					{
						if(j==0)
							printf("\n\tLunes con %.2f mm de lluvia.", norte[i][j]);
						else
						{
							if(j==1)
								printf("\n\tMartes con %.2f mm de lluvia.", norte[i][j]);
							else
								{
									if(j==2)
										printf("\n\tMiercoles con %.2f mm de lluvia.", norte[i][j]);
									else
									{
										if(j==3)
											printf("\n\tJueves con %.2f mm de lluvia.", norte[i][j]);
										else
										{
											if(j==4)
												printf("\n\tViernes con %.2f mm de lluvia.", norte[i][j]);
											else
											{
												if(j==5)
													printf("\n\tSabado con %.2f mm de lluvia.", norte[i][j]);
												else
												{
													printf("\n\tDomingo con %.2f mm de lluvia.", norte[i][j]);
												}
											}
										}
									}
								}
						}
					}
				}
	//Aqui se responde el inciso D

		if(conta_norte>conta_centro && conta_norte>conta_sur)
				printf("\n\n\tLa region con mayor lluvia mensual fue la Region Norte.");
			else
				if(conta_centro>conta_norte && conta_centro>conta_sur)
					printf("\n\n\tLa region con mayor lluvia mensual fue la Region Centro.");
				else
					printf("\n\n\tLa region con mayor lluvia mensual fue la Region Sur.");

}







void cine(void)
{

  /////////////////////// INICIO DE DECLARACIONES /////////////////////////////


  // Ya se escriben los espacios en la funcion main();
  // HEADER

  printf("CINE\n");

  //Declaración de variables generales:
  int menu_3D_o_2D;
  bool se_limpia_buffer = 0;
  int fila_deseada, adulto_o_nino, columna_deseada_int = -1;                    // Columna deseada int se marca para indicar que no fue encontrada la columna
  char columna_deseada_char;


  int confirmacion, comprar_boleto;

  // Las dos salas tienen la misma cantidad de columnas y comparten la misma etiqueta


  char sala_etiqueta_columnas[cine_columnas_asientos] =
      {'A','B','C','D'};                                                          // Es necesario modifica en caso de más filas y columnas


  // Variables para sala convencional
  int boletos_vendidos_2D = 0, boletos_vendidos_2D_adultos = 0,
  boletos_vendidos_2D_infantes = 0 ;
  float boletos_vendidos_2D_subtotal = 0;

    // Arreglo de la sala 2D
    int  sala_2D[cine_filas_asientos][cine_columnas_asientos] = {0};


  // Variables para la sala tridimensional

  int boletos_vendidos_3D = 0, boletos_vendidos_3D_adultos = 0,
  boletos_vendidos_3D_infantes = 0 ;
  float boletos_vendidos_3D_subtotal = 0;

    // Arreglo de la sala 3D
    int  sala_3D[cine_filas_asientos][cine_columnas_asientos] = {0};

  ////////////////////////// FIN  DE DECLARACIONES /////////////////////////////


  for(;;)                                                                        // CICLO INFINITO PARA EL MENU GENERAL
  {


    if(se_limpia_buffer)                                                        //No limpia la primera vez el buffer, el resto sí. Los primeros espacio son colocados por main()
      {
        limpiar_buffer();
        colocar_n_espacios(resolucion);
      }
    else
      se_limpia_buffer = true;

    ////////////////// IMPRESION DEL MENU //////////////////////////////////////

    printf("\t\t¡Hola! Bienvenido al Cine. Elige una opción:\n");

    printf("\t\t\t 1. Comprar boletos para la sala convencional (Boleto $50 Adulto)\n"
           "\t\t\t 2. Comprar boletos para la sala 3D (Boleto $100 Adulto)\n"
           "\t\t\t 3. Mostrar estadisticas de las salas\n"
           "\t\t\t 0. Salir al menú de programas\n"
        "\n\t\t\tIntroduce tu elección: "
      );

    ////////////////// FIN DE IMPRESIÓN DE MENÚ ////////////////////////////////



    scanf("%d", &menu_3D_o_2D);                                                 // Este scanf se "traga" el caracter de linea nueva residuo de la elección del programa. Lee la decision del usuario.

    switch (menu_3D_o_2D)                                                       // Este switch permite determinar que menú se muestra. Se ecuentra dentro de un for infinito
    {
      case 0:
        return;                                                                 // Caso en donde el usuario quiere regresar al menu de programas


      case 1:

        for(;;)                                                                 // Ciclo for infinito para el menu de la sala convencional
        {
          if(boletos_vendidos_2D < cine_filas_asientos*cine_columnas_asientos)  // Revisa si la sala no esta llena si esta llena, coloca espacio (limpia pantalla),
                                                                                // menciona que la sala ya esta llena y rompe el ciclo del menu de la sala con break;
          {

            //////////////////// IMPRESION DE LA SALA //////////////////////////

            colocar_n_espacios(resolucion);
            printf("Esta es la sala de cine convencional:\n");
            colocar_n_espacios(10);


            printf("\t\t\t");

            for (int i = 0; i < cine_columnas_asientos; i++)                    //Imprime eiquetas
              printf("\t%c", sala_etiqueta_columnas[i]);

            printf("\n");

            for (int i = 0; i < cine_filas_asientos; i++)                       // Imprime las filas
            {
              printf("\t\t\t");
              printf("%d", i+1);
              for (int j= 0; j < cine_columnas_asientos; j++)                   // Imprime columnas
                printf("\t%d", sala_2D[i][j]);
              printf("\n");
            }

            ///////////////// FIN IMPRESION DE LA SALA /////////////////////////



            colocar_n_espacios(5);

            printf("¿Desea comprar un asiento o regresar al menú? (1 = Comprar boleto, 2 = Regresar): ");
              scanf("%d", &comprar_boleto);
            if(comprar_boleto == 1)
            {
              printf("Estos son los asientos disponibles. ¿Qué asiento desea? \n "
                        "\t Introduzca la fila que desea: ");
                scanf("%d", &fila_deseada);

              printf("\t Introduzca la columna que desea: ");
                scanf(" %c", &columna_deseada_char);


              printf("El asiento que selecciono es %c%d. ¿Es correcto? (1 = Si, 2=No): ", columna_deseada_char, fila_deseada);
                scanf("%d", &confirmacion);

                if(confirmacion == 1)                                           // boleto confirmado!
                  {

                    columna_deseada_int = -1;                                   // Permite determinar si el caracter de columna es correcto (se encuentra en las etiquetas)
                    for(int t = 0; t < cine_columnas_asientos; t++)             // Le asigna un numero al caracter de la columna
                      if(columna_deseada_char == sala_etiqueta_columnas[t])
                        columna_deseada_int = t+1;


                    if(verificar_si_entero_esta_en_rango(fila_deseada, 1, cine_filas_asientos) &&
                       verificar_si_entero_esta_en_rango(columna_deseada_int, 1, cine_columnas_asientos))  // Verifica si el asiento se ecuentra en rango

                    {
                      if(sala_2D[fila_deseada-1][columna_deseada_int-1] == 0)   // Verifica si el aciento esta disponible, notese los menos 1
                        {
                        printf("¡Este asiento esta disponible!\n");
                        printf("¿Desea un boleto para adulto ($50) o para niño ($30)? (1 = Adulto, 2 = Niño): ");
                          scanf("%d", &adulto_o_nino);

                        if (adulto_o_nino == 1)
                        {
                          printf("Compro un boleto de adulto\n");
                          sala_2D[fila_deseada-1][columna_deseada_int-1] = 1;
                          boletos_vendidos_2D++;
                          boletos_vendidos_2D_adultos++;
                          boletos_vendidos_2D_subtotal += 50;
                        }
                        else if(adulto_o_nino == 2)
                          {
                            printf("Compro un boleto de niño\n");
                            sala_2D[fila_deseada-1][columna_deseada_int-1] = 1;
                            boletos_vendidos_2D++;
                            boletos_vendidos_2D_infantes++;
                            boletos_vendidos_2D_subtotal += 30;
                          }
                        else
                          {
                            printf("OPCION NO VÁLIDA\n");
                            Sleep(3000);
                            continue;                                           // Regresa al menu de la sala
                          }

                        }
                      else                                                      // Lo que pasa si el aciento no esta disponible
                      {
                        printf("Este asiento no esta disponieble ingrese otro\n");
                        Sleep(3000);
                        continue;                                               // Regresa al menu de la sala
                      }
                    }
                  }
                else                                                            // Si el boleto no se confirma,
                  continue;                                                     // Se regresa al inicio del ciclo del menu de la sala convencional
            }
            else                                                                // Lo que sucede si el boleto no esta confirmado
              break;                                                            // Regresa al menu de la sala
          }

          else
          {
              colocar_n_espacios(resolucion);
              colocar_n_espacios(10);
              printf("\t\t\t¡La sala ya esta llena!\n");                        // !!!!!!!!!!!!!! ANTENCIÓN !!!!!!!!!!!!!!! (La sigueinte inst. posible incopatibilidad entre Windows y otros OS)
              Sleep(3000);                                                      // Espera 3 segundos. !!!!!!!!!!!!!!!!! REMPLAZAR POR "sleep(3);" si se usa un sistema con POSIX !!!!!!!!!!!
              break;                                                            // Termina el ciclo for infinito de la sala convencional
            }
        }

        break;                                                                  // Termina el caso '1' (Sala convencional)
      case 2:

        for(;;)                                                                 // Ciclo for infinito para el menu de la sala 3D
        {
          if(boletos_vendidos_3D < cine_filas_asientos*cine_columnas_asientos)  // Revisa si la sala no esta llena si esta llena, coloca espacio (limpia pantalla),
                                                                                // menciona que la sala ya esta llena y rompe el ciclo del menu de la sala con break;
          {

            //////////////////// IMPRESION DE LA SALA //////////////////////////

            colocar_n_espacios(resolucion);
            printf("Esta es la sala de cine 3D:\n");
            colocar_n_espacios(10);


            printf("\t\t\t");

            for (int i = 0; i < cine_columnas_asientos; i++) //Imprime eiquetas
              printf("\t%c", sala_etiqueta_columnas[i]);

            printf("\n");

            for (int i = 0; i < cine_filas_asientos; i++) // Imprime las filas
            {
              printf("\t\t\t");
              printf("%d", i+1);
              for (int j= 0; j < cine_columnas_asientos; j++)
                printf("\t%d", sala_3D[i][j]);
              printf("\n");
            }

            ///////////////// FIN IMPRESION DE LA SALA /////////////////////////

            colocar_n_espacios(5);

            printf("¿Desea comprar un asiento o regresar al menú? (1 = Comprar boleto, 2 = Regresar): ");
              scanf("%d", &comprar_boleto);
            if(comprar_boleto == 1)
            {
              printf("Estos son los asientos disponibles. ¿Qué asiento desea? \n "
                        "\t Introduzca la fila que desea: ");
                scanf("%d", &fila_deseada);

              printf("\t Introduzca la columna que desea: ");
                scanf(" %c", &columna_deseada_char);


              printf("El asiento que selecciono es %c%d. ¿Es correcto? (1 = Si, 2=No): ", columna_deseada_char, fila_deseada);
                scanf("%d", &confirmacion);

                if(confirmacion == 1)                                           // boleto confirmado!
                  {
                    columna_deseada_int = -1;                                   // Permite determinar si el caracter de columna es correcto (se encuentra en las etiquetas)
                    for(int t = 0; t < cine_columnas_asientos; t++)             // Le asigna un numero al caracter de la columna
                      if(columna_deseada_char == sala_etiqueta_columnas[t])
                        columna_deseada_int = t+1;

                    if(verificar_si_entero_esta_en_rango(fila_deseada, 1, cine_filas_asientos) &&
                       verificar_si_entero_esta_en_rango(columna_deseada_int, 1, cine_columnas_asientos))  // Verifica si el asiento se ecuentra en rango
                    {
                      if(sala_3D[fila_deseada-1][columna_deseada_int-1] == 0)   // Verifica si el aciento esta disponible, notese los menos 1
                        {
                        printf("¡Este asiento esta disponible!\n");
                        printf("¿Desea un boleto para adulto ($100) o para niño ($60)? (1 = Adulto, 2 = Niño): ");
                          scanf("%d", &adulto_o_nino);

                        if (adulto_o_nino == 1)
                        {
                          printf("Compro un boleto de adulto\n");
                          sala_3D[fila_deseada-1][columna_deseada_int-1] = 1;
                          boletos_vendidos_3D++;
                          boletos_vendidos_3D_adultos++;
                          boletos_vendidos_3D_subtotal += 100;
                        }
                        else if(adulto_o_nino == 2)
                          {
                            printf("Compro un boleto de niño\n");
                            sala_3D[fila_deseada-1][columna_deseada_int-1] = 1;
                            boletos_vendidos_3D++;
                            boletos_vendidos_3D_infantes++;
                            boletos_vendidos_3D_subtotal += 60;
                          }
                        else
                          {
                            printf("OPCION NO VÁLIDA\n");
                            Sleep(3000);
                            continue;                                           // Regresa al menu de la sala
                          }

                        }
                      else                                                      // Lo que pasa si el aciento no esta disponible
                      {
                        printf("Este asiento no esta disponieble ingrese otro\n");
                        Sleep(3000);
                        continue;                                               // Regresa al menu de la sala
                      }
                    }
                  }
                else                                                            // Si el boleto no se confirma,
                  continue;                                                     // Se regresa al inicio del ciclo del menu de la sala 3D
            }
            else                                                                // Lo que sucede si el boleto no esta confirmado
              break;                                                            // Regresa al menu de la sala
          }
          else
          {
              colocar_n_espacios(resolucion);
              colocar_n_espacios(10);
              printf("\t\t\t¡La sala ya esta llena!\n");                        // !!!!!!!!!!!!!! ANTENCIÓN !!!!!!!!!!!!!!! (La sigueinte inst. posible incopatibilidad entre Windows y otros OS)
              Sleep(3000);                                                      // Espera 3 segundos. !!!!!!!!!!!!!!!!! REMPLAZAR POR "sleep(3);" si se usa un sistema con POSIX !!!!!!!!!!!
              break;                                                            // Termina el ciclo for infinito de la sala 3D
            }
        }                                                                       // Termina el caso '2' (Sala 3D)

        break;



      case 3:                                                                    // Impresión de las estadísticas de las salas
        colocar_n_espacios(resolucion);
        printf("Estos son los datos de la sala convencional:\n");
          printf("\tBoletos vendidos: %d\n", boletos_vendidos_2D);
            printf("\t\tBoletos vendidos de adultos: %d\n", boletos_vendidos_2D_adultos);
            printf("\t\tBoletos vendidos de niños: %d\n", boletos_vendidos_2D_infantes);
          printf("\tSubtotal de la sala: %.2f\n", boletos_vendidos_2D_subtotal);

        colocar_n_espacios(10);
        printf("Estos son los datos de la sala 3D:\n");
          printf("\tBoletos vendidos: %d\n", boletos_vendidos_3D);
            printf("\t\tBoletos vendidos de adultos: %d\n", boletos_vendidos_3D_adultos);
            printf("\t\tBoletos vendidos de niños: %d\n", boletos_vendidos_3D_infantes);
          printf("\tSubtotal de la sala: %.2f\n", boletos_vendidos_3D_subtotal);

        printf("Presiona cualquier tecla para continuar: \n");

        if(!feof(stdin))                                                        //Si en el buffer de stdin hay no algo
          getchar();                                                            // Espera que el usuario presione una tecla
        else
          limpiar_buffer();                                                     //De otra forma borra el buffer



        break;
      default:
        printf("¡Opción no válida!Intente de nuevo. Presiona una tecla para continuar.\n"); // Lo que sucede si no pones una opción valida
        break;
    }
  }
}




void datos_estadisticos(void)
{
  	int arreglo[20],i,j,cantidad_alumnos,sumacalif=0,contador_repetidos[20]={0},moda,reprobados=0,aprobados=0,aspirantes_beca=0,comparable;
  	float media,varianza = 0,desviacion,porcentaje_reprobados,porcentaje_aprobados;
  	do
  	{
    	printf("\n\n\t Ingrese el numero de alumnos que presentaron el examen: ");
    	scanf("%d",&cantidad_alumnos);
    	if(cantidad_alumnos < 2 || cantidad_alumnos > 20)
    		printf("\n\n\t Solo se encuentra permitido el rango [2,20] ");
  	}
  	while(cantidad_alumnos < 2 || cantidad_alumnos > 20);


  	//Ingresa las calificaciones de los alumnos
  	for(i=0;i<cantidad_alumnos;i++)
  	{
  		printf("\n\n\t Ingrese la calificacion que obtuvo el alumno %d: ",i+1);
  		scanf("%d",&arreglo[i]);
  		sumacalif+=arreglo[i];
  	}

  	//Obtencion de la media aritmetica
  	media=sumacalif*(1.0)/cantidad_alumnos;
  	//Obtencion de la varianza
  	for(i=0;i<cantidad_alumnos;i++)
  		varianza+=pow(arreglo[i]-media,2)/cantidad_alumnos;
  	//Obtencion de la desviación estandar
  	desviacion=pow(varianza,0.5);
  	//Obtencion de la moda
  	for(j=0;j<cantidad_alumnos;j++)
  		{
  			for(i=0;i<cantidad_alumnos;i++)
  			{
  				if(arreglo[j]==arreglo[i])
  					contador_repetidos[j]++;
  			}
  		}
  	comparable=0;
  	for(i=0;i<cantidad_alumnos;i++)
  		if(contador_repetidos[i]>comparable)
  		{
  			comparable=contador_repetidos[i];
  			moda=arreglo[i];
  		}
  	//Obtencion del numero de alumnos aprobados y reprobados
  	for(i=0;i<cantidad_alumnos;i++)
  		{
  			if(arreglo[i]<6)
  			reprobados++;
  			else
  			aprobados++;
  		}
  	//Obtencion del porcentaje de alumnos aprobados y reprobados
  	porcentaje_aprobados=aprobados*(100.0)/cantidad_alumnos;
  	porcentaje_reprobados=reprobados*(100.0)/cantidad_alumnos;
  	//Obtencion del numero de aspirantes a beca
  	printf("\n\n\t El arreglo ingresado es: \n");
  	for(i=0;i<cantidad_alumnos;i++)
  	{
  		printf("   %d",arreglo[i]);
  		if(arreglo[i]>8)
  		aspirantes_beca++;
  	}
  	//Finalmente, la impresion de los valores
  	printf("\n\n\t La media aritmetica es %.3f",media);
  	printf("\n\n\t La varianza es %.3f",varianza);
  	printf("\n\n\t La desviacion estandar es %.3f",desviacion);
  	if(comparable>1)
  	 printf("\n\n\t La moda es %d",moda);
  	else
  	 printf("\n\n\t Ninguna calificacion se repite, no hay moda");
  	printf("\n\n\t La cantidad de alumnos aprobados es %d, la de reprobados es %d",aprobados,reprobados);
  	printf("\n\n\t Porcentaje de alumnos aprobados= %.3f, de alumnos reprobados= %.3f",porcentaje_aprobados,porcentaje_reprobados);
  	printf("\n\n\t La cantidad de alumnos que aspiran a una beca es %d",aspirantes_beca);

    printf("\n\n\t Presione una tecla para continuar.");
    getchar();
}

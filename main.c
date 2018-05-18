/ BIBLIOTECAS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h> // Libreria usada para el Sleep

//MACROS
#define resolucion 36 // Define la cantdad de espacio que define un "Limpiado de pantalla"

  // MACROS PARA FUNCIÓN "CINE"
    #define cine_filas_asientos 4
    #define cine_columnas_asientos 4

// Definiciones de funciones principales
void promedios_de_lluvias(void);
void cine(void);
void datos_estadisticos(void);


// Definiciones de funciones miscelaneas
void limpiar_buffer(void);
void colocar_n_espacios(unsigned int numero_espacios);
bool verificar_si_entero_esta_en_rango(int numero_a_verificar, int rango_inferior, int rango_superior);


///////////////////////////////////////////////////////////////////////////////
//                        INICIO FUNCIÓN "MAIN"                              //
///////////////////////////////////////////////////////////////////////////////


int main(void)
{
  int decision;
  bool se_limpia_buffer = 0;

  for(;;) // CICLO "INFINITO" PARA REPETIR VARIAS VECES EL MENÚ
  {
    if(se_limpia_buffer)
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
        scanf("\n");
        colocar_n_espacios(resolucion);
        break; // Break no necesario, colocado unicamente por fines de código fuente
    }
  }

  terminar_programa: // Bandera para terminar programa

  return 0;
}


///////////////////////////////////////////////////////////////////////////////
//                           FIN FUNCIÓN "MAIN"                              //
///////////////////////////////////////////////////////////////////////////////


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
  float norte[4][7], centro[4][7], sur[4][7], prom_centro, conta_centro=0, conta_norte=0, conta_sur=0, semana1sur=0, semana1norte=0, semana2sur=0, semana2norte=0, semana3sur=0, semana3norte=0, semana4sur=0, semana4norte=0;
  int i, j;

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
  printf("\n\n\tEl promedio mensual de lluvias la Region Centro fue de: %.2f", prom_centro);


//Contadores para responder incisos B y C
    for(i=0; i<4; i++)
      if(i==0)
          for(j=0; j<7; j++)
          {
            semana1sur+=sur[i][j];
            semana1norte+=norte[i][j];
          }
      else
      {
        if(i==1)
          for(j=0; j<7; j++)
          {
            semana2sur+=sur[i][j];
            semana2norte+=norte[i][j];
          }
        else
        {
          if(i==3)
            for(j=0; j<7; j++)
            {
              semana3sur+=sur[i][j];
              semana3norte+=norte[i][j];
            }
          else
          {
            for(j=0; j<7; j++)
            {
              semana4sur+=sur[i][j];
              semana4norte+=norte[i][j];
            }
          }

        }
      }

//Aqui empieza el codigo para responder el inciso B
    if(semana1sur<semana2sur && semana1sur<semana3sur && semana1sur<semana4sur)
    {
      printf("\n\n\tLa semana con menor lluvia en la Region Sur fue la semana 1 con el siguiente registro:");
        for(i=0; i<1; i++)
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
    else
    {
      if(semana2sur<semana1sur && semana2sur<semana3sur && semana2sur<semana4sur)
      {
        printf("\n\n\tLa semana con menor lluvia en la Region Sur fue la semana 2 con el siguiente registro:");
          for(i=1; i<2; i++)
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
      else
      {
        if(semana3sur<semana1sur && semana3sur<semana2sur && semana3sur<semana4sur)
        {
          printf("\n\n\tLa semana con menor lluvia en la Region Sur fue la semana 3 con el siguiente registro:");
            for(i=2; i<3; i++)
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
        else
        {
          printf("\n\n\tLa semana con menor lluvia en la Region Sur fue la semana 4 con el siguiente registro:");
            for(i=3; i<4; i++)
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

      }
    }
//Aqui empieza el codigo para responder el inciso C
    if(semana1norte>semana2norte && semana1norte>semana3norte && semana1norte>semana4norte)
    {
      printf("\n\n\tLa semana con mayor lluvia en la Region Norte fue la semana 1 con el siguiente registro:");
        for(i=0; i<1; i++)
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
    else
    {
      if(semana2norte>semana1norte && semana2norte>semana3norte && semana2norte>semana4norte)
      {
        printf("\n\n\tLa semana con mayor lluvia en la Region Norte fue la semana 2 con el siguiente registro:");
          for(i=1; i<2; i++)
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
      else
      {
        if(semana3norte>semana1norte && semana3norte>semana3norte && semana3norte>semana4norte)
        {
          printf("\n\n\tLa semana con mayor lluvia en la Region Norte fue la semana 3 con el siguiente registro:");
            for(i=2; i<3; i++)
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
        else
        {
          printf("\n\n\tLa semana con mayor lluvia en la Region Norte fue la semana 4 con el siguiente registro:");
            for(i=3; i<4; i++)
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
  // Ya se escriben los espacios en la funcion main();
  // HEADER
  printf("CINE\n");

  //Declaración de variables generales:

  int menu_3D_o_2D;
  bool se_limpia_buffer = 0;
  int fila_deseada, adulto_o_nino, columna_deseada_int = -1; // Columna deseada int se marca para indicar que no fue encontrada la columna
  char columna_deseada_char;


  int confirmacion, comprar_boleto;

  // Las dos salas tienen la misma cantidad de columnas y comparten la misma etiqueta
  char sala_etiqueta_columnas[cine_columnas_asientos] =
      {'A','B','C','D'};
      // Es necesario modifica en caso de más filas y columnas

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



  //MENU
  for(;;)
  {
    if(se_limpia_buffer)
      {
        limpiar_buffer();
        colocar_n_espacios(resolucion);
      }
    else
      se_limpia_buffer = true;

    printf("\t\t¡Hola! Bienvenido al Cine. Elige una opción:\n");

    printf("\t\t\t 1. Comprar boletos para la sala convencional (Boleto $50 Adulto)\n"
           "\t\t\t 2. Comprar boletos para la sala 3D (Boleto $100 Adulto)\n"
           "\t\t\t 3. Mostrar estadisticas de las salas\n"
           "\t\t\t 0. Salir al menú de programas\n"
        "\n\t\t\tIntroduce tu elección: "
      );
    scanf("%d", &menu_3D_o_2D);

    switch (menu_3D_o_2D)
    {
      case 0:
        return;
      case 1:

        for(;;) // Ciclo para el menu de la sala convencional
        {
          if(boletos_vendidos_2D < cine_filas_asientos*cine_columnas_asientos)
          {
            colocar_n_espacios(resolucion);
            printf("Esta es la sala de cine convencional:\n");
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
                printf("\t%d", sala_2D[i][j]);
              printf("\n");
            }

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

                if(confirmacion == 1)
                  {
                    for(int t = 0; t < cine_columnas_asientos; t++)
                      if(columna_deseada_char == sala_etiqueta_columnas[t])
                        columna_deseada_int = t+1;

                    if(verificar_si_entero_esta_en_rango(fila_deseada, 1, cine_filas_asientos) && verificar_si_entero_esta_en_rango(columna_deseada_int, 1, cine_columnas_asientos))  // Verifica si el asiento se ecuentra en rango
                    {
                      if(sala_2D[fila_deseada-1][columna_deseada_int-1] == 0)
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
                            continue;
                          }

                        }
                      else
                      {
                        printf("Este asiento no esta disponieble ingrese otro\n");
                        Sleep(3000);
                        continue;
                      }
                    }
                  }
                else
                  continue;
            }
            else
              break;
          }
          else
          {
              colocar_n_espacios(resolucion);
              colocar_n_espacios(10);
              printf("\t\t\t¡La sala ya esta llena!\n");
              Sleep(3000);
              break;
            }
        }

        break;
      case 2:

        for(;;) // Ciclo para el menu de la sala convencional
        {
          if(boletos_vendidos_3D < cine_filas_asientos*cine_columnas_asientos)
          {
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

                if(confirmacion == 1)
                  {
                    for(int t = 0; t < cine_columnas_asientos; t++) // Le asigna un numero al caracter de la columna
                      if(columna_deseada_char == sala_etiqueta_columnas[t])
                        columna_deseada_int = t+1;

                    if(verificar_si_entero_esta_en_rango(fila_deseada, 1, cine_filas_asientos) && verificar_si_entero_esta_en_rango(columna_deseada_int, 1, cine_columnas_asientos))  // Verifica si el asiento se ecuentra en rango
                    {
                      if(sala_3D[fila_deseada-1][columna_deseada_int-1] == 0)
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
                            continue;
                          }

                        }
                      else
                      {
                        printf("Este asiento no esta disponieble ingrese otro\n");
                        Sleep(3000);
                        continue;
                      }
                    }
                  }
                else
                  continue;
            }
            else
              break;
          }
          else
          {
              colocar_n_espacios(resolucion);
              colocar_n_espacios(10);
              printf("\t\t\t¡La sala ya esta llena!\n");
              Sleep(3000);
              break;
            }
        }

        break;
      case 3:
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

        if(!feof(stdin))
          getchar();
        else
          limpiar_buffer();


        break;
      default:
        printf("¡Opción no válida!Intente de nuevo. Presiona una tecla para continuar.\n");
        break;
    }
  }
}




void datos_estadisticos(void)
{
  printf("DATOS ESTADISTICOS\n");
}

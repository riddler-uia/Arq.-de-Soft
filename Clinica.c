#include <stdio.h>
#include <stdlib.h>  //Librerias necesarias.
#include <string.h>
#include <time.h>
#include <ctype.h>

#define pacientes 100 //Constante para tener un control de pacientes.
#define doctores 100 //Constante para tener un control de doctores.

typedef struct HC
{
  char nombre[80];
  char dNombre[100];
  char FC[15];
  char diag[100000];  //Estructura para Historial Clinico.
  char trat[100000];
  char anot[10000];
}HC;

typedef struct Def_Paciente
{
  char nombre[100];
  char direccion[80];
  char tel[70];
  char sexo[50];
  char FN[30];    //Estructura para Pacientes.
  char edad[4];
  char estatura[30];
  char alergias[80];
  char TipoS[10];
  char padecimientos[200];
  struct HC historial; 
}TipoPaciente;

typedef struct Def_Doctor
{
	char Nombre[100];
	char Esp1 [80];
	char Esp2 [80];
        char Estatus[20];    //Estructura para Doctores   
	char tel_urg[20];
	char Direccion[200];
	char Tel[70];
	char Consul[10];
	char Dia_consul[100];
	char Hora_consul[50];

  struct Def_Doctores *siguiente;

       	
}TipoDoctor;

TipoDoctor lista_doc[doctores]; //Lista parqa guardar todos los datos de el archivo de Doctores.

TipoPaciente lista[pacientes]; // Lista para guardar todos los datos de el archivo Pacientes

HC historial[pacientes];//Crear un historial clinico al momento de dar de alta a nuevo paciente


void AltaPaciente();
void AltaDoctores();
void AltaHC();                              //Funciones Prototipo.
void BuscarPaciente();
void BuscarDoctor();
void BuscaHistorialClinico(void);
int ValidaLetras(char cadena[200]);
int ValidaNumeros(char lista[50]);
void ModificarDoctor();
void ModificarPaciente();
void ModificarHC();
void ld();
void le();



/* ------------------       PROGRAMA PRINCIPAL   ---------------------- */

int main (int argc, char *argv[])
{
  int *alta, contador=0;
  system("clear");
  
  // LeerPacientes(lista); // Guarda toda la informacion del archivo Pacientes.
  //LeerHistorialClinico(historial); //Guarda toda la informacion del archivo Historial Clinico.

  printf("\n\n                          \e[41m+++++++++++++++\e[m");
  printf("\n			  \e[41m+++++++++++++++\e[m");
  printf("\n			  \e[41m+++++++++++++++\e[m");
  printf("\n			  \e[41m+++++++++++++++\e[m");
  printf("\n			  \e[41m+++++++++++++++\e[m");
  printf("\n	   \e[41m+++++++++++++++++++++++++++++++++++++++++++++\e[m");
  printf("\n	   \e[41m+++++++++++++++++++++++++++++++++++++++++++++\e[m");
  printf("\n           \e[41m+++++++++++++++++++++++++++++++++++++++++++++\e[m");
  printf("\n	   \e[41m+++++++++++++++++++++++++++++++++++++++++++++\e[m");
  printf("\n	   \e[41m+++++++++++++++++++++++++++++++++++++++++++++\e[m");
  printf("\n		    	  \e[41m+++++++++++++++\e[m");
  printf("\n		          \e[41m+++++++++++++++\e[m");
  printf("\n		 	  \e[41m+++++++++++++++\e[m");
  printf("\n		          \e[41m+++++++++++++++\e[m");
  printf("\n			  \e[41m+++++++++++++++\e[m");

  printf("\n\n\t\tSISTEMA INTEGRAL DE INFORMACION CLINICA\n\n");
  
  printf("\n\t\tEquipo de Desarrolladores:\n\n\t\t\tRodrigo García Díaz \n\t\t\tJesús Enrique Domínguez Barrios\n\n\tPresione ENTER para continuar...");
  
  getchar(); //Presionar enter para que el programa inicie.
  system("clear"); //Limpiar la pantalla.

  /* ------------------ Inicio de programa --------------------- */

  int op;
  TipoPaciente *p = lista;

  //VolcarDoctores(&doctor, &alta);

  if(argc==1)
    {
      system("clear");
      
      printf("\n\n\t --------------------- MENU -------------------");
      printf("\n\t |       USTED ESTÁ EN EL MENÚ PRINCIPAL      |");
      printf("\n\t |  1. Doctores.                              |");
      printf("\n\t |  2. Pacientes.                             |");
      printf("\n\t |  3. Historia Clinica.                      |");
      printf("\n\t |  4. Salir.                                 |");
      printf("\n\t ----------------------------------------------\n");
      printf("\n\tOpcion... ");
      scanf("%d", &op);
      __fpurge(stdin);
      switch(op)
	{
	case 1:
	  system("clear");
	  printf("\n\n\t --------------------- MENU -------------------");
	  printf("\n\t |      USTED ESTÁ EN EL MENÚ DE DOCTORES.    |");
	  printf("\n\t |  1. Altas.                                 |");
	  printf("\n\t |  2. Consultas.                             |");
	  printf("\n\t |  3. Modificaciones.                        |");
	  printf("\n\t |  4. Salir.                                 |");
	  printf("\n\t ----------------------------------------------\n");
	  printf("\n\tOpcion...");

	  int op2;
	  
	  scanf("%d", &op2);

	  if(op2==1)
	    AltaDoctores();
	  if(op2==2)
	    BuscarDoctor();
	  if(op2==3)
	    ModificarDoctor();
	  if(op2==4)
	    {
	      system("clear");
	      printf("\n\n\t-----------------Hasta luego----------------\n\n");
	    }

	  
	  break;
	case 2:
	  system("clear");
	  printf("\n\n\t --------------------- MENU -------------------");
	  printf("\n\t |      USTED ESTÁ EN EL MENÚ DE PACIENTES.   |");
	  printf("\n\t |  1. Altas.                                 |");
	  printf("\n\t |  2. Consultas.                             |");
	  printf("\n\t |  3. Modificaciones.                        |");
	  printf("\n\t |  4. Salir.                                 |");
	  printf("\n\t ----------------------------------------------\n");
	  printf("\n\tOpcion...");

	  scanf("%d", &op2);

	  if(op2==1)
	    AltaPaciente();
	  if(op2==2)
	    BuscarPaciente();
	  if(op2==3)
	    ModificarPaciente();
	  if(op2==4)
	    {
	      system("clear");
	      printf("\n\n\t-----------------Hasta luego----------------\n\n");
	    }

        
	  break;
	case 3:
	  system("clear");
	  printf("\n\n\t --------------------- MENU -------------------");
	  printf("\n\t | USTED ESTÁ EN EL MENÚ DE HISTORIA CLÍNICA. |");
	  printf("\n\t |  1. Altas.                                 |");
	  printf("\n\t |  2. Consultas.                             |");
	  printf("\n\t |  3. Modificaciones.                        |");
	  printf("\n\t |  4. Salir.                                 |");
	  printf("\n\t ----------------------------------------------\n");
	  printf("\n\t Opcion...");
	  
	  scanf("%d", &op2);

	  if(op2==1)
	    AltaHC();
	  if(op2==2)
	    BuscaHistorialClinico();
	  if(op2==3)
	    ModificarHC();
	  if(op2==4)
	    {
	      system("clear");
	      printf("\n\n\t-----------------Hasta luego----------------\n\n");
	    }
	  
	  break;

	  
	case 4:
	  system("clear");
	  printf("\n\n\t-----------------Hasta luego----------------\n\n");
	  break;
	    

	default:
	  system("clear");
	  printf("-----------------Opcion No Disponible--------------");
	}
	
    }
  if(argc==2)
    {
      if(strcmp(argv[1], "-ld")==0)
	ld();
      if(strcmp(argv[1], "-le")==0)
	le();
    }
	  
	
}
void AltaPaciente()
{
  int validacion, repite, i, alergias;

   char mensaje[] = "\nPor favor, ingresa los datos del Paciente correctamente como se vayan indicando.\n\n"; //Esta string nos sirve para ahorrarnos lineas que iba escribiendo.
	
	TipoPaciente  Paciente;
	
	FILE *Archivo;
	
	Archivo = fopen ("Pacientes.txt", "at");
	
	if(Archivo==NULL)
	printf("\n\nERROR. El archivo no pudo ser abierto\n\n");

	else
	  {
	    system("clear"); //Se usa system clear y getchar a lo largo del programa para dar presentación.
	
	repite=1;
	
	while(repite==1)
	{
		
	puts(mensaje);
	
	printf("\n\tNombre: ");
	__fpurge(stdin);
	gets(Paciente.nombre);

	for(i=0;i<strlen(Paciente.nombre);i++)
	  Paciente.nombre[i]=toupper(Paciente.nombre[i]);
	
	validacion=ValidaLetras(Paciente.nombre);
	
	if(validacion==1)
	{
		
		printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		repite=1;


		printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
	
	}
	fprintf(Archivo,"%s\n", Paciente.nombre);
	
	repite=1;
	

	system("clear");
	
	puts(mensaje);
	printf("\n\tDireccion: ");
	fflush(stdin);
	gets(Paciente.direccion);
	fprintf(Archivo,"%s\n", Paciente.direccion);
	
	repite=1;

	while(repite==1)
	{
		
	system("clear");
	
	puts(mensaje);
		
	printf("\n\tTelefono: ");
	fflush(stdin);
	gets(Paciente.tel);
	  
	validacion=ValidaNumeros(Paciente.tel);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar letras ni caracteres especiales en este apartado.\n\n");
		
		repite=1;
		
        	printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
		
	}
	fprintf(Archivo,"%s\n", Paciente.tel);

	repite=1;
	
	while(repite==1)
	{
		
	system("clear");
	
	puts(mensaje);
	
	printf("\n\tSexo (Hombre/Mujer): ");
	fflush(stdin);
	gets(Paciente.sexo);

	for(i=0;i<strlen(Paciente.sexo);i++)
	  Paciente.sexo[i]=toupper(Paciente.sexo[i]);
	
	validacion=ValidaLetras(Paciente.sexo);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
		repite=1;
		
	        printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
	
	}
	
	fprintf(Archivo,"%s\n", Paciente.sexo);
	
	repite=1;
		
	system("clear");
	
	puts(mensaje);

	int dia, mes, anio;
	
	printf("\n\tFecha de Nacimiento (formato DD/MM/AAAA): ");
	fflush(stdin);
	gets(Paciente.FN);
	sscanf(Paciente.FN,"%d/%d/%d", &dia, &mes, &anio);
	
	fprintf(Archivo,"%s\n", Paciente.FN);
	 
	
	repite=1;
	
 
	while(repite==1)
	  {
	system("clear");
	
	puts(mensaje);
	
	printf("\n\tEstatura (en centímetros): ");
	fflush(stdin);
	gets(Paciente.estatura);
	

	validacion=ValidaNumeros(Paciente.estatura);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar letras ni caracteres especiales en este apartado.\n\n");
		
		repite=1;
		
        	printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
		
	  }fprintf(Archivo,"%s\n", Paciente.estatura);

	
	repite=1;

	
	while(repite==1)
	{
	      system("clear");
		
	      puts(mensaje);

	      printf("\n\t¿El paciente tiene alergias?\n\n");
	      printf("\n\t0. No tiene.\t1. Si tiene.");
	      printf("\n\tOpción...");
	      scanf("%d", &alergias);

	      if(alergias != 0 && alergias != 1)
		{
		  printf("\n\nElige una opcion correcta.\n\n");

		  repite=1;

		  printf("\n\n\tPresione ENTER para continuar...");

		  getchar();
		}
	      

	      if(alergias==0)
		{
		  fputs("No tiene alergias\n", Archivo);
		  repite=0;
		}
	    

	      if(alergias==1)
		{

		  system("clear");

		  puts(mensaje);

		  printf("\n\n\tIngresa las alergias separadas por una coma.");
		  printf("\n\n\tAlergias: ");
		  __fpurge(stdin);
		  gets(Paciente.alergias);

		  validacion=ValidaLetras(Paciente.alergias);

		  if(validacion==1)
		    {
		      printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
		      repite=1;
		
		      printf("\n\n\tPresiona ENTER para continuar...");
		
		      getchar();
		
		      system("clear");
		    }
	
		  else
		    repite=0;

		  fprintf(Archivo,"%s\n",Paciente.alergias);
		}

	
	}



	system("clear");

	puts(mensaje);
	    
	printf("\n\n\tTipo de Sangre: ");
	__fpurge(stdin);
	gets(Paciente.TipoS);
	fprintf(Archivo,"%s\n", Paciente.TipoS);
	
	
	

	system("clear");
	
	puts(mensaje);
	
	printf("\n\n\tPadecimientos crónicos: ");
	fflush(stdin);
	gets(Paciente.padecimientos);
	fprintf(Archivo,"%s\n\n\n", Paciente.padecimientos);
	
	
	printf("\n\n\n\n\tDatos del Paciente ingresados al sistema correctamente.\n\n");
	
	
	fclose(Archivo);
	  }
}


void AltaHC()
{
  int validacion=0, i;
  
  int repite;
  time_t o;       //Ayuda para establecer la fecha actual.
  o= time(NULL);  //Sirve para dar la fecha actual.
  HC nuevo;
 FILE *Archivo;

 Archivo = fopen("HistoriaClinica.txt", "at");

 repite=1;

 while(repite==1)
   {
     system("clear");
     
     printf("\nIngresa la información conforme vaya apareciendo\n\n");
     printf("\n\tNombre del Paciente: ");
     __fpurge(stdin);
     gets(nuevo.nombre);

     validacion=ValidaLetras(nuevo.nombre);

     if(validacion==1)
      {
       printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
       repite=1;
		
       printf("\n\n\tPresiona ENTER para continuar...");
		
       getchar();
		
       system("clear");
      }
	
      else
	repite=0;

		  
   }

  for(i=0;i<strlen(nuevo.nombre);i++)
      nuevo.nombre[i]=toupper(nuevo.nombre[i]);

  fprintf(Archivo,"%s\n",nuevo.nombre);

 repite=1;

 while(repite==1)
   {
     system("clear");

     printf("\nIngresa la información conforme vaya apareciendo\n\n");
     printf("\n\tNombre del Doctor: ");
     __fpurge(stdin);
     gets(nuevo.dNombre);

     validacion=ValidaLetras(nuevo.dNombre);

     if(validacion==1)
      {
       printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
       repite=1;
		
       printf("\n\n\tPresiona ENTER para continuar...");
		
       getchar();
		
       system("clear");
      }
	
     else
	repite=0;

		  
   }


   for(i=0;i<strlen(nuevo.dNombre);i++)
      nuevo.dNombre[i]=toupper(nuevo.dNombre[i]);

   fprintf(Archivo,"%s\n",nuevo.dNombre);
 

  //Guarda la fecha de consulta.
  strftime(nuevo.FC, 14, "%d/%m/%Y", localtime(&o));

  fprintf(Archivo,"%s\n",nuevo.FC);


  system("clear");

  printf("\nIngresa la información conforme vaya apareciendo\n\n");

  printf("\n\tEscriba el diagnostico: ");
  __fpurge(stdin);
  gets(nuevo.diag);

  fprintf(Archivo,"%s\n",nuevo.diag);


  system("clear");

  printf("\nIngresa la información conforme vaya apareciendo\n\n");

  printf("\n\tEscriba el Tratamiento: ");
  __fpurge(stdin);
  gets(nuevo.trat);

  fprintf(Archivo,"%s\n",nuevo.trat);


  system("clear");

  printf("\nIngresa la información conforme vaya apareciendo\n\n");

  printf("\n\tEscriba el Anotaciones: ");
  __fpurge(stdin);
  gets(nuevo.anot);

  fprintf(Archivo,"%s\n\n\n",nuevo.anot);


  printf("\n\n\n\n\tDatos de la Historia Clínica agregados al sistema correctamente.\n\n");

  
  fclose(Archivo);
}

void AltaDoctores()
{
  int validacion, repite, i;
	
	TipoDoctor Doctor;
	
	FILE *Archivo;
	
	Archivo = fopen ("Doctores.txt", "at");
	
	if(Archivo==NULL)
	printf("\n\nERROR. El archivo no pudo ser abierto\n\n");
	
	system("clear");
	
	
	repite=1;
	
	while(repite==1)//La variable repite permite que si la validacion retorna un valor igual a 0, se pida el dato hasta que porfin se cumpla la validación.
	{
		
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	
	printf("\n\tNombre: ");
	__fpurge(stdin);
	gets(Doctor.Nombre);

	for(i=0;i<strlen(Doctor.Nombre);i++)
	  Doctor.Nombre[i]=toupper(Doctor.Nombre[i]);
	
	validacion=ValidaLetras(Doctor.Nombre);
	
	if(validacion==1)
	{
		
		printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		repite=1;


		printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
	
	}
	fprintf(Archivo,"%s\n", Doctor.Nombre);
	
	
	repite=1;
	
	
	while(repite==1)
	{
		
	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
		
	printf("\n\tEspecialidad 1: ");
	fflush(stdin);
	gets(Doctor.Esp1);
	
	validacion=ValidaLetras(Doctor.Esp1);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
		repite=1;
		
	        printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;

	}
	fprintf(Archivo,"%s\n", Doctor.Esp1);
	
	repite=1;
	
	while(repite==1)
	{
		
	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	
	printf("\n\tEspecialidad 2: ");
	fflush(stdin);
	gets(Doctor.Esp2);
	
	validacion=ValidaLetras(Doctor.Esp2);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
		repite=1;
		
	        printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
	
	}
	fprintf(Archivo,"%s\n", Doctor.Esp2);
	
	repite=1;
	
	while(repite==1)
	{
		
	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	
	printf("\n\tEstatus (Activo/Inactivo): ");
	fflush(stdin);
	gets(Doctor.Estatus);
	
	validacion=ValidaLetras(Doctor.Estatus);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar numeros ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
		repite=1;
		
        	printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
	
	}
	fprintf(Archivo,"%s\n", Doctor.Estatus);
	
	repite=1;
	
	while(repite==1)
	{
		
	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
		
	printf("\n\tTelefono de Urgecias: ");
	fflush(stdin);
	gets(Doctor.tel_urg);
	
	validacion=ValidaNumeros(Doctor.tel_urg);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar letras ni caracteres especiales en este apartado.\n\n");
		
		repite=1;
		
        	printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
		
	}
	fprintf(Archivo,"%s\n", Doctor.tel_urg);
	
	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	printf("\n\tDireccion: ");
	fflush(stdin);
	gets(Doctor.Direccion);
	fprintf(Archivo,"%s\n", Doctor.Direccion);
	
	repite=1;
	
	while(repite==1)
	{
		
	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	
	printf("\n\tTelefono: ");
	fflush(stdin);
	gets(Doctor.Tel);
	
	validacion=ValidaNumeros(Doctor.Tel);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar letras ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
		repite=1;
		
        	printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
	
	}
	fprintf(Archivo,"%s\n", Doctor.Tel);
	
	repite=1;
	
	while(repite==1)
	{
		
	system("clear");
		
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	
	printf("\n\tConsultorio asignado(numero de consultorio): ");
	fflush(stdin);
	gets(Doctor.Consul);
	
	validacion=ValidaNumeros(Doctor.Consul);
	
	if(validacion==1)
	{
		printf("\nNo puedes ingresar letras ni caracteres especiales en este apartado. Inténtalo de nuevo.\n\n");
		
		repite=1;
		
        	printf("\n\n\tPresiona ENTER para continuar...");
		
		getchar();
		
		system("clear");
	}
	
	else
	repite=0;
	
	}
	fprintf(Archivo,"%s\n", Doctor.Consul);
	
	repite=1;

	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	
	printf("\n\tDias de Consulta\n\t(Por favor, ingresa los dias separados por una coma seguido de\n\tun espacio).\n\tEjemplo: Lunes, Martes\n\n\tDias: "); //Revisar el hecho de tener varios dias de consulta. Si se va a usar un array 2D o alguna otra opcion.
	fflush(stdin);
	gets(Doctor.Dia_consul);
	fprintf(Archivo,"%s\n", Doctor.Dia_consul);
	
	repite=1;

	system("clear");
	
	printf("\nPor favor, ingresa los datos del Doctor correctamente como se vayan indicando.\n\n");
	
	printf("\n\tHorario de Consulta\n\t(Por favor, utiliza el formato 24 horas de la siguiente formato:\n\t'hh a hh')\n\tEjemplo: 05 a 15\n\n\tHorario: ");
	fflush(stdin);
	gets(Doctor.Hora_consul);

	fprintf(Archivo,"%s\n\n\n",Doctor.Hora_consul);
	
	
	printf("\n\n\n\n\tDatos del Doctor ingresados al sistema correctamente.\n\n");
	
	
	fclose(Archivo);
}
  


int ValidaLetras(char cadena[200])
{
	int i=0, validacion=0, j;
	
	j=strlen(cadena);
	
	while(i<j && validacion==0)
	{
		
		if(cadena[i]==' ')
		  i++;

		if(cadena[i]==',')
		  i++;
		
		if(isalpha(cadena[i]) != 0) //isalpha es una funcion que nos permite saber si es una letra o no, queda a revisión si se puede usar en Unix.
		  i++;
		
		else
		  validacion=1;
	}
	
	return validacion;

}

int ValidaNumeros(char lista[50])
{
	int i=0, validacion=0, j;
	
	j=strlen(lista);
	
	while(i<j && validacion==0)
	{
		if(isdigit(lista[i]) != 0)
		i++;
		
		else
		validacion=1;
		
	}
	
	return validacion;
}

void BuscarPaciente(void)
{
  FILE *Archivo;

  int contador=0;

  char NomPac[100];
  
  int i;

  Archivo = fopen("Pacientes.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", lista[contador].nombre);
      fscanf(Archivo,"%[^\n]\n", lista[contador].direccion);
      fscanf(Archivo,"%[^\n]\n", lista[contador].tel);
      fscanf(Archivo,"%[^\n]\n", lista[contador].sexo);
      fscanf(Archivo,"%[^\n]\n", lista[contador].FN);
      fscanf(Archivo,"%[^\n]\n", lista[contador].edad);
      fscanf(Archivo,"%[^\n]\n", lista[contador].estatura);
      fscanf(Archivo,"%[^\n]\n", lista[contador].alergias);
      fscanf(Archivo,"%[^\n]\n", lista[contador].TipoS);
      fscanf(Archivo,"%[^\n]\n", lista[contador].padecimientos);
      contador=contador+1;
    }

  fclose(Archivo);

  system("clear");
  printf("\n\tIngresa nombre del paciente: ");
  __fpurge(stdin);
  gets(NomPac);

  int r;
  r=contador;
  system("clear");
  for(i=0; i<contador; i++)
    {
      
      if(strcmp(NomPac, lista[i].nombre)==0)
	{
	  
	  printf("Nombre: ");
	  puts(lista[i].nombre);
	  printf("Dirección: ");
	  puts(lista[i].direccion);
	  printf("Teléfono: ");
	  puts(lista[i].tel);
	  printf("Sexo: ");
	  puts(lista[i].sexo);
	  printf("Fecha de Nacimiento: ");
	  puts(lista[i].FN);
	  printf("Edad: ");
	  puts(lista[i].edad);
	  printf("Estatura:");
	  puts(lista[i].estatura);
	  printf("ALergias: ");
	  puts(lista[i].alergias);
	  printf("Tipo de Sangre: ");
	  puts(lista[i].TipoS);
	  printf("Padecimientos crónicos: ");
	  puts(lista[i].padecimientos);
	  printf("\n\n");
	  r= r-1;
	}
    }
  if(r==contador)
    printf("\t------------------No se encontro Paciente------------------\n\n");
}

void BuscarDoctor(void)
{
  FILE *Archivo;

  int contador=0;

  char NomDoc[100];
  
  int i;

  Archivo = fopen("Doctores.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Nombre);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp1);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp2);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Estatus);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].tel_urg);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Direccion);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Tel);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Dia_consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Hora_consul);
      contador=contador+1;
    }

  fclose(Archivo);

  system("clear");
  printf("Ingresa nombre del doctor: ");
  __fpurge(stdin);
  gets(NomDoc);

  int r;
  r=contador;
  
  system("clear");
  for(i=0; i<contador; i++)
    {
      
      if(strcmp(NomDoc, lista_doc[i].Nombre)==0)
	{
	  
	  printf("Nombre: ");
	  puts(lista_doc[i].Nombre);
	  printf("Especialidad 1: ");
	  puts(lista_doc[i].Esp1);
	  printf("Especialidad 2: ");
	  puts(lista_doc[i].Esp2);
	  printf("Estatus: ");
	  puts(lista_doc[i].Estatus);
	  printf("Telefono de urgencia: ");
	  puts(lista_doc[i].tel_urg);
	  printf("Direccion: ");
	  puts(lista_doc[i].Direccion);
	  printf("Telefono:");
	  puts(lista_doc[i].Tel);
	  printf("Consultorio: ");
	  puts(lista_doc[i].Consul);
	  printf("Dias de consulta : ");
	  puts(lista_doc[i].Dia_consul);
	  printf("Horas de Consulta: ");
	  puts(lista_doc[i].Hora_consul);
	  printf("\n\n");
	  
	  r= r-1;
	}
    }
  if(r==contador)
    printf("\t------------------No se encontro Doctor------------------\n\n");
}

void BuscaHistorialClinico(void)
{
  FILE *Archivo;

  int contador=0;

  char NomHC[100];
  
  int i;

  Archivo = fopen("HistoriaClinica.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", historial[contador].nombre);
      fscanf(Archivo,"%[^\n]\n", historial[contador].dNombre);
      fscanf(Archivo,"%[^\n]\n", historial[contador].FC);
      fscanf(Archivo,"%[^\n]\n", historial[contador].diag);
      fscanf(Archivo,"%[^\n]\n", historial[contador].trat);
      fscanf(Archivo,"%[^\n]\n", historial[contador].anot);
      contador=contador+1;
    }

  fclose(Archivo);

  system("clear");
  printf("Ingresa nombre del Paciente: ");
  __fpurge(stdin);
  gets(NomHC);

  int r;
  r=contador;
  
  system("clear");
  for(i=0; i<contador; i++)
    {
      
      if(strcmp(NomHC, historial[i].nombre)==0)
	{
	  
	  printf("Nombre: ");
	  puts(historial[i].nombre);
	  printf("Nombre del doctor tratante: ");
	  puts(historial[i].dNombre);
	  printf("Fecha de cita: ");
	  puts(historial[i].FC);
	  printf("Diagnostico: ");
	  puts(historial[i].diag);
	  printf("Tratamiento: ");
	  puts(historial[i].trat);
	  printf("Anotaciones: ");
	  puts(historial[i].anot);
	  printf("\n\n");
	  r= r-1;
	}
    }
  if(r==contador)
    printf("\t------------------No se encontro Historial Clinico------------------\n\n");

}

void ModificarDoctor()
{
   FILE *Archivo;

  int contador=0;

  char NomDoc[100];
  
  int i;

  Archivo = fopen("Doctores.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Nombre);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp1);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp2);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Estatus);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].tel_urg);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Direccion);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Tel);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Dia_consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Hora_consul);
      contador=contador+1;
    }

  fclose(Archivo);

  system("clear");
  printf("Ingresa nombre del doctor: ");
  __fpurge(stdin);
  gets(NomDoc);

  int op, r;
  r=contador;
  
  system("clear");
  for(i=0; i<contador; i++)
    {
      
      if(strcmp(NomDoc, lista_doc[i].Nombre)==0)
	{
	  
	  printf("\t\t 1.Nombre \n");
	  printf("\t\t 2.Especialidad 1 \n");
	  printf("\t\t 3.Especialidad 2 \n");
	  printf("\t\t 4.Estatus \n");
	  printf("\t\t 5.Telefono de urgencias \n");
	  printf("\t\t 6.Direccion particular \n");
	  printf("\t\t 7.Telefono \n");
	  printf("\t\t 8.Consultorio asignado \n");
	  printf("\t\t 9.Dias de Consulta \n");
	  printf("\t\t 10.Horario de consulta  \n");

	  printf("Que dato desea editar: \n");
	  scanf("%d", &op);
	  
	  switch(op)
	    {
	      
	    case 1:
	      system("clear");
	      printf("Nombre: ");
	       __fpurge(stdin);
	      gets(lista_doc[i].Nombre);
	      break;
	      
	    case 2:
	      system("clear");
	      printf("Especialidad 1: "); gets(lista_doc[i].Esp1);
	      break;

	    case 3:
	      system("clear");
	      printf("Especialidad 2: "); gets(lista_doc[i].Esp1);
	      break;

	    case 4:
	      system("clear");
	      printf("Estatus: "); gets(lista_doc[i].Estatus);
	      break;

	    case 5:
	      system("clear");
	      printf("Telefono para urgencias: "); gets(lista_doc[i].tel_urg);
	      break;

	    case 6:
	      system("clear");
	      printf("Dirrecion particular: "); gets(lista_doc[i].Direccion);
	      break;

	    case 7:
	      system("clear");
	      printf("Telefono: "); gets(lista_doc[i].Tel);
	      break;

	    case 8:
	      system("clear");
	      printf("Consultorio asignado: "); gets(lista_doc[i].Consul);
	      break;

	    case 9:
	      system("clear");
	      printf("Dias de consulta: "); gets(lista_doc[i].Dia_consul);
	      break;

	    case 10:
	      system("clear");
	      printf("Horarios de Consulta: "); gets(lista_doc[i].Hora_consul);
	      break;

	    default:
	      system("clear");
	      printf("\t ---------------------NO SE ENCONTRO OPCION--------------------- \n\n");
	    }
	}
	  Archivo = fopen("Doctores.txt","wt");

	  for(i=0 ; i<contador; i++)
	    {
	      fprintf(Archivo,"%s\n", lista_doc[i].Nombre);
	      fprintf(Archivo,"%s\n", lista_doc[i].Esp1);
	      fprintf(Archivo,"%s\n", lista_doc[i].Esp2);
	      fprintf(Archivo,"%s\n", lista_doc[i].Estatus);
	      fprintf(Archivo,"%s\n", lista_doc[i].tel_urg);
	      fprintf(Archivo,"%s\n", lista_doc[i].Direccion);
	      fprintf(Archivo,"%s\n", lista_doc[i].Tel);
	      fprintf(Archivo,"%s\n", lista_doc[i].Consul);
	      fprintf(Archivo,"%s\n", lista_doc[i].Dia_consul);
	      fprintf(Archivo,"%s\n", lista_doc[i].Hora_consul);
	    }
	  r= r-1;
    }
  if(r==contador)
    printf("\t------------------No se encontro Doctor------------------\n\n");
  fclose(Archivo);
  if(r != contador)
    {
      system("clear");
      printf("\t------------------PROCEDIMIENTO GUARDADO------------------\n\n");
    }
}

void ModificarPaciente()
{
    FILE *Archivo;

  int contador=0;

  char NomPac[100];
  
  int i, r;
  r=contador;

  Archivo = fopen("Pacientes.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", lista[contador].nombre);
      fscanf(Archivo,"%[^\n]\n", lista[contador].direccion);
      fscanf(Archivo,"%[^\n]\n", lista[contador].tel);
      fscanf(Archivo,"%[^\n]\n", lista[contador].sexo);
      fscanf(Archivo,"%[^\n]\n", lista[contador].FN);
      fscanf(Archivo,"%[^\n]\n", lista[contador].edad);
      fscanf(Archivo,"%[^\n]\n", lista[contador].estatura);
      fscanf(Archivo,"%[^\n]\n", lista[contador].alergias);
      fscanf(Archivo,"%[^\n]\n", lista[contador].TipoS);
      fscanf(Archivo,"%[^\n]\n", lista[contador].padecimientos);
      contador=contador+1;
    }

  fclose(Archivo);

  system("clear");
  printf("\n\tIngresa nombre del paciente: ");
  __fpurge(stdin);
  gets(NomPac);

  int op;
  
  system("clear");
  for(i=0; i<contador; i++)
    {
      
      if(strcmp(NomPac, lista[i].nombre)==0)
	{
	  
	  printf("\t\t 1.Nombre \n");
	  printf("\t\t 2.Direccion \n");
	  printf("\t\t 3.Telefono \n");
	  printf("\t\t 4.Sexo \n");
	  printf("\t\t 5.Fecha de Nacimiento  \n");
	  printf("\t\t 6.Edad  \n");
	  printf("\t\t 7.Estatura \n");
	  printf("\t\t 8.Alergias  \n");
	  printf("\t\t 9.Tipo de sangre   \n");
	  printf("\t\t 10.Padecimientos Conicos    \n");

	  printf("Que dato desea editar: \n");
	  scanf("%d", &op);
	  
	  switch(op)
	    {
	    case 1:
	      system("clear");
	      printf("Nombre: ");
	       __fpurge(stdin);
	      gets(lista[i].nombre);
	      break;
	      
	    case 2:
	      system("clear");
	      printf("Direccion: "); gets(lista[i].direccion);
	      break;

	    case 3:
	      system("clear");
	      printf("Telefono: "); gets(lista[i].tel);
	      break;

	    case 4:
	      system("clear");
	      printf("Sexo: "); gets(lista[i].sexo);
	      break;

	    case 5:
	      system("clear");
	      printf("Fecha de Nacimiento: "); gets(lista[i].FN);
	      break;

	    case 6:
	      system("clear");
	      printf("Edad: "); gets(lista[i].edad);
	      break;

	    case 7:
	      system("clear");
	      printf("Estatura: "); gets(lista[i].estatura);
	      break;

	    case 8:
	      system("clear");
	      printf("Alergias: "); gets(lista[i].alergias);
	      break;

	    case 9:
	      system("clear");
	      printf("Tipo de sangre : "); gets(lista[i].TipoS);
	      break;

	    case 10:
	      system("clear");
	      printf("Padecimientos Cronicos: "); gets(lista[i].padecimientos);
	      break;

	    default:
	      system("clear");
	      printf("\t ---------------------NO SE ENCONTRO OPCION--------------------- \n\n");
	    }
	}
	  Archivo = fopen("Pacientes.txt","wt");

	  for(i=0 ; i<contador; i++)
	    {
	      fprintf(Archivo,"%s\n", lista[i].nombre);
	      fprintf(Archivo,"%s\n", lista[i].direccion);
	      fprintf(Archivo,"%s\n", lista[i].tel);
	      fprintf(Archivo,"%s\n", lista[i].sexo);
	      fprintf(Archivo,"%s\n", lista[i].FN);
	      fprintf(Archivo,"%s\n", lista[i].edad);
	      fprintf(Archivo,"%s\n", lista[i].estatura);
	      fprintf(Archivo,"%s\n", lista[i].alergias);
	      fprintf(Archivo,"%s\n", lista[i].TipoS);
	      fprintf(Archivo,"%s\n", lista[i].padecimientos);
	    }
	  r= r-1;
    }
  if(r==contador)
    printf("\t------------------No se encontro Paciente------------------\n\n");
  fclose(Archivo);
  printf("\t------------------PROCEDIMIENTO GUARDADO------------------\n\n");
}

void ModificarHC()
{
    FILE *Archivo;

  int contador=0;

  char NomHC[100];
  
  int i, r;
  r=contador;

  Archivo = fopen("HistoriaClinica.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", historial[contador].nombre);
      fscanf(Archivo,"%[^\n]\n", historial[contador].dNombre);
      fscanf(Archivo,"%[^\n]\n", historial[contador].FC);
      fscanf(Archivo,"%[^\n]\n", historial[contador].diag);
      fscanf(Archivo,"%[^\n]\n", historial[contador].trat);
      fscanf(Archivo,"%[^\n]\n", historial[contador].anot);
      contador=contador+1;
    }

  fclose(Archivo);


  system("clear");
  printf("\n\tIngresa nombre del paciente: ");
  __fpurge(stdin);
  gets(NomHC);

  int op;
  
  system("clear");
  for(i=0; i<contador; i++)
    {
      
      if(strcmp(NomHC, historial[i].nombre)==0)
	{
	  
	  printf("\t\t 1.Nombre \n");
	  printf("\t\t 2.Nombre del doctor tratante \n");
	  printf("\t\t 3.Fecha de cita \n");
	  printf("\t\t 4.Diagnostico \n");
	  printf("\t\t 5.Tratamiento  \n");
	  printf("\t\t 6.Anotaciones  \n");

	  printf("Que dato desea editar: \n");
	  scanf("%d", &op);
	  
	  switch(op)
	    {
	    case 1:
	      system("clear");
	      printf("Nombre: ");
	       __fpurge(stdin);
	      gets(historial[i].nombre);
	      break;
	      
	    case 2:
	      system("clear");
	      printf("Nombre del doctor tratante: "); gets(historial[i].dNombre);
	      break;

	    case 3:
	      system("clear");
	      printf("Fecha de cita: "); gets(historial[i].FC);
	      break;

	    case 4:
	      system("clear");
	      printf("Diagnostico: "); gets(historial[i].diag);
	      break;

	    case 5:
	      system("clear");
	      printf("Tratamiento  : "); gets(historial[i].trat);
	      break;

	    case 6:
	      system("clear");
	      printf("Anotaciones: "); gets(historial[i].anot);
	      break;

	    default:
	      system("clear");
	      printf("\t ---------------------NO SE ENCONTRO OPCION--------------------- \n\n");
	    }
	}
	  Archivo = fopen("HistoriaClinica.txt","wt");

	  for(i=0 ; i<contador; i++)
	    {
	      fprintf(Archivo,"%s\n", historial[i].nombre);
	      fprintf(Archivo,"%s\n", historial[i].dNombre);
	      fprintf(Archivo,"%s\n", historial[i].FC);
	      fprintf(Archivo,"%s\n", historial[i].diag);
	      fprintf(Archivo,"%s\n", historial[i].trat);
	      fprintf(Archivo,"%s\n", historial[i].anot);
	    }
	  
	  r= r-1;
	  
    }
  if(r==contador)
    printf("\t------------------No se encontro Historial Clinico------------------\n\n");
  fclose(Archivo);
  printf("\t------------------PROCEDIMIENTO GUARDADO------------------\n\n");
}

void ld()
{
  FILE *Archivo;

  int contador=0;
  
  int i;

  Archivo = fopen("Doctores.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Nombre);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp1);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp2);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Estatus);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].tel_urg);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Direccion);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Tel);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Dia_consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Hora_consul);
      contador=contador+1;
    }

  fclose(Archivo);

  system("clear");
  for(i=0; i<contador; i++)
    { 
	  printf("Nombre: ");
	  puts(lista_doc[i].Nombre);
	  printf("Especialidad 1: ");
	  puts(lista_doc[i].Esp1);
	  printf("Especialidad 2: ");
	  puts(lista_doc[i].Esp2);
	  printf("Telefono de urgencia: ");
	  puts(lista_doc[i].tel_urg);
	  printf("\n\n");
	  
	}

printf("\t------------------Doctores de la clinica------------------\n\n");
}

void le()
{
  FILE *Archivo;

  int contador=0;
  
  int i;

  Archivo = fopen("Doctores.txt","rt");

  while(!feof(Archivo))
    {
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Nombre);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp1);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Esp2);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Estatus);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].tel_urg);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Direccion);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Tel);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Dia_consul);
      fscanf(Archivo,"%[^\n]\n", lista_doc[contador].Hora_consul);
      contador=contador+1;
    }

  fclose(Archivo);

  system("clear");
  for(i=0; i<contador; i++)
    { 
      puts(lista_doc[i].Esp1);
      printf("\n");
      puts(lista_doc[i].Esp2);
      printf("\n");
	  
    }

printf("\t------------------Especialidades En La Clinica------------------\n\n");
 printf("\n\n");
}
  

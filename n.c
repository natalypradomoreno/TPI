#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<conio.h>

struct colectivo{
	int nUnidad;
	int DNIC;
	int turno;
	char marca[45];
	int modelo;
	int asiento;
	float km;
	int alta[3];
	int adap;
}col;

//nos quedamos en la baja de usuarios
typedef struct {
	long int Dni;
	char NyA[200];
	int fechaNac[3];
	char Direccion[200];
	long int Telefono;
	char tipoU[200];
	char hbl[50];
} Usuarios;

typedef struct {
	long int DNIChofer;
	char NombreChofer[100];
	int FechaNacimiento[3];
	char direccion[100];
	long int telefono;
	char email [100];
}chofer;

//FUNCIONES PARA LA GESTION DE USUARIOS
void gestionar_usuarios();//COMPLETO
void registros_usuarios(char nombreAr[]);//COMPLETO
void baja_usuarios(char nombreAr[]);//COMPLETO
void modificar_usuarios(char nombreAr[]);//INCOMPLETO
void modificar_nombre();//COMPLETO
void modficar_direccion();//COMPLETO
void modificar_TU();//COMPLETO
void modificar_FdN();//COMPLETO
void modificar_dni();//COMPLETO
void modificar_tel();//COMPLETO

//FUNCIONES PARA LA GESTION DE CUENTAS
void gestionar_cuentas();//COMPLETO
void usar_TyB();//INCOMPLETO
void recarga_saldo();//INCOMPLETO
void consulta_saldo();//INCOMPLETO


//FUNCIONES PARA LOS MEDIOS DE TRANSPORTES Y CHOFERES
void gestionar_MTyC();//COMPLETO
void registros_choferes(char nombreAr[]);//COMPLETO
void registros_unidades(char nombreAr[]);//COMPLETO
void fecha(int fecha[3]);
void dar_baja();//INCOMPLETO
void modificaciones();//INCOMPLETO


//FUNCIONES PARA LAS CONSULTAS
void consultas();//COMPLETO
void lectura_usuarios(char nombreAr[]);;//COMPLETO
void movimientos_fechas();//INCOMPLETO
void recargas_usuarios_especifico();//INCOMPLETO
void usuarios_cBeneficios();//INCOMPLETO
void movimientos_usuarios_especifico();//INCOMPLETO
void choferes_pasajeros();//INCOMPLETO
void pasajeros_primerT();//INCOMPLETO

//FUNCION EXIT
void salir();

//FUNCIONES ADICIONALES
void carga_fechaNac(Usuarios *u);
int anio(int num, int *numm);
int mes(int num);
int dia(int numd,int numm);


//PRINCIPAL
int main() {
	system("cls");
	int op;
	puts("\n----------------------------------\n");
	puts("\nBIENVENIDO AL SISTEMA \"SPETP\"\n");
	puts("\n[1]GESTIONAR USUARIOS.\n");
	puts("\n[2]GESTIONAR CUENTAS.\n");
	puts("\n[3]GESTIONAR MEDIOS DE TRANSPORTE Y CHOFERES.\n");
	puts("\n[4]CONSULTAS.\n");
	puts("\n[5]SALIR\n");
	printf("..:");
	fflush(stdin);
	scanf("%i",&op);
	switch(op) {
		case 1:
			gestionar_usuarios();
			break;
		case 2:
			gestionar_cuentas();
			break;
		case 3:
			gestionar_MTyC();
			break;
		case 4:
			consultas();
			break;
		case 5:
			salir();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			main();
	}
}



///////////////////
//GESTOR USUARIOS//
///////////////////
void gestionar_usuarios() {
	system("cls");
	puts("\n----------------------------------\n");
	int op;
	puts("\nGESTIONAR USUARIOS\n");
	puts("\n[1]REGISTRAR USUARIOS.\n");
	puts("\n[2]MODIFICAR USUARIOS.\n");
	puts("\n[3]DAR DE BAJA\n");
	puts("\n[4]ATRAS\n");
	printf("..:");
	fflush(stdin);
	scanf("%i",&op);
	switch(op) {
		case 1:
			registros_usuarios("usuarios.dat");
			break;
		case 2:
			modificar_usuarios("usuarios.dat");
			break;
		case 3:
			baja_usuarios("usuarios.dat");
			break;
		case 4:
			main();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			gestionar_usuarios();
	}
}



/////////////////////
//REGISTRO USUARIOS//
////////////////////
void registros_usuarios(char nombreAr[]) {
	FILE *p;
	Usuarios u;
	p=fopen(nombreAr,"ab");
	if(p==NULL) {
		printf("\nERROR!\n");
	} else {
		puts("\n------------------------\n");
		printf("\nIngrese los datos del nuevo Usuario\n");
		printf("\nNombre y Apellido:");
		fflush(stdin);
		fgets(u.NyA,200,stdin);
		solucion(u.NyA);
		printf("\nDireccion:");
		fflush(stdin);
		fgets(u.Direccion,200,stdin);
		solucion(u.Direccion);
		printf("\n:habiliacion:");
		fflush(stdin);
		fgets(u.hbl,200,stdin);
		solucion(u.Direccion);
		printf("\nTipo de Usuario:");
		fflush(stdin);
		fgets(u.tipoU,200,stdin);
		solucion(u.tipoU);
		/*BUENO HASTA ACA NO HICE NINGUNA ACLARACION
		PORQUE NO HAY NADA FUERA DE LO COMUN
		PARA CARGAR LA FECHA DE NACIMIENTO, LLAMO A UNA FUNCION ESPECIFICA
		MMODULARIZO YA QUE LA FUNCION DE CARGA DE FECHA VAMOS A TENER Q OCUPARLA PARA
		OTROS CAMPOS, COMO EL PERFIL DEL CHOFER, PAGOS, TICKETS ETC*/
		printf("\nFecha de nacimiento\n");
		//FUNCION DE CARGA DE FECHAS
		carga_fechaNac(&u);
		printf("\nDni:");
		fflush(stdin);
		scanf("%li",&u.Dni);
		printf("\nTelefono:");
		fflush(stdin);
		scanf("%lu",&u.Telefono);
		fwrite(&u,sizeof(Usuarios),1,p);
	}
	fclose(p);
	gestionar_usuarios();
}

/////////////////////
//MODIFICAR USUARIO//
/////////////////////
void modificar_usuarios(char nombreAr[]) {
	system("cls");
	int op;
	long int dni_modif;
	FILE *arch;
	printf("\ningrese el dni de el usuario a modificar: \n");
	scanf("%li",&dni_modif);
	system("cls");
	
	arch=fopen("usuarios.dat","rb");
	
	while (fread(&u, sizeof(struct Usuarios), 1, arch) == 1) {
    	if (dni.u == dni_modif) {
    printf("usuario encontrado\n");
	
	
	puts("\n------------------------\n");
	puts("\nQUE DESEA CAMBIAR DEL USUARIO?\n");
	puts("\n[1]Nombre y Apellido");
	puts("\n[2]Direccion:");
	puts("\n[3]Tipo de Usuario:");
	puts("\n[4]Telefono:");
	puts("\n[5]ATRAS\n");
	printf("..:");
	fflush(stdin);
	scanf("%i",&op);
	switch(op) {
		case 1:
			modificar_nombre(&u);
			 fseek(arch, -sizeof(struct Usuarios), SEEK_CUR);
                    fwrite(&u, sizeof(struct Usuarios), 1, arch);                
			break;
		case 2:
			modficar_direccion(&u);
			 fseek(arch, -sizeof(struct Usuarios), SEEK_CUR);
                    fwrite(&u, sizeof(struct Usuarios), 1, arch);  
			break;
		case 3:
			modificar_TU(&u);
			 fseek(arch, -sizeof(struct Usuarios), SEEK_CUR);
                    fwrite(&u, sizeof(struct Usuarios), 1, arch);  
			break;
	
		case 4:
			modificar_tel(&u);
			 fseek(arch, -sizeof(struct Usuarios), SEEK_CUR);
                    fwrite(&u, sizeof(struct Usuarios), 1, arch);  
			break;
		case 5:
			gestionar_usuarios();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			modificar_usuarios("usuarios.dat");
	}
			else{
				printf("usuario no encontrado");
				modificar_usuarios("usuarios.dat");
			}
		}
	}
}

//Función para modificar Nombre 
void modificar_nombre(struct Usuarios *u) {
    char nuevoNombre[200];
    printf("Ingrese el nuevo Nombre y Apellido: ");
    fflush(stdin);
    fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
    
    // Eliminar el salto de línea al final si se lee con fgets
    nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0';

    // Copiar el nuevo nombre al campo correspondiente de la estructura
    strcpy(u->NyA, nuevoNombre);
    printf("Nombre modificado a: %s\n", u->nombre);
}

// Función para modificar la dirección de un usuario
void modificar_direccion(struct Usuarios *u) {
    printf("Ingrese la nueva dirección del usuario: ");
    fflush(stdin);
    fgets(u->Direccion, sizeof(u->Direccion), stdin);
    u->direccion[strcspn(u->direccion, "\n")] = '\0'; // Elimina el salto de línea
    printf("Dirección modificada a: %s\n", u->direccion);
}

// Función para modificar el tipo de usuario
void modificar_TU(struct Usuarios *u) {
    printf("Ingrese el nuevo Tipo de usuario: ");
    fflush(stdin);
    fgets(u->tipoU, sizeof(u->tipoU), stdin);
    u->tipoUsuario[strcspn(u->tipoUsuario, "\n")] = '\0'; // Elimina el salto de línea
    printf("Tipo de usuario modificado a: %s\n", u->tipoUsuario);
}


// Función para modificar el teléfono de un usuario
void modificar_tel(struct Usuarios *u) {
    printf("Ingrese el nuevo teléfono del usuario: ");
    fflush(stdin);
    scanf("%li", &(u->Telefono));
    printf("Teléfono modificado a: %li\n", u->telefono);
}

////////////////////
//BAJA DE USUARIOS//
////////////////////
void baja_usuarios(char nombreAr[]){
	int pos;
	FILE *p,*p2;
	Usuarios u;
	puts("\n------------------------\n");
	puts("\ningrese el Dni del usuario:\n");
	long int dniU;
	fflush(stdin);
	scanf("%li",&dniU);
	p=fopen(nombreAr,"rb");
	//printf("%i",ftell(p));
	//system("pause");
	if(p==NULL) {
		printf("\nERROR!\n");
	} else {
		
		fread(&u,sizeof(Usuarios),1,p);
		while(!feof(p)) 
		{
			if(u.Dni==dniU)
			{
				 pos= ftell(p)-sizeof(Usuarios);
			}
			fread(&u,sizeof(Usuarios),1,p);
		}
		if(pos==0)
		{
			printf("\ningresaste un dni incorrecto\n");
			system("cls");
			baja_usuarios("usuarios.dat");
			
		}
		fclose(p);
	}
	p2=fopen(nombreAr,"ab");
	if(p==NULL) {
		printf("\nERROR!\n");
	} else
	{
		fseek(p2,pos,0);
		strcpy(u.hbl,"deshabilitado");
		fwrite(&u,sizeof(Usuarios),1,p2);
	} 	
	fclose(p2);
	
}


/////////////////////
//GESTOR DE CUENTAS//
/////////////////////
void gestionar_cuentas() {
	system("cls");
	int op;
	puts("\n----------------------------------\n");
	puts("\nGESTIONAR CUENTAS\n");
	puts("\n[1]USAR TARJETA/BILLETERA ELECTRONICA.\n");
	puts("\n[2]RECARGA DE CUENTA.\n");
	puts("\n[3]CONSULTA DE SALDO.\n");
	puts("\n[4]ATRAS\n");
	printf("..:");
	fflush(stdin);
	scanf("%i",&op);
	switch(op) {
		case 1:
			usar_TyB();
			break;
		case 2:
			recarga_saldo();
			break;
		case 3:
			consulta_saldo();
			break;
		case 4:
			main();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			gestionar_cuentas();
	}
}

////////////////////////////
//USAR TARJETA O BILLETERA//
////////////////////////////
void usar_TyB() {
}

/////////////////
//RECARGA SALDO//
////////////////

void recarga_saldo() {
}

//////////////////
//CONSULTA SALDO//
//////////////////
void consulta_saldo() {
}

////////////////////////////////////
//GESTION DE COLECTIVOS Y CHOFERES//
////////////////////////////////////
void gestionar_MTyC() {
	system("cls");
	int op;
	puts("\n----------------------------------\n");
	puts("\nGESTIONAR MEDIOS DE TRANSPORTE Y CHOFERES\n");
	puts("\n[1]REGISTROS DE CHOFERES.\n");
	puts("\n[2]REGISTROS DE UNIDADES(COLECTIVOS).\n");
	puts("\n[3]DAR DE BAJA.\n");
	puts("\n[4]MODIFICACIONES.\n");
	puts("\n[5]ATRAS\n");
	printf("..:");
	fflush(stdin);
	scanf("%i",&op);
	switch(op) {
		case 1:
			registros_choferes("choferes.dat");
			break;
		case 2:
			registros_unidades("colectivo.dat");
			break;
		case 3:
			dar_baja();
			break;
		case 4:
			modificaciones();
			break;
		case 5:
			main();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			gestionar_MTyC();
	}
}

/////////////////////
//REGISTRO CHOFERES//
/////////////////////
void registros_choferes(char nombreAr[]){
	chofer ch;
	FILE *f;
	f=fopen(nombreAr,"ab");
	if(f==NULL)
	{
		printf("\nERROR!\n");
	}else
	{
		puts("\n------------------------\n");
		printf("\nDatos del Nuevo Chofer\n");
		printf("\nDni:");
		fflush(stdin);
		scanf("%ld",&ch.DNIChofer);
		printf("\nNombre:");
		fflush(stdin);
		fgets(ch.NombreChofer,100,stdin);
		solucion(ch.NombreChofer);
		printf("\nDireccion:");
		fflush(stdin);
		fgets(ch.direccion,100,stdin);
		solucion(ch.direccion);
		printf("\nTelefono:");
		fflush(stdin);
		scanf("%d",&ch.telefono);
		printf("\nEMmail:");
		fflush(stdin);
		fgets(ch.email,100,stdin);
		solucion(ch.email);
		printf("\nFecha de nacimiento\n");
		//Carga de Fechas
		carga_fechaNac(&ch);
		fwrite(&ch,sizeof(chofer),1,f);
		printf("\nCARGA COMPLETADA\n");
	}
	fclose(f);
}

/////////////////////
//REGISTRO UNIDADES//
/////////////////////
void registros_unidades(char nombreAr[]){
	int dni=0,b=0;
	FILE *fch,*fcol;
	fcol=fopen(nombreAr,"ab");
	
	if(fcol=NULL){
		printf("error colectivo");
	}else{
		printf("DATOS COLECTIVO\n");
		col.nUnidad+=1;
		printf("\nDNI DEL COLECTIVERO:\t");
		fflush(stdin);
		scanf("%d",&dni);
		
		//aca pregunte si ya existe de chofer sino va a funcion de alta chofer
		fch=fopen("choferes.dat","rb");
		fread(&ch,sizeof(ch),1,fch);
		while((!feof(fch))&&(b=0)){
			if(ch.DNIChofer==dni){
				b=1;
				col.DNIC=dni;
			}else{
				printf("no existe chofer, creando nuevo");
				b=1;
				//altaChofer("choferes.dat");	
			}
			fread(&ch,sizeof(ch),1,fch);	
		}
		fclose(fch);
		
		printf("\nTURNO (SELECCIONE UNO)\n1-00hs a 11:59hs\n2- 12hs a 23:59hs\n");
		fflush(stdin);
		scanf("%d",&col.turno);
		printf("\nMARCA\t");
		fflush(stdin);
		fgets(col.marca,45,stdin);
		fflush(stdin);
		//solucion(col.marca);
		printf("\nMODELO:\t");
		fflush(stdin);
		scanf("%d",&col.modelo);
		printf("\nCANTIDAD DE ASIENTOS:\t");
		fflush(stdin);
		scanf("%f",&col.asiento);
		printf("\nKILOMETRAJE:\t");
		fflush(stdin);
		scanf("%f",&col.km);
		printf("¿APTO DISCAPACIDAD?\n1- SI\n0- NO");
		fflush(stdin);
		scanf("%d",&col.adap);
		fecha(col.alta);
		fwrite(&col,sizeof(col),1,fcol);
		fclose(fcol);
	}	
}

void fecha(int fecha[3]) {
    time_t tiempo;
    struct tm *tmInfo;

    // Obtener el tiempo actual
    time(&tiempo);
    tmInfo = localtime(&tiempo);

    // Almacenar la fecha actual en el arreglo
    fecha[0] = tmInfo->tm_mday;     // Día
    fecha[1] = tmInfo->tm_mon + 1;  // Mes (0-11)
    fecha[2] = tmInfo->tm_year + 1900;  // Año (desde 1900)

    // Nota: Sumamos 1 al mes y 1900 al año para obtener los valores reales.
}

/////////////////////////////////
//BAJA CHOFER O COLECTIVO////////
////////////////////////////////
void dar_baja() {
}

//////////////////////////////////////
//MODIFICAR CHOFER O COLECTIVO////////
/////////////////////////////////////
void modificaciones() {
}


//////////////
//CONSULTAS//
/////////////
void consultas() {
	system("cls");
	int op;
	puts("\n----------------------------------\n");
	puts("\nCONSULTAS\n");
	puts("\n[1]LISTAR USUARIOS.\n");
	puts("\n[2]MOVIMIENTOS REGISTRADOS ENTRE 2 FECHAS.\n");
	puts("\n[3]LISTAR RECARGAS EFECTUADAS POR UN USUARIO.\n");
	puts("\n[4]USUARIOS CON BENEFICIOS\n");
	puts("\n[5]MOVIMIENTOS DE UN USUARIO \n");
	puts("\n[6]CHOFERES CON MAS PASAJEROS\n");
	puts("\n[7]PORCENTAJE DE PASAJEROS QUE VIAJAN EN EL PRIMER TURNO\n");
	puts("\n[8]ATRAS\n");
	printf("..:");
	fflush(stdin);
	scanf("%i",&op);
	switch(op) {
		case 1:
			lectura_usuarios("usuarios.dat");
			break;
		case 2:
			movimientos_fechas();
			break;
		case 3:
			recargas_usuarios_especifico();
			break;
		case 4:
			usuarios_cBeneficios();
			break;
		case 5:
			movimientos_usuarios_especifico();
			break;
		case 6:
			choferes_pasajeros();
			break;
		case 7:
			pasajeros_primerT();
			break;
		case 8:
			main();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			consultas();
	}
}


void lectura_usuarios(char nombreAr[]) {

	FILE *p;
	Usuarios u;
	p=fopen(nombreAr,"rb");
	if(p==NULL) {
		printf("\nERROR!\n");
	} else {
		fread(&u,sizeof(Usuarios),1,p);
		while(!feof(p)) {
			puts("\n------------------------\n");
			printf("\nDATOS DE USUARIOS\n");
			printf("\nNombre y Apellido: %s",u.NyA);
			printf("\nDni: %Li",u.Dni);
			printf("\nFecha de Nacimiento: %i/%i/%i",u.fechaNac[0],u.fechaNac[1],u.fechaNac[2]);
			printf("\nDireccion: %s",u.Direccion);
			printf("\nNro Telefono:%li",u.Telefono);
			printf("\nTipo de Usuario: %s",u.tipoU);
			printf("\nHabilitacion: %s",u.hbl);
			fread(&u,sizeof(Usuarios),1,p);
		}
		fclose(p);
	}
}

void movimientos_fechas() {
}

void recargas_usuarios_especifico() {
}

void usuarios_cBeneficios() {
}

void movimientos_usuarios_especifico() {
}

void choferes_pasajeros() {
}

void pasajeros_primerT() {
}



//Exit
void salir() {
	system("cls");
	puts("\nHASTA LUEGO!\n");
}


void solucion(char string[]) {
	int i=0;
	int len =strlen(string);
	for(i; i<len; i++) {
		if(string[i]=='\n') {
			string[i]= '\0';
		}
	}
}

void carga_fechaNac(Usuarios *u) {
	/*
		ESTA FUNCION GUARDA LOS DATOS PEDIDOS UNICAMENTE
		SE PIDE PRIMERO EL DATO DEL MES, LUEGO EL DIA, Y POR ULTIMO EL AÑO
		PARA QUE LAS CINDICIONES Y RESTRICCIONES QUE TIENE QUE TENER LA FECHA
		SE HAGAN MAS FACILES
	*/
	printf("Ingrese la fecha de nacimiento (MM/DD/AA):");
	int i;
	for(i=0; i<3; i++) {
		if(i==0) {
			int numm;
			printf("\nMes: ");
			scanf("%d",&numm);
			u->fechaNac[1]=mes(numm);
		} else if(i==1) {
			int numd;
			printf("Dia: ");
			scanf("%d",&numd);
			u->fechaNac[0]=dia(numd,u->fechaNac[1]);
		} else if(i==2) {
			int numa;

			printf("AÃ±o: ");
			scanf("%d",&numa);
			u->fechaNac[2]=anio(numa,&u->fechaNac[1]);
		}

	}

}
/*LA FUNCION "ANIO" COMPRUEBA QUE EL AÑO QUE INGRESO EL USUARIO O ADMINISTRADOR
ES CORRECTA YA QUE NO PUEDE INGRESAR UN AÑO QUE NO LLEGO TDV EJEMPLO 2024*/
int anio(int num, int *numm) {
	int band=0;
	int op=0;
	Usuarios u;
	while(*numm == 12 && num == 2022) {
		printf("Disculpe esa Fecha tdv no a llegado.\n");
		printf("*se ah equivocado de mes?(1);\n");
		printf("\n*se ah equivocado de aÃ±o?(2);\n");
		fflush(stdin);
		scanf("%d",&op);
		if(op==1) {
			int num1;
			printf("\nMes: ");
			scanf("%d",&num1);
			if(num1==12)op=0;
			if(num1!=12)*numm=mes(num1);
		} else if(op==2) {
			printf("AÃ±o: ");
			scanf("%d",&num);
		} else {
			printf("no corresponde a ninguna opcion.\n");
			printf("\n*se ah equivocado de mes?(1);\n");
			printf("*se ah equivocado de aÃ±o?(2);\n");
			fflush(stdin);
			printf("\nOpcion: ");
			scanf("%d",&op);
		}
	}
	return num;
}
/*LA FUNCION "MES* COMPRUEBA QUE EL MES INGRESADO SEA DEL 1 AL 12 , YA QUE SE TRABAJA CON NUMEROS*/
int mes(int num) {
	while(num<1 || num>12) {
		printf("por favor ingresar un mes que exista:");
		printf("\nMes: ");
		fflush(stdin);
		scanf("%d",&num);
	}
	return num;
}
/* LA FUNCION "DIA" COMPRUEBA QUE EL DIA INGRESADO SEA EL CORRESPONDIENTE AL MES INGRESADO ANTERIORMENTE, EJEMPLO
FEBRERO NO PUEDE TENER 30 DIAS NI 31(ASI SUCESIVAMENTE DEPENDIENDO DEL MES)*/
int dia(int numd,int numm) {
	switch(numm) {
		case 1:
			while(numd<1 || numd>31) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 2:
			while(numd<1 || numd>28) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 3:
			while(numd<1 || numd>31) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 4:
			while(numd<1 || numd>30) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 5:
			while(numd<1 || numd>31) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 6:
			while(numd<1 || numd>30) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 7:
			while(numd<1 || numd>31) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 8:
			while(numd<1 || numd>31) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 9:
			while(numd<1 || numd>30) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 10:
			while(numd<1 || numd>31) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 11:
			;
			while(numd<1 || numd>30) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;

		case 12:
			while(numd<1 || numd>31) {
				printf("Disculpe, el numero que ingreso no corresponde a -\n-ningun dia del mes");
				printf("\nDia: ");
				fflush(stdin);
				scanf("%d",&numd);
			};
			return numd;
			break;
	}
}


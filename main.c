#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<conio.h>


//nos quedamos en la baja de usuarios
typedef struct {
	char id[100];
	long int Dni;
	char NyA[200];
	int fechaNac[3];
	char Direccion[200];
	long int Telefono;
	int tipoU;
	char hbl;
} Usuarios;

typedef struct{
	int nUnidad;
	int DNIC;
	int turno;
	char marca [45];
	int modelo;
	int asiento;
	float km;
	int alta[3];
	int adap;
}col;


typedef struct{
	long int dni;
	long int nroControl;
	float monto;
	char bocaPago[100];
	int fecha[3];
	int hora[2];
}Cargas;

typedef struct{
	long int dni;
	long int nroCelular;
	float saldoDisp;
}Cuentas;

typedef struct{
	long int DNIChofer;
	char NombreChofer[100];
	int FechaNacimiento[3];
	char direccion[100];
	long int telefono;
	char email [100];
}Chofer;

//FUNCIONES PARA LA GESTION DE USUARIOS
void gestionar_usuarios();//COMPLETO
void registros_usuarios(char nombreAr[],char nombreAr2[]);//COMPLETO
void baja_usuarios(char nombreAr[]);//COMPLETO
void modificar_usuarios(char nombreAr[]);//COMPLETO
void modificar_nombre(Usuarios *u);//COMPLETO
void modificar_direccion(Usuarios *u);//COMPLETO
void modificar_TU( Usuarios *u);//COMPLETO
void modificar_tel(Usuarios *u);//COMPLETO

//FUNCIONES PARA LA GESTION DE CUENTAS
void gestionar_cuentas();//COMPLETO
void usar_TyB();//INCOMPLETO
void recarga_saldo(char nombreAr[],char nombreAr2[],char nombreAr3[]);//COMPLETO
void consulta_saldo(char nombreAr[]);//COMPLETO


//FUNCIONES PARA LOS MEDIOS DE TRANSPORTES Y CHOFERES
void gestionar_MTyC();//COMPLETO
void registros_choferes(char nombreAr[]);//COMPLETO
void registros_unidades(char nombreAr[],char nombreAr2[]);//COMPLETO
void fecha(int fecha[3]);
void dar_baja();//INCOMPLETO
void modificaciones();//COMPLETO


//FUNCIONES PARA LAS CONSULTAS
void consultas();//COMPLETO
void lectura_usuarios(char nombreAr[]);//COMPLETO
void movimientos_fechas();//INCOMPLETO
void recargas_usuarios_especifico();//INCOMPLETO
void usuarios_cBeneficios();//COMPLETO
void movimientos_usuarios_especifico();//INCOMPLETO
void choferes_pasajeros();//INCOMPLETO
void pasajeros_primerT();//INCOMPLETO

//FUNCION EXIT
void salir();

//FUNCIONES ADICIONALES
void solucion(char string[]);
void carga_fechaNac(int *f);
int anio(int num, int numm);
int mes(int num);
int dia(int numd,int numm);
Cuentas modifsaldo (Cuentas c,float saldo);
void carga_saldo(long int dni, float sald);
void fecha2(int fecha[3],int hora[2]);
int aleatorio_entre3(int o);

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




//Gestion de Usuarios
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
			registros_usuarios("usuarios.dat","cuentas.dat");
			break;
		case 2:
			modificar_usuarios("usuarios.dat");
			break;
		case 3:
			//baja_usuarios("usuarios.dat");
			break;
		case 4:
			main();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			gestionar_usuarios();
	}
}

void registros_usuarios(char nombreAr[],char nombreAr2[]) {
	FILE *p,*p2;
	Cuentas c;
	Usuarios u;
	p=fopen(nombreAr,"ab");
	p2=fopen(nombreAr2,"ab");
	if((p==NULL)&&(p2==NULL)){
		printf("\nERROR!\n");
	} else {
		puts("\n------------------------\n");
		printf("\nIngrese los datos del nuevo Usuario\n");
		fseek(p2,0,2);
		fseek(p,0,2);
		int novo =ftell(p)/sizeof(Usuarios);
		sprintf(u.id,"%d",novo); 
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
		scanf("%c",u.hbl);
		
		printf("\nTipo de Usuario:");
		puts("\n[1]Normal");
   		puts("\n[2]Estudiantil");
    	puts("\n[3]Discapacidad");
    	puts("\n[4]Mayor de edad");
    	puts("\n[5]Veterano de malvina");
    	fflush(stdin);
    	scanf("%d",u.tipoU);
		
		/*BUENO HASTA ACA NO HICE NINGUNA ACLARACION
		PORQUE NO HAY NADA FUERA DE LO COMUN
		PARA CARGAR LA FECHA DE NACIMIENTO, LLAMO A UNA FUNCION ESPECIFICA
		MMODULARIZO YA QUE LA FUNCION DE CARGA DE FECHA VAMOS A TENER Q OCUPARLA PARA
		OTROS CAMPOS, COMO EL PERFIL DEL CHOFER, PAGOS, TICKETS ETC*/
		printf("\nFecha de nacimiento\n");
		//FUNCION DE CARGA DE FECHAS
		carga_fechaNac(u.fechaNac);
		printf("\nDni:");
		fflush(stdin);
		scanf("%li",&u.Dni);
		c.dni=u.Dni;
		printf("\nTelefono:");
		fflush(stdin);
		scanf("%lu",&u.Telefono);
		c.nroCelular = u.Telefono;
		c.saldoDisp=0;
		fwrite(&u,sizeof(Usuarios),1,p);
		fwrite(&c,sizeof(Cuentas),1,p);
	}
	fclose(p);
	fclose(p2);
	gestionar_usuarios();
}

void modificar_usuarios(char nombreAr[]) {
	int pos;
	Usuarios u;
	system("cls");
	int op;
	long int dni_modif;
	FILE *arch;
	printf("\ningrese el dni de el usuario a modificar: \n");
	fflush(stdin);
	scanf("%li",&dni_modif);
	system("cls");
	
	arch=fopen("usuarios.dat","rb");
	
	while (fread(&u, sizeof(Usuarios), 1, arch)== 1) {
    	if (u.Dni == dni_modif) {
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
			pos = ftell(arch)-sizeof(Usuarios);
			 	fseek(arch,pos, 0);
                    fwrite(&u, sizeof(Usuarios), 1, arch);                
			break;
		case 2:
			modificar_direccion(&u);
			pos = ftell(arch)-sizeof(Usuarios);
			fseek(arch,pos, 0);
            fwrite(&u, sizeof(Usuarios), 1, arch);  
		break;
		case 3:
			modificar_TU(&u);
			  pos = ftell(arch)-sizeof(Usuarios);
			 	fseek(arch,pos, 0);
                    fwrite(&u, sizeof(Usuarios), 1, arch);  
			break;
	
		case 4:
			modificar_tel(&u);
			  pos = ftell(arch)-sizeof(Usuarios);
			 	fseek(arch,pos, 0);
                    fwrite(&u, sizeof( Usuarios), 1, arch);  
			break;
		case 5:
			gestionar_usuarios();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			modificar_usuarios("usuarios.dat");
			}
}else{
				printf("usuario no encontrado");
				modificar_usuarios("usuarios.dat");
			}
		}
	}


void modificar_nombre(Usuarios *u) {
    char nuevoNombre[200];
    printf("Ingrese el nuevo Nombre y Apellido: ");
    fflush(stdin);
    fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
    
    // Eliminar el salto de línea al final si se lee con fgets
    nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0';

    // Copiar el nuevo nombre al campo correspondiente de la estructura
    strcpy(u->NyA, nuevoNombre);
    printf("Nombre modificado a: %s\n", u->NyA);
}

// Función para modificar la dirección de un usuario
void modificar_direccion(Usuarios *u) {
    printf("Ingrese la nueva dirección del usuario: ");
    fflush(stdin);
    fgets(u->Direccion, 200, stdin);
    u->Direccion[strcspn(u->Direccion, "\n")] = '\0';// Elimina el salto de línea
    printf("Dirección modificada a: %s\n", u->Direccion);
}

// Función para modificar el tipo de usuario
void modificar_TU( Usuarios *u) {
    printf("Ingrese el nuevo Tipo de usuario: ");
    puts("\n[1]Normal");
    puts("\n[2]Estudiantil");
    puts("\n[3]Discapacidad");
    puts("\n[4]Mayor de edad");
    puts("\n[5]Veterano de malvina");
    fflush(stdin);
    scanf("%d",u->tipoU);
	if((u->tipoU<1)&&(u->tipoU>5))
	{
		puts("\nSelecciono un numero invalido");
		system("pause");
		modificar_TU(u);
	}
    printf("Tipo de usuario modificado a: %d\n", u->tipoU);
}


// Función para modificar el teléfono de un usuario
void modificar_tel(Usuarios *u) {
    printf("Ingrese el nuevo teléfono del usuario: ");
    fflush(stdin);
    scanf("%li", &(u->Telefono));
    printf("Teléfono modificado a: %li\n", u->Telefono);
}

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
		u.hbl='d';
		fwrite(&u,sizeof(Usuarios),1,p2);
	} 	
	fclose(p2);
	
}



//Gestion de Cuentas
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
			recarga_saldo("usuarios.dat","cargas_cuentas.dat","cuentas.dat");
			break;
		case 3:
			consulta_saldo("cuentas.dat");;
			break;
		case 4:
			main();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			gestionar_cuentas();
	}
}

void usar_TyB() {
	
}

void recarga_saldo(char nombreAr[],char nombreAr2[],char nombreAr3[])
{
	char num_id[1000];
	char nombretxt[]="cargas_";
	int band=0;
	Cuentas cs;
	FILE *p,*p2,*p3;
	Usuarios u;
	Cargas c;
	long int dniu;
	printf("\nDni:");
	fflush(stdin);
	scanf("%d",&dniu);
	p=fopen(nombreAr,"rb");
	if(p==NULL)
	{	
		printf("\nERROR\n");
	}else
	{
		fread(&u,sizeof(Usuarios),1,p);
	
		while(!feof(p))
		{
		
			if((u.Dni==dniu))
			{
				if(u.hbl =='h')
				{
					strcpy(num_id,u.id);
					band=1;	
					printf("El usuario existe.\n");
				}
			}
			fread(&u,sizeof(Usuarios),1,p);
		}
		if(band==0)
		{
			printf("\nCuenta no registrada o no habilitada\n");
			main();
		}
		//aki va la funcion anterior a esta
		//->
		
	fclose(p);
	}
	
	float dinero_carga;
	printf("\nIngrese el dinero a cargar:");
	fflush(stdin);
	scanf("%f",&dinero_carga);
	
	carga_saldo(dniu,dinero_carga);
	
	p2=fopen(nombreAr2,"ab");
	if(p2==NULL)
	{
		printf("\nERROR\n");
	}else
	{
		
		srand(time(NULL));
		c.dni=dniu;
		int op=aleatorio_entre3(rand()%50);
		switch(op)
		{
			case 0:strcpy(c.bocaPago,"Rapipago.");break;
			case 1:strcpy(c.bocaPago,"Local comercial.");break;
			case 2:strcpy(c.bocaPago,"Aplicacion.");break;
		}
		c.nroControl=rand()%1000;
		char nro_c[20];
		sprintf(nro_c,"%i",c.nroControl);
		c.monto=dinero_carga;
		fecha2(&c.fecha,&c.hora);
		fwrite(&c,sizeof(Cargas),1,p2);
		
		strcat(nombretxt,num_id);
		strcat(nombretxt,".");
		strcat(nombretxt,nro_c);
		strcat(nombretxt,".txt");
		printf("%s",nombretxt);
		system("pause");
		p3=fopen(nombretxt,"ab");
		if(p3==NULL)
		{
			printf("\nERROR\n");
		}else
		{
			
			char cad[100];
			sprintf(cad,"%li",c.dni);
			fprintf(p3,"\n%s",cad);
			
			
			sprintf(cad,"%li",c.nroControl);
			fprintf(p3,"\n %s",cad);
			
			
			sprintf(cad,"%.f",c.monto);
			fprintf(p3,"\n %s",cad);
			fprintf(p3,"\n %s",c.bocaPago);
		}
					
		fclose(p3);
	}
	fclose(p2);
}

void consulta_saldo(char nombreAr[]){
	int band=0;
	Cuentas c;
	FILE *p;
	long int dniu;
	printf("\nIngrese el dni del usuario a consultar:");
	fflush(stdin);
	scanf("%li",&dniu);
	
	p=fopen(nombreAr,"rb");
	if(p==NULL) {
		printf("\nERROR!\n");
	} else {
		fread(&c,sizeof(Cuentas),1,p);
		while((!feof(p))&&band==0) {
			if(dniu==c.dni)
			{
				printf("\nEl usuario Dni: %Li",c.dni);
				printf("\nEl Saldo disponible es: %.2f",c.saldoDisp);
				band=1;
			}
			fread(&c,sizeof(Cuentas),1,p);
		}
		fclose(p);
	}
}







//Gestion de Medios de Transporte y Choferes
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
			registros_unidades("colectivo.dat","choferes.dat");
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

void registros_choferes(char nombreAr[]){
	FILE *f;
	Chofer ch;
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
		carga_fechaNac(ch.FechaNacimiento);
		fwrite(&ch,sizeof(Chofer),1,f);
		printf("\nCARGA COMPLETADA\n");
	}
	fclose(f);
}

void registros_unidades(char nombreAr[],char nombreAr2[]){
	system("pause");
	int pos;
	col c;
	Chofer ch;
	int dni=0,b=0;
	FILE *f2,*f1;
	printf("\nDNI DEL COLECTIVERO:");
	fflush(stdin);
	scanf("%d",&dni);
	f2=fopen(nombreAr2,"rb");
	if(f2==NULL){
		printf("\n¡ERROR!\n");
		
	}else{
		fread(&ch,sizeof(Chofer),1,f2);
		while((!feof(f2))&&(b==0)){
			if(ch.DNIChofer==dni){
				b=1;
				pos= ftell(f2)-sizeof(Chofer);
			}
			fread(&ch,sizeof(Chofer),1,f2);
		}
		fclose(f2);
		if(b==0)
		{
			printf("\nel numero de dni que ingreso\nno corresponde a ningun chofer\n");
			registros_unidades("colectivos.dat","choferes.dat");
			
		}
	}		
	
	f1=fopen(nombreAr,"ab");
	if(f1==NULL){
		printf("\n¡ERROR!\n");
		
	}else{
		
		printf("\nDATOS COLECTIVO\n");
		c.nUnidad=pos;
		c.DNIC=dni;
		printf("\nTurno\n[1]00hs a 11:59hs\n[2]12hs a 23:59hs\n");
		fflush(stdin);
		scanf("%d",&c.turno);
		printf("\nMarca:");
		fflush(stdin);
		fgets(c.marca,45,stdin);
		fflush(stdin);
		solucion(c.marca);
		printf("\nModelo:");
		fflush(stdin);
		scanf("%d",&c.modelo);
		printf("\nCantidad de asientos:");
		fflush(stdin);
		scanf("%d",&c.asiento);
		printf("\nKilometraje:");
		fflush(stdin);
		scanf("%f",&c.km);
		printf("Apto para Discapacitados?\n[1]SI\n[2]NO");
		fflush(stdin);
		printf(":");
		scanf("%d",&c.adap);
		fecha(c.alta);
		fwrite(&c,sizeof(col),1,f1);
		fclose(f1);
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

void dar_baja() {
}

//////////////////////////////////////
//MODIFICAR CHOFER O COLECTIVO////////
/////////////////////////////////////
void modificaciones() {
	system("cls");
	int mod;
	FILE *fch,*fcol;

	//pregunto por que quiere modificar
	printf("\nQUE DESEA CAMBIAR:\n");
	printf("\n1-chofer\n2-unidad de colectivo");
	scanf("%d",&mod);
	switch(mod){
		case 1: 
			mod_chofer(fch,fcol);
			break;
		case 2:
			mod_col(fcol);
			break;
		default:
			puts("ingreso una opcion invalida\n");
			modificaciones(fch,fcol);
	}
}


/////////////////////
//MODIFICAR CHOFER//
///////////////////
void mod_chofer(FILE *fcol,FILE *fch){
	system("cls");
	long int dni;
	int op;
	Chofer ch;
	
	printf("\ningrese el dni del chofer a modificar: \n");
	scanf("%ld",&dni);
	system("cls");
	fch=fopen("choferes.dat","r+b");
	while (fread(&ch, sizeof(ch), 1, fch) == 1) {
    	if ( ch.DNIChofer== dni) {
    printf("chofer encontrado\n");
    
    puts("\n------------------------\n");
	puts("\nQUE DESEA CAMBIAR DEL USUARIO?\n");
	puts("\n[1]Nombre y Apellido");
	puts("\n[2]DNI:");
	puts("\n[3]Direccion:");
	puts("\n[4]Telefono:");
	puts("\n[5]:Email");
	puts("\n[0]ATRAS\n");
	printf("..:");
	fflush(stdin);
	scanf("%d",&op);
	switch(op) {
		case 1:
			modificar_nom(&ch);
			 fseek(fch, -sizeof(ch), SEEK_CUR);
                    fwrite(&fch, sizeof(ch), 1, fch);                
			break;
		case 2:
			modificar_dni(&ch,fcol,dni);
			 fseek(fch, -sizeof(ch), SEEK_CUR);
                    fwrite(&fch, sizeof(ch), 1, fch);   
			break;
		case 3:
			modificar_direc(&ch);
			 fseek(fch, -sizeof(ch), SEEK_CUR);
                    fwrite(&fch, sizeof(ch), 1, fch);   
			break;
	
		case 4:
			modificar_tele(&ch);
			 fseek(fch, -sizeof(ch), SEEK_CUR);
                    fwrite(&fch, sizeof(ch), 1, fch);  
			break;
		case 5:
			modificar_email(&ch);
			 fseek(fch, -sizeof(ch), SEEK_CUR);
                    fwrite(&fch, sizeof(ch), 1, fch);  
		case 0:
			modificaciones();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			mod_chofer(fcol,fch);
			fclose(fch);
		}
	}else{
				printf("chofer no encontrado");
				mod_chofer(fcol,fch);
				fclose(fch);
			}
		}
		}

	
// MODIFICAR Nombre chofer
void modificar_nom(struct Chofer *ch) {
    char nuevoNombre[200];
    printf("Ingrese el nuevo Nombre y Apellido del chofer: ");
    fflush(stdin);
    fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
    
    // Eliminar el salto de l?nea al final si se lee con fgets
    nuevoNombre[strcspn(nuevoNombre, "\n")] = '\0';

    // Copiar el nuevo nombre al campo correspondiente de la estructura
    strcpy(ch->NombreChofer, nuevoNombre);
    printf("Nombre modificado a: %s\n", ch->nombre);
   
	}

// MODIFICAR el dni de chofer
void modificar_dni(struct chofer *ch, long int dniviejo, FILE *fcol ) {
	fcol=fopen("colectivos.dat","r+b");
	FILE *fch;
	fch=fopen("choferes.dat","r+b");	
    printf("Ingrese el nuevo dni del chofer: ");
    fflush(stdin);
    fgets(ch->DNIChofer, sizeof(ch->DNIChofer), stdin);
    ch->DNIChofer[strcspn(ch->DNIChofer, "\n")] = '\0'; // Elimina el salto de l?nea
    printf("DNI de chofer modificado a: %ld\n", ch->DNIChofer);
     if(fcol!=NULL){
     	fread(&col,sizeof(col),1,fcol);
    	while(!feof(fcol)){
    		if(col.DNIC==dniviejo)
    			col.DNIC=ch.DNIChofer;
    			fseek(fcol,sizeof(col)*(-1),SEEK_CUR);
    			fwrite(&col,sizeof(col),1,fcol);
    		fread(&col,sizeof(col),1,fcol);
		}
	}
	fclose(fcol);
	fclose(fch);
}

// MODIFICAR la direccion 
void modificar_direc(struct chofer *ch) {
    printf("Ingrese la nueva direcci?n del chofer: ");
    fflush(stdin);
    fgets(ch->direccion, sizeof(ch->direccion), stdin);
    ch->direccion[strcspn(ch->direccion, "\n")] = '\0'; // Elimina el salto de l?nea
    printf("Direcci?n modificada a: %s\n", ch->direccion);
}

// MODIFICAR el telefono chofer
void modificar_tele(struct Chofer *ch) {
    printf("Ingrese el nuevo tel?fono del chofer: ");
    fflush(stdin);
    scanf("%ld", &(ch->telefono));
    printf("Tel?fono modificado a: %ld\n", ch->telefono);
}

// MODIFICAR el email del chofer
void modificar_email(struct Chofer *ch) {
    printf("Ingrese el nuevo email del chofer: ");
    fflush(stdin);
    fgets(ch->email, sizeof(ch->email), stdin);
    ch->email[strcspn(ch->email, "\n")] = '\0'; // Elimina el salto de linea
    printf("Email modificado a: %s\n", ch->email);
}

///////////////////////
//MODIFICAR COLECTIVO//
///////////////////////
void mod_col(FILE *col,FILE *ch){
	system("cls");
	int nu,op;
	FILE *fcol, *fch;
	
	printf("\ningrese el numero de unidad a modificar: \n");
	scanf("%d",&nu);
	system("cls");
	fcol=fopen("colectivos.dat","r+b");
	while (fread(&col, sizeof(col), 1, fcol) != NULL) {
    	if (col.nUnidad == nu) {
    printf("colectivo encontrado\n");
    
    puts("\n------------------------\n");
	puts("\nQUE DESEA CAMBIAR DE UNIDAD DE COLECTIVO?\n");
	puts("\n[1]DNI del Chofer");
	puts("\n[2]Turno:");
	puts("\n[3]Marca:");
	puts("\n[4]Modelo:");
	puts("\n[5]:Numero de Asientos");
	puts("\n[6]:Kilometraje");
	puts("\n[7]:Es apto para discapacidad?");
	puts("\n[0]ATRAS\n");
	printf("..:");
	fflush(stdin);
	scanf("%d",&op);
	switch(op) {
		case 1:
			modificar_dnic(&col);
			 fseek(fcol, sizeof(col)*(-1), SEEK_CUR);
                    fwrite(&fcol, sizeof(col), 1, fcol);                
			break;
		case 2:
			modificar_turno(&col);
				fseek(fcol, sizeof(col)*(-1), SEEK_CUR);
                    fwrite(&fcol, sizeof(col), 1, fcol);   
			break;
		case 3:
			modificar_marca(&col);
			 	fseek(fcol, sizeof(col)*(-1), SEEK_CUR);
                    fwrite(&fcol, sizeof(col), 1, fcol); 
			break;
	
		case 4:
			modificar_modelo(&col);
			 fseek(fcol, sizeof(col)*(-1), SEEK_CUR);
                    fwrite(&fcol, sizeof(col), 1, fcol);  
			break;
		case 5:
			modificar_asiento(&col);
			 fseek(fcol, sizeof(col)*(-1), SEEK_CUR);
                    fwrite(&fcol, sizeof(col), 1, fcol); 
    	case 6:
			modificar_km(&col);
			 fseek(fcol, sizeof(col)*(-1), SEEK_CUR);
                    fwrite(&fcol, sizeof(col), 1, fcol); 
        case 7:
			modificar_adap(&col);
			 fseek(fcol, sizeof(col)*(-1), SEEK_CUR);
                    fwrite(&fcol, sizeof(col), 1, fcol);
        
		case 0:
			modificaciones();
			break;
		default:
			puts("ingreso una opcion invalida\n");
			mod_colectivo(fcol);
			fclose(fcol);
	}
			}else{
				printf("colectivo no encontrado");
				mod_chofer(col,ch);
				fclose(col);
				fclose(ch);
			}
		}
	}


// Modificar DNI
void modificar_dnic(struct colectivo *col) {
	Chofer ch;
    printf("Ingrese el nuevo dni del chofer: ");
    fflush(stdin);
    fgets(ch.DNIChofer, sizeof(ch.DNIChofer), stdin);
    ch->DNIChofer[strcspn(ch->DNIChofer, "\n")] = '\0'; // Elimina el salto de l?nea
    printf("DNI de chofer modificado a: %ld\n", ch->DNIChofer);
}
	
//Modificar TURNO
void modificar_turno(struct colectivo *col) {
    printf("Ingrese el nuevo turno (SELECCIONE UNO)\n1-00hs a 11:59hs\n2- 12hs a 23:59hs\n  ");
    fflush(stdin);
    scanf("%d", &(col->turno));
    printf("Turno modificado a: %d\n", col->turno);
}

// Modificar MARCA
void modificar_marca(struct colectivo *col) {
    printf("Ingrese la nueva marca: ");
    fflush(stdin);
    fgets(col->marca, sizeof(col->marca), stdin);
    col->marca[strcspn(col->marca, "\n")] = '\0'; // Elimina el salto de l?nea
    printf(" Marca modificada a: %s\n", col->marca);
}

// Modificar MODELO
void modificar_modelo(struct colectivo *col) {
    printf("Ingrese el nuevo a?o de modelo  ");
    fflush(stdin);
    scanf("%d", &(col->modelo));
    printf("Cantidad de asientos modificado a: %d\n", col->modelo);
    
// Modificar CANTIDAD DE ASIENTOS
void modificar_asiento(struct colectivo *col) {
    printf("Ingrese el nueva cantidad de asientos  ");
    fflush(stdin);
    scanf("%d", &(col->asiento));
    printf("Cantidad de asientos modificado a: %d\n", col->asiento);
}

// MOdificar KILOMETRAJE
void modificar_km(struct colectivo *col) {
    printf("Ingrese el nuevo kilometraje: ");
    fflush(stdin);
    scanf("%f", &(col->km));
    printf("Telefono modificado a: %f\n", col->km);
}

// Modificar DISCAPACIDAD
void modificar_adap(struct colectivo *col) {
   printf("?APTO DISCAPACIDAD?\n1- SI\n0- NO ");
    fflush(stdin);
    scanf("%d", &(col->adap));
    printf("Turno modificado a: %d\n", col->adap);
}





//Consultas
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
			printf("\nId: %s",u.id);
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

////////////////////////////////
//Num de usuarios con BENEFICIOS
////////////////////////////////
void usuarios_cBeneficios() {
	FILE *fu;
	if((fu=fopen("usuarios.dat","rb"))!=NULL){
		Usuarios u;
		fread(&u,sizeof(u),1,fu);
		while(!feof(fu)){
			if(u.tipoU!=1){
			puts("\n------------------------\n");
			printf("\nDATOS DE USUARIOS\n");
			printf("\nNombre y Apellido: %s",u.NyA);
			printf("\nDni: %ld",u.Dni);
			printf("\nFecha de Nacimiento: %d/%d/%d",u.fechaNac[0],u.fechaNac[1],u.fechaNac[2]);
			printf("\nDireccion: %s",u.Direccion);
			printf("\nNro Telefono:%ld",u.Telefono);
			printf("\nTipo de Usuario: %s",u.tipoU);
			printf("\nHabilitacion: %s",u.hbl);
			fread(&u,sizeof(u),1,fu);
			}
		}
	}else printf("no se pudo abrir archivo");
fclose(fu);
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

void carga_fechaNac(int *f) {
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
			f[1]=mes(numm);
			printf("%d\n",f[1]);
		} else if(i==1) {
			int numd;
			printf("Dia: ");
			scanf("%d",&numd);
			f[0]=dia(numd,f[1]);
			printf("%d\n",f[0]);
		} else if(i==2) {
			int numa;
			printf("AÃ±o: ");
			scanf("%d",&numa);
			f[2]=anio(numa,f[1]);
			printf("%d\n",f[2]);
		}

	}

}
/*LA FUNCION "ANIO" COMPRUEBA QUE EL AÑO QUE INGRESO EL USUARIO O ADMINISTRADOR
ES CORRECTA YA QUE NO PUEDE INGRESAR UN AÑO QUE NO LLEGO TDV EJEMPLO 2024*/
int anio(int num, int numm) {
	int band=0;
	int op=0;
	while(numm == 12 && num == 2022) {
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
			if(num1!=12)numm=mes(num1);
		} else if(op==2) {
			printf("AÃ±o: ");
			fflush(stdin);
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

void carga_saldo(long int dni, float sald)
{
	int band=0;
	int pos;
	Cuentas c;
	FILE *p;
	p=fopen("cuentas.dat","r+b");

	if((p==NULL))
	{
		printf("\nERROR\n");
	}else
	{
		fread(&c,sizeof(Cuentas),1,p);
		while((!feof(p))&&band==0)
		{
			printf("%i\n",ftell(p));
			if(dni==c.dni)
			{
				fseek(p,ftell(p)-sizeof(Cuentas),0);
				printf("%i\n",ftell(p));
				system("pause");
				c = modifsaldo(c,sald);
				fwrite(&c,sizeof(Cuentas),1,p);
				fseek(p,ftell(p)-sizeof(Cuentas),0);
				printf("%i\n",ftell(p));
				system("pause");
				band=1;
			}
		
			fread(&c,sizeof(Cuentas),1,p);
		}
		fclose(p);
	}
}

Cuentas modifsaldo(Cuentas c,float saldo)
{
	c.saldoDisp=c.saldoDisp + saldo;
	return c;
}

void fecha2(int fecha[],int hora[]) {
    time_t tiempo;
    struct tm *tmInfo;

    // Obtener el tiempo actual
    time(&tiempo);
    tmInfo = localtime(&tiempo);
	
    // Almacenar la fecha actual en el arreglo
    fecha[0] = tmInfo->tm_mday;     // Día
    fecha[1] = tmInfo->tm_mon + 1;  // Mes (0-11)
    fecha[2] = tmInfo->tm_year + 1900;  // Año (desde 1900)
	hora[0] = tmInfo->tm_hour;
	hora[1] = tmInfo->tm_min;
	printf("%d\n",fecha[0]);
	printf("%d\n",fecha[1]);
	printf("%d\n",fecha[2]);
	printf("%d\n",hora[1]);
	printf("%d\n",hora[1]);
    // Nota: Sumamos 1 al mes y 1900 al año para obtener los valores reales.
}

int aleatorio_entre3(int o)
{
	if(o>30)
	{
		o=0;
	}else if(o>10)
	{
		o=1;
	}else 
	{
		o=2;
	}
	return (o);	
}









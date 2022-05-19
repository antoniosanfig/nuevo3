#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int clave;
	float precio;
	char desc[20];
	int cant;
	
}postres;

void registro_postre(postres post[],int*);
void consulta_pos(postres post[],int*);
void consulta_especifica(postres post[],int*);
int consulta_binaria(postres post[],int, int, int);
void consulta_clave(postres post[],int*);

int main()
{
    postres postre[100];
    
    
    int pos, bajo, alto, clave, valor;
    char opc,opc2;

     do{
     	
     	puts("\n-----POSTRES TONY Y DAFNE-----");
     	puts("a) Registrar Postre.");
     	puts("b) Consultas");
     	puts("f) Salir.");
     	
     	fflush(stdin);
     	scanf("%c",&opc);
     	fflush(stdin);
     	
     	switch(opc)
     	{
     		case 'a': case 'A':
     			registro_postre(postre,&pos);
     		
     	
     			break;
     		case 'b': case 'B':
     			
     			 puts("\n--------------CONSULTAS---------------");
     	         puts("a) Consulta ordenada");
     			 puts("b) Consulta especifica por nombre.");
     		   	 puts("c) Consulta especifica por clave.");
     			 puts("d) Regresar.");
		     	 fflush(stdin);
		     	 scanf("%c",&opc2);
		     	 fflush(stdin);
		     	 
		     	 switch(opc2){
		     	 	
		     	 	case 'a': case 'A':
		     	 		
		     	 	consulta_pos(postre,&pos);
		     	 		
		     	 		break;
		     	 	case 'b': case 'B':
		     	 		
		     	 		consulta_especifica(postre,&pos);
		     	 		
		     	 		break;
		     	 	case 'c': case 'C':
		     	 		consulta_clave(postre,&pos);
		     	 		bajo = 0;
		     	 		alto = pos - 1;
		     	 		printf("Ingrese clave a buscar: ");
		     	 		scanf("%d",&clave);
		     	 		valor= consulta_binaria(postre,bajo,alto,clave);
		     	 		
		     	 		if(valor!=-1){
		     	 			printf("Clave:     Nombre:         Precio:   Cantidad: \n");
		     	 			printf("%-10d  %-18s %-10.2f %d\n",postre[valor].clave, postre[valor].desc,postre[valor].precio,postre[valor].cant);	
							} else{
								printf("No se encontro el producto. \n");
							}
							
		     	 		break;	
				  }
     			 
     			break;
     		default:
			    printf("\n Adios ~(OvO)~ \n");
			 break;		
     		
		 }
     	
	 } while(opc!='f'&&opc!='F');

	
	
	return 0;
}

void registro_postre(postres post[100],int *pos)
{
	system("cls");
	int bandera=0, cla, i=0;
	
	do{
	bandera=0;
	puts("Ingresa la clave del postre: ");
	scanf("%d",&cla);
	fflush(stdin);
	
	for(i=0;i<*pos;i++)
	{
		if(cla==post[i].clave)
		{
			puts("Esta clave ya esta registrada, utiliza otra distinta.");
			bandera=1;
		}
		
	}
	
	}while(bandera!=0);
	
	post[*pos].clave=cla;
	
	puts("Ingresa el nombre del postre: ");
	gets(post[*pos].desc);
	
	puts("Ingresa el costo del postre: ");
	scanf("%f",&post[*pos].precio);
	
	
	puts("Ingresa la cantidad en existencia del postre: ");
	scanf("%d",&post[*pos].cant);
	
	*pos = *pos + 1;
	
	fflush(stdin);
	
}

void consulta_pos(postres post[100], int *pos)
{
   system("cls");
   int i, aux, y;
   char auxiliar[100];
   
   puts("Clave:     Nombre:         Precio:   Cantidad:");

   for(i=1;i<*pos;i++)
   {
	    for(y=0;y<*pos-i;y++)
		{
		   	 if(strcasecmp(post[y].desc,post[y+1].desc)>0)
		   	 {
		   	 	
		   	    aux=post[y].clave;
		   	    post[y].clave=post[y+1].clave;
		   	    post[y+1].clave=aux;
		   	    
		   	    strcpy(auxiliar,post[y].desc);
				strcpy(post[y].desc,post[y+1].desc);
				strcpy(post[y+1].desc,auxiliar);
		   	    
		   	    aux=post[y].precio;
		   	    post[y].precio=post[y+1].precio;
		   	    post[y+1].precio=aux;
		   	    
		   	    aux=post[y].cant;
		   	    post[y].cant=post[y+1].cant;
		   	    post[y+1].cant=aux;
			 }
	    }
   }
   
   for(i=0;i<*pos;i++)
   {
	printf("%-10d  %-18s %-10.2f %d\n",post[i].clave, post[i].desc,post[i].precio,post[i].cant);	
   }
   
   fflush(stdin);
	
}


void consulta_especifica(postres post[100], int *pos)
{
	
	system("cls");
	char nom[20];
	int i,band=0;
	
	 puts("Ingresa el nombre del postre a consultar: ");
      gets(nom);
      
      
      for( i=0;i<*pos;i++)
      {
      	if(strcasecmp(nom,post[i].desc)==0)
      	{
      		  puts("Clave:     Nombre:         Precio:   Cantidad:");
      		  printf("%-10d  %-18s %-10.2f %d\n",post[i].clave, post[i].desc,post[i].precio,post[i].cant);
      		  band=1;
		}
	  }
	  
	  if(band==0)
	  {
	  	printf("El postre que busca no se encuentra en el registro. \n\n");
	  }
	  
	fflush(stdin);
	
}

int consulta_binaria(postres post[100], int bajo, int alto, int clave)
{
	if(bajo<=alto)
	{
		int central=(bajo+alto)/2;
		int valor_central = post[central].clave;
		
		if (clave==valor_central)
		{
			return central;
			
		} else{
		if (clave<valor_central)
		{
			alto = central-1;
		} else{
			bajo = central+1;
			}
		} 
		return consulta_binaria(post,bajo,alto,clave);
	}
	
		return -1;	
}

void consulta_clave(postres post[100], int *pos)
{
   system("cls");
   int i, aux, y;
   char auxiliar[100];
   
   puts("Clave:     Nombre:         Precio:   Cantidad:");

   for(i=1;i<*pos;i++)
   {
	    for(y=0;y<*pos-i;y++)
		{
		   	 if(post[y].clave>post[y+1].clave)
		   	 {
		   	 	
		   	    aux=post[y].clave;
		   	    post[y].clave=post[y+1].clave;
		   	    post[y+1].clave=aux;
		   	    
		   	    strcpy(auxiliar,post[y].desc);
				strcpy(post[y].desc,post[y+1].desc);
				strcpy(post[y+1].desc,auxiliar);
		   	    
		   	    aux=post[y].precio;
		   	    post[y].precio=post[y+1].precio;
		   	    post[y+1].precio=aux;
		   	    
		   	    aux=post[y].cant;
		   	    post[y].cant=post[y+1].cant;
		   	    post[y+1].cant=aux;
			 }
	    }
   }
   
   for(i=0;i<*pos;i++)
   {
	printf("%-10d  %-18s %-10.2f %d\n",post[i].clave, post[i].desc,post[i].precio,post[i].cant);	
   }
   
   fflush(stdin);
	
}



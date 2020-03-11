//Bibliotecas principales para el programa
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

//Función para la escritura de un archivo
void escribirArchivo(char titulo[], char texto[]){
	FILE *fichero;
	fichero=fopen(titulo,"wt"); //Creación del archivo
	fputs(texto,fichero); //Escritura del archivo
	fclose(fichero);
}

int main(void){
	pid_t hijo[5];
	hijo[0]=fork(); //Creación del primer hijo
	if(hijo[0]==0){
		//Acciones a realizar si el proceso es el primer hijo
		escribirArchivo("Hijo1.txt","Hola\n");
		sleep(3);
	}
	else{
		hijo[1]=fork(); //Creación del segundo hijo
		if(hijo[1]==0){
			//Acciones a realizar si el proceso es el segundo hijo
			escribirArchivo("Hijo2.txt","esta\n");
			sleep(3);
		}
		else{
			hijo[2]=fork(); //Creación del tercer hijo
			if(hijo[2]==0){
				/*Acciones a realizar si el proceso es el tercer
				hijo*/
				escribirArchivo("Hijo3.txt","es\n");
				sleep(3);
			}
			else{
				hijo[3]=fork(); //Creación del cuarto hijo
				if(hijo[3]==0){
					/*Acciones a realizar si el proceso es el
					cuarto hijo*/
					escribirArchivo("Hijo4.txt","mi\n");
					sleep(3);
				}
				else{
					hijo[4]=fork(); //Creación del quinto hijo
					if(hijo[4]==0){
						/*Acciones a realizar si el proceso es el
						quinto hijo*/
						escribirArchivo("Hijo5.txt","práctica\n");
						sleep(3);
					}
					else{
						/*Acciones a realizar si el proceso es el
						padre*/
						wait(NULL);
						escribirArchivo("Padre.txt","uno.\n");
					}
				}
			}
		}
	}
}
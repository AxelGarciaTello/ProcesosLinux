#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

void escribirArchivo(char titulo[], char texto[]){
	FILE *fichero;
	fichero=fopen(titulo,"wt");
	fputs(texto,fichero);
	fclose(fichero);
}

int main(void){
	pid_t hijo[5];
	int x;
	hijo[0]=fork();
	if(hijo[0]==0){
		escribirArchivo("Hijo1.txt","Hola");
		sleep(3);
	}
	else{
		hijo[1]=fork();
		if(hijo[1]==0){
			escribirArchivo("Hijo2.txt","esta");
			sleep(3);
		}
		else{
			hijo[2]=fork();
			if(hijo[2]==0){
				escribirArchivo("Hijo3.txt","es");
				sleep(3);
			}
			else{
				hijo[3]=fork();
				if(hijo[3]==0){
					escribirArchivo("Hijo4.txt","mi");
					sleep(3);
				}
				else{
					hijo[4]=fork();
					if(hijo[4]==0){
						escribirArchivo("Hijo5.txt","práctica");
						sleep(3);
					}
					else{
						wait(NULL);
						escribirArchivo("Padre.txt","uno.");
					}
				}
			}
		}
	}
}
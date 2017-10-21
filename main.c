#include <stdio.h>

int main()
{
    FILE* fichero;
    FILE* direccioncorrecta1;
    char direccion[9999];
    char direccioncorrecta[9999];
    int i=0,j=0;
            fichero = fopen("C:/Users/Isaac/Desktop/direccion.txt","r");
            direccioncorrecta1 = fopen("C:/Users/Isaac/Desktop/direccioncorrecta1.txt","w");
            if(fichero==NULL||direccioncorrecta1==NULL){
                printf("Error en main: no se pudo abrir el fichero correctamente\n");
            }
            else{
                printf("\nFichero abierto correctamente\n");
                direccion[i] = getc(fichero);
                direccioncorrecta[i]=direccion[i];
                // Imprimir por pantalla
                while (direccion[i] != EOF)
                {
                    printf("%c",direccion[i]);
                  i++;
                     direccion[i]=fgetc(fichero);
                      direccioncorrecta[i]=direccion[i];
                      if('\\'==direccion[i])
                      {
                          direccioncorrecta[i]='/';
                      }
                }
                printf("\n");

                for(j = 0; j < i; j++){
                      fprintf(direccioncorrecta1,"%c",direccioncorrecta[j]);
                      printf("%c",direccioncorrecta[j]);

                }
                if (feof(fichero))
                   printf("\n End of file reached.\n");
                else
                   printf("\n Something went wrong.\n");

                if (fclose(fichero) != 0||fclose(direccioncorrecta1)){
                printf("Error: no se ha cerrado el fichero.");
                }
                else {
                    printf("Fichero cerrado correctamente\n");
                }
                fclose(fichero);
                fclose(direccioncorrecta1);
                }
}

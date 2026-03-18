#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arreglo[10];
    int tamano = 0;
    int opcion, valor, pos;
    int i;

    srand(time(NULL));

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inicializar con 5 aleatorios\n");
        printf("2. Mostrar arreglo\n");
        printf("3. Agregar al final\n");
        printf("4. Insertar en posicion\n");
        printf("5. Eliminar por posicion\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                tamano = 5;
                for(i = 0; i < tamano; i++) {
                    arreglo[i] = rand() % 100;
                }
                printf("Arreglo inicializado\n");
                break;

            case 2:
                printf("Arreglo: ");
                for(i = 0; i < tamano; i++) {
                    printf("%d ", arreglo[i]);
                }
                printf("\n");
                break;

            case 3:
                if(tamano < 10) {
                    printf("Ingresa valor: ");
                    scanf("%d", &valor);
                    arreglo[tamano] = valor;
                    tamano++;
                } else {
                    printf("Arreglo lleno\n");
                }
                break;

            case 4:
                printf("Posicion: ");
                scanf("%d", &pos);
                printf("Valor: ");
                scanf("%d", &valor);

                if(pos >= 0 && pos <= tamano && tamano < 10) {
                    for(i = tamano; i > pos; i--) {
                        arreglo[i] = arreglo[i - 1];
                    }
                    arreglo[pos] = valor;
                    tamano++;
                } else {
                    printf("Posicion invalida\n");
                }
                break;

            case 5:
                printf("Posicion a eliminar: ");
                scanf("%d", &pos);

                if(pos >= 0 && pos < tamano) {
                    for(i = pos; i < tamano - 1; i++) {
                        arreglo[i] = arreglo[i + 1];
                    }
                    tamano--;
                } else {
                    printf("Posicion invalida\n");
                }
                break;

        }

    } while(opcion != 6);

    return 0;
}
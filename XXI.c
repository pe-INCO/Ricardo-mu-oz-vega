#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO "datos.txt"
#define TEMP_ARCHIVO "temp.txt"

// Prototipos de funciones
void leerArchivo();
void agregarRegistro();
void actualizarRegistro();
void eliminarRegistro();

int main() {
    int opcion;

    do {
        printf("\n--- MENU DE GESTION DE ARCHIVO ---\n");
        printf("1. Leer el archivo completo\n");
        printf("2. Agregar registro\n");
        printf("3. Actualizar un registro\n");
        printf("4. Eliminar registro\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        
        // Validación básica de entrada
        if (scanf("%d", &opcion) != 1) {
            printf("Por favor, ingrese un numero valido.\n");
            while(getchar() != '\n'); // Limpiar buffer en caso de error
            continue;
        }
        getchar(); // Limpiar el buffer del salto de linea

        switch(opcion) {
            case 1: leerArchivo(); break;
            case 2: agregarRegistro(); break;
            case 3: actualizarRegistro(); break;
            case 4: eliminarRegistro(); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while(opcion != 5);

    return 0;
}

// 1. LEER ARCHIVO
void leerArchivo() {
    FILE *archivo = fopen(ARCHIVO, "r");
    char linea[100];

    if (archivo == NULL) {
        printf("\n[!] El archivo no existe o esta vacio.\n");
        return;
    }

    printf("\n--- CONTENIDO DEL ARCHIVO ---\n");
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }
    fclose(archivo);
}

// 2. AGREGAR REGISTRO (Modo "a" de append)
void agregarRegistro() {
    FILE *archivo = fopen(ARCHIVO, "a");
    char texto[100];

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("Ingrese el nuevo registro: ");
    fgets(texto, sizeof(texto), stdin);
    
    fprintf(archivo, "%s", texto);
    fclose(archivo);
    printf("Registro agregado con exito.\n");
}

// 3. ACTUALIZAR REGISTRO
void actualizarRegistro() {
    FILE *archivo = fopen(ARCHIVO, "r");
    FILE *temporal = fopen(TEMP_ARCHIVO, "w");
    char linea[100], buscar[100], nuevoTexto[100];
    int encontrado = 0;

    if (archivo == NULL || temporal == NULL) {
        printf("Error: Asegurate de que el archivo 'datos.txt' exista.\n");
        return;
    }

    printf("Ingrese el texto exacto de la linea que desea actualizar: ");
    fgets(buscar, sizeof(buscar), stdin);
    buscar[strcspn(buscar, "\n")] = 0; // Elimina el \n capturado por fgets

    printf("Ingrese el nuevo contenido: ");
    fgets(nuevoTexto, sizeof(nuevoTexto), stdin);

    while (fgets(linea, sizeof(linea), archivo)) {
        char lineaLimpia[100];
        strcpy(lineaLimpia, linea);
        lineaLimpia[strcspn(lineaLimpia, "\n")] = 0;

        if (strcmp(lineaLimpia, buscar) == 0) {
            fprintf(temporal, "%s", nuevoTexto);
            encontrado = 1;
        } else {
            fprintf(temporal, "%s", linea);
        }
    }

    fclose(archivo);
    fclose(temporal);

    remove(ARCHIVO);
    rename(TEMP_ARCHIVO, ARCHIVO);

    if (encontrado) printf("Registro actualizado correctamente.\n");
    else printf("No se encontro ninguna coincidencia exacta.\n");
}

// 4. ELIMINAR REGISTRO
void eliminarRegistro() {
    FILE *archivo = fopen(ARCHIVO, "r");
    FILE *temporal = fopen(TEMP_ARCHIVO, "w");
    char linea[100], borrar[100];
    int encontrado = 0;

    if (archivo == NULL || temporal == NULL) {
        printf("Error al procesar el archivo.\n");
        return;
    }

    printf("Ingrese el texto exacto de la linea a eliminar: ");
    fgets(borrar, sizeof(borrar), stdin);
    borrar[strcspn(borrar, "\n")] = 0;

    while (fgets(linea, sizeof(linea), archivo)) {
        char lineaLimpia[100];
        strcpy(lineaLimpia, linea);
        lineaLimpia[strcspn(lineaLimpia, "\n")] = 0;

        if (strcmp(lineaLimpia, borrar) != 0) {
            fprintf(temporal, "%s", linea);
        } else {
            encontrado = 1;
        }
    }

    fclose(archivo);
    fclose(temporal);

    remove(ARCHIVO);
    rename(TEMP_ARCHIVO, ARCHIVO);

    if (encontrado) printf("Registro eliminado.\n");
    else printf("No se encontro el registro.\n");
}
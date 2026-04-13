#include <stdio.h>

// Función para intercambiar valores
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función QuickSort
void quicksort(int arr[], int inicio, int fin) {
    int i = inicio;
    int j = fin;
    int pivote = arr[(inicio + fin) / 2]; // pivote central

    while (i <= j) {
        while (arr[i] < pivote) {
            i++;
        }
        while (arr[j] > pivote) {
            j--;
        }
        if (i <= j) {
            intercambiar(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    // Llamadas recursivas
    if (inicio < j)
        quicksort(arr, inicio, j);

    if (i < fin)
        quicksort(arr, i, fin);
}

// Función para imprimir
void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main
int main() {
    int datos[] = {8, 3, 1, 7, 0, 10, 2};
    int n = sizeof(datos) / sizeof(datos[0]);

    quicksort(datos, 0, n - 1);

    printf("Arreglo ordenado: ");
    imprimir(datos, n);

    return 0;
}
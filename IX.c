
#include <stdio.h>

int main()
{
    float notas [3][4];
    float suma, promedio;
    float max;
    int posEst = 0,  posMat = 0; 
    
    for (int i = 0; i<3;i++){
    printf("\nEstudiante %d:\n", i + 1);
    for (int j = 0; j<4;j++){
        printf ("ingrese la nota de la materia %d:",j+1);
        scanf ("%f",&notas[i][j]);
    }
}
    printf ("\n Matriz de notas:\n");
    for(int i=0; i<3; i++){
    for(int j=0; j<4;j++){
        printf("%2.f",notas [i][j]);
    }
    printf("\n");
}
    printf("\nPromedio por estudiante:\n");
    for(int i = 0; i<3; i++){
        suma = 0; 
        for(int j = 0; j < 4; j++){
            suma += notas[i][j];
    }
     promedio = suma / 4;
        printf("Estudiante %d: %.2f\n", i + 1, promedio);
      printf("\nPromedio por materia:\n");
    for (int j = 0; j < 4; j++) {
        suma = 0;
        for (int i = 0; i < 3; i++) {
            suma += notas[i][j];
        }
        promedio = suma / 3;
        printf("Materia %d: %.2f\n", j + 1, promedio);
    }

    max = notas[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (notas[i][j] > max) {
                max = notas[i][j];
                posEst = i;
                posMat = j;
            }
        }
    }

    printf("\nNota mas alta: %.2f\n", max);
    printf("Corresponde al Estudiante %d, Materia %d\n", posEst + 1, posMat + 1);

    return 0;
}
}
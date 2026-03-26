
#include <stdio.h>

int main()
{
    int i,j,temp,n;
    int arreglo []={30,60,70,80,90,100};
    n =sizeof (arreglo) /sizeof(arreglo[0]);
    
        for (i=0; i<n-1;i++){
            for(j=i+1;j < n; j++){
                
            if (arreglo[i]>arreglo[j]){
                temp = arreglo[i];
                arreglo [i]= arreglo[j];
                arreglo[j]= temp;
                
                printf("%d, ",arreglo[i]);
                printf("%d,",arreglo[j]);
        }
    }
        }
        for(i=0; i<n-1; i++)
        printf ("%d",arreglo[i]);
        return 0;
}
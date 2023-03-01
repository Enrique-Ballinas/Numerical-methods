// Diseñar un programa en C, que encuentre la raíz de la siguiente función utilizando el método de la bisección
// 𝑓(𝑥)=𝑒^(−𝑥)−𝑥

#include <stdio.h>
#include <math.h>

float f_x(float x){
    #define E 2.71828182845904523536
    return pow(E,-x) - x;
}

int main(){
    float xl; // intervalo inferior
    float xu; // intervalo superior
    float xr; // nuevo limite
    float ep = 1; // Error minimo en porcentaje
    int bandera = 0; // variable para identificar paso 1
    float error = 0;
    int iter = 0; // iteraciones

    // Paso 1. Verificamos si f(xl).f(xu) < 0
    while(bandera == 0){
        printf("Ingrese el intervalo inferior Xl: ");    
        scanf("%f", &xl);
        printf("Ingrese el intervalo superior Xu: ");    
        scanf("%f", &xu);

        if(f_x(xl)*f_x(xu) < 0){
            bandera = 1;
        }
        else{
            printf("Intervalos no validos... \n");
        }
    }

    bandera = 0;

    while (bandera == 0)
    {
        // Paso 2. Calculo Xr
        xr = (xl + xu) / 2;

        // Calculo el error
        error = (fabs(xl - xu) / 2) * 100;
        if(error <= ep){
            bandera = 1; // termina el proceso
        }
        else{
            // Paso 3. Realizamos las siguiente evaluaciones para determinar en que subintervalo se encuentra la raiz
            if(f_x(xl)*f_x(xr) < 0){
                xu = xr;
            }
            else{
                xl = xr;
            }
        }
        iter+=1;
    }
    printf("La raiz de la funcion es: %f con un error de %f %%\n", xr, error);
    printf("Se realizaron %d iteraciones", iter);
    return 0;
}
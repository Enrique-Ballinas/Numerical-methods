// Implementar el programa del método de la bisección y probar con la siguiente función.
// 𝑓(𝑥)=𝑒^3𝑥−4

#include <stdio.h>
#include <math.h>

// 𝑓(𝑥)=𝑒^(−𝑥)−𝑥
float f_x(float x){
    #define E 2.71828182845904523536
    return pow(E,-x) - x;
}
// 𝑓(𝑥)=𝑒^3𝑥−4
float f_x1(float x){
    #define E 2.71828182845904523536
    return pow(E,(3*x)) - 4;
}


int main(){
    float xl; // intervalo inferior
    float xu; // intervalo superior
    float xr; // nuevo limite
    float ep = 0.1; // Error minimo en porcentaje
    int bandera = 0; // variable para identificar paso 1
    float error = 0;
    int iter = 0; // iteraciones

    // Paso 1. Verificamos si f(xl).f(xu) < 0
    while(bandera == 0){
        printf("Ingrese el intervalo inferior Xl: ");    
        scanf("%f", &xl);
        printf("Ingrese el intervalo superior Xu: ");    
        scanf("%f", &xu);

        if(f_x1(xl)*f_x1(xu) < 0){
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
            if(f_x1(xl)*f_x1(xr) < 0){
                xu = xr;
            }
            else{
                xl = xr;
            }
        }
        iter+=1;
    printf("iteracion: %d, Xr: %f, Error: %f %%\n", iter, xr, error);
    }
    return 0;
}
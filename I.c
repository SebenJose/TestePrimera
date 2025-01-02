#include <stdio.h>
#include <math.h>


    int main(){


        double a, b , c, x1, x2, delta;
       
            printf("Digete suas entradas: ");
            scanf("%lf %lf %lf", &a, &b, &c);


    delta = (b*b) - 4*a*c;


    x1 = (-b - sqrt(delta)) / (2*a);
    x2 = (-b + sqrt(delta)) / (2*a);


        if (delta < 0) {
            printf("Nao ha raizes reais!!\n");
        } else {
            printf("As raizes sao: %.2f %.2f", x1, x2 );
        }


return 0;
    }

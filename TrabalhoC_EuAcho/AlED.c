#include <stdio.h>
#include <math.h>
char primo(int n) {
    if(n==2)return 's';
    if (n <= 1) return '<';
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 'S';
    }
    return 'N';
}
char par (int n){
    if(n%2 == 0) return 'S';
    return 'N';
}
char quadrado (int n){
    if ((n = sqrt(n))%1 == 0 )return 'S'; 
    return 'N'; 
}
int multiplo6(int n) {
    if ((n%2== 0) && (n%3 == 0)) return 'S';
     return 'N'; 
}
int main(){ 
    int n;
    scanf ("%d", &n);
    printf("PRIMO : %c\n",primo(n));
    printf("PAR : %c\n",par(n));
    printf("QUADRADO PERFEITO: %c\n",quadrado(n));
    printf("MULTIPLO DE 6: %c\n",multiplo6(n));
    return 0;   
}
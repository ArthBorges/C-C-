#include <stdio.h>

const double PI = 3.14159;

int main() {
 
    double raio, area;
    scanf("%f", &raio);
    
    area = PI * raio * raio;
    printf("A=%.4f\n", area);
    
    return 0;
}
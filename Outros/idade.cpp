#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a_nasc, a_atual;

    a_nasc = atoi(argv[2]);
    a_atual = atoi(argv[3]);

    printf("Oi %s, você tem %d anos\n", argv[1], a_atual - a_nasc);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int senha, senha_valida;

    scanf("%d", &senha);
    printf("senha cadastrada: %d\n", senha);

    while (1){
        scanf("%d", &senha_valida);

        if (senha_valida == senha) {
            printf("Senha valida!\n");
            break;
        } else {
            printf("Senha invalida!\n");
        }
    }

    return 0;
}
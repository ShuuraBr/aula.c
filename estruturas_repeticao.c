#include <stdio.h>

int main() {
  float nota;

  while (1) {
    printf("Digite a nota: ");
    scanf("%f", &nota);

    if (nota >= 0 && nota <= 10) {
      break;
    } else {
      printf("Nota inválida. Digite novamente.\n");
    }
  }

  printf("A nota digitada foi: %.2f\n", nota);

  return 0;
}
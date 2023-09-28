#include <stdio.h>
 
int main() {
   // Anos dos Jogos Olímpicos de Verão e Copa do Mundo de Futebol
   int jogos_olimpicos_verao[] = {1896, 1900, 1904, 1908, 1912, 1920, 1924, 1928, 1932, 1936, 1948, 1952, 1956, 1960, 1964, 1968, 1972, 1976, 1980, 1984, 1988, 1992, 1996, 2000, 2004, 2008, 2012, 2016};
   int copa_do_mundo[] = {1930, 1934, 1938, 1950, 1954, 1958, 1962, 1966, 1970, 1974, 1978, 1982, 1986, 1990, 1994, 1998, 2002, 2006, 2010, 2014};
 
   // Entrada do ano
   int ano;
   scanf("%d", &ano);
 
   // Verifica se ocorreram Jogos Olímpicos de Verão
   int ocorreu_jogos_olimpicos = 0;
   for (int i = 0; i < sizeof(jogos_olimpicos_verao) / sizeof(jogos_olimpicos_verao[0]); i++) {
       if (ano == jogos_olimpicos_verao[i]) {
           ocorreu_jogos_olimpicos = 1;
           break;
       }
   }
 
   // Verifica se ocorreu a Copa do Mundo de Futebol
   int ocorreu_copa_do_mundo = 0;
   for (int i = 0; i < sizeof(copa_do_mundo) / sizeof(copa_do_mundo[0]); i++) {
       if (ano == copa_do_mundo[i]) {
           ocorreu_copa_do_mundo = 1;
           break;
       }
   }
 
   // Exibe a saída de acordo com o resultado
   if (ocorreu_jogos_olimpicos && ocorreu_copa_do_mundo) {
       printf("Os Jogos Olímpicos de Verão e a Copa do Mundo de Futebol ocorreram no ano de %d.\n", ano);
   } else if (ocorreu_jogos_olimpicos) {
       printf("Os Jogos Olímpicos de Verão ocorreram no ano de %d.\n", ano);
   } else if (ocorreu_copa_do_mundo) {
       printf("A Copa do Mundo de Futebol ocorreu no ano de %d.\n", ano);
   } else {
       printf("Não houve Jogos Olímpicos de Verão ou Copa do Mundo no ano de %d.\n", ano);
   }
 
   return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, v, soma;
    soma=0;

    scanf("%d",&n);
    

    if(n%2==0){
        printf("%d eh par\n", n);
        v=n;
        while(n>0){
            soma=soma+n%10;
            n=n/10;
        }
        printf("A soma dos algarismo de %d eh %d\n", v, soma);
    }  else if(n%2!=0){
        printf("%d eh impar\n", n);
        v=n;
        while(n>0){
            soma=soma+n%10;
            n=n/10;
        }
        printf("A soma dos algarismo de %d eh %d\n", v, soma);
    }
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isPrime(int x){
    if (x<=1) return 0;
    if (x==2) return 1;
    for (int i=2;i<x;i++){
        if (x%i==0){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char * argv[argc + 1]){
    FILE * fp = fopen(argv[1],"r");
    if(fp==NULL) return 0;
    int number;
    while (fscanf(fp,"%d",&number) != EOF){
        if(isPrime(number)){
            if(isPrime(number-2) || isPrime(number+2)){
                printf("yes\n");
                continue;
            }
        }
        printf("no\n");
    }

    return EXIT_SUCCESS;
}

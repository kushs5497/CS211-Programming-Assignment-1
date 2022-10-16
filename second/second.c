#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get(int x,int n){
    int bit = (x>>n)&1;
    return bit;
}
int set(int x, int n,int v){
    if(v==1)x|=1<<n;
    else x&= ~(1<<n);
    return x;
}
int comp(int x, int n){
    x ^=1<<n;
    return x;
}

int main(int argc, char const *argv[]){
    FILE * file = fopen(argv[1],"r");
    if(file==NULL) return 0;
    int x=0;
    fscanf(file,"%d",&x);
    char str[]="    ";
    int n = 0;
    int v=0;
    while (fscanf(file,"%s %d %d",str, &n, &v) != EOF){
        if(str[0]=='g'){
            printf("%d\n",get(x,n));
        }
        else if(str[0]=='s') {
            x=set(x,n,v);
            printf("%d\n",x);
        }
        else if(str[0]=='c'){
            x=comp(x,n);
            printf("%d\n",x);
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int x=atoi(argv[1]);
    int oneBits=(x>>1)&1;
    int lastbit=(x>>1)&1;
    int parity=0;
    while(x>0){
        //printf("%d\n",x);
        if(((x>>1)&1)==1){
            oneBits++;
            if(lastbit==1){
                parity++;
                lastbit=0;
            }
            else lastbit++;
        }
        x=x>>1;
    }
    if (oneBits%2==0) printf("Even-Parity\t%d\n",parity);
    else printf("Odd-Parity\t%d\n",parity);
    return 0;
}

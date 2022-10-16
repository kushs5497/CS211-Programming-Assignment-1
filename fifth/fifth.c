#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node* hashTable[10000];

int search(int x){
    for(node * ptr = hashTable[x%10000];ptr!=NULL;ptr=ptr->next){
        if(ptr->data==x) return 1;
    }
    return 0;
}

int insert(int x){
    node *new = malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(hashTable[x%10000]==NULL){
        hashTable[x%10000]=new;
        return 0;
    }
    if(search(x)){
        free(new);
        return 1;
    }
    new->next=hashTable[x%10000];
    hashTable[x%10000]=new;
    return 1;
}

int main(int argc, char const *argv[]){
    FILE * file = fopen(argv[1],"r");
    char command='i';
    int value=0;
    int collisionCount=0;
    int successCount=0;
    while (fscanf(file,"%c %d",&command,&value)!=EOF){
        if(command=='i'){
            if(insert(value)) collisionCount++;
        }
        if(command=='s'){
            if(search(value)) successCount++;
        }
    }
    printf("%d\n%d\n",collisionCount,successCount);
    
    return 0;
}


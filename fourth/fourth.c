#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node * head = NULL;

void printList(){
    if(head==NULL){
        printf("EMPTY\n");
        return;
    }
    for(node * ptr = head;ptr!=NULL;ptr=ptr->next){
        if(ptr->next==NULL) printf("%d\n",ptr->data);
        else printf("%d ",ptr->data);
    }
}

void insert(int x){
    node * ptr = head;
    node *temp = malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    if(ptr == NULL){
        head = temp;
        printList();
        return;
    }
    if(ptr->data==temp->data){
        free(temp);
        printList();
        return;
    }
    while(ptr->next != NULL){
        if(ptr->data < x && ptr->next->data > x){
            temp->next = ptr->next;
            ptr->next = temp;
            printList();
            return;
        }
        if(ptr->data > x){
            temp->next = ptr;
            head = temp;
            printList();
            return;
        }
        if(ptr->next->data==x){
            free(temp);
            printList();
            return;
        }
        ptr = ptr->next;
    }
    if(ptr->data < x){
        ptr->next = temp;
        printList();
        return;
    }
    temp->next = ptr;
    head = temp;
    printList();
    return;
}

int delete(int x){
    if(head->data==x){
        node * del=head;
        head=head->next;
        free(del);
        return 1;
    }
    if(head==NULL) return 0;
    node * ptr = head;
    while (ptr->next!=NULL && ptr->next->data!=x){
        ptr=ptr->next;
    }
    if(ptr->next->data==x){
        node * del=ptr->next;
        ptr->next=ptr->next->next;
        free(del);
        return 1;
    }
    return 0;
}

int main(int argc, char * argv[argc + 1]){
    FILE * file = fopen(argv[1],"r");
    char command[]="      ";
    int value;
    while(fscanf(file,"%s %d",command,&value)!=EOF){
        if(command[0]=='I'){
            insert(value);
        }
        else{
            if(delete(value)) printf("SUCCESS\n");
            else printf("FAILED\n");
        }
    }
    fclose(file);
    return 0;
}

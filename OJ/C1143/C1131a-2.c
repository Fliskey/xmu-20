#include <stdio.h>
#include <string.h>

typedef struct Node{
    char word[12];
    int count;
    struct Node *next;
}Node,*Linklist;

int linkadd(){
    extern Linklist Head;
    Linklist p;
    p = (Linklist) malloc(sizeof(Node));
    strcpy(p->word,wordin);
    if(Head->next == NULL){
        p->count = 1;
        p->next = NULL;
        Head->next = p;
        return 0;
    }

    //first search wordin
    Linklist q;
    q = Head->next;
    while(q){
        int value;
        value = strcmp(q->word,p->word);
        if(value == 0){
            q->count++;
            return 0;
        }
        q = q->next;
    }
    
    //second insert p
    p->count = 1;
    q = Head;
    while(q->next){
        int value;
        value = strcmp(q->next->word,p->word);
        if(value < 0){
            p->next = q->next;
            q->next = p;
            return 0;
        }
        q = q->next;
    }
    p->next = NULL;
    q->next = p;

    return 0;
}

int main(){

    Linklist Head;
    Head = (Linklist) malloc(sizeof(Node));
    Head->next = NULL;

    char line[10004];
    while(gets(line)){
        int linei = 0;
        int linelen = strlen(line);
        int in_begin = 0;
        char wordin[12];
        for(int i=0;i<linlen;i++){
            if()
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* last;
    struct Node* next;
}Node,*Linklist;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        Linklist Head;
        Head->data = 0;
        Head->last = Head;
        Head->next = Head;
        for(int i=1;i<=n;i++){
            Linklist p;
            p->data = i;

            Head->last->next = p;
            p->last = Head->last;
            Head->last = p;
            p->next = Head;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* last;
    struct Node* next;
}Node,*Linklist;

int main(){
    int n,m;
    int is_a = 1;
    while(scanf("%d %d",&n,&m) != EOF){
        if(!is_a){
            printf("\n");
        }
        Linklist Head;
        Head = (Linklist) malloc(sizeof(Node));
        Head->data = 0;
        Head->last = Head;
        Head->next = Head;
        for(int i=1;i<=n;i++){
            Linklist p = (Linklist) malloc(sizeof(Node));
            p->data = i;

            Head->last->next = p;
            p->last = Head->last;
            Head->last = p;
            p->next = Head;
        }
        int is_first = 1;
        Linklist p = Head->next;
        while(n!=0){
            for(int i=2;i<=m;i++){
                p = p->next;
                if(p->data == 0){
                	p = p->next;
				}
            }
            if(is_first){
                printf("%d",p->data);
                is_first = 0;
            }
            else{
                printf(" %d",p->data);
            }
            p->last->next = p->next;
            p->next->last = p->last;
            Linklist del = p;
            p = p->next;
            if(p->data == 0){
            	p = p->next;
			}
            free(del);
            n--;
        }
        if(is_a){
            is_a = 0;
        }
    }
    return 0;
}

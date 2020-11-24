#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char word[12];
    int count;
    struct Node *next;
}Node,*Linklist;

void swap(Linklist l1_front,Linklist l2_front){
	
}

int main(){
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    Linklist Head;
    Head = (Linklist) malloc(sizeof(Node));
    Head->next = NULL;

    char wordin[12];

    while(scanf("%s",wordin) != EOF){
        Linklist p;
        p = (Linklist) malloc(sizeof(Node));
        strcpy(p->word,wordin);
        if(Head->next == NULL){
            p->count = 1;
            p->next = NULL;
            Head->next = p;
            continue;
        }

        //first search wordin
        Linklist q;
        q = Head->next;
        while(q){
            int value;
            value = strcmp(q->word,p->word);
            if(value == 0){
                q->count++;
                goto mcon;
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
                goto mcon;
            }
            q = q->next;
        }
        p->next = NULL;
        q->next = p;

        mcon : continue;
    }
    
    Linklist k;
    k = Head->next;

    while(k){
        printf("%s(%d)\n",k->word,k->count);
        k = k->next;
    }
    
    //sort
	Linklist p;
	p = Head;
	
	while(p->next){
		
	}

    return 0;
}

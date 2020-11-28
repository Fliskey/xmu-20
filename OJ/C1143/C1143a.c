#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char word[12];
    int count;
    struct Node *next;
}Node,*Linklist;

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
    
    Node ans[1004];

    while(k){
        printf("%s(%d)\n",k->word,k->count);

        k = k->next;
    }
    
    /*
	//choose sort
    int numi = 0;
    for( ;numi<1000;numi++){
        if(Head->next == NULL){
            break;
        }
        int max = 0;
        Linklist maxp,loop;
        loop = Head;
        while(loop->next){
            if(loop->next->count > max){
                maxp = loop;
                max = loop->next->count;
            }
        }
        ans[numi] = *(maxp->next);
        maxp->next = maxp->next->next;
    }
    for(int i=0;i<numi;i++){
        printf("%s(%d)\n",ans[i].word,ans[i].count);
    }
	
	*/ 
    return 0;
}

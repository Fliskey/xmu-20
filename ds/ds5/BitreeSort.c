#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 20
#define MAXNUM 200

int data[N];

typedef int KeyType;

typedef struct BiTnode
{
    KeyType key;  //关键字域
    struct BiTnode *Lchild;  //左指针域
    struct BiTnode *Rchild;  //右指针域
} BiTnode, *BiTree;

int Insert(BiTree*,KeyType);
int PrintTree(BiTree);
int Search(BiTree,KeyType);
int DelNode(BiTree,KeyType);

int main(){
    srand(time(0));
    BiTree root = (BiTree) malloc (sizeof(BiTnode));
    root->Lchild = NULL;
    root->Rchild = NULL;
    root->key = 0x7fffffff;

    printf("插入数据：");
    for(int i=1;i<=N;i++){
        int x = rand() % MAXNUM;
        data[i-1] = x;
        printf("%d ",x);
        Insert(&root,x);
    }
    printf("\n中序遍历：");
    PrintTree(root);
    printf("\n");

    for(int i=1;i<=MAXNUM/N;i++){
        int x = rand() % MAXNUM;
        printf("查找%-3d :",x);
        int re = Search(root,x);
        if(re != 0){
            printf("查找成功！查找长度为：%d\n",re);
        }
        else{
            printf("查找失败\n");
        }
    }

    printf("\n");
    
    int chosen[N] = {0};
    for(int i=1;i<=N/3;i++){
        int x = rand()%N;
        while(chosen[x] != 0){
            x = rand()%N;
        }
        chosen[x] = 1;
        printf("待删除数：%d\n",data[x]);
        DelNode(root,data[x]);
        printf("删除后遍历：");
        PrintTree(root);
        printf("\n\n");
    }
    
    printf("补充插入：");
    for(int i=1;i<=N/3;i++){
        int x = rand()%MAXNUM;
        printf("%d ",x);
        Insert(&root,x);
    }
    printf("\n插入后遍历：");
    PrintTree(root);
    printf("\n");

    system("pause");
    return 0;
}

int DelNode(BiTree T, KeyType key){
    if(!Search(T,key)){
        printf("此数不在树中！\n");
        return 0;
    }
    BiTree p = T;
    BiTree q = p;
    int lr = 0;//left0 right1
    while(p->key != key){
        q = p;
        if(p->key > key){
            lr = 0;
            p = p->Lchild;
        }
        else{
            lr = 1;
            p = p->Rchild;
        }
    }
    if(p->Rchild == NULL && p->Lchild == NULL){
        if(lr == 1){
            q->Rchild = NULL;
            free(p);
        }
        else{
            q->Lchild = NULL;
            free(p);
        }
        return 1;
    }
    if(p->Rchild == NULL){
        if(lr == 1){
            q->Rchild = p->Lchild;
        }
        else{
            q->Lchild = p->Lchild;
        }
        return 1;
    }
    if(p->Lchild == NULL){
        if(lr == 1){
            q->Rchild = p->Rchild;
        }
        else{
            q->Lchild = p->Rchild;
        }
        return 1;
    }
    BiTree s = p;
    s = s->Lchild;
    while(s->Rchild != NULL){
        q = s;
        s = s->Rchild;
    }
    p->key = s->key;
    if(q == p){
        p->Lchild = s->Lchild;
    }
    else{
        
    }
    return 1;
}

int link(BiTree T,)

int Search(BiTree T, KeyType key){
    if(T == NULL){
        return 0;
    }
    int r =Search(T->Lchild,key);
    if(r){
        return r+1;
    }
    if(T->key == key){
        return 1;
    }
    r = Search(T->Rchild,key);
    if(r){
        return r+1;
    }
}

int PrintTree(BiTree T){
    if(T == NULL){
        return 0;
    }
    PrintTree(T->Lchild);
    if(T->key != 0x7fffffff)
        printf("%d ",T->key);
    PrintTree(T->Rchild);
}

int Insert(BiTree *T,KeyType key){
    BiTree p = *T;
    BiTree q = (BiTree) malloc (sizeof(BiTnode));
    q->Rchild = NULL;
    q->Lchild = NULL;
    q->key = key;

    while(p->Lchild != NULL || p->Rchild != NULL){
        if(p->key == key){
            free(q);
            return 0;
        }
        else if(p->key > key){
            if(p->Lchild == NULL){
                p->Lchild = q;
                return 1;
            }
            else{
                p = p->Lchild;
            }
        }
        else{
            if(p->Rchild == NULL){
                p->Rchild = q;
                return 1;
            }
            else{
                p = p->Rchild;
            }
        }
    }
    q->key = key;
    if(p->key > key){
        p->Lchild = q;
    }
    else{
        p->Rchild = q;
    }
    return 1;
}

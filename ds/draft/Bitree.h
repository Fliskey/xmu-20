
int TreeVisit(BiTree root){

}

int TreeInsert(BiTree root,BiTree ready){
    BiTree p = root;
    while(p->Lchild || p->Rchild){
        if(ready->key > p->key){
            p = p->Rchild;
        }
        else{
            p = p->Lchild;
        }
    }
    if(ready->key > p->key){
        p->Rchild = ready;
    }
    else{
        p->Lchild = ready;
    }
    return 1;
}

int TreeInit(BiTree T){
    T = (BiTree) malloc (sizeof(BiTnode));
    T->key = -1;
    T->Lchild = NULL;
    T->Rchild = NULL;
    return 1;
}

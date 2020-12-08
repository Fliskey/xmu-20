#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int KeyType;

typedef struct BiTnode
{
    KeyType key;  //关键字域
//  ElemType *otherinfo;  //其它数据项(可以忽略)
    struct BiTnode *Lchild;  //左指针域
    struct BiTnode *Rchild;  //右指针域
} BiTnode, *BiTree;

int main(){
    BiTree root;
    TreeInit(root);

    int n;
    printf("请输入数据个数：");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d. ",i);
        int x;
        scanf("%d",&x);

        BiTree p;
        TreeInit(p);
        p->key = x;

        TreeInsert(root,p);
    }

    return 0;
}

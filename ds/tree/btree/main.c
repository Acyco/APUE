//
// Created by Acyco on 2023-12-23.
//
#include <stdio.h>
#include <stdlib.h>



#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

struct node_st
{
    struct score_st data;
    struct node_st *l, *r;
};

struct node_st *tree = NULL;

void print_s(struct score_st *d)
{
    printf("%d %s %d %d \n",d->id,d->name,d->math,d->chinese);
}

int insert(struct node_st **root, struct score_st *data)
{
    struct node_st *node;
    if(*root == NULL) // 如果节点为空我就要申请 并把第一个节点放进
    {
       node =  malloc(sizeof(*node));
       if(node == NULL)
           return -1;
       node->data = *data;
       node->l = NULL;
       node->r = NULL;
       *root = node;
       return 0;
    }

    if(data->id <= (*root)->data.id) // 走到叶子节点  进行比较 当前的数据id比叶子节点id小就放在左边
      return  insert(&(*root)->l, data);
    return insert(&(*root)->r, data);
}

struct score_st *find(struct node_st *root, int id)
{
    if(root == NULL) // 没有找到
        return NULL;
    if(id == root->data.id)
        return &root->data;

    if(id < root->data.id) // 如果比叶子节点小 就往左边找
       return find(root->l ,id);
    else
       return find(root->r ,id);

}

void draw_(struct node_st *root, int level)
{
    int i;
    if(root == NULL)
        return ;
    draw_(root->r,level+1);
    for (i = 0; i < level; i++)
        printf("    ");
    print_s(&root->data);

    draw_(root->l,level+1);

}

void draw(struct node_st *root)
{
    draw_(root,0);
}

int main()
{
    int arr[] = {1, 2, 3, 7, 6, 5, 9, 8, 4};
    int i ;
    struct score_st tmp, *datap;

    for(i = 0; i < sizeof(arr)/ sizeof(*arr); i++ )
    {
        tmp.id = arr[i];
        snprintf(tmp.name,NAMESIZE,"stu%d", arr[i]);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;
        insert(&tree, &tmp);
    }

    draw(tree);

#if 0
    int tmpid = 12;
    datap = find(tree,tmpid);
    if(datap == NULL)
        printf("Can not find the id %d\n", tmpid);
    else
        print_s(datap);
#endif

    exit(0);
}
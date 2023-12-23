//
// Created by Acyco on 2023-12-23.
//
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

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

    draw_(root->r,level + 1);

    for (i = 0; i < level; i++)
        printf("    ");
    print_s(&root->data);

    draw_(root->l,level + 1);
}

void draw(struct node_st *root)
{
    draw_(root,0);
    printf("\n\n");
//    getchar();
}


static int get_num(struct node_st *root)
{
    if(root == NULL)
        return 0;
    return get_num(root->l) + 1 + get_num(root->r); // 左右子节点 + 自身
}


static struct node_st *find_min(struct node_st *root)
{
    if(root->l == NULL)
        return root;
    return find_min(root->l);
}

static struct node_st *find_max(struct node_st *root)
{
    if(root->r == NULL) //r
        return root;
    return find_max(root->r);
}

// 左旋
static void turn_left(struct  node_st **root)
{
    struct node_st *cur = *root; // 保存当前旧的根节点
    *root = cur->r; // 把旧的右子节点挂在根节点
    cur->r = NULL; // 把当前的右子节点为空
    find_min(*root)->l = cur; // 继续找新的根节点最左边的叶子节点 把当前旧的根节点挂上
//    draw(tree);
}

// 右旋
static void turn_right(struct node_st **root)
{
    struct node_st *cur = *root; // 保存当前旧的根节点 6
    *root = cur->l; // 把旧的左叶子节点挂在根节点 root 5
    cur->l = NULL; // 把当前的左子叶子节点设置为空 5
    find_max(*root)->r = cur; // 继续找新的根节点最右边的叶子节点 把当前旧的根节点挂上
//    draw(tree);
}

void balance(struct node_st **root)
{
    int sub;
    if(*root == NULL)
        return;
    while (1)
    {
        sub = get_num((*root)->l) - get_num((*root)->r);
        if(sub >= -1 && sub <= 1)
            break;
        if(sub < -1)
            turn_left(root);
        else
            turn_right(root);
    }

    balance(&(*root)->l); // 再平衡左叶子节点
    balance(&(*root)->r); // 再平衡右叶子节点
}

void delete(struct node_st **root, int id)
{
    struct node_st **node = root;
    struct node_st *cur = NULL;
    while (*node != NULL && (*node)->data.id != id)
    {
        if(id < (*node)->data.id)
            node = &(*node)->l;
    }
    if(*node == NULL)
        return ;

    cur = *node;

    if(cur->l == NULL)
        *node = cur->r;
    else
    {
        *node = cur->l;
        find_max(cur->l)->r = cur->r;
    }
    free(cur);
}

#if 0
void travel(struct node_st *root)
{
    if(root == NULL)
        return;
    print_s(&root->data);
    travel(root->l);
    travel(root->r);
}

#else

void travel(struct node_st *root)
{
    QUEUE *qu;
    struct node_st *cur;
    int ret;

    qu = queue_create(sizeof(struct node_st *));

    if(qu == NULL)
        return;
    queue_en(qu, &root);
    /* if error */
    while (1)
    {

        ret = queue_de(qu, &cur);
        if(ret == -1)
            break;
        print_s(&cur->data);

        if(cur->l != NULL)
            queue_en(qu, &cur->l);
        if(cur->r != NULL)
            queue_en(qu, &cur->r);
    }

    queue_destroy(qu);
}

#endif

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

    balance(&tree);

    draw(tree);


    travel(tree);
#if 0
    int tmpid = 5;
    delete(&tree, tmpid);

    draw(tree);

#endif

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
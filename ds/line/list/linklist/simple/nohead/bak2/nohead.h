//
// Created by Acyco on 2023-12-17.
//

#ifndef NOHEAD_H__
#define NOHEAD_H__
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
    struct node_st *next;
};

int list_insert(struct node_st **, struct score_st *data);

void list_show(struct node_st *);

int list_delete(struct node_st **);

int list_find(struct node_st *, int id);

#endif //NOHEAD_H__
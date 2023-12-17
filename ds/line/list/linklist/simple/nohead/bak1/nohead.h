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

struct node_st *list_insert(struct node_st *, struct score_st *data);

void list_show(struct node_st *);
/*
list_delete();
list_find();
*/
#endif //NOHEAD_H__

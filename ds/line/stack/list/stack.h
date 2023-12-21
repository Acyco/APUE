//
// Created by Acyco on 2023-12-22.
//

#ifndef STACK_H__
#define STACK_H__
#include "llist.h"

typedef LLIST STACK;

STACK *stack_create(int initsize);

int stack_push(STACK *, const void *data);

int stack_pop(STACK *, void *data);

void stack_destroy(STACK *);

#endif //STACK_H__

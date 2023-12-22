//
// Created by Acyco on 2023-12-22.
//
#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"

void compute(sqstack *snum,datatype *op)
{
    datatype n1, n2, n;

    st_pop(snum, &n2); // 第一个操作数字（操作符后）
    st_pop(snum, &n1); // 第二个操作数字（操作符前）

    switch (*op)// op是指针 *op才是指向地址的值
    {
        case '+':
            n = n1 + n2;
            break;
        case '-':
            n = n1 - n2;
            break;
        case '*':
            n = n1 * n2;
            break;
        case '/':
            n = n1 / n2;
            break;
        default:
            exit(1);

    }
    st_push(snum, &n); // 计算完后，把结果继续入栈
}

// 计算优先级
static int get_pri(int op)
{
    switch (op)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}
// 处理操作符 op 是既未入栈的操作符，能不能入栈取决优先级
void deal_op(sqstack *snum , sqstack *sop, int op)
{
    datatype old_op;
    if(st_isempty(sop) || op == '('){ // 如果操作栈为空或左括号 直接入栈
        st_push(sop, &op);
        return;
    }

    st_top(sop, &old_op); // 获取操作栈的栈顶，也就是前一个操作符， 用来比较，只要栈顶不需要弹出

    if(get_pri(op) > get_pri(old_op)) // 当前的操作符的优先级比操作栈的栈顶大 则直接入栈
    {
        st_push(sop, &op);
        return;
    }

    while (get_pri(op) <= get_pri(old_op)) // 优先级小，则出栈、计算
    {
        st_pop(sop, &old_op);
        compute(snum,&old_op);
        if(st_isempty(sop))
            break;
        st_top(sop, &old_op);
    }
    st_push(sop,&op);// 都没有了最后则入栈操作栈
}

// 处理右括号 直到处理到左括号
void deal_bracket(sqstack *snum, sqstack *sop)
{
    datatype old_op;
    st_top(sop, &old_op);
    while (old_op != '(')
    {
        st_pop(sop, &old_op);
        compute(snum, &old_op);
        st_top(sop, &old_op);
    }
    st_pop(sop, &old_op); // 最后把左括号也出栈
}

int main()
{
    char str[] = "(11+3)*2-5";

    sqstack *snum, *sop;
    int i = 0;
    int value = 0;
    int flag = 0;
    datatype old_op;

    snum = st_create();
    if (snum == NULL)
        exit(1);

    sop = st_create();
    if (sop == NULL)
        exit(1);

    while (str[i] != '\0')
    {

        if (str[i] >= '0' && str[i] < '9') // 数字 0-9
        {
            value = value * 10 + (str[i] - '0');
            flag = 1; // 标记 我上一个处理的是数字
        }
        else // is a op
        {
            if (flag) // 如果前一个是数字 现在是操作符 则把完整的数字入栈并把临时的初始化
            {
                st_push(snum, &value); // 把数字入栈
                flag = 0;
                value = 0;
            }
            if (str[i] == ')') // 碰到的是右括号，不入栈
            {
                deal_bracket(snum, sop); // 处理括号的优先级
            }
            else // ( + - * /
            {
                deal_op(snum, sop, str[i]); // 进行操作计算
            }
        }
        i++;
    }

    if(flag) // 最后的数字入栈
        st_push(snum, &value);

    while (!st_isempty(sop)) // 字符读取完，并不代表计算完，防止没有计算完
    {
        st_pop(sop, &old_op);
        compute(snum, &old_op);
    }
    st_travel(snum);

    st_destroy(snum);
    st_destroy(sop);

    exit(0);
}
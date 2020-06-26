/*********************************************************************************
 *Copyright(C),2015-2020 by Robin He. All rights reserved.
 *FileName:    example.c
 *Author:      Robin
 *Version:     0.1
 *Date:        2020-06-26 13:56:03
 *Last Modify: 2020-06-26 21:27:15
 *Description: 
**********************************************************************************/

#include <stdio.h>
#include "du_list.h"

struct ex{
    DULIST_NODE node;
    int32_t val;
};

static void _print_list(DULIST *pList)
{
    struct ex *pEx;

    DULIST_FOR_EACH_NODE(struct ex, pEx, pList)
    {
        printf("%d ", pEx->val);
    }
    printf("\n");
}

int32_t main()
{
    DULIST list;
    int32_t i;
    struct ex ex[10];

    DuList_Init(&list);

    for(i = 0; i < 10; i++)
    {
        ex[i].val = i; 
        DuList_AddTail(&list, &ex[i].node);
    }

    printf("add tail:");
    _print_list(&list);

    printf("del 3:");
    DuList_Del(&ex[3].node);
    _print_list(&list);

    printf("readd 3:");
    DuList_AddAfter(&ex[2].node, &ex[3].node);
    _print_list(&list);

    printf("del 9:");
    DuList_Del(&ex[9].node);
    _print_list(&list);

    printf("readd 9:");
    DuList_AddAfter(&ex[8].node, &ex[9].node);
    _print_list(&list);

    return 0;
}

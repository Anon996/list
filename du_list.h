/*********************************************************************************
 *Copyright(C),2015-2020 by Robin He. All rights reserved.
 *FileName:    du_list.h
 *Author:      Robin
 *Version:     0.1
 *Date:        2020-06-26 13:55:19
 *Last Modify: 2020-06-26 21:27:05
 *Description: 
**********************************************************************************/

#ifndef __DU_LIST_H__
#define __DU_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct _DULIST_NODE{
    struct _DULIST_NODE *pPrev;
    struct _DULIST_NODE *pNext;
}DULIST_NODE;

typedef struct _LIST{
    DULIST_NODE *pHeadNode;
    DULIST_NODE *pTailNode;
    int32_t nodeNum;
}DULIST;

#define DULIST_FOR_EACH_NODE(_struct, _node, _list)\
    for(_node=(_struct *)((_list)->pHeadNode);NULL!=_node;_node=(_struct *)(((DULIST_NODE *)_node)->pNext))\

int32_t DuList_Init(DULIST *pList);

int32_t DuList_AddTail(DULIST *pList, DULIST_NODE *pNewNode);

int32_t DuList_AddAfter(DULIST_NODE *pNode, DULIST_NODE *pNewNode);

int32_t DuList_Del(DULIST_NODE *pNode);

#ifdef __cplusplus
}
#endif

#endif


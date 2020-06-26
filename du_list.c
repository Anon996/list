/*********************************************************************************
 *Copyright(C),2015-2020 by Robin He. All rights reserved.
 *FileName:    du_list.c
 *Author:      Robin
 *Version:     0.1
 *Date:        2020-06-26 13:54:51
 *Last Modify: 2020-06-26 21:26:55
 *Description: 
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include "du_list.h"

int32_t DuList_Init(DULIST *pList)
{
    if(NULL == pList)
    {
        return -1;
    }

    memset(pList, 0, sizeof(*pList));

    return 0;
}

int32_t DuList_AddTail(DULIST *pList, DULIST_NODE *pNewNode)
{
    if(NULL == pList || NULL == pNewNode)
    {
        return -1;
    }

    if(NULL == pList->pHeadNode)
    {
        pList->pHeadNode = pNewNode;
    }
    else
    {
        pNewNode->pPrev = pList->pTailNode;
        pList->pTailNode->pNext = pNewNode;
        pNewNode->pNext = NULL;
    }

    pList->pTailNode = pNewNode;

    return 0;
}

int32_t DuList_AddAfter(DULIST_NODE *pNode, DULIST_NODE *pNewNode)
{
    if(NULL == pNode|| NULL == pNewNode)
    {
        return -1;
    }

    pNewNode->pNext = pNode->pNext;
    pNewNode->pPrev = pNode;
    pNode->pNext = pNewNode;

    return 0;
}

int32_t DuList_Del(DULIST_NODE *pNode)
{
    pNode->pPrev->pNext = pNode->pNext;

    if(NULL != pNode->pNext)
    {
        pNode->pNext->pPrev = pNode->pPrev;
    }

    memset(pNode, 0, sizeof(*pNode));

    return 0;
}


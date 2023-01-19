#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"
#include <limits.h>

p_node createGraph(int num_nodes)
{
    p_node newNode, index, head = NULL;
    
    if((head = (p_node)malloc(sizeof(node))) == NULL)
        exit(1);

    head->next = NULL; 

    head->nodeId = 0;
    
    head->edges = NULL;

    index = head;
    
    for (int i = 0; i < num_nodes-1; i++)
    {
        newNode = (p_node)malloc(sizeof(node));
        if (newNode == NULL)
        exit(1);
        
        index->next = newNode;
        newNode->edges = NULL;
        newNode->nodeId = (i+1);
        newNode->next = NULL;
        

        index = index->next;
    }
    return head;
}

void deleteGraph(p_node *head)
{
    p_node indexNode = *head;
    while (indexNode != NULL)
    {
        p_edge indexEdge = indexNode->edges;
        while (indexEdge != NULL)
        {
            p_edge indexEdgefree = indexEdge;
            indexEdge = indexEdge->next;
            free(indexEdgefree);
        }
        p_node indexFree = indexNode;
        indexNode = indexNode->next;
        free(indexFree);
    }
    free(indexNode);
}

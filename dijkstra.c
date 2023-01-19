#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <limits.h>

p_dijkstra getPointerDijkstra(p_dijkstra head, int id);

int shortestPath(p_node start, int src, int dest)
{
    p_dijkstra head = NULL;
    p_dijkstra *index = &head;
    while (start != NULL)
    {
        (*index) = (p_dijkstra)malloc(sizeof(dijkstra));
        if ((*index) == NULL)
        exit(1);

        (*index)->node = start;
        if (start->nodeId == src)
        {
            (*index)->weight = 0;
        }
        else
        {
            (*index)->weight = INFINITY;
        }
        (*index)->tag = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        start = start->next;
    }

    p_dijkstra dijkstraHead = head;
    p_dijkstra help = dijkstraHead;
    p_dijkstra ver = NULL;
    while (help != NULL)
    {
        if ((help->tag)!=1 && (ver == NULL || ver->weight < help->weight) && help->weight < INFINITY)
        {
            ver = help;
        }
        help = help->next;
    }
    if (ver != NULL)
    {
        ver->tag = 1;
    }
    p_dijkstra u = ver;

    while (u != NULL)
    {
        p_edge edgeIndex = u->node->edges;
        while (edgeIndex != NULL)
        {
     
            p_dijkstra v = getPointerDijkstra(dijkstraHead, edgeIndex->dest->nodeId);
            int newDist = u->weight + edgeIndex->weight;
            if (v->weight > newDist)
            {
                v->weight = newDist;
            }
            edgeIndex = edgeIndex->next;
        }
    help = dijkstraHead;
 ver = NULL;
    while (help != NULL)
    {
        if ((help->tag)!=1 && (ver == NULL || ver->weight < help->weight) && help->weight < INFINITY)
        {
            ver = help;
        }
        help = help->next;
    }
    if (ver != NULL)
    {
        ver->tag = 1;
    }
    u = ver;
    }
    int distance= -1;
    p_dijkstra  temp = dijkstraHead;
    while (temp != NULL)
    {
        if (temp->node->nodeId == dest)
        {
            distance  = temp->weight;
        }
        temp = temp->next;
    }
    if (distance == INFINITY)
    {
        distance = -1;
    }
       while (dijkstraHead != NULL)
    {
        p_dijkstra temp = dijkstraHead;
        dijkstraHead = dijkstraHead->next;
        free(temp);
    }
    free(temp);
    free(ver);
    free(help);
    return distance;
}
p_dijkstra getPointerDijkstra(p_dijkstra head, int id)
{
    while (head != NULL)
    {
        if (head->node->nodeId == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
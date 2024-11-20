#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"


Node* GetLastNode(Node *root)
{
    while(root->next != NULL)
    {
        root = root->next;
    }
    return root;
}

Node* CreateRandomNode(Node* parent)
{
    Node *node = malloc(sizeof(Node));
    node->circle_radius = rand() % 20 + 5;
    node->line_length = rand() % 50 + (parent ? parent->circle_radius : 0) + node->circle_radius + 5;
    node->angle = (float)rand() / (float)(RAND_MAX) * 2.f * M_PI;
    node->angular_speed = ((float)rand() / (float)(RAND_MAX) - 0.5f) * 2 * M_PI; // in radians
    node->color = (Color){rand() % 256, rand() % 256, rand() % 256, 255};
    node->next = NULL;
    return node;
}

void AddRandomNode(Node *root)
{
    Node *parent = GetLastNode(root);
    Node *node = CreateRandomNode(parent);
    parent->next = node;
}

void RemoveLastNode(Node *root)
{
    if(root->next == NULL) return;
    Node *prevNode = root;
    Node *curNode = root->next;
    while(curNode->next != NULL)
    {
        prevNode = curNode;
        curNode = curNode->next;
    }
    prevNode->next = NULL;
    free(curNode);
}
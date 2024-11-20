#ifndef NODE_H
#define NODE_H
#define M_PI 3.14159265358979323846
#include "raylib.h"

typedef struct Node
{
    float circle_radius;
    float line_length;
    float angle;
    float angular_speed; // in radians
    Color color;
    struct Node * next;
} Node;

Node* GetLastNode(Node *root);
Node* CreateRandomNode(Node* parent);
void AddRandomNode(Node *root);
void RemoveLastNode(Node *root);

#endif
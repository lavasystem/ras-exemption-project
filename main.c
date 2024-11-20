#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "raylib.h"
#include "node.h"
#include <math.h>

void IterateAndDrawLinesRecursively(Node* node, float x, float y, float scale, float deltaTime)
{
    if(node == NULL) return;
    node->angle += deltaTime * node->angular_speed;
    float nextX = x + scale * node->line_length * cos(node->angle);
    float nextY = y + scale * node->line_length * sin(node->angle);
    DrawLine(x, y, nextX, nextY, node->color);
    IterateAndDrawLinesRecursively(node->next, nextX, nextY, scale, deltaTime);
}

void DrawCirclesRecursively(Node *node, float x, float y, float scale)
{
    if(node == NULL) return;
    float nextX = x + scale * node->line_length * cos(node->angle);
    float nextY = y + scale * node->line_length * sin(node->angle);
    DrawCircle(nextX, nextY, scale * node->circle_radius, node->color);
    DrawCirclesRecursively(node->next, nextX, nextY, scale);
}

int main()
{
    srand(time(NULL));
    int screenWidth = 600;
    int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "RAS Exemption Project");
    SetTargetFPS(30);

    Node *root = CreateRandomNode(NULL);
    root->line_length = 0;
    float scale = 1.0f;

    while(!WindowShouldClose())
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            AddRandomNode(root);
        }
        else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            RemoveLastNode(root);
        }
        float mouseWheelMove = GetMouseWheelMove();
        if(mouseWheelMove > 0)
        {
            scale *= 1.1111111111111f;
        }
        else if(mouseWheelMove < 0)
        {
            scale *= 0.9f;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        IterateAndDrawLinesRecursively(root, screenWidth / 2, screenHeight / 2, scale, GetFrameTime());
        DrawCirclesRecursively(root, screenWidth / 2, screenHeight / 2, scale);
        EndDrawing();
    }
    while(root->next != NULL)
    {
        RemoveLastNode(root);
    }
    free(root);
    CloseWindow();
    return 0;
}

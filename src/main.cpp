#include "raylib.h"
#include "Game.h"

int main() {
    InitWindow(800, 450, "Raylib OOP Game");
    SetTargetFPS(60);

    Game game;
    game.init();

    while (!WindowShouldClose()) {
        game.update();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        game.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

#include "raylib.h"
#include "Game.h"

//設定遊戲視窗
int main() {
    InitWindow(800, 450, "Raylib OOP Game");
    SetTargetFPS(60);

    //遊戲初始化
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

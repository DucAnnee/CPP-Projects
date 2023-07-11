#include <iostream>
#include "game.h"

double lastUpdateTime = 0;
bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main () {
    InitWindow(500, 620, "TETRIS");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/Monogram.ttf");

    Game game = Game();

    while(WindowShouldClose() == false) {
        game.HandleInput();
        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
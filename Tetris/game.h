#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
public:
    Game();
    ~Game();
    void Draw(int offsetX, int offsetY);
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Sound rotateSound;
    Sound clearSound;
};
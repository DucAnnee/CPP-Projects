#include "block.h"

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffsets = 0;
    colOffsets = 0;
}

void Block::Draw(int offsetX, int offsetY) {
    std::vector<Position> tiles = GetCellPosition();
    for (Position item : tiles) {
        DrawRectangle(item.col * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int cols) {
    rowOffsets += rows;
    colOffsets += cols;
}

std::vector<Position> Block::GetCellPosition() {
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles) {
        Position newPos = Position(item.row + rowOffsets, item.col + colOffsets);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate() {
    rotationState++;
    if (rotationState == (int)cells.size()) {
        rotationState = 0;
    }
}

void Block::UndoRotation() {
    rotationState--;
    if (rotationState == -1) {
        rotationState = (int)cells.size() - 1;
    }
}

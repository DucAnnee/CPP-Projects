#include "grid.h"
#include "color.h"
#include <iostream>

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize -1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int col) {
    return (!(row >= 0 && row < numRows && col >= 0 && col < numCols));
}

bool Grid::IsCellEmpty(int row, int col) {
    if (grid[row][col] == 0) return true;
    return false;
}

int Grid::ClearFullRow() {
    int completed = 0;
    for (int row = numRows-1; row >= 0; row--) {
        if (isRowFull(row)) {
            clearRow(row);
            completed++;
        }
        else if (completed > 0) {
            moveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::isRowFull(int row) {
    for (int col = 0; col < numCols; col++) {
        if (grid[row][col] == 0) return false;
    }
    return true;
}

void Grid::clearRow(int row) {
    for (int col = 0; col < numCols; col++) {
        grid[row][col] = 0;
    }
}

void Grid::moveRowDown(int row, int numRows) {
    for (int col = 0; col < numCols; col++) {
        grid[row+numRows][col] = grid[row][col];
        grid[row][col] = 0; 
    }
}

#pragma once
#include <raylib.h>
#include <vector>

class Grid {
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int col);
    bool IsCellEmpty(int row, int col);
    int ClearFullRow();
    int grid[20][10];
private:
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};
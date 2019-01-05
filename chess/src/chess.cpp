#include "shared.h"
#include "piece.cpp"
#include "board.cpp"

int main()  
{
 
    Board board {};
    board.initBoard();
    board.printBoard();

    return 0;
}
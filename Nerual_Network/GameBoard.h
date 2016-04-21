
#include "Player.h"

const int WINNING_LENGTH = 5;
const int BOARD_DIMENSION = 7;  // 7x7

enum E_PieceType
{
   BLACK = -1,
   BLANK  = 0,
   RED   = 1
};

class GameBoard
{
private:
   E_PieceType board[BOARD_DIMENSION][BOARD_DIMENSION];

   bool CheckForOrderWin(const int row,const int column);
   bool CheckForChaosWin();
   void FindStartingPoint(int& row, int& column, bool positiveSlope);




public:
   GameBoard();
   GameBoard(int inputBoard[]);


   // Returns true if the game is complete
   E_PlayerType AddPiece(int row, int column, E_PieceType piece);
   E_PieceType GetPiece(int row, int column) {return board[row][column];}
   void ShowBoard();

};
#ifndef _ORDER_AND_CHAOS_H_
#define _ORDER_AND_CHAOS_H_

#include "Neural_Network.h"

const int WINNING_LENGTH = 5;
const int BOARD_DIMENSION = 7;  // 7x7


enum E_PieceType
{
   BLACK = -1,
   NONE  = 0,
   RED   = 1
};

enum E_PlayerType
{
   CHAOS = -1,
   NONE  = 0,
   ORDER = 1,
   DRAW
};

enum E_BoardDirection
{
   ROW,
   COLUMN,
   DIAGONAL
};

class OrderAndChaos
{
private:
   NeuralNetwork m_order;
   NeuralNetwork m_chaos;


public:
   OrderAndChaos()
   {

   }

};



class GameBoard
{
private:
   E_PieceType board[BOARD_DIMENSION][BOARD_DIMENSION];
   int boardDimension;

   E_PlayerType CheckRowsAndColumns();
   E_PlayerType CheckDiagonals();
   E_PlayerType CheckRows();



public:
   GameBoard();

   void AddPiece(int row, int column, E_PieceType piece) {board[row][column] = piece;}

   E_PlayerType GameCompleted();


};

#endif

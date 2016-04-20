#ifndef _ORDER_AND_CHAOS_H_
#define _ORDER_AND_CHAOS_H_

#include "Neural_Network.h"

const int WINNING_LENGTH = 5;
const int BOARD_DIMENSION = 7;  // 7x7


enum E_PieceType
{
   BLACK = -1,
   BLANK  = 0,
   RED   = 1
};

enum E_PlayerType
{
   CHAOS = -1,
   NONE  = 0,
   ORDER = 1
   
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

   bool CheckForOrderWin(const int row,const int column);
   bool CheckForChaosWin();
   void FindStartingPoint(int& row, int& column, bool positiveSlope);




public:
   GameBoard();
   GameBoard(int inputBoard[]);


   // Returns true if the game is complete
   E_PlayerType AddPiece(int row, int column, E_PieceType piece);
   void ShowBoard();

};

#endif

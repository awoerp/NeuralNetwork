#ifndef _GAME_H_
#define _GAME_H_

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

class GameBoard
{
private:
   E_PieceType board[BOARD_DIMENSION][BOARD_DIMENSION];
   int numberOfPiecesPlayed;


   void FindStartingPoint(int& row, int& column, bool positiveSlope);




public:
   GameBoard();
   GameBoard(int inputBoard[]);


   // Returns true if the game is complete
   
   E_PieceType GetPiece(int row, int column) {return board[row][column];}
   bool CheckForOrderWin(const int row,const int column);
   bool CheckForChaosWin();
   bool AddPiece(int row, int column, E_PieceType piece);
   void ShowBoard();

};






class Player
{
private:
   NeuralNetwork m_brain;
   E_PlayerType m_playerType;

   E_PlayerType MakeBestMove(std::vector<float> response, GameBoard* board);


public:

   Player(E_PlayerType type);
   E_PlayerType MakeMove(GameBoard* board);

};

#endif
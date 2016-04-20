#include <stdexcept>
#include "orderAndChaos.h"
#include <iomanip>


GameBoard::GameBoard()
{
   for(int row = 0; row < BOARD_DIMENSION; row++)
   {
      for(int column = 0; column < BOARD_DIMENSION; column++)
         board[row][column] = E_PieceType::BLANK;
   }
}

E_PlayerType GameBoard::AddPiece(int row, int column, E_PieceType piece)
{
   if( board[row][column] == E_PieceType::BLANK)
      board[row][column] = piece;
   else
      throw std::invalid_argument("ERROR in AddPiece(): An occupied square was attempted to be overwritten");

   bool winner = false;
   winner = CheckForOrderWin(row, column);

   if(winner)
      return E_PlayerType::ORDER;
   
   winner = CheckForChaosWin();

   return E_PlayerType::NONE;
}


GameBoard::GameBoard(int inputBoard[])
{

   int arrayLength = sizeof(inputBoard) / sizeof(inputBoard[0]);
   if( arrayLength != BOARD_DIMENSION * BOARD_DIMENSION)
      throw std::invalid_argument("ERROR in GameBoard(inputBoard[]): The input board is not the correct size");

   int count = 0;
   for(int row = 0; row < BOARD_DIMENSION; row++)
   {
      for(int column = 0; column < BOARD_DIMENSION; column++)
      {
         E_PieceType val = (E_PieceType)inputBoard[count];
         board[row][column] = val;
      }
   }
}



bool GameBoard::CheckForOrderWin(const int row,const int column)
{
   int rowIndex;
   int columnIndex;
   int consecutiveSum = 0;

   E_PieceType lastPiece;
   E_PieceType currentPiece;

   bool firstIteration = true;

   //Check the horizontal row for 5 consecutive pieces
   rowIndex = row;
   columnIndex = 0;

   while(columnIndex < BOARD_DIMENSION)
   {
      currentPiece = board[rowIndex][columnIndex];
      if(firstIteration)
      {
         firstIteration = false;
         lastPiece = currentPiece;
      }
      if(currentPiece == E_PieceType::BLANK)
         consecutiveSum = 1;
      else if(currentPiece == lastPiece)
         consecutiveSum++;
      else
         consecutiveSum = 1;
      if(consecutiveSum == WINNING_LENGTH)
         return true;
      columnIndex++;
      lastPiece = currentPiece;
   }

   //Check the vertical column for 5 consecutive pieces
   rowIndex = 0;
   columnIndex = column;
   firstIteration = true;
   consecutiveSum = 0;
   while(rowIndex < BOARD_DIMENSION)
   {
      currentPiece = board[rowIndex][columnIndex];
      if(firstIteration)
      {
         firstIteration = false;
         lastPiece = currentPiece;
      }
      if(currentPiece == E_PieceType::BLANK)
         consecutiveSum = 1;
      else if(currentPiece == lastPiece)
         consecutiveSum++;
      else
         consecutiveSum = 1;
      if(consecutiveSum == WINNING_LENGTH)
         return true;
      rowIndex++;
      lastPiece = currentPiece;
   }
   
   // Check the diagonal with the positive slope.
   rowIndex = row;
   columnIndex = column;
   FindStartingPoint(rowIndex, columnIndex, true);
   firstIteration = true;
   consecutiveSum = 0;
   while(rowIndex > 0 && columnIndex < BOARD_DIMENSION)
   {
      currentPiece = board[rowIndex][columnIndex];
      if(firstIteration)
      {
         firstIteration = false;
         lastPiece = currentPiece;
      }
      if(currentPiece == E_PieceType::BLANK)
         consecutiveSum = 1;
      else if(currentPiece == lastPiece)
         consecutiveSum++;
      else
         consecutiveSum = 1;

      if(consecutiveSum == WINNING_LENGTH)
         return true;
      rowIndex--;
      columnIndex++;
      lastPiece = currentPiece;
   }

   // Check the diagonal with the negative slope.
   rowIndex = row;
   columnIndex = column;
   FindStartingPoint(rowIndex, columnIndex, false);
   firstIteration = true;
   consecutiveSum = 0;
   while(rowIndex < BOARD_DIMENSION && columnIndex < BOARD_DIMENSION)
   {
      currentPiece = board[rowIndex][columnIndex];
      if(firstIteration)
      {
         firstIteration = false;
         lastPiece = currentPiece;
      }
      if(currentPiece == E_PieceType::BLANK)
         consecutiveSum = 1;
      else if(currentPiece == lastPiece)
         consecutiveSum++;
      else
         consecutiveSum = 1;

      if(consecutiveSum == WINNING_LENGTH)
         return true;
      rowIndex++;
      columnIndex++;
      lastPiece = currentPiece;
   }
   return false;
}









// This method will return true if the entire board is full (Chaos victory)
// and false otherwise.
bool GameBoard::CheckForChaosWin()
{
   for(int row = 0; row < BOARD_DIMENSION; row++)
   {
      for(int column = 0; column < BOARD_DIMENSION; column++)
      {
         if(board[row][column] == E_PieceType::BLANK)
            return false;
      }
   }
   return true;
}


// This method will determine the starting point for checking to see whether there is a diagonal
// containing 5 consecutive pieces based on the piece that was just placed.
void GameBoard::FindStartingPoint(int& row, int& column, bool positiveSlope)
{
   int rowCopy = row;
   int columnCopy = column;

   // if you want the starting point of the diagonal with the positive
   // slope.
   if(positiveSlope)
   {
      while(column > 0 && row < BOARD_DIMENSION)
      {
         row++;
         column--;
      }
   }
   else
   {
      while(column > 0 && row > 0)
      {
         row--;
         column--;
      }
   }
}


void GameBoard::ShowBoard()
{
   for(int row = 0; row < BOARD_DIMENSION; row++)
   {
      for(int column = 0; column < BOARD_DIMENSION; column++)
      {
         std::cout << std::setw(2) << board[row][column] << " ";
      }
      std::cout << std::endl;
   }
   std::cout << std::endl;


}
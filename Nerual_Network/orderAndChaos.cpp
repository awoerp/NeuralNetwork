
#include "orderAndChaos.h"

GameBoard::GameBoard()
{
   for(int row = 0; row < boardDimension; row++)
   {
      for(int column = 0; column < boardDimension; column++)
         board[row][column] = 0;
   }
}


E_PlayerType GameBoard::GameCompleted()
{
   E_PlayerType winningPlayer = E_PlayerType::NONE;
   
   winningPlayer = GameBoard::CheckRowsAndColumns();

   if(winningPlayer != E_PlayerType::NONE)
   {
      return winningPlayer;
   }

   winningPlayer = GameBoard::CheckDiagonals();







  
}


E_PlayerType GameBoard::CheckDiagonals()
{
   //Checking outer diagonals where the length of the diagonal is 5
   int row = 0;
   int column = 2;
   while(column < 7)
   {
      sum += board[row][column];
      row++;
      column++;
   }
   if(sum == WINNING_LENGTH || sum == -WINNING_LENGTH)
   {
      return E_PlayerType::ORDER;
   }


   sum = 0;
   row = 2;
   column = 0;
   while(row < 7)
   {
      sum += board[row][column];
      row++;
      column++;
   }
   if(sum == WINNING_LENGTH || sum == -WINNING_LENGTH)
   {
      return E_PlayerType::ORDER;
   }


   sum = 0;
   row = 4;
   column = 0;
   while(row >= 0)
   {
      sum += board[row][column];
      row--;
      column++;
   }
   if(sum == WINNING_LENGTH || sum == -WINNING_LENGTH)
   {
      return E_PlayerType::ORDER;
   }


   sum = 0;
   row = 6;
   column = 2;
   while(column < 7)
   {
      sum += board[row][column];
      row--;
      column++;
   }
   if(sum == WINNING_LENGTH || sum == -WINNING_LENGTH)
   {
      return E_PlayerType::ORDER;
   }





   
}


E_PlayerType GameBoard::CheckRowsAndColumns()
{
   bool firstRowIteration = true;
   bool firstColumnIteration = true;

   int consecutiveRowPieces = 0;
   int consecutiveColumnPieces = 0;
   int lastRowPiece = 0;
   int lastColumnPiece = 0;
   int currentRowPiece;
   int currentColumnPiece;

   for(int row = 0; row < boardDimension; row++)
   {
      for(int column = 0; column < boardDimension; column++)
      {
         currentRowPiece = board[row][column];
         currentColumnPiece = board[column][row];
         
         if(firstRowIteration)
         {
            lastRowPiece = currentRowPiece;
            firstRowIteration = false;
         }
         if(firstColumnIteration)
         {
            lastColumnPiece = currentColumnPiece;
            firstColumnIteration = false;
         }

         if(currentRowPiece == lastRowPiece)
         {
            consecutiveRowPieces++;
         }
         else
         {
            consecutiveRowPieces = 0;
         }

         if(currentColumnPiece == lastColumnPiece)
         {
            consecutiveColumnPieces++;
         }
         else
         {
            consecutiveColumnPieces = 0;
         }

         if(consecutiveRowPieces == WINNING_LENGTH ||
            consecutiveColumnPieces == WINNING_LENGTH) // 5
         {
            return E_PlayerType::ORDER;
         }

         lastRowPiece = currentRowPiece;
         lastColumnPiece = currentColumnPiece;
         firstRowIteration = true;
      }
      firstColumnIteration = true;

   }
   return E_PlayerType::NONE;
}

/*
E_PlayerType GameBoard::CheckRows()
{
   int rowArray[BOARD_DIMENSION * BOARD_DIMENSION];
   int count = 0;
   // disassemble the 2D game board into a 1D array
   for(int row = 0; row < boardDimension; row++)
   {
      for(int column = 0; column < boardDimension; column++)
      {
         rowArray[count] = board[row][column];
         count++;
      }
   }

   int columnIndex = 0;
   int consecutivePieces = 0;
   int currentPiece;
   int lastPiece;
   bool newRow = true;

   for(int i = 0; i < BOARD_DIMENSION * BOARD_DIMENSION; i++)
   {
      if(i % BOARD_DIMENSION == 0)
      {
         newRow = true;
         consecutivePieces = 0;
      }
      currentPiece = rowArray[i];
      
      if(newRow)
      {
         lastPiece = currentPiece;
         newRow = false;
      }

      if(currentPiece == lastPiece)
      {
         consecutivePieces++;
      }
      else
      {
         consecutivePieces = 0;
      }

      if(consecutivePieces == 5)
      {
         return E_PlayerType::ORDER;
      }

   }



 */


}
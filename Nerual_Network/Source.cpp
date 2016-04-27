#include "Game.h"
#include <windows.h>


void main()
{
   
   int cat;
   /*
   int orderWins = 0;
   int chaosWins = 0;
   int numGames = 0;

   srand((unsigned int)time(NULL));

   while(numGames < 100)
   {

      Player Player1 = Player(E_PlayerType::CHAOS);
      Player Player2 = Player(E_PlayerType::ORDER);

      GameBoard board = GameBoard();

      E_PlayerType winningPlayer = E_PlayerType::NONE;
      E_PlayerType currentPlayer = E_PlayerType::CHAOS;

      //std::cout << "GAME START!!!!" << std::endl;
      //board.ShowBoard();

      while(winningPlayer == E_PlayerType::NONE)
      {
         if(currentPlayer == E_PlayerType::CHAOS)
         {
         
            winningPlayer = Player1.MakeMove(&board);
         }
         else
         {
            winningPlayer = Player2.MakeMove(&board);
         }
         //board.ShowBoard();
         //Sleep(1000);
         // Toggle which player is up next
         currentPlayer = (E_PlayerType)(((int)currentPlayer) * -1);
      }


      if(winningPlayer == E_PlayerType::CHAOS)
      {
         std::cout << "CHAOS Wins!!!" << std::endl;
         chaosWins++;
      }
      else
      {
         std::cout << "ORDER Wins!!!" << std::endl;
         orderWins++;
      }
      numGames++;

   }


   std::cout << "Order Wins: " << orderWins << std::endl <<
                "Chaos Wins: " << chaosWins << std::endl;


   */

   NeuralNetwork n1 = NeuralNetwork();
   NeuralNetwork n2 = NeuralNetwork(&n1);

   std::cin >> cat;

}
#include "Game.h"
#include <windows.h>


void main()
{
   
   int cat;

   srand((unsigned int)time(NULL));

   Player Player1 = Player(E_PlayerType::CHAOS);
   Player Player2 = Player(E_PlayerType::ORDER);

   GameBoard board = GameBoard();

   E_PlayerType winningPlayer = E_PlayerType::NONE;
   E_PlayerType currentPlayer = E_PlayerType::CHAOS;

   std::cout << "GAME START!!!!" << std::endl;
   board.ShowBoard();

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
      board.ShowBoard();
      Sleep(1000);
      // Toggle which player is up next
      currentPlayer = (E_PlayerType)(((int)currentPlayer) * -1);
   }


   if(winningPlayer == E_PlayerType::CHAOS)
      std::cout << "CHAOS Wins!!!" << std::endl;
   else
      std::cout << "ORDER Wins!!!" << std::endl;
   //net.PrintTest();


   

   std::cin >> cat;

}
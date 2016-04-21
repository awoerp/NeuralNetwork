#include "Player.h"
#include "Neural_Network.h"
#include "GameBoard.h"


void main()
{
   
   int cat;

   srand(time(NULL));

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
      _sleep(1000);
      // Toggle which player is up next
      currentPlayer = (E_PlayerType)(((int)currentPlayer) * -1);
   }
   //net.PrintTest();


   

   std::cin >> cat;

}
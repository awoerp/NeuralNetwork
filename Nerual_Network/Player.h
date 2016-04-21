#ifndef _Player_H_
#define _Player_H_



#include "Neural_Network.h"
#include "GameBoard.h"






enum E_PlayerType
{
   CHAOS = -1,
   NONE  = 0,
   ORDER = 1
   
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

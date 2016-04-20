#include "Neural_Network.h"
#include "orderAndChaos.h"

void main()
{
   
   int cat;

   /*
   srand(time(NULL));
   NeuralNetwork net;
   std::vector<int> innerTopology;
   innerTopology.push_back(5);
   innerTopology.push_back(4);
   innerTopology.push_back(2);
   net.DefineNetworkTopology(2, innerTopology, 6);
   net.CreateNeurons();
   net.ConnectNeurons();
   net.RandomizeConnectionWeights();
   std::vector<float> inputValues;
   inputValues.push_back(2.0);
   inputValues.push_back(1.0);
   std::vector<float> nnResponse;

   net.SetInputValues(inputValues);
   nnResponse = net.CalculateNetworkResponse();
   for(int i = 0; i < nnResponse.size(); i++)
   {
      std::cout << nnResponse[i] << std::endl;
   }
   //net.PrintTest();

   */

   GameBoard board = GameBoard();
   board.ShowBoard();
   std::cout << board.AddPiece(1,1,E_PieceType::BLACK) << std::endl;
   board.ShowBoard();
   std::cout << board.AddPiece(2,2,E_PieceType::BLACK) << std::endl;
   board.ShowBoard();
   std::cout << board.AddPiece(3,3,E_PieceType::BLACK) << std::endl;
   board.ShowBoard();
   std::cout << board.AddPiece(4,4,E_PieceType::BLACK) << std::endl;
   board.ShowBoard();
   std::cout << board.AddPiece(5,5,E_PieceType::BLACK) << std::endl;
   board.ShowBoard();
   std::cout << board.AddPiece(6,6,E_PieceType::BLACK) << std::endl;
   board.ShowBoard();
   std::cout << board.AddPiece(0,0,E_PieceType::BLACK) << std::endl;
   board.ShowBoard();
   

   std::cin >> cat;

}
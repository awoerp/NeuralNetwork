#include "Neural_Network.h"

void main()
{
   int cat;
   srand(time(NULL));
   NeuralNetwork net;
   std::vector<int> innerTopology;
   innerTopology.push_back(4);
   innerTopology.push_back(5);
   innerTopology.push_back(6);
   net.DefineNetworkTopology(3, innerTopology, 4);
   net.CreateNeurons();
   net.ConnectNeurons();
   net.RandomizeConnectionWeights();
   net.PrintTest();


   std::cin >> cat;

}
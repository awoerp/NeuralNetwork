#include "Neural_Network.h"

void main()
{
   int cat;
   srand(time(NULL));
   NeuralNetwork net;
   std::vector<int> innerTopology;
   innerTopology.push_back(16);
   innerTopology.push_back(32);
   innerTopology.push_back(81);
   net.DefineNetworkTopology(1, innerTopology, 50);
   net.CreateNeurons();
   net.ConnectNeurons();
   net.RandomizeConnectionWeights();
   std::vector<float> inputValues;
   inputValues.push_back(2.0);
   std::vector<float> nnResponse;

   net.SetInputValues(inputValues);
   nnResponse = net.CalculateNetworkResponse();
   for(int i = 0; i < nnResponse.size(); i++)
   {
      std::cout << nnResponse[i] << std::endl;
   }
   //net.PrintTest();


   std::cin >> cat;

}
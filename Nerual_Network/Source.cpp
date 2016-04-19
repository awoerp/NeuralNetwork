#include "Neural_Network.h"

void main()
{
   int cat;
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


   std::cin >> cat;

}
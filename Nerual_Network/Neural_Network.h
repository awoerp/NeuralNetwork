#ifndef _NN_
#define _NN_

#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>

#define MAX_NUMBER_OF_HIDDEN_LAYERS 5
#define MAX_NEURONS_PER_LAYER 8

#define MAX_WEIGHT_RANGE 1.0f
#define MIN_WEIGHT_RANGE -1.0f

#define DELTA_WEIGHT_RANGE MAX_WEIGHT_RANGE - MIN_WEIGHT_RANGE

enum ActivationFunctionType
{
   e_TanH,
   e_ArtTan,
   e_Step
};

enum NeuronType
{
   e_Input,
   e_Hidden,
   e_Output,
   e_Bias
};

enum Bias
{
   False,
   True,
};

float ActivationFunction(float inputVal, float variable, ActivationFunctionType type);


class Neuron
{
private:
   ActivationFunctionType m_activationFunction;
   NeuronType m_neuronType;

   std::vector<Neuron*> m_outputConnections;
   std::vector<float>   m_outputWeights;
   std::vector<float>   m_inputValues;

   float   m_unweightedOutputVal;
   float   m_activationFunctionVariable;
   
   int m_neuronNumber;  // This is the neuron number within a specific layer
   int m_numberOfOutputConnections;
   int m_numberOfInputConnections;

protected:
public:
   Neuron(NeuronType type, int neuronNum): m_neuronType(type),
                                           m_neuronNumber(neuronNum),
                                           m_numberOfOutputConnections(0),
                                           m_numberOfInputConnections(0){};

   void SetNeuronActivationFunction(ActivationFunctionType function, float variable);
   void AddOutputWeight(float weight);
   void SetInputValue(float val, int connectionNumber);
   void AddOutputConnection(Neuron* outputNeuron);
   void AddInputConnection();
   void CalculateNeuronResponse();
   void PropagateNeuronResponse();

   int GetNeuronNumber() {return m_neuronNumber;}
   float GetConnectionWeight() {return m_outputWeights[0];}
};

class NeuralNetwork
{
private:
   int m_numInputNeurons;
   std::vector<int> m_numHiddenNeurons;  // A vector holding the number of neurons in each of the hidden layers
   int m_numOutputNeurons;
   int m_numHiddenLayers;
   
   //Neuron* Network[MAX_NEURONS_PER_LAYER][MAX_NUMBER_OF_HIDDEN_LAYERS + 2];

   std::vector<std::vector<Neuron*>> Network;


protected:
public:
   NeuralNetwork();

   void DefineNetworkTopology(int numInputNeurons, std::vector<int> hiddenNodeTopology, int numOutputNeurons);
   void CreateNeurons();  // Should I do something to add a bias?
   void ConnectNeurons();
   void RandomizeConnectionWeights();

   void SetInputValues(std::vector<float> values);

   void PrintTest();
};

#endif
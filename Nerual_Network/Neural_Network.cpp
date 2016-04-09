#include "Neural_Network.h"




void Neuron::SetNeuronActivationFunction(ActivationFunctionType function, float variable) {m_activationFunction = function;
                                                                                           m_activationFunctionVariable = variable;}
void Neuron::AddOutputWeight(float weight) {m_outputWeights.push_back(weight);}
void Neuron::SetInputValue(float val, int connectionNumber) {m_inputValues.push_back(val);}

void Neuron::AddOutputConnection(Neuron* outputNeuron)
{
   m_outputConnections.push_back(outputNeuron);
   m_numberOfOutputConnections++;
}

void Neuron::AddInputConnection()
{
   m_inputValues.push_back(0);
   m_numberOfInputConnections++;
}

void Neuron::CalculateNeuronResponse()
{
   float totalInputValue = 0;
   for(int i = 0; i < m_numberOfInputConnections; i++)
   {
      totalInputValue += m_inputValues[i];
   }


   m_unweightedOutputVal = ActivationFunction(totalInputValue, m_activationFunctionVariable, m_activationFunction);
}

void Neuron::PropagateNeuronResponse()
{
   for(int i = 0; i < m_numberOfOutputConnections; i++)
      m_outputConnections[i]->SetInputValue(m_unweightedOutputVal * m_outputWeights[i], m_neuronNumber);
}




NeuralNetwork::NeuralNetwork()
{
   m_numInputNeurons = 0;
   m_numHiddenLayers = 0;
   m_numOutputNeurons = 0;
}

void NeuralNetwork::DefineNetworkTopology(int numInputNeurons, std::vector<int> hiddenNodeTopology, int numOutputNeurons)
{
   m_numInputNeurons  = numInputNeurons;
   m_numOutputNeurons = numOutputNeurons;
   for(int i = 0; i < hiddenNodeTopology.size(); i++)
   {
      m_numHiddenNeurons.push_back(hiddenNodeTopology[i]);
      m_numHiddenLayers++;
   }
}

void NeuralNetwork::CreateNeurons()
{
   std::vector<Neuron*> dumbyVector;
   // Initializing the correct number of layers by pushing back 
   // blank vectors.  This includes the input and output layers
   for(int i = 0; i < m_numHiddenLayers + 2; i++)
   {
      Network.push_back(dumbyVector);
   }
   
   // Initiallizing Input Neurons
   for(int i = 0; i < m_numInputNeurons; i++)
   {
      Neuron* newNeuron = new Neuron(NeuronType::e_Input, i);
      newNeuron->SetNeuronActivationFunction(e_ArtTan, 1);
      Network[0].push_back(newNeuron);
   }

   // Initiallizing Hidden Neurons
   // i == colum Number (Neuron Layer)
   // j == row Number
   for(int i = 1; i <= m_numHiddenLayers; i++)
   {
      //m_numHiddenNeurons.push_back(0);
      for(int j = 0; j < m_numHiddenNeurons[i-1]; j++)
      {
         Neuron* newNeuron = new Neuron(NeuronType::e_Hidden, j);
         newNeuron->SetNeuronActivationFunction(e_ArtTan, 1);
         Network[i].push_back(newNeuron);
      }
   }
   
   // Initiallizing Output Neurons
   // The value of m_numHiddenLayers will be the colum index of the output layer of neurons 
   for(int i = 0; i < m_numOutputNeurons; i++)
   {
      Neuron* newNeuron = new Neuron(NeuronType::e_Output, i);
      newNeuron->SetNeuronActivationFunction(e_ArtTan, 1);
      Network[m_numHiddenLayers + 1].push_back(newNeuron);
   }


}

void NeuralNetwork::ConnectNeurons()
{
   
   // Connect the input neuron outputs to the first hidden layer neurons
   for(int inputNeuron = 0; inputNeuron < m_numInputNeurons; inputNeuron++)
   {
      for(int hiddenNeuron = 0; hiddenNeuron < Network[1].size(); hiddenNeuron++)
      {
         Network[0][inputNeuron]->AddOutputConnection(Network[1][hiddenNeuron]);
         Network[1][hiddenNeuron]->IncreaseNumberOfInputConnections(1);
      }
   }

   // Connect the hidden neurons to themselves and the output neurons
   for(int layerNumber = 1; layerNumber < Network.size() - 1; layerNumber++)
   {
      for(int hiddenNeuron = 0; hiddenNeuron < Network[layerNumber].size(); hiddenNeuron++)
      {
         for(int outputConnection = 0; outputConnection < Network[layerNumber + 1].size(); outputConnection++)
         {
            Neuron* outputConnectionNeuron = Network[layerNumber + 1][outputConnection];
            Network[layerNumber][hiddenNeuron]->AddOutputConnection(outputConnectionNeuron);
            outputConnectionNeuron->IncreaseNumberOfInputConnections(1);
         }
      }
   }

}


void NeuralNetwork::PrintTest()
{
   for(int i = 0; i < m_numHiddenLayers + 2; i++)
   {
      for(int j = 0; j < Network[i].size(); j++)
      {
         std::cout << Network[i][j]->GetNeuronResponse() << std::endl;
      }
   }

}

void NeuralNetwork::RandomizeConnectionWeights()
{
   for(int i = 0; i < Network.size() - 1; i++)
   {
      for(int j = 0; j < Network[i].size(); j++)
      {
         for(int k = 0; k < Network[i + 1].size(); k++)
         {
            float weight = rand() / float((RAND_MAX));

            if(rand() / float(RAND_MAX) > 0.5)
               weight = -1.0 * weight;
            Network[i][j]->AddOutputWeight(weight);
            //std::cout << weight << std::endl;
         }
      }
   }
}

void NeuralNetwork::SetInputValues(std::vector<float> values)
{
   if(values.size() != m_numInputNeurons)
      std:: cout << "ERROR: Number of Input Neurons does not match number of input neuron values" << std::endl;
   else
   {
      for(int i = 0; i < values.size(); i++)
      {
         Network[0][i]->ClearInputValues();
         Network[0][i]->SetInputValue(values[i], i);
      }
   }
}


std::vector<float> NeuralNetwork::CalculateNetworkResponse()
{
   for(int i = 0; i < Network.size() - 1; i++)
   {
      for(int j = 0; j < Network[i].size(); j++)
      {
         Network[i][j]->CalculateNeuronResponse();
         Network[i][j]->PropagateNeuronResponse();
      }
   }

   std::vector<float> outputValues;
   float outputValue;

   int indexOfOutputNeurons = Network.size() - 1;

   for(int i = 0; i < Network[indexOfOutputNeurons].size(); i++)
   {
      Network[indexOfOutputNeurons][i]->CalculateNeuronResponse();
      outputValue = Network[indexOfOutputNeurons][i]->GetNeuronResponse();
      outputValues.push_back(outputValue);
   }
   return outputValues;
}


float ActivationFunction(float inputVal, float variable, ActivationFunctionType type)
{
   switch(type)
   {
   case e_TanH:
      return (2.0 / (1 + std::exp( variable * inputVal))) - 1;
      break;

   case e_ArtTan:
      return (std::atan(variable * inputVal));
      break;

   case e_Step:
      if(inputVal >= 0.0)
         return 1.0;
      else
         return 0.0;
      break;

   default:
      return inputVal;

   }
}
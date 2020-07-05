//
//  main.cpp
//  neural net
//
//  Created by Greg Lewin on 7/3/20.
//  Copyright © 2020 Greg Lewin. All rights reserved.
//

#include <iostream>
#include <modelling/nn.h>

NeuralNet nn;
ivector nodesPerLevel(3);

fmatrix inputs(300, 3);
fmatrix outputs(300, 1);

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";

    nodesPerLevel[0] = 3;
    nodesPerLevel[1] = 4;
    nodesPerLevel[2] = 1;
    //nodesPerLevel[3] = 1;
    
    ifstream inData("/Users/greg/Documents/projects/neural network/neural net/neural net/data.txt");
    if(!inData)
    {
        std::cout << "Error reading file\n";
        return -1;
    }
    
    int len;
    inData >> len;

    std::cout << len << "\n";
    
    for(int i = 0; i < 300; i++)
    {
        float output;
        inData >> output;
        cout << output << endl;
        outputs[i][0] = output;
        
        for(int j = 0; j < 5; j++)
        {
            float input;
            inData >> input;
            cout << input << endl;
            if(j > 0 && j < 4)
                inputs[i][j-1] = input;
        }
    }

    nn.CreateStdMap(nodesPerLevel, VALUE);
    
    nn.SetInputNorms(0, 0, 1200);
    nn.SetInputNorms(1, 0, 1200);
    nn.SetInputNorms(2, 0, 1200);
    //nn.SetInputNorms(3, 0, 1200);
    //nn.SetInputNorms(4, 0, 1200);
    
    nn.SetOutputNorms(0, 0, 2);
    
    nn.GenerateRandomWeights(1.0);
    
    nn.TrainBP(inputs, outputs, 100000, 0, 0.5);
    
    nn.WriteFile("/Users/greg/Documents/projects/neural network/neural net/neural net/weights.txt");

    return 0;
}


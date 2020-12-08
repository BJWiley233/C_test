#include <bits/stdc++.h> //header file for all basic c++ libraries
#include <shark/Data/Csv.h> //header file ro importing data in csv format
#include <shark/ObjectiveFunctions/Loss/SquaredLoss.h> //header file for implementing squared loss function
#include <shark/Algorithms/Trainers/LinearRegression.h>// header file for implementing linear regression

Data<RealVector> inputs; //container for storing the x values
Data<RealVector> labels; //conatiner for storing the y values
importCSV(inputs, "input.csv"); // storing the values in specific container by specifying the path of csv
importCSV(labels, "label.csv");

RegressionDataset data(inputs, labels);
LinearRegression trainer;// trainer for linear regression model
LinearModel<> model; // linear model

//training the model
trainer.train(model, data);// train function ro training the model.

// show model parameters
cout << "intercept: " << model.offset() << endl;
cout << "matrix: " << model.matrix() << endl;

SquaredLoss<> loss;   //initializing square loss object
Data<RealVector> prediction = model(data.inputs());  //prediction is calculated based on data inputs
cout << "squared loss: " << loss(data.labels(), prediction) << endl; // In end we ouptut the loss
//////////////////////////////////////////////////////////////
// Title: QuickHeat //////////////////////////////////////////
// Description: C++ heatmap library for 2D vector matricies //
// Written by: Matthew Nielsen ///////////////////////////////
// Date: March 4 2018 ////////////////////////////////////////
//////////////////////////////////////////////////////////////

#include "quickheat.hpp"
#include <fstream>
#include <stddef.h>
#include <iostream>

//Returns the rgb(,,) color data string based on scheme and input value
std::string color_of(const int data, enum colorScheme scheme){
  std::string col;

  switch(scheme){
    case GREYSCALE:
      col =  "rgb(" + std::to_string(data) + "," + std::to_string(data) + "," + std::to_string(data) + ")";
      break;
    case BLUE:
      col = "rgb(0,0," + std::to_string(data) + ")";
      break;
    case PURPLE:
      col =  "rgb(" + std::to_string(data)+ ",0," + std::to_string(data)+ ")";
      break;
    case RED:
      col =  "rgb(" + std::to_string(data) + ",0,0)";
      break;
    case GREEN:
      col =  "rgb(0," + std::to_string(data) + ",0)";
      break;
    case YELLOW:
      col =  "rgb(" + std::to_string(data) + "," + std::to_string(data) + ",0)";
      break;
    case HEAT:
      col =  "rgb(" + std::to_string(data) + "," + std::to_string(255 - data) + ",0)";
      break;
    case ORANGE:
      col =  "rgb(" + std::to_string(data) + "," + std::to_string(data * 64 / 100) + ",0)";
      break;
    case PLASMA:
      col = "rgb(0," + std::to_string(data) + "," + std::to_string(255 - data) + ")";
      break;
    case GRAPE:
      col =  "rgb(" + std::to_string(data) + ",0," + std::to_string(255 - data) + ")";
      break;    
  }
  return col;
}

//Returns a struct containing the max and min values of the vector matrix
map_stats * range_of(std::vector< std::vector<int> > &matrix){
  //Initiate dataSet
  map_stats  * dataSet = new map_stats;
  dataSet->max = matrix[0][0];
  dataSet->min = matrix[0][0];

  //Find min and max values in the matrix
  for(int y = 0; y < matrix.size(); y++){
    for(int x = 0; x < matrix[y].size(); x++){
      if(matrix[y][x] > dataSet->max){
        dataSet->max = matrix[y][x];
      }else if(matrix[y][x] < dataSet->min){
        dataSet->min = matrix[y][x];
      }
    }
  }
  return dataSet;
}

//Returns a struct containing the max and min values of the vector matrix
map_stats * range_of(std::vector< std::vector<float> > &matrix){
  //Initiate dataSet
  map_stats  * dataSet = new map_stats;
  dataSet->max = matrix[0][0];
  dataSet->min = matrix[0][0];

  //Find min and max values in the matrix
  for(int y = 0; y < matrix.size(); y++){
    for(int x = 0; x < matrix[y].size(); x++){
      if(matrix[y][x] > dataSet->max){
        dataSet->max = matrix[y][x];
      }else if(matrix[y][x] < dataSet->min){
        dataSet->min = matrix[y][x];
      }
    }
  }
  return dataSet;
}

//Returns the discreet weighting of the value on a scale of 0 to 255
int discreet_weight(float max, float min, float value){
  return (value - min) / (max - min) * 255;
}

//Render an SVG of some matrix with a certain color scheme stored in a specified file
bool render_heatmap(std::vector< std::vector<int> > &matrix, enum colorScheme scheme, std::string filename){
  //The height of the matrix
  size_t height = matrix.size();

  //Creating output file
  std::ofstream f(filename);

  //If the output file is open
  if(f.is_open()){
    //Print header of svg file
    f << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 0 " 
      << matrix[0].size()
      << " " 
      << height 
      << "\">\n";

    //Determine max and minimum value in matrix, for use in colorscale
    map_stats * dataSet = range_of(matrix);

    //render all elements of vector matrix
    for(int y = 0; y < matrix.size(); y++){
      for(int x = 0; x < matrix[y].size(); x++){
        f <<"<rect x=\""
          << x 
          << "\" y=\"" 
          << y 
          << "\" width=\"1\" height=\"1\" fill=\""
          << color_of(discreet_weight(dataSet->max, dataSet->min, matrix[y][x]), scheme) 
          << "\"/>\n";
      }
    }

    //Print footer of svg file
    f << "</svg>\n";

    //Clost output file
    f.close();

    return true;

  }else return false;
}

//Render an SVG of some matrix with a certain color scheme stored in a specified file
bool render_heatmap(std::vector< std::vector<float> > &matrix, enum colorScheme scheme, std::string filename){

  //The height of the matrix
  size_t height = matrix.size();

  //Creating output file
  std::ofstream f(filename);

  //If the output file is open
  if(f.is_open()){
    //Print header of svg file
    f << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 0 " 
      << matrix[0].size()
      << " " 
      << height 
      << "\">\n";

    //Determine max and minimum value in matrix, for use in colorscale
    map_stats * dataSet = range_of(matrix);

    //render all elements of vector matrix
    for(int y = 0; y < matrix.size(); y++){
      for(int x = 0; x < matrix[y].size(); x++){
        f <<"<rect x=\""
          << x 
          << "\" y=\"" 
          << y 
          << "\" width=\"1\" height=\"1\" fill=\""
          << color_of(discreet_weight(dataSet->max, dataSet->min, matrix[y][x]), scheme) 
          << "\"/>\n";
      }
    }

    //Print footer of svg file
    f << "</svg>\n";

    //Clost output file
    f.close();

    return true;

  }else return false;
}
#include "quickheat.hpp"
#include <fstream>
#include <stddef.h>
using namespace::std;

//Returns the rgb(,,) color data string based on scheme and input value
string color_of(const int data, enum colorScheme scheme){
  switch(scheme){
    case GREYSCALE:
      return "rgb(" + to_string(data) + "," + to_string(data) + "," + to_string(data) + ")";
      break;
    case BLUE:
      return "rgb(0,0," + to_string(data) + ")";
      break;
    case PURPLE:
      return "rgb("+to_string(data)+ ",0," + to_string(data)+ ")";
      break;
    case RED:
      return "rgb(" + to_string(data) + ",0,0)";
      break;
    case GREEN:
      return "rgb(0," + to_string(data) + ",0)";
      break;
    case YELLOW:
      return "rgb(" + to_string(data) + "," + to_string(data) + ",0)";
      break;
    case HEAT:
      return "rgb(" + to_string(data) + "," + to_string(255 - data) + ",0)";
      break;
    case ORANGE:
      return "rgb(" + to_string(data) + "," + to_string(data * 64 / 100) + ",0)";
      break;
    case PLASMA:
      return "rgb(0," + to_string(data) + "," + to_string(255 - data) + ")";
      break;
    case GRAPE:
      return "rgb(" + to_string(data) + ",0," + to_string(255 - data) + ")";
      break;   
  }
}

//Returns a struct containing the max and min values of the vector matrix
map_stats * range_of(vector< vector<int> > &matrix){
  //Initiate dataSet
  map_stats  * dataSet = new map_stats;
  dataSet->max = matrix[0][0];
  dataSet->min = matrix[0][0];

  for(int y = 0; y < matrix.size(); y++){
    for(int x = 0; x < matrix[y].size(); x++){
      if(matrix[x][y] > dataSet->max){
        dataSet->max = matrix[x][y];
      }else if(matrix[x][y] < dataSet->min){
        dataSet->min = matrix[x][y];
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
bool render_heatmap(vector< vector<int> > &matrix, enum colorScheme scheme, string filename){
  //The height of the matrix
  size_t height = matrix.size();

  //Creating output file
  ofstream f(filename);

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
          << color_of(discreet_weight(dataSet->max, dataSet->min, matrix[x][y]), scheme) 
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
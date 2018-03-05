//////////////////////////////////////////////////////////////
// Title: QuickHeat //////////////////////////////////////////
// Description: C++ heatmap library for 2D vector matricies //
// Written by: Matthew Nielsen ///////////////////////////////
// Date: March 4 2018 ////////////////////////////////////////
//////////////////////////////////////////////////////////////

#ifndef QUICKHEAT_HPP
#define QUICKHEAT_HPP

#include <vector>
#include <string>

//Enum defining the various supported colour schemes
enum colorScheme{GREYSCALE, BLUE, YELLOW, RED, GREEN, HEAT, PURPLE, ORANGE, PLASMA, GRAPE};

//Struct to contain the min and max value of the vector matrix
struct map_stats{
  float min;
  float max;
};

//Returns the rgb(,,) color data string based on scheme and input value
std::string color_of(const int data, enum colorScheme scheme);

//Returns a struct containing the max and min values of the vector matrix
map_stats * range_of(std::vector< std::vector<int> > &matrix);
map_stats * range_of(std::vector< std::vector<float> > &matrix);

//Returns the discreet weighting of the value on a scale of 0 to 255
int discreet_weight(float max, float min, float value);

//Render an SVG of some matrix with a certain color scheme stored in a specified file
bool render_heatmap(std::vector< std::vector<int> > &matrix, enum colorScheme scheme, std::string filename);
bool render_heatmap(std::vector< std::vector<float> > &matrix, enum colorScheme scheme, std::string filename);
#endif
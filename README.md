# QuickHeat

## Visualize your data with quick, beautiful heatmaps

### Beautiful

#### Solid

![Missing: Image of red 10x10 gradient](docs/images/red.png)
![Missing: Image of orange 10x10 gradient](docs/images/orange.png)
![Missing: Image of yellow 10x10 gradient](docs/images/yellow.png)
![Missing: Image of green 10x10 gradient](docs/images/green.png)
![Missing: Image of blue 10x10 gradient](docs/images/blue.png)
![Missing: Image of purple 10x10 gradient](docs/images/purple.png)

#### Mixed

![Missing: Image of heat 10x10 gradient](docs/images/heat.png)
![Missing: Image of grape 10x10 gradient](docs/images/grape.png)
![Missing: Image of plasma 10x10 gradient](docs/images/plasma.png)

#### Greyscale

![Missing: Image of greyscale 10x10 gradient](docs/images/greyscale.png)

### Simple

QuickHeat makes it easy to render heatmaps, simply pass in your vector matrix, desired color scheme, file name, and let QuickHeat do the rest

### Discreet

QuickHeat creates a discreet color scale to fit the range of your data. You can rest assured that any numerical data set you pass in will be properly represented on the heatmap.

### Usage

C++ implementation file

```cpp
#include "quickheat.hpp"

...

//  Select a colorscheme from the following preset options
//  colorScheme{GREYSCALE, BLUE, YELLOW, RED, GREEN, HEAT, PURPLE, ORANGE, PLASMA, GRAPE, RAINBOW}
colorScheme desiredColorScheme = BLUE;

// Load data into a two-dimensional vector matrix
std::vector<std::vector<float> > matrix;

//Render the heatmap by using the following function
render_heatmap(matrix, desiredColorScheme, "filename.svg");

```

### License

See [LICENSE](docs/LICENSE.md)

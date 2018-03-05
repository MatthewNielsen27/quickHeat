# Usage

* Include `quickheat.hpp` in your implementation file

* Load heatmap data into a two-dimensional vector matrix.

* Chose which colorScheme you wish to use from the following preset options

```colorScheme{GREYSCALE, BLUE, YELLOW, RED, GREEN, HEAT, PURPLE, ORANGE, PLASMA, GRAPE, RAINBOW}```

* Render the matrix by using the following function

```render_heatmap(matrix, colorScheme, "filename.svg");```

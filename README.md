# FDF 3D Wireframe Renderer

This project is a simple 3D wireframe renderer that reads a map file and creates an isometric projection of the map. The map file contains information about the height and color of the points on the grid. The renderer uses the Bresenham's line algorithm to draw the lines between the points and uses mlx library to manage the window.

## Table of Contents

1. [Requirements](#requirements)
2. [Installation](#installation)
3. [Usage](#usage)
4. [License](#license)

## Requirements

- gcc or any other C compiler
- make
- libmlx (the MiniLibX library)
- libft (a custom C library, included in the repository)

## Installation

1. Clone the repository: `git clone https://github.com/abbastoof/FDF.git`
2. Change to the project directory: `cd fdf`
3. Compile the project: `make`

## Usage

1. Run the program by providing the map file as an argument: `./fdf path/to/map/file`
2. Use the following keys to control the view:

   - Zoom: `+` and `-`
   - Move: Arrow keys
   - Adjust Z-axis: `w` and `s`
   - Toggle projection (isometric/2D): `p`
   - Exit: `esc`

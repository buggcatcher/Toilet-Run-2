# Toilet-Run-2
The **so_long** project is part of the 42 curriculum, where the objective is to create a simple 2D game using the MiniLibX library.
The game includes basic elements like movement, collectibles, and an exit.        
This game uses 2 set of textures for graphical representation and involves simple gameplay mechanics.

![Gameplay GIF](https://github.com/buggcatcher/bug-catcher/blob/main/PKMN.gif?raw=true)            
add pkmn textures            
add screen recording of mr. poopie            
use box to host images        


## Features
- Player-controlled character with basic movement (up, down, left, right).
- Collectibles that the player needs to gather before reaching the exit.
- A minimalistic 2D map with obstacles and a defined exit goal.
- Integration with MiniLibX for graphics and window management.
- Many maps to choose from for an almost fun gameplay.



## Getting Started

To set up and run the Bug Catcher game, follow these steps:
Prerequisites

Make sure you have the following installed:

    A C compiler (like GCC).
    Make utility for building the project.
    Git for version control (optional).

Clone the Repository: Open your terminal and clone the Bug Catcher repository:

    git clone https://github.com/buggcatcher/bug-catcher.git
    cd bug-catcher



Download MiniLibX: Download the MiniLibX library by running the following command:

    curl -O https://cdn.intra.42.fr/document/document/26192/minilibx-linux.tgz

Extract MiniLibX: Extract the downloaded tarball and rename the directory:


    tar -xzf minilibx-linux.tgz
    mv minilibx-linux mlx

Compile the Game: Build the project using Makefile. Ensure you are in the bug-catcher directory and run:

    make

Run the Game: After successful compilation, you can run the game with:

    ./so_long <path_to_map>

Replace <path_to_map> with your desired map file in the maps folder.

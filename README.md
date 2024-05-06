# Pokémon Mini-Game in C

## Overview

This project was created hastily for amusement quite some time ago, serving as my first personal endeavor in C programming (though initially intended for school). As such, it's not to be taken too seriously. The entire code follows the 42 code norm, hence the disastrous structure and file names. The code was designed for the same repetitive battle loop; therefore, it would have been vastly different if I had intended to add more Pokémon. The project utilizes MLX42.

## Issues and Known Limitations

- One known issue is that the Team Rocket (enemies) do not move, whereas in older versions, they could move in a random direction.
- There's a problem when the user presses enter after selecting the "object" category in a Pokémon battle.

## Features

- Smooth movement in 8 directions.
- Turn-based battles with a fully implemented Pokémon battle system.
- Collection of all Pikachu and interaction with the bicycle to win.
- Integration of a step counter displayed on a map panel.
- An escape menu with a save system that saves the player's position and step count.

## Custom Map Creation

Users can create their own maps by creating a `.ber` file. In this file, they can draw their map using characters:
- `1` represents bushes
- `0` represents ground
- `E` represents the exit (the bicycle)
- `C` represents collectibles (Pikachu)
- `R` represents enemies (Team Rocket)
- `S` represents the panel displaying the step count
- `P` represents the player

## Usage

After compiling with `make`, launch the game by running `./a.out <map_path>`. A default map is provided at `maps/map.ber` and can be used as an example for creating custom maps.

## Disclaimer

This README serves as documentation for a hobby project created long ago. While effort has been made to explain its functionality and limitations, please understand that the codebase may not adhere to professional standards.

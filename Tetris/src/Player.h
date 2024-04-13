#pragma once
#include <iostream>
#include <vector>

class Player
{
  private:
    enum class Tetromino {
        I_BLOCK,
        J_BLOCK,
        L_BLOCK,
        O_BLOCK,
        S_BLOCK,
        T_BLOCK,
        Z_BLOCK
    };

    int rotation_state;
    std::vector<std::vector<int>> tetromino_states;
    std::vector<int> tetromino;

    bool can_rotate();

  public:
    Player();

    void update();
    void draw();

    void rotate();

    void print_tile_to_console();
};

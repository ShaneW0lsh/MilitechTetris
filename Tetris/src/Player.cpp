#include "Player.h"
#include <SFML/System/Vector2.hpp>

Player::Player()
{
    Tetromino type = Tetromino::S_BLOCK;
    switch (type) {
        case Tetromino::J_BLOCK:
            tetromino_states = {{1, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 1, 0},
                                {0, 0, 0, 1, 1, 1, 0, 0, 1},
                                {0, 1, 0, 0, 1, 0, 1, 1, 0}};
            break;
        case Tetromino::S_BLOCK:
            tetromino_states = {{0, 0, 0, 0, 1, 1, 1, 1, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1},
                                {0, 0, 0, 0, 1, 1, 1, 1, 0},
                                {1, 0, 0, 1, 1, 0, 0, 1, 0}};
            break;
        default:
            break;
    }
    rotation_state = 0;
    tetromino = tetromino_states[rotation_state];
};

// Checks if the tile can be rotated without colliding with other blocks
bool Player::can_rotate() { return true; }

void Player::rotate()
{
    if (can_rotate()) ++rotation_state %= tetromino_states.size();
    tetromino = tetromino_states[rotation_state];
}

void Player::print_tile_to_console()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << tetromino[i * 3 + j] << " ";
        std::cout << '\n';
    }
}

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

class Player
{
  private:
    sf::Vector2f p_position;
    sf::Vector2f p_size;
    sf::Vector2f p_velocity;
    sf::RenderWindow *window;

    enum class Tetromino {
        I_BLOCK,
        J_BLOCK,
        L_BLOCK,
        O_BLOCK,
        S_BLOCK,
        T_BLOCK,
        Z_BLOCK
    };

    uint32_t rotation_state;
    std::vector<std::vector<uint32_t>> tetromino_states;
    std::vector<uint32_t> tetromino;

    bool can_rotate();

  public:
    Player(sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocity,
           sf::RenderWindow *window);
    Player();

    void update();
    void draw();

    void rotate();

    sf::Vector2f get_position();
    sf::Vector2f get_size();
    sf::Vector2f get_velocity();
    void set_velocity(sf::Vector2f vel);

    void print_tile_to_console();

    void move_left(uint32_t grid_size);
    void move_right(uint32_t grid_size);
};

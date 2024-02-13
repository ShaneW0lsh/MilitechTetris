#include "Player.h"
#include <SFML/System/Vector2.hpp>

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocity,
               sf::RenderWindow *window)
    : p_position(position), p_size(size), p_velocity(velocity), window(window)
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
}

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

void Player::update()
{
    if (p_position.y + p_velocity.y >= window->getSize().y) {
        p_position.y = window->getSize().y - p_size.x;
        p_velocity.y = 0;
    }
    p_position += p_velocity;
}

// Checks if the tile can be rotated without colliding with other blocks
bool Player::can_rotate() { return true; }

void Player::rotate()
{
    if (can_rotate()) ++rotation_state %= tetromino_states.size();
    tetromino = tetromino_states[rotation_state];
}

void Player::draw()
{
    sf::RectangleShape shape(p_size);
    shape.setPosition(p_position);
    shape.setFillColor(sf::Color::Red);
    window->draw(shape);
}

sf::Vector2f Player::get_position() { return p_position; }
sf::Vector2f Player::get_size() { return p_size; }
sf::Vector2f Player::get_velocity() { return p_velocity; }

void Player::set_velocity(sf::Vector2f vel) { p_velocity = vel; }

void Player::print_tile_to_console()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << tetromino[i * 3 + j] << " ";
        std::cout << '\n';
    }
}

void Player::move_left(uint32_t grid_size) { p_position.x -= grid_size; }

void Player::move_right(uint32_t grid_size) { p_position.x += grid_size; }

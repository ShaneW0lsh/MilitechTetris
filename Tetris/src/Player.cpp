#include "Player.h"
#include <SFML/System/Vector2.hpp>

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocity,
               sf::RenderWindow &window)
    : p_position(position), p_size(size), p_velocity(velocity),
      window(window){};

void Player::update()
{
    if (p_position.y + p_velocity.y >= window.getSize().y) {
        p_position.y = window.getSize().y - p_size.x;
        p_velocity.y = 0;
    }
    p_position += p_velocity;
}

void Player::draw()
{
    sf::RectangleShape shape(p_size);
    shape.setPosition(p_position);
    shape.setFillColor(sf::Color::Red);
    window.draw(shape);
}

sf::Vector2f Player::get_position() { return p_position; }
sf::Vector2f Player::get_size() { return p_size; }
sf::Vector2f Player::get_velocity() { return p_velocity; }

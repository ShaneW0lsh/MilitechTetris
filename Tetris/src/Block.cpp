#include "Block.h"
#include <SFML/System/Vector2.hpp>

sf::Vector2f Block::get_position() { return c_position; }

Block::Block(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow &window)
    : c_position(position), c_size(size), window(window)
{
}

void Block::draw()
{
    sf::RectangleShape shape(c_size);
    shape.setFillColor(sf::Color::Red);
    window.draw(shape);
}

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Block
{
  private:
    sf::Vector2f c_position;
    sf::Vector2f c_size;
    sf::RenderWindow &window;

  public:
    Block(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow &window);
    sf::Vector2f get_position();

    void draw();
};

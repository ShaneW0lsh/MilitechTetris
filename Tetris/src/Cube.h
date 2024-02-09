#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Cube
{
  private:
    sf::Vector2f c_position;
    sf::Vector2f c_size;
    sf::RenderWindow &window;

  public:
    Cube(sf::Vector2f position, sf::Vector2f size, sf::RenderWindow &window);
    sf::Vector2f get_position();

    void draw();
};

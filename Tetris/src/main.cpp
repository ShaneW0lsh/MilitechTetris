#include "Cube.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(3);

    std::vector<Cube *> cubes;
    Player *player = new Player(sf::Vector2f(0, 0), sf::Vector2f(50, 50),
                                sf::Vector2f(0, 50), window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        player->update();
        /* if (player->get_velocity().y == 0) { */
        /*     Cube *new_cube = new Cube(player->get_position()); */
        /*     cubes.push_back(new_cube); */
        /*     shape.setPosition(new_cube->get_position()); */
        /* } else { */
        /*     shape.setPosition(player->get_position()); */
        /* } */

        window.clear();

        for (Cube *cube : cubes)
            cube->draw();
        player->draw();
        window.display();
    }
}

#include "Cube.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdint>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(60);

    uint32_t grid_size = window.getSize().x / 20;
    std::vector<Cube *> cubes;
    Player *player = new Player(sf::Vector2f((float)window.getSize().x / 2, 0),
                                sf::Vector2f(grid_size, grid_size),
                                sf::Vector2f(0, grid_size), window);

    uint32_t game_shift = 0;
    while (window.isOpen()) {
        game_shift++;
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    // handle_key_press();
                    if (event.key.scancode == sf::Keyboard::Scan::Left ||
                        event.key.scancode == sf::Keyboard::Scan::A) {
                        player->move_left(grid_size);
                    } else if (event.key.scancode ==
                                   sf::Keyboard::Scan::Right ||
                               event.key.scancode == sf::Keyboard::Scan::D) {
                        player->move_right(grid_size);
                    }
                    break;
                default:
                    break;
            }
        }
        if (game_shift == 30) {
            game_shift %= 30;
            player->update();
        }
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

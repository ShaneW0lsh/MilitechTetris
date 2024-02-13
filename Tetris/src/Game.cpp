#include "Game.h"

Game::Game(sf::VideoMode vm_arg, std::string title)
{

    window = new sf::RenderWindow(vm_arg, title);
    window->setFramerateLimit(60);
    grid_size = vm_arg.width / 20;

    player = new Player(sf::Vector2f((float)window->getSize().x / 2, 0),
                        sf::Vector2f(grid_size, grid_size),
                        sf::Vector2f(0, grid_size), window);
    game_step = 0;
}

void Game::poll_events()
{
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                handle_key_press();
                break;
            default:
                break;
        }
    }
}

void Game::handle_key_press()
{
    if (event.key.scancode == sf::Keyboard::Scan::Left ||
        event.key.scancode == sf::Keyboard::Scan::A) {
        player->move_left(grid_size);
        std::cout << "left\n";
    } else if (event.key.scancode == sf::Keyboard::Scan::Right ||
               event.key.scancode == sf::Keyboard::Scan::D) {
        player->move_right(grid_size);
        std::cout << "right\n";
    }
}

void Game::run()
{
    while (window->isOpen()) {
        poll_events();
        if (game_step == 30) {
            player->update();
            game_step %= 30;
        }
        game_step++;

        /* std::cout << player->get_position().x << ' ' <<
         * player->get_position().y */
        /*           << std::endl; */
        /* std::cout << "Grid size: " << grid_size << std::endl; */

        render();
    }
}

void Game::render()
{
    window->clear();

    player->draw();
    for (auto &block : blocks)
        block->draw();

    window->display();
}

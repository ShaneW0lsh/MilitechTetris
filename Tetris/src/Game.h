#pragma once
#include "Block.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdint>
#include <iostream>

class Game
{
  private:
    sf::RenderWindow *window;
    sf::Event event;

    Player *player;
    std::vector<Block *> blocks;
    uint32_t grid_size;
    uint32_t game_step;

    void poll_events();
    void handle_key_press();

    void render();

  public:
    Game(sf::VideoMode vm, std::string title);
    void run();
};

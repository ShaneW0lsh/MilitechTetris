#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Player
{
  private:
    sf::Vector2f p_position;
    sf::Vector2f p_size;
    sf::Vector2f p_velocity;
    sf::RenderWindow *window;

    uint32_t tile_state;

    void check_for_collisions();

  public:
    Player(sf::Vector2f position, sf::Vector2f size, sf::Vector2f velocity,
           sf::RenderWindow *window);

    void update();
    void draw();

    void rotate();

    sf::Vector2f get_position();
    sf::Vector2f get_size();
    sf::Vector2f get_velocity();
    void set_velocity(sf::Vector2f vel);

    void move_left(uint32_t grid_size);
    void move_right(uint32_t grid_size);
};

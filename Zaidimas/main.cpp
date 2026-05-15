#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280u, 720u}), "Zaidimas");
    while (window.isOpen()) {
        while (const std::optional<sf::Event> e = window.pollEvent()) {
            if (e->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
    return 0;
}

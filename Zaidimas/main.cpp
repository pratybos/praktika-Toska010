#include <SFML/Graphics.hpp>
#include <iostream>

float zaidejoGreitis = 100u;
float zaidejoPlotas = 40u;
float zaidejoAukstis = 15u;
struct Zaidejas {
    sf::ConvexShape figura;
    Zaidejas() {
        figura = sf::ConvexShape(3);
        //Kaire Desine Virsus
        figura.setPoint(0, {0u, 0u});
        figura.setPoint(1, {zaidejoPlotas, 0u});
        figura.setPoint(2, {zaidejoPlotas * 0.5f, zaidejoAukstis });
        //Kaire Desine Virsus
        figura.setFillColor(sf::Color::Green);
        figura.setPosition({0u, 0u});
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280u, 720u}), "Zaidimas");
    while (window.isOpen()) {
        while (const std::optional<sf::Event> e = window.pollEvent()) {
            if (e->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        Zaidejas zaidejas;
        window.clear();
        window.draw(zaidejas.figura);
        window.display();

    }
    return 0;
}

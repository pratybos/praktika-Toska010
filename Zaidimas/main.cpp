#include <SFML/Graphics.hpp>
#include <iostream>
// ZAIDEJAS *******************************************************************************
// Parametrai
float zaidejoGreitis = 250u;
float zaidejoPlotas = 40u;
float zaidejoAukstis = 15u;
// Objektas
struct Zaidejas {
    sf::ConvexShape figura;
    Zaidejas() : figura(3) {
        //Kaire Desine Virsus
        figura.setPoint(0, {0u, 0u});
        figura.setPoint(1, {zaidejoPlotas, 0u});
        figura.setPoint(2, {zaidejoPlotas * 0.5f, -zaidejoAukstis });
        //Kaire Desine Virsus
        figura.setFillColor(sf::Color::Green);
        figura.setPosition({100u, 100u});
    }
};
// Valdymas
sf::Vector2f zaidejoIvestis(float zaidejoGreitis, float dt) {
    sf::Vector2f pastumimas{0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {pastumimas.y -= zaidejoGreitis * dt;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {pastumimas.y += zaidejoGreitis * dt;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {pastumimas.x -= zaidejoGreitis * dt;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {pastumimas.x += zaidejoGreitis * dt;}
    return pastumimas;
}
// Judinimas
void zaidejoJudinimas(sf::ConvexShape& figura, const sf::Vector2f& pastumimas) {
    figura.move(pastumimas);
}
// ZAIDEJAS *******************************************************************************
int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Zaidimas", sf::Style::None);
    sf::Clock ciklas;
    Zaidejas zaidejas;
    while (window.isOpen()) {
        while (const std::optional<sf::Event> e = window.pollEvent()) {
            if (e->is<sf::Event::Closed>()) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {window.close();}
        }
        const float dt = ciklas.restart().asSeconds();
        const sf::Vector2f pastumimas = zaidejoIvestis(zaidejoGreitis, dt);
        zaidejoJudinimas(zaidejas.figura, pastumimas);
        window.clear();
        window.draw(zaidejas.figura);
        window.display();

    }
    return 0;
}

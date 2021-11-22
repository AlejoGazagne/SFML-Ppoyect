#include "Puntaje.h"

state Puntaje::draw(sf::RenderWindow &window) {
    // IMPRIMIR POR PANTALLA LOS PUNTAJES
    window.clear();
    window.draw(imagen);

    Olddata.setFont(font);
    Olddata.setFillColor(sf::Color::White);
    Olddata.setString(pantalla);
    Olddata.setCharacterSize(10);
    Olddata.setPosition(300, 35);

    window.draw(Olddata);
    window.display();

    timeout++;
    if (timeout > 480) {
        timeout = 0;
        return MENU;
    }

    return TABLE;
}

Puntaje::Puntaje() {
    if (!textura.loadFromFile("assets/puntajes.png")) {
        //handle error;
    }
    imagen.setTexture(textura);
    if (!font.loadFromFile("assets/letra.ttf")) {
        //handle error
    }
    string line;
    pantalla = "";
    std::ifstream ifs;

    ifs.open("Puntajes.txt");
    if (ifs.is_open()) {
        while (getline(ifs, line)) {
            pantalla += line + '\n';
        }
        ifs.close();
    }
}

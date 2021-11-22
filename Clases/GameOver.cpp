#include "GameOver.h"
#include <fstream>
#include <iostream>
#include <thread>

state GameOver::draw(sf::RenderWindow &window) {
    // IMPRIMIR POR PANTALLA LOS PUNTAJES
    window.clear();
    window.draw(fondo);

    Olddata.setFont(font);
    Olddata.setFillColor(sf::Color::White);
    Olddata.setString(pantalla);
    Olddata.setCharacterSize(20);
    Olddata.setPosition(280, 200);

    window.draw(Olddata);
    window.display();
    timeout++;
    if (timeout > 480) {
        timeout = 0;
        return MENU;
    }
    return GAMEOVER;
}

GameOver::GameOver() {
    std::this_thread::sleep_for(1000ms);
    if (!font.loadFromFile("assets/letra.ttf")) {
        //handle error
    }
    if (!textura.loadFromFile("assets/gameover.png")) {
        //handle error;
    }
    fondo.setTexture(textura);

    string line;
    pantalla = "";
    std::ifstream ifs;
    timeout = 0;

    ifs.open("Tabla.txt");
    if (ifs.is_open()) {
        while (getline(ifs, line)) {
            pantalla += line + '\n';
        }
        ifs.close();
    }
}

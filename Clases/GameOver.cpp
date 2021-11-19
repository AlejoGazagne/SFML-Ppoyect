#include "GameOver.h"
#include <fstream>
#include <iostream>
#include <thread>

state GameOver::draw(sf::RenderWindow &window) {
    // IMPRIMIR POR PANTALLA LOS PUNTAJES

    Olddata.setFont(font);
    Olddata.setFillColor(sf::Color::White);
    Olddata.setString(pantalla);
    Olddata.setPosition(100, 100);

    window.clear();
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

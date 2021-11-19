#include "GameOver.h"
#include <fstream>
#include <iostream>

void GameOver::draw(sf::RenderWindow &window) {
    // IMPRIMIR POR PANTALLA LOS PUNTAJES

    Olddata.setFont(font);
    Olddata.setFillColor(sf::Color::White);
    Olddata.setString(pantalla);
    Olddata.setPosition(500,500);

    window.clear();
    window.draw(Olddata);
    window.display();
}

state GameOver::events(sf::Event event) {
    return GAMEOVER;
}

GameOver::GameOver() {
    if (!font.loadFromFile("assets/letra.ttf")) {
        //handle error
    }
    pantalla = "";
    std::ifstream ifs;

    ifs.open("Tabla.txt");
    if(ifs.is_open()){
        while (!ifs.eof()){
            pantalla += ifs.get();
        }
        ifs.close();
    }
}

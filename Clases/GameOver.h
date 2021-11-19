//
// Created by martin on 19/11/21.
//

#ifndef PERSONAJE_H_GAMEOVER_H
#define PERSONAJE_H_GAMEOVER_H


#include <SFML/Graphics.hpp>
#include "../main.h"

class GameOver {
public:
    GameOver();

    state events(sf::Event event);

    void draw(sf::RenderWindow &window);
};


#endif //PERSONAJE_H_GAMEOVER_H

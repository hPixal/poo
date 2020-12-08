#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
class Game {
    RenderWindow _window;
    Event _ev;
    void initWindow();
public:

    //Functions;
    Game();
    virtual ~Game();
    
    void update();                              // Polls every event and puts them in _ev || If the event type is close, it closes the active window.
    void render();                              // Asks every sub class to render whathever is going on on the game
    const RenderWindow& getWindow() const;
    
};
#include "Window.h"
#include "playfield_dimensions.h"

Window::Window() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris");
}

sf::RenderWindow& Window::getWindow() {
    return window;
}
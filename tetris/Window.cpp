#include "Window.h"
#include "playfield_dimensions.h"

Window::Window() {
    window.create(sf::VideoMode(WIDTH * RESIZE * CELL_SIZE * 2, VISIBLE_HEIGHT * RESIZE * CELL_SIZE), "Tetris");
}

sf::RenderWindow& Window::getWindow() {
    return window;
}
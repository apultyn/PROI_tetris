#pragma once
#include <SFML/Graphics.hpp>

constexpr int HEIGHT = 20;
constexpr int VISIBLE_HEIGHT = 20;
constexpr int WIDTH = 10;
constexpr int RESIZE = 6;
constexpr int CELL_SIZE = 8;
constexpr int INIT_X = 3;
constexpr int INIT_Y = -2;
constexpr int OUTLINE_THICKNESS = -2;
const enum colors { GREY, SALMON, ORANGE, YELLOW, GREEN, CYAN, PURPLE, RED,
DARK_ORANGE, SANDY_BROWN, DARK_GREEN, BLUE, DARK_PURPLE, NAVY, DARK_MEDIUM_BLUE };

const sf::Color GREY_COLOR(41, 44, 51);
const sf::Color SALMON_COLOR(253, 63, 89);
const sf::Color ORANGE_COLOR(255, 200, 46);
const sf::Color YELLOW_COLOR(254, 251, 52);
const sf::Color GREEN_COLOR(83, 218, 63);
const sf::Color CYAN_COLOR(1, 237, 250);
const sf::Color PURPLE_COLOR(221, 10, 178);
const sf::Color RED_COLOR(234, 20, 28);
const sf::Color DARK_ORANGE_COLOR(254, 72, 25);
const sf::Color SANDY_BROWN_COLOR(255, 145, 12);
const sf::Color DARK_GREEN_COLOR(57, 137, 47);
const sf::Color BLUE_COLOR(0, 119, 211);
const sf::Color DARK_PURPLE_COLOR(120, 37, 111);
const sf::Color NAVY_COLOR(46, 46, 132);
const sf::Color DARK_MEDIUM_BLUE_COLOR(72, 93, 197);

#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Bubble : public sf::CircleShape
{

    sf::Vector2f bubblePosition;
    sf::Vector2f bubbleMove;
    sf::Color bubbleColor;
    int alpha =100;     // bubble transparency
    int r;              // bubble radius
    int bubbleThickness = 2;  // bubble border thickness

    public:
        Bubble();
        Bubble(sf::Vector2f);
        Bubble(sf::Vector2f, sf::Vector2f);
        virtual ~Bubble();
        void moveBubble(Bubble &target, int width, int height);
        bool isCollision(Bubble &target);

    protected:

    private:
};

#endif // BUBBLE_H

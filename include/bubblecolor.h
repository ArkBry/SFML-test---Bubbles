#ifndef BUBBLECOLOR_H
#define BUBBLECOLOR_H

#include <iostream>
#include <SFML/Graphics.hpp>

class BubbleColor : public sf::Color
{
    int topColor;   // limit RGB range - allowed values from 0 to 255
    int downColor;  // limit RGB range - allowed values from 0 to 255
    int counter;
    float step=0.2; //




    public:
        sf::Color actualColor;

        BubbleColor(sf::Color myColor);
        BubbleColor(sf::Color myColor, int d, int t);
        virtual ~BubbleColor();
        sf::Color colorSmoothChange();

    protected:

    private:
};

#endif // BUBBLECOLOR_H

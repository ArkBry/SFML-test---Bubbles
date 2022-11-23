#include "bubblecolor.h"

//    sf::Color actualColor;
//    int topColor;
//    int downColor;
//    int counter;
//    float step=0.2;


BubbleColor::BubbleColor(sf::Color myColor)
{
    actualColor=myColor;
    topColor=255;
    downColor=0;
    counter=1;
}

BubbleColor::BubbleColor(sf::Color myColor, int d, int t)
{
    actualColor=myColor;
    topColor=t;
    downColor=d;
    counter=1;

    if (topColor<0 || topColor>255) topColor=255;
    if (downColor<0 || downColor>255) downColor=0;
}

BubbleColor::~BubbleColor()
{
    //dtor
}

sf::Color BubbleColor::colorSmoothChange()
{
/*
1. G++
2. R--
3. B++
4. G--
5. R++
6. B--
*/

    if (counter==1)
    {
        actualColor=actualColor + sf::Color(0,1,0);
        if (actualColor.g==topColor)counter++;
    }
    else if (counter==2)
    {
        actualColor=actualColor - sf::Color(1,0,0);
        if (actualColor.r==downColor)counter++;
    }
    else if (counter==3)
    {
        actualColor=actualColor + sf::Color(0,0,1);
        if (actualColor.b==topColor)counter++;
    }
    else if (counter==4)
    {
        actualColor=actualColor - sf::Color(0,1,0);
        if (actualColor.g==downColor)counter++;
    }
    else if (counter==5)
    {
        actualColor=actualColor + sf::Color(1,0,0);
        if (actualColor.r==topColor)counter++;
    }
    else if (counter==6)
    {
        actualColor=actualColor - sf::Color(0,0,1);
        if (actualColor.b==downColor)counter++;
    };
    if (counter==7)counter=1;

//    else    actualColor = actualColor + sf::Color(1,1,1);
    return actualColor;

}

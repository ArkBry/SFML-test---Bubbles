#include "bubble.h"
#include <math.h>

using namespace std;

// Constructor with random speed and direction
Bubble::Bubble(sf::Vector2f pos)
{
    bubblePosition = pos;
    r=rand()%20+10;
    bubbleColor=sf::Color(rand()%255,rand()%255,rand()%255);
    setOutlineColor(bubbleColor);
    setFillColor(bubbleColor-sf::Color(0,0,0,alpha));
    setRadius(r);
    setOutlineThickness(bubbleThickness);
    setOrigin(r,r);
    setPosition(bubblePosition);
    bubbleMove=sf::Vector2f(rand()%10-5,rand()%10-5);
}

// Constructor with defined speed and direction
Bubble::Bubble(sf::Vector2f pos, sf::Vector2f mov)
{

    bubblePosition = mov;
    r=rand()%20+10;
    bubbleColor=sf::Color(rand()%255,rand()%255,rand()%255);
    setOutlineColor(bubbleColor);
    setFillColor(bubbleColor-sf::Color(0,0,0,alpha));
    setRadius(r);
    setOutlineThickness(bubbleThickness);
    setOrigin(r,r);
    setPosition(bubblePosition);
    bubbleMove.x=(mov.x-pos.x)/20;
    bubbleMove.y=(mov.y-pos.y)/20;
}

Bubble::~Bubble()
{
    //dtor
}

void Bubble::moveBubble(Bubble &target, int width, int height)
{
    target.move(bubbleMove);
/*
// when I used that code have bug when mov point is closer window edge than r - bubbles are glued to the window edge


    if (target.getPosition().x - r <= 0 || target.getPosition().x + r >= width)
    {
        bubbleMove.x=bubbleMove.x *(-1);
    };
    if (target.getPosition().y - r <= 0 || target.getPosition().y + r >= height)
    {
        bubbleMove.y=bubbleMove.y *(-1);
    };
*/

    if (target.getPosition().x - r <= 0)
    {
        bubbleMove.x=abs(bubbleMove.x);
    };

    if (target.getPosition().x + r >= width)
    {
        bubbleMove.x=abs(bubbleMove.x)*(-1);
    };

    if (target.getPosition().y - r <= 0)
    {
        bubbleMove.y=abs(bubbleMove.y);
    };

    if (target.getPosition().y + r >= height)
    {
        bubbleMove.y=abs(bubbleMove.y)*(-1);
    };
}

bool Bubble::isCollision(Bubble &target)
{
    float distance=sqrt(pow(this->getPosition().x-target.getPosition().x,2)+pow(this->getPosition().y-target.getPosition().y,2));
    float minDistance=this->getRadius()+target.getRadius();

    if (distance <= minDistance)
    {
        bubbleMove.x=bubbleMove.x*(-1);
        bubbleMove.y=bubbleMove.y*(-1);
        target.bubbleMove.x=target.bubbleMove.x*(-1);
        target.bubbleMove.y=target.bubbleMove.y*(-1);
        return true;
    }
    return false;

}

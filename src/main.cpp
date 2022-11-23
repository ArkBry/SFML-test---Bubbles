
#include <iostream>
#include <SFML/Graphics.hpp>

#include "bubble.h"
#include "bubblecolor.h"

using namespace std;

int windowWidth = 800;
int windowHeight = 600;

// --------------------- Print message ---------------------
void printMessage (int x)
{
    if (x == 1)
    {
        cout << "There is "<< x << " bubble" << endl;
    }
    else if (x != 1 && x != 0)
    {
        cout << "There are "<< x << " bubbles" << endl;
    }
    else if (x == 0)
    {
        cout << "All bubbles deleted" << endl;
    }
};


// --------------------- Main function ---------------------
int main()
{
    cout<<"Welcome"<<endl;
    cout<<"Click left mouse button on screen to add there a bubble with random move."<<endl;
    cout<<"Click, drag mouse and leave button to create a bubble with defined move and speed."<<endl;
    cout<<"'Backspace' will delete last bubble and 'Delete' will delete all bubbles."<<endl;
    cout<<"Press 'c' key to enable/disable collisions."<<endl;
    cout<<"Have a fun with bubbles..."<<endl;

    sf::Vector2f pressMouse, releaseMouse;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bubbles");
    window.setFramerateLimit(30);

    vector <Bubble> Bubbles;
    BubbleColor backgroundColor (sf::Color(65, 21, 97),50,130);
    bool collisionEnable=true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                pressMouse = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                releaseMouse = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                if (pressMouse == releaseMouse)
                {
                    Bubble n (pressMouse);
                    Bubbles.push_back(n);
                    printMessage(Bubbles.size());
                }
                else
                {
                    Bubble n (pressMouse,releaseMouse);
                    Bubbles.push_back(n);
                    printMessage(Bubbles.size());
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Delete)
            {
                Bubbles.clear();
                printMessage(Bubbles.size());
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
            {
                if (Bubbles.size() > 0)
                {
                    Bubbles.erase(Bubbles.end());
                    printMessage(Bubbles.size());
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C)
            {
                if (collisionEnable==true)
                {
                    collisionEnable=false;
                    cout<<"Collisions disabled"<<endl;
                }
                else
                {
                    collisionEnable=true;
                    cout<<"Collisions enabled"<<endl;
                }
            }

        }
        backgroundColor.colorSmoothChange();
        window.clear(backgroundColor.actualColor);
        for (auto i=Bubbles.begin();i != Bubbles.end(); i++)
        {
            i->moveBubble(*i,windowWidth,windowHeight);

            if (collisionEnable==true)
            {
                for (auto j=Bubbles.begin();j != Bubbles.end(); j++)
                {
                    if (i==j)continue;
                    i->isCollision(*j);
                }
            }
            window.draw(*i);
        }

        window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>

// Based on this video https://www.youtube.com/watch?v=R87RUYUfgwM&t
class BouncingRect
{

public:
    void Run()
    {
        sf::RenderWindow window(sf::VideoMode(1280, 720), "The window");
        window.setFramerateLimit(60);
        sf::Vector2f rectSize(100,100);
        sf::RectangleShape rect(rectSize);
        sf::Vector2u size = window.getSize();
        sf::Vector2f rectPos(size.x / 2, size.y / 2);
        rect.setPosition(rectPos);

        sf::Vector2f velocity(3, 3);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    velocity.x *= 1.5;
                    velocity.y *= 1.5;
                }
            }
            sf::Vector2f pos = rect.getPosition();
            if (pos.x >= (size.x - rectSize.x)|| pos.x <= 0)
            {
                velocity.x = -velocity.x;
            }
            if (pos.y >= (size.y - rectSize.y)|| pos.y <= 0)
            {
                velocity.y = -velocity.y;
            }

            moveShape(rect, velocity);

            // collision

            // draw stuff
            window.clear(/*sf::Color::Black*/);
            window.draw(rect);
            window.display();
        }
    }

private:
    void moveShape(sf::Shape &shape, sf::Vector2f velocity)
    {
        sf::Vector2f pos = shape.getPosition();
        pos.x += velocity.x;
        pos.y += velocity.y;
        shape.setPosition(pos);
    }

    void moveShape(sf::Shape &shape, float xVelocity, float yVelocity)
    {
        sf::Vector2f pos = shape.getPosition();
        pos.x += xVelocity;
        pos.y += yVelocity;
        shape.setPosition(pos);
    }

    void handleShapeCollision(sf::Shape &shape, sf::Window &window)
    {
        sf::Vector2f pos = shape.getPosition();
        sf::Vector2u windowSize = window.getSize();
        if (pos.x == windowSize.x || pos.x == 0)
        {
        }
        if (pos.y == windowSize.y || pos.y == 0)
        {
        }
    }
};
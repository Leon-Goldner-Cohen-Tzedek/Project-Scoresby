#include <SFML/Graphics.hpp>

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 255;

  sf::RenderWindow window(sf::VideoMode(1000, 1000), "Scoresby", sf::Style::Default, settings);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color(255, 255, 255));

  sf::Texture car;
  car.loadFromFile("car.png");
  car.setSmooth(true);

  sf::Sprite carSprite;
  carSprite.setTexture(car);

  while (window.isOpen())
  {

    sf::Event event;
    while (window.pollEvent(event))
    {
      window.clear();
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed)
      {
        if(event.key.code == sf::Keyboard::W)
        {
          carSprite.move(sf::Vector2f(0.f, -5.f));
        }
        if(event.key.code == sf::Keyboard::S)
        {
          carSprite.move(sf::Vector2f(0.f, 5.f));
        }
        if(event.key.code == sf::Keyboard::A)
        {
          carSprite.move(sf::Vector2f(-5.f, 0.f));
        }
        if(event.key.code == sf::Keyboard::D)
        {
          carSprite.move(sf::Vector2f(5.f, 0.f));
        }
      }

      else window.draw(shape); window.draw(carSprite);
      window.display();
    }
  }

    return 0;
}

#include <SFML/Graphics.hpp>

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 255;

  sf::RenderWindow window(sf::VideoMode(300, 400), "Scoresby", sf::Style::Default, settings);

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

      else window.draw(shape); window.draw(carSprite);
      window.display();
    }
  }

    return 0;
}

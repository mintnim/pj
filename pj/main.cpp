#include<iostream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>

using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "CODING BOOSTER");
	sf::Event ev;
	
	sf::Sprite background_menu;
	sf::Texture background_menu_texture;

	background_menu_texture.loadFromFile("images/background.png");
	background_menu.setTexture(background_menu_texture);

	sf::Sprite logo;
	sf::Texture logo_texture;

	logo_texture.loadFromFile("images/logo.png");
	logo.setTexture(logo_texture);
	logo.setPosition(sf::Vector2f(450, -300));
	logo.setScale(sf::Vector2f(1.10, 1.10));

	sf::Sprite bplay;
	sf::Texture bplay_texture;
	sf::Texture bplay_on_texture;

	bplay_texture.loadFromFile("images/bplay.png");
	bplay_on_texture.loadFromFile("images/bplay_on.png");
	bplay.setTexture(bplay_texture);
	bplay.setPosition(sf::Vector2f(820, 500));
	bplay.setScale(sf::Vector2f(0.7, 0.7));

	sf::Sprite binfo;
	sf::Texture binfo_texture;

	binfo_texture.loadFromFile("images/binfo.png");
	binfo.setTexture(binfo_texture);
	binfo.setPosition(sf::Vector2f(825, 650));
	binfo.setScale(sf::Vector2f(0.7, 0.7));

	sf::Sprite bhigh;
	sf::Texture bhigh_texture;

	bhigh_texture.loadFromFile("images/bhigh.png");
	bhigh.setTexture(bhigh_texture);
	bhigh.setPosition(sf::Vector2f(895, 850));
	bhigh.setScale(sf::Vector2f(0.7, 0.7));

	sf::Sprite mod1;
	sf::Texture mod1_texture;

	mod1_texture.loadFromFile("images/mod1.png");
	mod1.setTexture(mod1_texture);
	mod1.setPosition(sf::Vector2f(360, 200));
	mod1.setScale(sf::Vector2f(1.5, 1.5));

	sf::Sprite mod2;
	sf::Texture mod2_texture;

	mod2_texture.loadFromFile("images/mod2.png");
	mod2.setTexture(mod2_texture);
	mod2.setPosition(sf::Vector2f(360, 400));
	mod2.setScale(sf::Vector2f(1.5, 1.5));

	sf::Sprite mod3;
	sf::Texture mod3_texture;

	mod3_texture.loadFromFile("images/mod3.png");
	mod3.setTexture(mod3_texture);
	mod3.setPosition(sf::Vector2f(360, 600));
	mod3.setScale(sf::Vector2f(1.5, 1.5));

	sf::Sprite buttbacktomenu;
	sf::Texture buttback_texture;

	buttback_texture.loadFromFile("images/buttback.png");
	buttbacktomenu.setTexture(buttback_texture);
	buttbacktomenu.setPosition(sf::Vector2f(1750, 950));
	buttbacktomenu.setScale(sf::Vector2f(0.5, 0.5));

	window.clear();

	window.draw(background_menu);
	window.draw(logo);
	window.draw(bplay);
	window.draw(binfo);
	window.draw(bhigh);

	window.display();
	
	while (window.isOpen()) 
	{
		while (window.pollEvent(ev)) 
		{
			switch (ev.type) 
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();	
			case sf::Event::MouseButtonPressed:
				if (ev.mouseButton.button == sf::Mouse::Left)
				{
					if (bplay.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();

						window.draw(background_menu);
						window.draw(mod1);
						window.draw(mod2);
						window.draw(mod3);
						window.draw(buttbacktomenu);

						window.display();
					}
					if (buttbacktomenu.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						window.clear();

						window.draw(background_menu);
						window.draw(logo);
						window.draw(bplay);
						window.draw(binfo);
						window.draw(bhigh);

						window.display();
					}

					break;
				}

			}
		}
		
	}

	return 0;
}
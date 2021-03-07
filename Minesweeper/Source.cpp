#include "Minesweeper.h"
#include "Menu.h"

int main() {
	while (true) {
		sf::RenderWindow window;
		window.create(sf::VideoMode(400, 300), "Minesweeper");
		sf::Event event;

		Menu menu(window.getSize().x, window.getSize().y);
	
		while (window.isOpen()) {
			while (window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					return 0;

				case sf::Event::KeyReleased:
					switch (event.key.code) {
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;
					case sf::Keyboard::Down:
						menu.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (menu.getPressedItem()) {
						case 0:
							std::cout << "Button 0\n";
							break;
						case 1:
							std::cout << "Button 1\n";
							break;
						case 2:
							std::cout << "Button 2\n";
							break;
						case 3:
							std::cout << "Button 3\n";
							window.close();
							return 0;
						}
					}

				case sf::Event::MouseButtonReleased:
					if (event.key.code == sf::Mouse::Left) {
						switch (menu.getPressedItem()) {
						case 0:
							window.close();
							Minesweeper(288, 288, 9, 9, 10);
							break;
						case 1:
							window.close();
							Minesweeper(512, 512, 16, 16, 40);
							break;
						case 2:
							window.close();
							Minesweeper(960, 512, 30, 16, 99);
							break;
						case 3:
							window.close();
							return 0;
						}

					}
					break;

				case sf::Event::MouseMoved:
					sf::Vector2i mousePoz = sf::Mouse::getPosition(window);
					if (mousePoz.x >= 0 && mousePoz.x <= window.getSize().x && mousePoz.y >= 55 && mousePoz.y <= 100) {
						menu.setMenuColor(0, sf::Color::Red);
						menu.setMenuColor(1, sf::Color::White);
						menu.setMenuColor(2, sf::Color::White);
						menu.setMenuColor(3, sf::Color::White);

						menu.setSelectedItemIndex(0);
					}

					if (mousePoz.x >= 0 && mousePoz.x <= window.getSize().x && mousePoz.y >= 125 && mousePoz.y <= 150) {
						menu.setMenuColor(0, sf::Color::White);
						menu.setMenuColor(1, sf::Color::Red);
						menu.setMenuColor(2, sf::Color::White);
						menu.setMenuColor(3, sf::Color::White);

						menu.setSelectedItemIndex(1);
					}

					if (mousePoz.x >= 0 && mousePoz.x <= window.getSize().x && mousePoz.y >= 185 && mousePoz.y <= 210) {
						menu.setMenuColor(0, sf::Color::White);
						menu.setMenuColor(1, sf::Color::White);
						menu.setMenuColor(2, sf::Color::Red);
						menu.setMenuColor(3, sf::Color::White);

						menu.setSelectedItemIndex(2);
					}

					if (mousePoz.x >= 0 && mousePoz.x <= window.getSize().x && mousePoz.y >= 245 && mousePoz.y <= 270) {
						menu.setMenuColor(0, sf::Color::White);
						menu.setMenuColor(1, sf::Color::White);
						menu.setMenuColor(2, sf::Color::White);
						menu.setMenuColor(3, sf::Color::Red);

						menu.setSelectedItemIndex(3);
					}

					break;
				}
			}

			window.clear();
			menu.draw(window);
			window.display();
		}
	}
}
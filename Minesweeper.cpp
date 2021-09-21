#include "Minesweeper.h"

void search(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid, std::vector<std::vector<bool>>& visited, int x, int y) {
	const int X = grid.size() - 2;
	const int Y = grid[0].size() - 2;

	if (sgrid[x][y] != 0) {
		visited[x][y] = true;
		grid[x][y] = sgrid[x][y];
		return;
	}
	if (sgrid[x][y] == 0) {
		visited[x][y] = true;
		grid[x][y] = sgrid[x][y];
	}

	//up
	if (x - 1 >= 1 && visited[x - 1][y] == 0) { search(grid, sgrid, visited, x - 1, y); }
	//down
	if (x + 1 <= X && visited[x + 1][y] == 0) { search(grid, sgrid, visited, x + 1, y); }
	//right
	if (y + 1 <= Y && visited[x][y + 1] == 0) { search(grid, sgrid, visited, x, y + 1); }
	//left
	if (y - 1 >= 1 && visited[x][y - 1] == 0) { search(grid, sgrid, visited, x, y - 1); }

	//up-left
	if (x - 1 >= 1 && y - 1 >= 1 && visited[x - 1][y - 1] == 0) { search(grid, sgrid, visited, x - 1, y - 1); }
	//up-right
	if (x - 1 >= 1 && y + 1 <= Y && visited[x - 1][y + 1] == 0) { search(grid, sgrid, visited, x - 1, y + 1); }
	//down-left
	if (x + 1 <= X && y - 1 >= 1 && visited[x + 1][y - 1] == 0) { search(grid, sgrid, visited, x + 1, y - 1); }
	//down-right
	if (x + 1 <= X && y + 1 <= Y && visited[x + 1][y + 1] == 0) { search(grid, sgrid, visited, x + 1, y + 1); }


}

int searchFlags(const std::vector<std::vector<int>>& grid, int x, int y) {
	int count = 0;
	//first row
	if (grid[x - 1][y - 1] == 11) count++;
	if (grid[x - 1][y] == 11) count++;
	if (grid[x - 1][y + 1] == 11) count++;
	//second row
	if (grid[x][y - 1] == 11) count++;
	if (grid[x][y + 1] == 11) count++;
	//third row
	if (grid[x + 1][y - 1] == 11) count++;
	if (grid[x + 1][y] == 11) count++;
	if (grid[x + 1][y + 1] == 11) count++;

	return count;
}

void numberDiscover(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid, bool& gameOver, int x, int y) {
	if (grid[x][y] == searchFlags(grid, x, y)) {
		//first row
		if (grid[x - 1][y - 1] != 11) { grid[x - 1][y - 1] = sgrid[x - 1][y - 1]; }//if (grid[x - 1][y - 1] == 0) search(grid, sgrid, x - 1, y - 1); }
		if (grid[x - 1][y] != 11) { grid[x - 1][y] = sgrid[x - 1][y]; } //if (grid[x - 1][y] == 0) search(grid, sgrid, x - 1, y); }
		if (grid[x - 1][y + 1] != 11) { grid[x - 1][y + 1] = sgrid[x - 1][y + 1]; }//if (grid[x - 1][y + 1] == 0) search(grid, sgrid, x - 1, y + 1); }
		//second row
		if (grid[x][y - 1] != 11) { grid[x][y - 1] = sgrid[x][y - 1]; }//if (grid[x][y - 1] == 0) search(grid, sgrid, x, y - 1); }
		if (grid[x][y + 1] != 11) { grid[x][y + 1] = sgrid[x][y + 1]; }//if (grid[x][y + 1] == 0) search(grid, sgrid, x, y + 1); }
		//third row
		if (grid[x + 1][y - 1] != 11) { grid[x + 1][y - 1] = sgrid[x + 1][y - 1]; }//if (grid[x + 1][y - 1] == 0) search(grid, sgrid, x + 1, y - 1); }
		if (grid[x + 1][y] != 11) { grid[x + 1][y] = sgrid[x + 1][y]; }//if (grid[x + 1][y] == 0) search(grid, sgrid, x + 1, y); }
		if (grid[x + 1][y + 1] != 11) { grid[x + 1][y + 1] = sgrid[x + 1][y + 1]; }//if (grid[x + 1][y + 1] == 0) search(grid, sgrid, x + 1, y + 1); }

		//gameover
		if ((grid[x - 1][y - 1] == 9 || grid[x - 1][y] == 9 || grid[x - 1][y + 1] == 9 || grid[x][y - 1] == 9 || grid[x][y + 1] == 9 || grid[x + 1][y - 1] == 9
			|| grid[x + 1][y] == 9 || grid[x + 1][y + 1] == 9)) {
			gameOver = true;
		}
	}
}

void findMines(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid) {
	static bool called = false;
	if (called) return;

	for (int i = 1; i <= grid.size() - 2; i++) {
		for (int j = 1; j <= grid[0].size() - 2; j++) {
			if (sgrid[i][j] == 9) {
				grid[i][j] = sgrid[i][j];
			}
		}
	}
	called = true;
}

void discoverAll(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid) {
	static bool called = false;
	if (called) return;

	for (int i = 1; i <= grid.size() - 2; i++) {
		for (int j = 1; j <= grid[0].size() - 2; j++) {
			if (grid[i][j] != 11) {
				grid[i][j] = sgrid[i][j];
			}
		}
	}
	called = true;
}

void Minesweeper(const int windowX, const int windowY, const int X, const int Y, const int minesNr) {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(windowX, windowY + 25), "Minesweeper");
	sf::Event event;

	std::vector<std::vector<int>> grid(X + 2, std::vector<int>(Y + 2, 10));
	std::vector<std::vector<int>> sgrid(X + 2, std::vector<int>(Y + 2, 10));
	std::vector<std::vector<bool>> visited(X + 2, std::vector<bool>(Y + 2, false));

	bool gameOver = false;
	int xPos = 0, yPos = 0;
	int flags = 0;
	int flagsR = 0;

	const int ts = 32; //texture size

	//set mines
	for (int i = 0; i < minesNr; i++) {
		int x = 1 + rand() % X;
		int y = 1 + rand() % Y;
		if (sgrid[x][y] == 9) i--;
		else sgrid[x][y] = 9;
	}

	//set numbers
	for (int i = 1; i <= X; i++) {
		for (int j = 1; j <= Y; j++) {
			if (sgrid[i][j] != 9) {
				int count = 0;
				//first row
				if (sgrid[i - 1][j - 1] == 9) count++;
				if (sgrid[i - 1][j] == 9) count++;
				if (sgrid[i - 1][j + 1] == 9) count++;
				//second row
				if (sgrid[i][j - 1] == 9) count++;
				if (sgrid[i][j + 1] == 9) count++;
				//third row
				if (sgrid[i + 1][j - 1] == 9) count++;
				if (sgrid[i + 1][j] == 9) count++;
				if (sgrid[i + 1][j + 1] == 9) count++;
				sgrid[i][j] = count;
			}
		}
	}

	//debugging
	for (int i = 0; i < X + 2; i++) {
		for (int j = 0; j < Y + 2; j++) {
			std::cout << sgrid[i][j] << " ";
		}
		std::cout << "\n";
	}

	//set texture
	sf::Texture imgTexture;
	if (!imgTexture.loadFromFile("tiles.jpg")) {
		std::cerr << "Error loading texture!\n";
		return;
	}

	//set sprite
	sf::Sprite img;
	img.setTexture(imgTexture);

	//set font
	sf::Font font;
	if (!font.loadFromFile("CorbertWide-Regular.ttf")) {
		std::cerr << "Error loadind font!\n";
		return;
	}

	//set text

	//game over
	sf::Text textGameOver;
	textGameOver.setFont(font);
	textGameOver.setString("Game Over!");
	textGameOver.setCharacterSize(30);
	textGameOver.setOutlineThickness(10);
	textGameOver.setFillColor(sf::Color::Red);
	textGameOver.setPosition(sf::Vector2f((windowX / 2) - (textGameOver.getLocalBounds().width / 2), 100.0f));

	//win 
	sf::Text textWin;
	textWin.setFont(font);
	textWin.setString("Win!");
	textWin.setCharacterSize(50);
	textWin.setOutlineThickness(7);
	textWin.setFillColor(sf::Color::Green);
	textWin.setPosition(sf::Vector2f((windowX / 2) - (textWin.getLocalBounds().width / 2), 100.0f));

	//score
	sf::Text textScore;
	const int scoreSize = 25;
	textScore.setFont(font);
	textScore.setString(std::to_string(minesNr) + "/" + std::to_string(flagsR));
	textScore.setCharacterSize(20);
	textScore.setFillColor(sf::Color::White);
	textScore.setPosition(sf::Vector2f((windowX / 2) - (textScore.getLocalBounds().width / 2), 0.0));
	//std::cout << textScore.getLocalBounds().width;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonReleased) {
				if (gameOver && event.key.code == sf::Mouse::Left) {
					window.close();
				}

				if (event.key.code == sf::Mouse::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					int x = mousePos.x / ts + 1;
					int y = (mousePos.y - scoreSize) / ts + 1;
					if (mousePos.y > scoreSize) {
						if (sgrid[x][y] == 9 && grid[x][y] != 11) gameOver = true;
						if (grid[x][y] != 11) search(grid, sgrid, visited, x, y);

						if (x == xPos && y == yPos) {
							numberDiscover(grid, sgrid, gameOver, x, y);
						}

						xPos = x;
						yPos = y;
					}
				}

				if (event.key.code == sf::Mouse::Right) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					int x = mousePos.x / ts + 1;
					int y = (mousePos.y - scoreSize) / ts + 1;
					if (mousePos.y > scoreSize) {
						if (grid[x][y] == 11) { grid[x][y] = 10; textScore.setString(std::to_string(minesNr) + "/" + std::to_string(--flagsR)); }
						else if (grid[x][y] == 10) { grid[x][y] = 11; textScore.setString(std::to_string(minesNr) + "/" + std::to_string(++flagsR)); }

						if (grid[x][y] == 11 && sgrid[x][y] == 9) {
							flags++;
							textScore.setString(std::to_string(minesNr) + "/" + std::to_string(flagsR));
							if (flags == minesNr) gameOver = true;
						}
					}
				}
			}
		}
		if (!gameOver) {
			window.clear();
			window.draw(textScore);
			for (int i = 1; i <= X; i++) {
				for (int j = 1; j <= Y; j++) {
					img.setTextureRect(sf::IntRect(ts * grid[i][j], 0, 32, 32));
					img.setPosition(sf::Vector2f(ts * (i - 1), ts * (j - 1) + scoreSize));
					window.draw(img);
				}
			}

			window.display();
		}
		else {
			//lose
			if (minesNr != flags) {
				window.clear();
				findMines(grid, sgrid);
				window.draw(textScore);
				for (int i = 1; i <= X; i++) {
					for (int j = 1; j <= Y; j++) {
						img.setTextureRect(sf::IntRect(ts * grid[i][j], 0, 32, 32));
						img.setPosition(sf::Vector2f(ts * (i - 1), ts * (j - 1) + scoreSize));
						window.draw(img);
					}
				}
				window.draw(textGameOver);
				window.display();
			}
			//win
			else {
				window.clear();
				window.draw(textScore);
				discoverAll(grid, sgrid);
				for (int i = 1; i <= X; i++) {
					for (int j = 1; j <= Y; j++) {
						img.setTextureRect(sf::IntRect(ts * grid[i][j], 0, 32, 32));
						img.setPosition(sf::Vector2f(ts * (i - 1), ts * (j - 1) + scoreSize));
						window.draw(img);
					}
				}
				window.draw(textWin);
				window.display();
			}
		}
	}
}

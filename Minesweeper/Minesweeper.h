#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

void search(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid, std::vector<std::vector<bool>>& visited, int x, int y);

int searchFlags(const std::vector<std::vector<int>>& grid, int x, int y);

void numberDiscover(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid, bool& gameOver, int x, int y);

void findMines(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid);

void discoverAll(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& sgrid);

void Minesweeper(int windowX, int windowY, int X, int Y, int minesNr);
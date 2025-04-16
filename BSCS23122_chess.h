#pragma once
#pragma once
#include "BSCS23122_board.h"
#include "BSCS23122_player.h"


#include <SFML/Graphics.hpp>
using namespace sf;
class chess
{
public:
	int Turn;
	Board* B;
	chess();
	chess(string name);
	void MessageAlongWithBaari(RenderWindow& window);
	void WindowFirstImprs(RenderWindow& window);
	void TurnRandom();
	void WindowMakeItAbove(RenderWindow& window, bool** A);
	bool FirstInterface(sf::RenderWindow& window);
	void CheckInterfaceWords(int Turn, RenderWindow& window);
	void MateUnderCheck(RenderWindow& window, int Turn);
	void print();
	void Play_Game();
	chess(int a);
	bool is_piece_captured(Position source_Pos, Position des_Pos);

};
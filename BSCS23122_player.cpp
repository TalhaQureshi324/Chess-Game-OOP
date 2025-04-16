#include"BSCS23122_player.h"


Player::Player()
{
	name = " Blank ---- name";
	this->Duration = 0;
}

void Player::p1(string na, int cl)
{
	name = na;
	if (cl == 0)
		col = 0;
	else
		col = 1;
}

string Player::getname()
{
	return name;
}

Position Player::SelectPortion()
{
	cout << "Row  Col "; cin >> pos.row_index;
	cin >> pos.col_index;
	pos.row_index--;
	pos.col_index--;
	return pos;
}
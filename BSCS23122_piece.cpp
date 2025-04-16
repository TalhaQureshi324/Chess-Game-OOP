#include"BSCS23122_piece.h"
#include"BSCS23122_board.h"
#include<iostream>

using namespace std;
piece::piece() : PIECE('-'), pos{ -1, -1 }, b(nullptr), IsSmallInSize(false) {}

piece::piece(char a, int ri, int ci, Board* B) : PIECE(a), pos{ ri, ci }, b(B), IsSmallInSize(false) {}

piece::piece(const piece& a) : PIECE(a.PIECE), pos{ a.pos }, b(a.b), IsSmallInSize(a.IsSmallInSize) {}

void piece::make_change()
{
	PIECE = '-';
	pos = { -1, -1 };
}
void piece::print_Piece()
{
	cout << this->PIECE;
}
bool piece::IsValidPieceMovement(int Turn)
{
	if (Turn != this->IsSmallInSize)
	{
		if (Turn == 1 && this->PIECE == '-')
			return 0;
		else
			return 1;
	}
	return 0;
}

bool piece::Isnot_my_piece(int T)
{
	if (T == this->IsSmallInSize)
	{
		return 1;
	}
	return 0;

}
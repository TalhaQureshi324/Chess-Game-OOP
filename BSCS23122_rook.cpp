#include<iostream>
#include"BSCS23122_rook.h"
#include"BSCS23122_board.h"
using namespace std;


rook::rook(int Turn, Board* B)
{
	this->b = B;
	if (Turn == 0) {
		IsSmallInSize = 1;
		this->PIECE = 'r';
	}
	else {
		this->PIECE = 'R';
		IsSmallInSize = 0;
	}
	this->first_mov = true;
}
void rook::drawPiece()
{
	cout << this->PIECE;
}

bool rook::isLegal(Position S, Position D, int T)
{
	return (vertical_motion(S, D) && is_vertical_path_clear(*b, S, D)) || (horizontal_motion(S, D) && is_horizontal_path_clear(*b, S, D));
}


void rook::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.row_index = A.pos.row_index;
	this->pos.col_index = A.pos.col_index;
	this->PIECE = A.PIECE;
	this->IsSmallInSize = A.IsSmallInSize;
}

void rook::move(Position S, Position D)
{
	this->first_mov = false;

	b->pie[D.row_index][D.col_index] = b->pie[S.row_index][S.col_index];
	b->pie[S.row_index][S.col_index] = new em();

}

bool rook::isFirstMov(Position A)
{
	if (b->pie[A.row_index][A.col_index]->PIECE == 'r' || b->pie[A.row_index][A.col_index]->PIECE == 'R')
	{
		return this->first_mov;
	}
}
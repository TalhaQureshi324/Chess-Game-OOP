#include"BSCS23122_king.h"
#include<iostream>
#include"BSCS23122_board.h"
using namespace std;


king::king(int Turn, Board* B)
{
	this->b = B;
	if (Turn == 0) 
	{
		this->PIECE = 'k';
		this->IsSmallInSize = 1;
	}
	else
		this->PIECE = 'K';
	this->first_mov = true;

}

void king::Piece_Formation()
{
	cout << this->PIECE;
}

bool king::isLegal(Position S, Position D, int Turn)
{
	int dRow = D.row_index - S.row_index;
	int dCol = D.col_index - S.col_index;

	if ((dRow >= -1 && dRow <= 1) && (dCol >= -1 && dCol <= 1)) {
		if (!b->pie[D.row_index][D.col_index]->IsValidPieceMovement(Turn)) {
			if (dRow == 0 || dCol == 0) {
				return true;
			}
			else if (abs(dRow) == abs(dCol)) {
				return true;
			}
		}
	}

	if (IsSmallInSize) {
		if (S.row_index == 0 && S.col_index == 4 && (D.row_index == 0 && D.col_index == 2 || D.row_index == 0 && D.col_index == 6)) {
			return true;
		}
	}
	else {
		if (S.row_index == 7 && S.col_index == 4 && (D.row_index == 7 && D.col_index == 2 || D.row_index == 7 && D.col_index == 6)) {
			return true;
		}
	}

	return false;
}

void king::move(Position R, Position C)
{
	this->first_mov = false;
	if (this->IsSmallInSize && (R.row_index == 0 && R.col_index == 4) && b->pie[C.row_index][C.col_index]->PIECE == 'r' && ((C.row_index == 0 && C.col_index == 0) || (C.row_index == 0 && C.col_index == 7)))
	{
		if (C.row_index == 0 && C.col_index == 0)
		{
			b->pie[C.row_index][C.col_index + 3] = b->pie[C.row_index][C.col_index];
			b->pie[R.row_index][R.col_index - 2] = b->pie[R.row_index][R.col_index];
			b->pie[C.row_index][C.col_index] = new em();
			b->pie[R.row_index][R.col_index] = new em();
		}
		else if (C.row_index == 0 && C.col_index == 7)
		{
			b->pie[C.row_index][C.col_index - 2] = b->pie[C.row_index][C.col_index];
			b->pie[R.row_index][R.col_index + 2] = b->pie[R.row_index][R.col_index];
			b->pie[C.row_index][C.col_index] = new em();
			b->pie[R.row_index][R.col_index] = new em();
		}
	}
	else if ((R.row_index == 7 && R.col_index == 4) && b->pie[C.row_index][C.col_index]->PIECE == 'R' && ((C.row_index == 7 && C.col_index == 0) || (C.row_index == 7 && C.col_index == 7)))
	{
		if (C.row_index == 7 && C.col_index == 0)
		{
			b->pie[C.row_index][C.col_index + 3] = b->pie[C.row_index][C.col_index];
			b->pie[R.row_index][R.col_index - 2] = b->pie[R.row_index][R.col_index];
			b->pie[C.row_index][C.col_index] = new em();
			b->pie[R.row_index][R.col_index] = new em();
		}
		else if (C.row_index == 7 && C.col_index == 7)
		{
			b->pie[C.row_index][C.col_index - 2] = b->pie[C.row_index][C.col_index];
			b->pie[R.row_index][R.col_index + 2] = b->pie[R.row_index][R.col_index];
			b->pie[C.row_index][C.col_index] = new em();
			b->pie[R.row_index][R.col_index] = new em();
		}
	}
	else
	{
		b->pie[C.row_index][C.col_index] = b->pie[R.row_index][R.col_index];
		b->pie[R.row_index][R.col_index] = new em();
	}
}


void king::operator=(const piece& other)
{
	this->b = other.b;
	this->pos.row_index = other.pos.row_index;
	this->pos.col_index = other.pos.col_index;
	this->PIECE = other.PIECE;
	this->IsSmallInSize = other.IsSmallInSize;
}
#include<iostream>
#include"BSCS23122_knight.h"
using namespace std;
#include"BSCS23122_board.h"

knight::knight(int Turn, Board* B)
{
	this->b = B;
	this->IsSmallInSize = (Turn == 0);
	this->PIECE = this->IsSmallInSize ? 'n' : 'N';
}

void knight::Piece_Formation()
{
	cout << this->PIECE;
}
bool knight::isLegal(Position R, Position C, int Turn)
{
	int ROW_CHANGE = R.row_index - C.row_index;
	int COL_CHANGE = R.col_index - C.col_index;

	ROW_CHANGE = ROW_CHANGE < 0 ? -ROW_CHANGE : ROW_CHANGE;
	COL_CHANGE = COL_CHANGE < 0 ? -COL_CHANGE : COL_CHANGE;

	if ((ROW_CHANGE == 1 && COL_CHANGE == 2) || (ROW_CHANGE == 2 && COL_CHANGE == 1))
	{
		return true;
	}

	return false;
}

void knight::operator=(const piece& A)
{
	////////////////////////////////////////////////////
}

void knight::move(Position R, Position C)
{
	b->pie[C.row_index][C.col_index] = b->pie[R.row_index][R.col_index];
	b->pie[R.row_index][R.col_index] = new em();
}
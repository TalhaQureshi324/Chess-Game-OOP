#include<iostream>
using namespace std;
#include"BSCS23122_queen.h"
#include"BSCS23122_board.h"




queen::queen(int Turn, Board* B)
{
	this->b = B;
	if (Turn == 0) 
	{
		IsSmallInSize = 1;
		this->PIECE = 'q';
	}
	else 
	{
		this->PIECE = 'Q';
		IsSmallInSize = 0;
	}
}
void queen::drawPiece()
{
	cout << this->PIECE;
}
bool queen::isLegal(Position S, Position D, int T)
{
	if ((vertical_motion(S, D) && is_vertical_path_clear(*b, S, D)) || (horizontal_motion(S, D) && is_horizontal_path_clear(*b, S, D)))
	{
		return true;
	}

	if (Diagonal_Motioon(S, D))
	{
		if (isSameDiagonalDirectionMove(S, D))
		{
			return is_diagonal_path_to_right_clear(*b, S, D);
		}
		return is_diagonal_left_clear(*b, S, D);
	}

	return false;
}


void queen::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.row_index = A.pos.row_index;
	this->pos.col_index = A.pos.col_index;
	this->PIECE = A.PIECE;
	this->IsSmallInSize = A.IsSmallInSize;
}

void queen::move(Position S, Position D)
{
	b->pie[D.row_index][D.col_index] = b->pie[S.row_index][S.col_index];
	b->pie[S.row_index][S.col_index] = new em();
}
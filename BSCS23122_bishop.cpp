#include"BSCS23122_bishop.h"
#include<iostream>
#include"BSCS23122_board.h"


using namespace std;

bishop::bishop(int Turn, Board* B)
{
	this->b = B;

	this->PIECE = (Turn == 0) ? 'b' : 'B';

	this->IsSmallInSize = (Turn == 0) ? 1 : 0;
}

void bishop::Piece_Formation()
{
	cout << this->PIECE;
}

bool bishop::isLegal(Position S, Position D, int T)
{
	if (downright_movement(S, D) || upleft_movement(S, D) || upright_movement(S, D) || downleft_movement(S, D))
		return true;
	if (Diagonal_Motioon(S, D))
		if (isSameDiagonalDirectionMove(S, D))
		{
			if (is_diagonal_path_to_right_clear(*b, S, D))
			{
				return true;
			}

		}
		else if (is_diagonal_left_clear(*b, S, D))
			return true;
	return false;
}


void bishop::operator=(const piece& other)
{
	this->b = other.b;
	this->pos.row_index = other.pos.row_index;
	this->pos.col_index = other.pos.col_index;
	this->PIECE = other.PIECE;
	this->IsSmallInSize = other.IsSmallInSize;
}

void bishop::move(Position R, Position C)
{
	b->pie[C.row_index][C.col_index] = b->pie[R.row_index][R.col_index];
	b->pie[R.row_index][R.col_index] = new em();
}
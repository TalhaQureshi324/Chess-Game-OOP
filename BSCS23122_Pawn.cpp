#include"BSCS23122_Pawn.h"
#include<iostream>
#include"BSCS23122_board.h"

using namespace std;

void Pawn::drawPiece()
{
	cout << this->PIECE;
}
bool Pawn::isLegal(Position R, Position C, int Turn)
{
	int direction = this->IsSmallInSize ? 1 : -1;
	int startRow = this->IsSmallInSize ? 1 : 6;
	int doubleStepRow = startRow + 2 * direction;

	if (R.row_index + direction == C.row_index && R.col_index == C.col_index && b->pie[C.row_index][C.col_index]->PIECE == '-')
		return true;

	if (R.row_index + 2 * direction == C.row_index && R.row_index == startRow && R.col_index == C.col_index && b->pie[C.row_index][C.col_index]->PIECE == '-')
		return true;

	if (R.row_index + direction == C.row_index && (R.col_index + 1 == C.col_index || R.col_index - 1 == C.col_index) && b->pie[C.row_index][C.col_index]->PIECE != '-')
		return true;

	return false;
}

void Pawn::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.row_index = A.pos.row_index;
	this->pos.col_index = A.pos.col_index;
	this->PIECE = A.PIECE;
	this->IsSmallInSize = A.IsSmallInSize;
}
void Pawn::move(Position S, Position D)
{
	this->make_first_move = false;
	b->pie[D.row_index][D.col_index] = b->pie[S.row_index][S.col_index];
	b->pie[S.row_index][S.col_index] = new em();

}
Pawn::Pawn(int Turn, Board* B)
{
	this->b = B;
	if (Turn == 0)
	{
		IsSmallInSize = 1;
		this->PIECE = 'p';
	}
	else
	{
		this->PIECE = 'P';
		IsSmallInSize = 0;
	}
	this->make_first_move = 1;
}
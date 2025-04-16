#include"BSCS23122_saaf.h"
#include"BSCS23122_board.h"
#include<iostream>
using namespace std;

em::em()
{
	this->PIECE = '-';
}
void em::drawPiece()
{
	cout << this->PIECE;
}
bool em::isLegal(Position S, Position D, int T)
{
	return 1;
}
void em::print_Piece()
{
	cout << PIECE;
}
void em::operator=(const piece& A)
{
	this->b = A.b;
	this->pos.row_index = A.pos.row_index;
	this->pos.col_index = A.pos.col_index;
	this->PIECE = A.PIECE;
	this->IsSmallInSize = A.IsSmallInSize;
}
void em::move(Position S, Position D)
{
	// No movement logic for empty squares
   // This function remains empty
}
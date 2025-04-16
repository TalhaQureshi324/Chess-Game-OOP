#pragma once
#pragma once
#include"BSCS23122_allOtherFunctions.h"

class piece
{
public:
	char PIECE;
	Position pos;
	bool IsSmallInSize;
	Board* b;
	piece();
	piece(char a, int ri, int ci, Board* B);
	piece(const piece& a);
	virtual void operator = (const piece& A) = 0;
	void make_change();
	virtual bool isLegal(Position S, Position D, int T) = 0;
	virtual void print_Piece();
	bool IsValidPieceMovement(int Turn);
	virtual void move(Position S, Position D) = 0;
	bool Isnot_my_piece(int T);
};
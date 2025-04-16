#pragma once
#include"BSCS23122_piece.h"


class Board;
class Pawn :public piece
{
public:
	bool make_first_move;
	Pawn(int Turn, Board* B);
	virtual void drawPiece();
	virtual bool isLegal(Position R, Position C, int Turn);
	virtual void operator = (const piece& A);
	virtual void move(Position R, Position C);

};
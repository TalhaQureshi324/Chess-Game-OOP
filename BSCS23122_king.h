#pragma once

#include"BSCS23122_piece.h"
class Board;

class king :public piece
{
	bool first_mov;
public:
	king(int Turn, Board* B);
	virtual void Piece_Formation();
	virtual bool isLegal(Position R, Position C, int Turn);
	virtual void move(Position R, Position C);
	virtual void operator = (const piece& other);
};
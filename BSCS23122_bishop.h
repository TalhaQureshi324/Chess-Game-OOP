#pragma once
#include"BSCS23122_piece.h"
class Board;

class bishop :public piece
{
public:
	bishop(int Turn, Board* B);
	virtual void Piece_Formation();
	virtual bool isLegal(Position R, Position C, int Turn);
	virtual void operator = (const piece& other);
	virtual void move(Position R, Position C);

};
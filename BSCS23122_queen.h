#pragma once
#include"BSCS23122_piece.h"
class Board;

class queen :public piece
{
	//char p;
public:
	queen(int Turn, Board* B);
	virtual void drawPiece();
	virtual bool isLegal(Position S, Position D, int T);
	virtual void operator = (const piece& A);
	virtual void move(Position S, Position D);


};
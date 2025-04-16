#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<string.h>
#include "BSCS23122_piece.h"
#include "BSCS23122_pawn.h"
#include "BSCS23122_king.h"
#include "BSCS23122_bishop.h"
#include "BSCS23122_queen.h"
#include "BSCS23122_rook.h"
#include "BSCS23122_knight.h"
#include "BSCS23122_saaf.h"
#include "BSCS23122_player.h"


static char** Load(string name)
{
	ifstream Rdr(name);
	char** A; A = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		A[i] = new char[8];
		for (int c = 0; c < 8; c++)
		{
			Rdr >> A[i][c];
		}
	}
	return A;
}

class Board
{
public:
	int rows;
	int cols;
	piece*** pie;
	int dim = 8;
	Player player[2];
	Position Source_Pos;
	Position des_Pos;	

	Board();
	Board(string name);
	Board(const Board& A);
	void initialize();
	void MoveThemToNewOne(Board& B);
	Position FindKing(int Turn);
	void printBoard();
	void game_over_draw();
	void MateUnderCheckMessage(int Turn);
	void display_highlighted_board(bool** highlighted_squares);
	void SeletSourcePosition(Position source_Pos);
	void SeletDesPosition(Position source_Pos);
	bool IsLegal(Position s);
	void move(Position source_Pos, Position des_Pos);
	bool iSMY_PIECE(int Turn1, Position S);
	void LoadToFile(string A);
	bool isCheck(int Turn);
	void CheckMsg(int Turn);
	bool Selfcheck(int Turn);
	bool Stalement(int Turn);
	bool checkMate(int Turn);
	friend ostream& operator <<(ostream& co, const Board& a);
	bool Castling(Position S, Position D, int Turn);
	bool** findHight(int Turn);
	void undo(Board  A);
	void Update_only(Position S, Position D);
	void mouse_position(Position& P, int len);
	void draw_chessboard_with_pieces();
	void Hilight_Position(bool** Hilght);
	void UHilight_Position(bool** Hilight);

	~Board();
};

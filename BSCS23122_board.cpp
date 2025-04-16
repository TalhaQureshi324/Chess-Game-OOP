#include"BSCS23122_board.h"
#include<conio.h>
#include"BSCS23122_allOtherFunctions.h"
#include<iostream>
using namespace std;

Board::Board()
{
    rows = 0;
    cols = 0;
    pie = nullptr;
    dim = 0;
    player[0] = Player();
    player[1] = Player();
    Source_Pos.col_index = 0;
    Source_Pos.row_index = 0;
    des_Pos.row_index = 0;
    des_Pos.col_index = 0;

    pie = new piece * *[8];
    for (int i = 0; i < 8; ++i)
    {
        pie[i] = nullptr;
    }
}

Board::Board(string name)
{
    player[0].p1("qureshi", 0);
    player[1].p1("opponent", 15);
    rows = 160;
    cols = 250;
    dim = 8;
    char** A = Load(name);
    pie = new piece * *[dim];

    for (int i = 0; i < dim; ++i)
    {
        pie[i] = new piece * [dim];
        for (int c = 0; c < dim; ++c)
        {
            if (A[i][c] == 'p' || A[i][c] == 'P' || A[i][c] == 'k' || A[i][c] == 'K' || 
                A[i][c] == 'b' || A[i][c] == 'B' || A[i][c] == 'q' || A[i][c] == 'Q' ||
                A[i][c] == 'r' || A[i][c] == 'R' || A[i][c] == 'n' || A[i][c] == 'N')
            {
                if (A[i][c] == 'p') pie[i][c] = new Pawn(0, this);
                else if (A[i][c] == 'P') pie[i][c] = new Pawn(15, this);
                else if (A[i][c] == 'k') pie[i][c] = new king(0, this);
                else if (A[i][c] == 'K') pie[i][c] = new king(15, this);
                else if (A[i][c] == 'b') pie[i][c] = new bishop(0, this);
                else if (A[i][c] == 'B') pie[i][c] = new bishop(15, this);
                else if (A[i][c] == 'q') pie[i][c] = new queen(0, this);
                else if (A[i][c] == 'Q') pie[i][c] = new queen(15, this);
                else if (A[i][c] == 'r') pie[i][c] = new rook(0, this);
                else if (A[i][c] == 'R') pie[i][c] = new rook(15, this);
                else if (A[i][c] == 'n') pie[i][c] = new knight(0, this);
                else if (A[i][c] == 'N') pie[i][c] = new knight(15, this);
            }
            else
            {
                pie[i][c] = new em();
            }
        }
    }

    for (int i = 0; i < dim; ++i)
    {
        delete[] A[i];
    }
    delete[] A;
}

Board::Board(const Board& A)
{
    dim = 8;
    pie = new piece * *[8];

    for (int i = 0; i < dim; ++i)
    {
        pie[i] = new piece * [dim];
        for (int c = 0; c < dim; ++c)
        {
            if (A.pie[i][c]->PIECE == 'p' || A.pie[i][c]->PIECE == 'P' || A.pie[i][c]->PIECE == 'k' || A.pie[i][c]->PIECE == 'K' || 
                A.pie[i][c]->PIECE == 'b' || A.pie[i][c]->PIECE == 'B' || A.pie[i][c]->PIECE == 'q' || A.pie[i][c]->PIECE == 'Q' ||
                A.pie[i][c]->PIECE == 'r' || A.pie[i][c]->PIECE == 'R' || A.pie[i][c]->PIECE == 'n' || A.pie[i][c]->PIECE == 'N')
            {
                switch (A.pie[i][c]->PIECE)
                {
                case 'p': pie[i][c] = new Pawn(0, this); break;
                case 'P': pie[i][c] = new Pawn(15, this); break;
                case 'k': pie[i][c] = new king(0, this); break;
                case 'K': pie[i][c] = new king(15, this); break;
                case 'b': pie[i][c] = new bishop(0, this); break;
                case 'B': pie[i][c] = new bishop(15, this); break;
                case 'q': pie[i][c] = new queen(0, this); break;
                case 'Q': pie[i][c] = new queen(15, this); break;
                case 'r': pie[i][c] = new rook(0, this); break;
                case 'R': pie[i][c] = new rook(15, this); break;
                case 'n': pie[i][c] = new knight(0, this); break;
                case 'N': pie[i][c] = new knight(15, this); break;
                default: pie[i][c] = new em();
                }
            }
            else
            {
                pie[i][c] = new em();
            }
        }
    }

    player[0].p1("Talha Mr. Pro", 0);
    player[1].p1("opponent", 15);
}

void Board::initialize()
{
	rows = 160;
	cols = 250;
	dim = 8;
	pie = new piece * *[dim];
	for (int i = 0; i < dim; i++)
	{
		pie[i] = new piece * [dim];
		for (int c = 0; c < dim; c++)
		{
			pie[i][c] = new Pawn(0, this);
		}
	}
}
void Board::draw_chessboard_with_pieces()
{
	int Dim = 8;
	int colour, col1 = 0, col2 = 4;

	for (int r = 0; r < Dim; ++r)
	{
		for (int c = 0; c < Dim; ++c)
		{
			char sym = this->pie[r][c]->PIECE;
			colour = ((r + c) % 2 == 0) ? 15 : 7;

			switch (sym)
			{
			case 'p':
				draw_pawn(r * 9, c * 9, 9, col1, colour, -37);
				break;
			case 'P':
				draw_pawn(r * 9, c * 9, 9, col2, colour, -37);
				break;
			case 'r':
				draw_rook(r * 9, c * 9, 9, col1, colour, -37);
				break;
			case 'R':
				draw_rook(r * 9, c * 9, 9, col2, colour, -37);
				break;
			case 'b':
				draw_bishop(r * 9, c * 9, 9, col1, colour, -37);
				break;
			case 'B':
				draw_bishop(r * 9, c * 9, 9, col2, colour, -37);
				break;
			case 'k':
				draw_king(r * 9, c * 9, 9, col1, colour, -37);
				break;
			case 'K':
				draw_king(r * 9, c * 9, 9, col2, colour, -37);
				break;
			case 'n':
				draw_knight(r * 9, c * 9, 9, col1, colour, -37);
				break;
			case 'N':
				draw_knight(r * 9, c * 9, 9, col2, colour, -37);
				break;
			case 'q':
				draw_queen(r * 9, c * 9, 9, col1, colour, -37);
				break;
			case 'Q':
				draw_queen(r * 9, c * 9, 9, col2, colour, -37);
				break;
			default:
				draw_rectangle_box(r * 9, c * 9, 9, 9, colour, -37);
				break;
			}
		}
		cout << endl;
	}

	draw_centered_box(5 * 9, 12 * 9, 9, 9, 2, 'U');
	draw_centered_box(5 * 9, 14 * 9, 9, 9, 14, 'R');
}

void Board::Hilight_Position(bool** Hilght)
{

	int Dim = 8;
	for (int r = 0; Dim > r; r++)
	{
		for (int c = 0; Dim > c; c++)
		{
			if (Hilght[r][c] == 1)
				draw_frame(r * 9, c * 9, 9, 9, 9);
		}
	}
}
void Board::UHilight_Position(bool** Hilight)
{

	int Dim = 8;
	for (int r = 0; Dim > r; r++)
	{
		for (int c = 0; Dim > c; c++)
		{
			if (Hilight[r][c] == 1)
			{
				if ((r + c) % 2 == 0)
					draw_frame(r * 9, c * 9, 9, 9, 15);
				else
					draw_frame(r * 9, c * 9, 9, 9, 7);
			}
		}
	}

}
void Board::MoveThemToNewOne(Board& B)
{
	B.pie = new piece * *[8];
	for (int i = 0; i < 8; i++)
		B.pie[i] = new piece * [8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			B.pie[i][j] = this->pie[i][j];
		
		}
	}
}
Position Board::FindKing(int Turn)
{
	Position A;
	char kingChar = (Turn == 0) ? 'k' : 'K';
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (this->pie[i][j]->PIECE == kingChar)
			{
				A.row_index = i;
				A.col_index = j;
				return A; 
			}
		}
	}
	return A;
}
void Board::printBoard()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			pie[i][j]->print_Piece();
		}
		cout << endl;
	}
}
void Board::game_over_draw()
{
	cout << "Draw"; 
	_getche();
	exit(1);
}
void Board::MateUnderCheckMessage(int Turn)
{
	cout << this->player[(Turn + 1) % 2].getname() << " CHECKMATEFD   BRO   :-)";
}
void Board::display_highlighted_board(bool** highlighted_squares)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			SetClr(highlighted_squares[i][j] ? 1 : 15);
			pie[i][j]->print_Piece();
		}
		cout << endl;
	}
	SetClr(15);
}
void Board::SeletSourcePosition(Position source_Pos)
{
	cin >> source_Pos.row_index >> source_Pos.col_index;
}
void Board::SeletDesPosition(Position source_Pos)
{
	cin >> source_Pos.row_index >> source_Pos.col_index;

}
bool Board::IsLegal(Position s)
{
	if (s.row_index < 8 && s.row_index >= 0 && s.col_index < 8 && s.col_index >= 0)
		return 1;
	return 0;
}
void Board::move(Position Source_Pos, Position des_Pos)
{
	this->pie[Source_Pos.row_index][Source_Pos.col_index]->move(Source_Pos, des_Pos);
	if (pie[des_Pos.row_index][des_Pos.col_index]->PIECE == 'p' || pie[des_Pos.row_index][des_Pos.col_index]->PIECE == 'P')
	{
		if (pie[des_Pos.row_index][des_Pos.col_index]->IsSmallInSize && des_Pos.row_index == 6)
		{
			pie[des_Pos.row_index][des_Pos.col_index] = new queen(0, this);
		}
		else if (!pie[des_Pos.row_index][des_Pos.col_index]->IsSmallInSize && des_Pos.row_index == 1)
		{
			pie[des_Pos.row_index][des_Pos.col_index] = new queen(15, this);

		}
	}
}
bool Board::iSMY_PIECE(int Turn1, Position S)
{
	return this->pie[S.row_index][S.col_index]->IsValidPieceMovement(Turn1);
}
void Board::LoadToFile(string A)
{
	ofstream wrt(A);
	wrt << *this;
}
bool Board::isCheck(int Turn)
{
	int T = (Turn + 1) % 2;
	Position kingPos = FindKing(T);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			Position sourcePos = { i, j };
			if (iSMY_PIECE(Turn, sourcePos) && pie[sourcePos.row_index][sourcePos.col_index]->isLegal(sourcePos, kingPos, Turn))
			{
				return true;
			}
		}
	}
	return false;
}
void Board::CheckMsg(int Turn)
{
	cout << this->player[(Turn + 1) % 2].getname() << " ---------- is in CHECK";
}
bool Board::Selfcheck(int Turn)
{
	int T = (Turn + 1) % 2;
	return isCheck(T);

}
bool Board::Stalement(int Turn)
{
	int T = (Turn + 1) % 2;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->Source_Pos.row_index = i;
			this->Source_Pos.col_index = j;
			if (this->iSMY_PIECE(T, this->Source_Pos)) {
				bool** U = this->findHight(T);

				for (int a = 0; a < 8; a++)
				{
					for (int b = 0; b < 8; b++)
					{
						if (U[a][b])
							return false;
					}
				}
			}
		}
	}
	return true;
}
bool Board::checkMate(int Turn)
{
	if (this->isCheck(Turn))
	{
		if (Stalement(Turn))
		{
			return 1;
		}
	}
	return 0;
}
bool Board::Castling(Position S, Position D, int Turn)
{
	if (S.row_index == D.row_index && S.col_index == D.col_index)
		return 0;
	if (this->pie[S.row_index][S.col_index]->IsSmallInSize == this->pie[D.row_index][D.col_index]->IsSmallInSize)
	{

		if (this->pie[S.row_index][S.col_index]->IsSmallInSize && (S.row_index == 0 && S.col_index == 4) && pie[D.row_index][D.col_index]->PIECE == 'r' && ((D.row_index == 0 && D.col_index == 0) || (D.row_index == 0 && D.col_index == 7)))
		{
			return (horizontal_motion(S, D) && is_horizontal_path_clear(*this, S, D));
		}
		else if ((S.row_index == 7 && S.col_index == 4) && pie[D.row_index][D.col_index]->PIECE == 'R' && ((D.row_index == 7 && D.col_index == 0) || (D.row_index == 7 && D.col_index == 7)))
		{
			return (horizontal_motion(S, D) && is_horizontal_path_clear(*this, S, D));
		}
	}
	return false;

}
ostream& operator<<(ostream& co, const Board& A)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) 
		{
			co << A.pie[i][j]->PIECE << " ";
		}
		co << endl;

	}
	return co;
}
bool** Board::findHight(int Turn)
{
	Board N;
	bool** U; U = new bool* [8];
	for (int i = 0; i < 8; i++)
	{
		U[i] = new bool[8];

		for (int j = 0; j < 8; j++)
		{
			des_Pos.row_index = i;
			des_Pos.col_index = j;
			if ((!this->iSMY_PIECE(Turn, des_Pos) || Castling(this->Source_Pos, this->des_Pos, Turn)) && this->IsLegal(des_Pos) && this->pie[Source_Pos.row_index][Source_Pos.col_index]->isLegal(Source_Pos, des_Pos, Turn))
			{
				if (this->pie[Source_Pos.row_index][Source_Pos.col_index]->IsSmallInSize != this->pie[i][j]->IsSmallInSize || this->pie[i][j]->PIECE == '-' || Castling(this->Source_Pos, this->des_Pos, Turn))
				{
					Board N(*this);
					N.move(Source_Pos, des_Pos);
					if (N.Selfcheck(Turn))
						U[i][j] = false;
					else
						U[i][j] = true;
				}
			}
			else
				U[i][j] = false;
		}
	}
	return U;
}
void Board::undo(Board A)
{
	A.MoveThemToNewOne(*this);
}
void Board::Update_only(Position S, Position D)
{
	int SymR = (S.row_index + D.row_index) / 2;
	int SymC = (S.col_index + D.col_index) / 2;

	char sym = this->pie[SymR][SymC]->PIECE;
	int colour = ((SymR + SymC) % 2 == 0) ? 15 : 7;
	int col1 = 0, col2 = 4;

	if (sym == 'p')
		draw_pawn(S.row_index * 9, S.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'P')
		draw_pawn(S.row_index * 9, S.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'r')
		draw_rook(S.row_index * 9, S.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'R')
		draw_rook(S.row_index * 9, S.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'b')
		draw_bishop(S.row_index * 9, S.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'B')
		draw_bishop(S.row_index * 9, S.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'k')
		draw_king(S.row_index * 9, S.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'K')
		draw_king(S.row_index * 9, S.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'n')
		draw_knight(S.row_index * 9, S.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'N')
		draw_knight(S.row_index * 9, S.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'q')
		draw_queen(S.row_index * 9, S.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'Q')
		draw_queen(S.row_index * 9, S.col_index * 9, 9, col2, colour, -37);
	else
		draw_rectangle_box(S.row_index * 9, S.col_index * 9, 9, 9, colour, -37);

	sym = this->pie[D.row_index][D.col_index]->PIECE;
	colour = ((D.row_index + D.col_index) % 2 == 0) ? 15 : 7;

	if (sym == 'p')
		draw_pawn(D.row_index * 9, D.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'P')
		draw_pawn(D.row_index * 9, D.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'r')
		draw_rook(D.row_index * 9, D.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'R')
		draw_rook(D.row_index * 9, D.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'b')
		draw_bishop(D.row_index * 9, D.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'B')
		draw_bishop(D.row_index * 9, D.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'k')
		draw_king(D.row_index * 9, D.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'K')
		draw_king(D.row_index * 9, D.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'n')
		draw_knight(D.row_index * 9, D.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'N')
		draw_knight(D.row_index * 9, D.col_index * 9, 9, col2, colour, -37);
	else if (sym == 'q')
		draw_queen(D.row_index * 9, D.col_index * 9, 9, col1, colour, -37);
	else if (sym == 'Q')
		draw_queen(D.row_index * 9, D.col_index * 9, 9, col2, colour, -37);
	else
		draw_rectangle_box(D.row_index * 9, D.col_index * 9, 9, 9, colour, -37);
}

void Board::mouse_position(Position& P, int len)
{

	getRowColbyLeftClick(P.row_index, P.col_index);
	P.row_index = P.row_index / len; P.col_index = P.col_index / len;
}
Board::~Board()
{
//////////////////////////////////////
}

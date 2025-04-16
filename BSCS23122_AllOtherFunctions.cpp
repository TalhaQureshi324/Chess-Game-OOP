#include"BSCS23122_allOtherFunctions.h"
#include"BSCS23122_board.h"
#include<cstdlib>
#include<iostream>
#include<windows.h>

using namespace sf;


Position Mouse_Click(RenderWindow& window)
{
	Position raw{ -1,-1 };
	Event event;
	while (window.waitEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			exit(0);
			break;
		case Event::MouseButtonReleased:
			if (event.mouseButton.button == Mouse::Left)
			{
				raw.row_index = event.mouseButton.y;
				raw.col_index = event.mouseButton.x;
				return raw;
			}
			break;
		default:
			break;
		}
	}
	return raw;
}

Position get_grid_position_from_mouse_click(RenderWindow& window)
{
	Position M;
	while (true)
	{
		M = Mouse_Click(window);
		M.row_index -= 27;
		M.col_index -= 380;
		M.row_index /= 70;
		M.col_index /= 70;
		cout << " R C" << M.row_index << " " << M.col_index << endl;
		return M;
	}
}


void get_grid_index_from_mouse_click(Position& P, int cell_size)
{
	getRowColbyLeftClick(P.row_index, P.col_index);
	P.row_index = P.row_index / cell_size; P.col_index = P.col_index / cell_size;
}

void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}

void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}

void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

bool upward_motion(Position R, Position C) 
{
	return C.row_index - 1 == R.row_index && C.col_index == R.col_index;
}

bool down_motion(Position R, Position C) 
{
	return C.row_index + 1 == R.row_index && C.col_index == R.col_index;
}

bool left_motion(Position R, Position C) 
{
	return C.row_index == R.row_index && C.col_index - 1 == R.col_index;
}

bool right_motion(Position R, Position C) 
{
	return C.row_index == R.row_index && C.col_index + 1 == R.col_index;
}
bool upleft_movement(Position R, Position C)
{
	return C.row_index == R.row_index - 1 && C.col_index == R.col_index - 1;
}

bool upright_movement(Position R, Position C)
{
	return C.row_index == R.row_index - 1 && C.col_index == R.col_index + 1;
}

bool downright_movement(Position R, Position C)
{
	return C.row_index == R.row_index + 1 && C.col_index == R.col_index + 1;
}

bool downleft_movement(Position R, Position C)
{
	return C.row_index == R.row_index + 1 && C.col_index == R.col_index - 1;
}
bool horizontal_motion(Position So, Position D)
{
	return So.row_index == D.row_index;
}

bool vertical_motion(Position So, Position D)
{
	return So.col_index == D.col_index;
}

bool Diagonal_Motioon(Position So, Position D)
{
	return abs(So.row_index - D.row_index) == abs(So.col_index - D.col_index);
}

bool isSameDiagonalDirectionMove(Position S, Position D)
{
	return (S.row_index > D.row_index && S.col_index > D.col_index) || (S.row_index < D.row_index && S.col_index < D.col_index);
}
bool AreCoordinatesUnequal(Position S, Position D)
{
	return S.row_index != D.row_index || S.col_index != D.col_index;
}

bool IsValidKnightMove(Position S, Position D)
{
	return (abs(S.row_index - D.row_index) == 1 && abs(S.col_index - D.col_index) == 2) || (abs(S.row_index - D.row_index) == 2 && abs(S.col_index - D.col_index) == 1);
}

bool is_vertical_path_clear(Board B, Position So, Position D)
{
	int st = min(So.row_index, D.row_index) + 1;
	int en = max(So.row_index, D.row_index);
	for (int i = st; i < en; i++)
	{
		if (B.pie[i][D.col_index]->PIECE != '-')
			return false;
	}
	return true;
}

bool is_horizontal_path_clear(Board B, Position So, Position D)
{
	int st = min(So.col_index, D.col_index) + 1;
	int en = max(So.col_index, D.col_index);
	for (int i = st; i < en; i++) {
		if (B.pie[D.row_index][i]->PIECE != '-')
			return false;
	}
	return true;
}

bool is_diagonal_path_to_right_clear(Board B, Position S, Position D)
{
	int dr = abs(D.row_index - S.row_index) - 1;
	for (int i = 1; i <= dr; i++) {
		if (B.pie[S.row_index + i][S.col_index + i]->PIECE != '-')
			return false;
	}
	return true;
}

bool is_diagonal_left_clear(Board B, Position S, Position D)
{
	int dr = abs(D.row_index - S.row_index) - 1;
	for (int i = 1; i <= dr; i++) {
		if (B.pie[S.row_index + i][S.col_index - i]->PIECE != '-')
			return false;
	}
	return true;
}

void draw_rectangle_box(int x1, int y1, int x2, int y2, int color, char symbol)
{
	for (int r = 0; r < x2; r++)
	{
		for (int c = 0; c < x2; c++)
		{
			gotoRowCol(x1 + r, y1 + c);
			SetClr(color);
			cout << symbol;
		}
	}
}

void draw_frame(int x1, int y1, int x2, int y2, int color)
{
	char ch = -37;
	for (int r = 0; r < x2; r++)
	{
		for (int c = 0; c < y2; c++)
		{
			gotoRowCol(x1 + r, y1 + c);
			if (r == 0 || r == x2 - 1 || c == 0 || c == y2 - 1)
			{
				SetClr(color);
				cout << ch;
			}
		}
	}
}

void draw_centered_box(int x1, int y1, int h, int w, int color, char symbol)
{
	char ch = -37;
	int centerRow = h / 2;
	int centerCol = w / 2;

	int r = 0;
	while (r < h)
	{
		int c = 0;
		while (c < w)
		{
			gotoRowCol(x1 + r, y1 + c);
			if (r == centerRow && c == centerCol)
			{
				SetClr(11);  
				cout << symbol;
			}
			else
			{
				SetClr(color); 
				cout << ch;
			}
			c++;
		}
		r++;
	}
}

void draw_pawn(int start_row, int start_col, int size, int color1, int color2, char symbol)
{
	int r = 0;
	while (r < size)
	{
		int c = 0;
		while (c < size)
		{
			gotoRowCol(start_row + r, start_col + c);

			if (((r == 2) && (c == 4)) || ((r == 3) && (c == 3)) || ((r == 3) && (c == 4)) ||
				((r == 3) && (c == 5)) || ((r == 5) && (c == 3)) || ((r == 5) && (c == 4)) ||
				((r == 5) && (c == 5) || (r == 4 && c == 4)))
			{
				SetClr(color1);
			}
			else
			{
				SetClr(color2);
			}

			cout << symbol;
			c++;
		}
		r++;
	}
}




void draw_queen(int start_row, int start_col, int size, int color1, int color2, char symbol)
{
	int r = 0;
	while (r < size)
	{
		int c = 0;
		while (c < size)
		{
			gotoRowCol(start_row + r, start_col + c);

			if (((r == 2 && c == 4) || (r == 2 && c == 2) || (r == 3 && c == 4) || (r == 3 && c == 2)) ||
				((c == 3) && (r <= 5 && r > 1)) || (r == 5 && c == 2) || (r == 5 && c == 4) || (r == 6 && (c >= 1 && c < 6)))
			{
				SetClr(color1);
			}
			else if (c == 4 && r == 1)
			{
				SetClr(color1);
			}
			else
			{
				SetClr(color2);
			}

			cout << symbol;
			c++;
		}
		r++;
	}
}


void draw_king(int start_row, int start_col, int size, int color1, int color2, char symbol)
{
	int r = 0;
	while (r < size)
	{
		int c = 0;
		while (c < size)
		{
			gotoRowCol(start_row + r, start_col + c);

			if ((r == 6 && (c == 2 || c == 6)) || ((r >= 4 && r <= 6) && (c >= 3 && c < 6)) ||
				((r == 3 || r == 7) && (c >= 1 && c < 8)) || (r == 7 && (c >= 2 && c <= 7)) ||
				((r == 1 || r == 2) && (c == 1 || c == 2 || c == 4 || c == 6 || c == 7)))
			{
				SetClr(color1);
			}
			else
			{
				SetClr(color2);
			}

			cout << symbol;
			c++;
		}
		r++;
	}
}

void draw_knight(int start_row, int start_col, int size, int color1, int color2, char symbol)
{
	int r = 0;
	while (r < size)
	{
		int c = 0;
		while (c < size)
		{
			gotoRowCol(start_row + r, start_col + c);

			if (((r == 3 && c == 2)) || ((r == 3 && c == 5)) || ((r == 3 && c == 1)) || ((c == 3) && (r <= 5 && r >= 1)) ||
				(r == 5 && (c == 2 || c == 4)) || ((r == 2 || r == 5) && (c == 2 || c == 4)))
			{
				SetClr(color1);
			}
			else
			{
				SetClr(color2);
			}

			cout << symbol;
			c++;
		}
		r++;
	}
}

void draw_bishop(int start_row, int start_col, int size, int color1, int color2, char symbol)
{
	int r = 0;
	while (r < size)
	{
		int c = 0;
		while (c < size)
		{
			gotoRowCol(start_row + r, start_col + c);

			bool condition = (r == 5 && (c == 3 || c == 6)) ||
				(r == 4 && (c == 3 || c == 5)) ||
				(r == 1 && c == 4) ||
				((r == 2 || r == 3) && (c == 3 || c == 4 || c == 5));

			if (condition)
			{
				SetClr(color1);
			}
			else
			{
				SetClr(color2);
			}

			cout << symbol;
			c++;
		}
		r++;
	}
}






void draw_rook(int start_row, int start_col, int size, int color1, int color2, char symbol)
{
	int r = 0;
	while (r < size)
	{
		int c = 0;
		while (c < size)
		{
			gotoRowCol(start_row + r, start_col + c);

			if ((r < 8 && r > 3) && (c < 6 && c >= 3))
			{
				SetClr(color1);
			}
			else if ((r == 3 || r == 4 || r == 7) && (c == 2 || c == 6 || c == 4))
			{
				SetClr(color1);
			}
			else
			{
				SetClr(color2);
			}

			cout << symbol;
			c++;
		}
		r++;
	}
}







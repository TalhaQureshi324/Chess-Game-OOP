#pragma once

class Board;
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

struct Position
{
	int row_index;
	int col_index;

};

Position Mouse_Click(RenderWindow& window);
Position get_grid_position_from_mouse_click(RenderWindow& window);
void get_grid_index_from_mouse_click(Position& P, int cell_size);

void SetClr(int clr);
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);

bool upward_motion(Position R, Position C);
bool down_motion(Position R, Position C);
bool left_motion(Position R, Position C);
bool right_motion(Position R, Position C);
bool upleft_movement(Position R, Position C);
bool upright_movement(Position R, Position C);
bool downright_movement(Position R, Position C);
bool downleft_movement(Position R, Position C);
bool horizontal_motion(Position So, Position D);
bool vertical_motion(Position So, Position D);
bool Diagonal_Motioon(Position So, Position D);

bool isSameDiagonalDirectionMove(Position S, Position D);
bool AreCoordinatesUnequal(Position S, Position D);
bool IsValidKnightMove(Position S, Position D);
bool is_vertical_path_clear(Board B, Position So, Position D);
bool is_horizontal_path_clear(Board B, Position So, Position D);
bool is_diagonal_path_to_right_clear(Board B, Position S, Position D);
bool is_diagonal_left_clear(Board B, Position S, Position D);

void draw_rectangle_box(int x1, int y1, int x2, int y2, int color, char symbol);
void draw_frame(int x1, int y1, int x2, int y2, int color);
void draw_centered_box(int x1, int y1, int h, int w, int color, char symbol);

void draw_pawn(int start_row, int start_col, int size, int color1, int color2, char symbol);
void draw_queen(int start_row, int start_col, int size, int color1, int color2, char symbol);
void draw_king(int start_row, int start_col, int size, int color1, int color2, char symbol);
void draw_knight(int start_row, int start_col, int size, int color1, int color2, char symbol);
void draw_bishop(int start_row, int start_col, int size, int color1, int color2, char symbol);
void draw_rook(int start_row, int start_col, int size, int color1, int color2, char symbol);

#pragma once
#include"BSCS23122_chess.h"
#include"BSCS23122_allOtherFunctions.h"
#include<conio.h>
#include<string>

using namespace sf;

chess::chess()
{
	Turn = rand() % 2;
}
chess::chess(string name)
{
	Turn = rand() % 2;
	this->B = new Board(name);
}
void chess::print()
{
	this->B->printBoard();
}

void  chess::MessageAlongWithBaari(RenderWindow& window)
{
	int Total_rows = 770, Total_cols = 1360;

	String A = this->B->player[Turn].getname(); A += " Duration = ";
	int a = this->B->player[Turn].Duration; A += " ";
	String T = to_string(a);
	A += T;

	Font font;
    font.loadFromFile("Lato.ttf");
	Text text;
	text.setFont(font); 
	text.setCharacterSize(12);
	text.setFillColor(Color::Blue);
	text.setString(A);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(1100.f, 420.f);
	window.draw(text);

}

void chess::WindowFirstImprs(RenderWindow& window)
{
	window.clear(Color::Red);

	const int Dim = 8;
	const int TotalRows = 770, TotalCols = 1360;
	const float mulRow = 70.3, mulCol = 70.9;
	const int offsetX = 396, offsetY = 37;

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("boardBackground.jpg");
	Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setScale(TotalCols / static_cast<float>(backgroundTexture.getSize().x), TotalRows / static_cast<float>(backgroundTexture.getSize().y));
	window.draw(backgroundSprite);

	String playerInfo = this->B->player[Turn].getname() + " Duration = " + to_string(this->B->player[Turn].Duration);
	Font font;
	font.loadFromFile("Lato.ttf");
	Text text(playerInfo, font, 12);
	text.setFillColor(Color::Blue);
	text.setStyle(Text::Underlined);
	text.setPosition(1100.f, 400.f);
	window.draw(text);

	Texture undoTexture, redoTexture;
	undoTexture.loadFromFile("undo.png");
	redoTexture.loadFromFile("redo.png");

	Sprite undoSprite(undoTexture);
	undoSprite.setScale(0.5, 0.5);
	undoSprite.setPosition(30, TotalRows - 200);
	window.draw(undoSprite);

	Sprite redoSprite(redoTexture);
	redoSprite.setScale(0.5, 0.5);
	redoSprite.setPosition(TotalCols - 155, TotalRows - 200);
	window.draw(redoSprite);

	Texture boardTexture;
	boardTexture.loadFromFile("B1.png");
	Sprite boardSprite(boardTexture);
	boardSprite.setScale(2.5, 2.5);
	boardSprite.setPosition(TotalCols / 3 - 100, 0);
	window.draw(boardSprite);

	map<char, Texture> textures;
	textures['p'].loadFromFile("pawn.png");
	textures['P'].loadFromFile("pawn1.png");
	textures['r'].loadFromFile("rook.png");
	textures['R'].loadFromFile("rook1.png");
	textures['b'].loadFromFile("bishop.png");
	textures['B'].loadFromFile("bishop1.png");
	textures['k'].loadFromFile("king.png");
	textures['K'].loadFromFile("king1.png");
	textures['n'].loadFromFile("knight.png");
	textures['N'].loadFromFile("knight1.png");
	textures['q'].loadFromFile("queen.png");
	textures['Q'].loadFromFile("queen1.png");

	for (int row = 0; row < Dim; ++row)
	{
		for (int col = 0; col < Dim; ++col)
		{
			char pieceSymbol = this->B->pie[row][col]->PIECE;
			if (textures.count(pieceSymbol)) 
			{
				Sprite pieceSprite(textures[pieceSymbol]);
				pieceSprite.setScale(1, 1);
				pieceSprite.setPosition(offsetX + col * mulCol, offsetY + row * mulRow);
				window.draw(pieceSprite);
			}
		}
	}
}

void  chess::TurnRandom()
{
	this->Turn = (this->Turn + 1) % 2;
}

void chess::WindowMakeItAbove(RenderWindow& window, bool** A)
{
	const int Dim = 8;
	const int TotalRows = 770, TotalCols = 1360;
	const float mulRow = 70.3, mulCol = 70.9;
	const int offsetX = 396, offsetY = 37;

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("boardBackground.jpg");
	Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setScale(TotalCols / static_cast<float>(backgroundTexture.getSize().x), TotalRows / static_cast<float>(backgroundTexture.getSize().y));
	window.draw(backgroundSprite);

	String playerInfo = this->B->player[Turn].getname() + " Time = " + to_string(this->B->player[Turn].Duration);
	Font font;
	font.loadFromFile("Lato.ttf");
	Text text(playerInfo, font, 12);
	text.setFillColor(Color::Blue);
	text.setStyle(Text::Underlined);
	text.setPosition(1100.f, 400.f);
	window.draw(text);

	Texture undoTexture, redoTexture;
	undoTexture.loadFromFile("undo.png");
	redoTexture.loadFromFile("redo.png");

	Sprite undoSprite(undoTexture);
	undoSprite.setScale(0.5, 0.5);
	undoSprite.setPosition(30, TotalRows - 200);
	window.draw(undoSprite);

	Sprite redoSprite(redoTexture);
	redoSprite.setScale(0.5, 0.5);
	redoSprite.setPosition(TotalCols - 155, TotalRows - 200);
	window.draw(redoSprite);

	Texture boardTexture;
	boardTexture.loadFromFile("B1.png");
	Sprite boardSprite(boardTexture);
	boardSprite.setScale(2.5, 2.5);
	boardSprite.setPosition(TotalCols / 3 - 100, 0);
	window.draw(boardSprite);

	Texture highlightTexture;
	highlightTexture.loadFromFile("black.png");
	Sprite highlightSprite(highlightTexture);
	highlightSprite.setScale(0.9, 0.9);

	for (int row = 0; row < Dim; ++row) 
	{
		for (int col = 0; col < Dim; ++col) 
		{
			if (A[row][col]) {
				highlightSprite.setPosition(offsetX - 12 + col * mulCol, offsetY - 6 + row * mulRow);
				window.draw(highlightSprite);
			}
		}
	}

	map<char, Texture> textures;
	textures['p'].loadFromFile("pawn.png");
	textures['P'].loadFromFile("pawn1.png");
	textures['r'].loadFromFile("rook.png");
	textures['R'].loadFromFile("rook1.png");
	textures['b'].loadFromFile("bishop.png");
	textures['B'].loadFromFile("bishop1.png");
	textures['k'].loadFromFile("king.png");
	textures['K'].loadFromFile("king1.png");
	textures['n'].loadFromFile("knight.png");
	textures['N'].loadFromFile("knight1.png");
	textures['q'].loadFromFile("queen.png");
	textures['Q'].loadFromFile("queen1.png");

	for (int row = 0; row < Dim; ++row) {
		for (int col = 0; col < Dim; ++col) {
			char pieceSymbol = this->B->pie[row][col]->PIECE;
			if (textures.count(pieceSymbol)) {
				Sprite pieceSprite(textures[pieceSymbol]);
				pieceSprite.setScale(1, 1);
				pieceSprite.setPosition(offsetX + col * mulCol, offsetY + row * mulRow);
				window.draw(pieceSprite);
			}
		}
	}
}

bool chess::FirstInterface(RenderWindow& window)
{
	Texture homeTexture;
	homeTexture.loadFromFile("home.png");
	Sprite homeSprite(homeTexture);
	homeSprite.setScale(1.9f, 2.0f);
	homeSprite.setPosition(100, 100);
	window.draw(homeSprite);

	Font font;
	font.loadFromFile("Lato.ttf");

	window.display();

	Position A = get_grid_position_from_mouse_click(window);

	return A.col_index <= 3;
}


void chess::CheckInterfaceWords(int Turn, RenderWindow& window)
{
	const int Dim = 8;
	const int TotalRows = 770, TotalCols = 1360;
	const float mulRow = 70.3f, mulCol = 70.9f;
	const int offsetX = 396, offsetY = 37;

	String playerInfo = this->B->player[Turn].getname() + " Time = " + to_string(this->B->player[Turn].Duration);

	Font font;
	font.loadFromFile("Lato.ttf");

	Text text(playerInfo, font, 12);
	text.setFillColor(Color::Black);
	text.setStyle(Text::Underlined);
	text.setPosition(1300.f, 400.f);
	window.draw(text);

	Texture undoTexture, redoTexture;
	undoTexture.loadFromFile("undo.png");
	redoTexture.loadFromFile("redo.png");

	Sprite undoSprite(undoTexture);
	undoSprite.setScale(0.5f, 0.5f);
	undoSprite.setPosition(30, TotalRows - 200);
	window.draw(undoSprite);

	Sprite redoSprite(redoTexture);
	redoSprite.setScale(0.5f, 0.5f);
	redoSprite.setPosition(TotalCols - 155, TotalRows - 200);
	window.draw(redoSprite);

	map<char, Texture> textures;
	textures['p'].loadFromFile("pawn.png");
	textures['P'].loadFromFile("pawn1.png");
	textures['r'].loadFromFile("rook.png");
	textures['R'].loadFromFile("rook1.png");
	textures['b'].loadFromFile("bishop.png");
	textures['B'].loadFromFile("bishop1.png");
	textures['k'].loadFromFile("king.png");
	textures['K'].loadFromFile("king1.png");
	textures['n'].loadFromFile("knight.png");
	textures['N'].loadFromFile("knight1.png");
	textures['q'].loadFromFile("queen.png");
	textures['Q'].loadFromFile("queen1.png");

	for (int row = 0; row < Dim; ++row)
	{
		for (int col = 0; col < Dim; ++col)
		{
			char pieceSymbol = this->B->pie[row][col]->PIECE;
			if (textures.count(pieceSymbol))
			{
				Sprite pieceSprite(textures[pieceSymbol]);
				pieceSprite.setScale(1.0f, 1.0f);
				pieceSprite.setPosition(offsetX + col * mulCol, offsetY + row * mulRow);
				window.draw(pieceSprite);
			}
		}
	}

	String checkMsg = B->player[(Turn + 1) % 2].getname() + " ------ in CHECK";
	Text checkText(checkMsg, font, 15);
	checkText.setFillColor(Color::Blue);
	checkText.setStyle(Text::Bold | Text::Underlined);
	checkText.setPosition(1120.f, 300.f);
	window.draw(checkText);
}

void chess::MateUnderCheck(RenderWindow& window, int Turn)
{
	Music cm;
	cm.play();

	window.clear(sf::Color::Black);
	String A = this->B->player[(Turn + 1) % 2].getname();
	A += " CHECK MATE Bro ";

	Font font;
	for (int i = 0; i < 100; ++i) {
		font.loadFromFile("Lato.ttf");
	}

	Text text;
	for (int i = 0; i < 50; ++i)
	{
		text.setCharacterSize(10);
		text.setFont(font);
		text.setCharacterSize(25);
		text.setFillColor(Color::Red);
		text.setString(A);
		text.setStyle(sf::Text::Underlined);
		text.setPosition(460.f + i, 19.f);
		window.draw(text);
	}

	Texture temp;
	for (int i = 0; i < 200; ++i)
	{
		temp.loadFromFile("check_mate.png");
	}

	Sprite a(temp);
	int Total_rows = 770, Total_cols = 1360;
	a.setScale(1, 1);
	a.setPosition(580, 200);

	for (int i = 0; i < 100; ++i)
	{
		window.draw(a);
	}

	window.display();

	for (int i = 0; i < 1000000; ++i)
	{
		for (int j = 0; j < 10000; ++j)
		{
			int waste = i * j;
		}
	}
}


void chess::Play_Game()
{
	static int Total_rows = 770, Total_cols = 1360;
	RenderWindow window(VideoMode(Total_cols, Total_rows), "                             CHESS                      ");
	window.clear(sf::Color::Black);
	if (this->FirstInterface(window))
	{
		this->B = new Board("piece.txt");
	}
	else
	{
		this->B = new Board("pieces.txt");

	}
	window.clear(sf::Color::Black);
	long long inti = time(0);
	Board RedO;
	bool canUndo = 0;
	bool canRedo = 0;
	bool** U; U = new bool* [8];
	Board Previous(*this->B);
	Position A, F; A.row_index = 0; A.col_index = 0; F.row_index = 7; F.col_index = 7;

	Music m, u, r, c, cm;
	this->B->Source_Pos.row_index = 1;
	this->B->Source_Pos.col_index = 1;
	this->WindowFirstImprs(window); window.display();

	Event event;
	while (window.isOpen())
	{
		while (window.waitEvent(event) && !B->checkMate(Turn))
		{
			{
				if (B->isCheck(Turn))
				{
					CheckInterfaceWords(Turn, window);
					window.display();
				}
				else if (B->Stalement(Turn))
				{
					B->game_over_draw();
				}
			}
			this->B->player[Turn].Duration += time(0) - inti;
			inti = time(0);
			if (this->B->player[Turn].Duration >= 300)
			{
				system("cls");
				cout << this->B->player[(Turn + 1) % 2].getname() << " Player is Winner"; exit(1);
			}
			TurnRandom();
			do 
			{
				do
				{
					B->Source_Pos = get_grid_position_from_mouse_click(window);
					if ((B->Source_Pos.row_index == 9 || B->Source_Pos.row_index == 8) && (B->Source_Pos.col_index == 11 || B->Source_Pos.col_index == 12 || B->Source_Pos.col_index == 13) && canRedo == 1)
					{
						r.play();
						canUndo = 0;
						canRedo = 0;
						RedO.MoveThemToNewOne(*B);

						goto lable11;


					}
					if ((B->Source_Pos.row_index == 9 || B->Source_Pos.row_index == 8) && (B->Source_Pos.col_index == -4 || B->Source_Pos.col_index == -3) && canUndo == 1)
					{
						u.play();
						B->MoveThemToNewOne(RedO);
						Previous.MoveThemToNewOne(*B);
						canUndo = 0;
						canRedo = 1;
						goto lable11;
					}
				} 
				while (!(B->IsLegal(B->Source_Pos) && B->iSMY_PIECE(Turn, B->Source_Pos)));
				U = B->findHight(Turn);
				window.clear(sf::Color::Black);
				this->WindowMakeItAbove(window, U); window.display();
				B->des_Pos = get_grid_position_from_mouse_click(window);
				window.clear(sf::Color::Black);
				this->WindowFirstImprs(window); window.display();

			}
			while (!U[B->des_Pos.row_index][B->des_Pos.col_index]);


			{
				B->MoveThemToNewOne(Previous);
				cout << Previous;
				if (this->is_piece_captured(B->Source_Pos, B->des_Pos))
				{
					c.play();
				}
				B->move(B->Source_Pos, B->des_Pos);

				m.play();
				canUndo = 1;
			lable11:
				{}
				window.clear(sf::Color::Black);

				this->WindowFirstImprs(window); window.display();
				B->LoadToFile("piece.txt");
			}

		}

		MateUnderCheck(window, Turn);
		_getche();
		window.close();
	}


}
chess::chess(int a)
{
	if (a == 1)
		*this = chess("pieces.txt");
	else
		*this = chess("piece.txt");
}


bool chess::is_piece_captured(Position source_Pos, Position des_Pos)
{
	if (this->B->pie[des_Pos.row_index][des_Pos.col_index]->PIECE == '-')
		return false;
	return 1;
}

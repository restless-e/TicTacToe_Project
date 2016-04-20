// TicTacToe_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

//initialized functions
void gameStart(char);
void boardState(char[3][3], char);
int markLoc();
short playerTurn(short&);
char markerType(char&);
bool check(char[3][3], char, bool&);

int main()
{
	short turn = 1; //alternates between 1 and -1 for players
	unsigned markIn = 0;
	char gameBoard[3][3] = { { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } };
	bool gameEnd = 0;
	bool  tie = 0;
	char marker = 'X'; // alternates between 'O' and 'X'

	//gameStart(marker); //might need later
	boardState(gameBoard, marker);
	while (!gameEnd)
	{
		markIn = markLoc();
		(gameBoard[(markIn / 3)][(markIn % 3) - 1] == 'X' || gameBoard[(markIn / 3)][(markIn % 3) - 1] == 'O') ? markLoc() : gameBoard[(markIn / 3)][(markIn % 3) - 1] = marker;
		//cout << "Already in use, try again. " << endl,
		marker = markerType(marker);
		boardState(gameBoard, marker);
		gameEnd = check(gameBoard, marker, tie);
		turn = playerTurn(turn);
		
	}
	system("pause");
	return 0;
}
// initial setup of 3x3 tic tac toe game
void gameStart(char mark)
{
	cout << "Player " << mark << " starts, enter location to mark." << endl;
}
// refreshes gameboard state with user inputs on screen
void boardState(char gb[3][3], char mark)
{
	system("cls");
	//cout << "---------------------" << endl << endl;
	cout << "     |     |     " << endl;
	cout << "  " << gb[0][0] << "  |  " << gb[0][1] << "  |  " << gb[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << gb[1][0] << "  |  " << gb[1][1] << "  |  " << gb[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << gb[2][0] << "  |  " << gb[2][1] << "  |  " << gb[2][2] << endl;
	cout << "     |     |     " << endl;
	cout << "Turn : " << mark << "      " << endl;
}
// handles user input to mark location;
int markLoc()
{
	unsigned spot = 0;

	cout << "Location to mark: ";
	cin >> spot;
	if (cin.fail())
	{
		cin.ignore();
		cin.clear();
		markLoc();
	}
	else if (spot < 0 || spot > 9)
	{
		cout << "Input entry is out of range. Try again. " << endl;
		markLoc();
	}
	return spot;
}

short playerTurn(short& pturn)
{
	return pturn * -1;
}

char markerType(char& mark)
{
	//return ((mark == 'X') ? 'O' : 'X');
	if (mark == 'X')
	{
		mark = 'O';
	}
	else if (mark == 'O')
	{
		mark = 'X';
	}
	return mark;
}

bool check(char gb[3][3], char mark, bool& tie)
{
	//Check for a win
	for (int i = 0; i < 3; i++)
	{
		if ((gb[i][0] == gb[i][1] && gb[i][1] == gb[i][2]) ||
			(gb[0][i] == gb[1][i] && gb[1][i] == gb[2][i]) ||
			(gb[0][0] == gb[1][1] && gb[1][1] == gb[2][2]) ||
			(gb[0][2] == gb[1][1] && gb[1][1] == gb[2][0]))
		{
			cout << mark << " wins!" << endl;;
			return true;
		}
	}
	//full board - check if draw
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gb[i][j] != 'X' && gb[i][j] != 'O')
			{
				return false;
			}
		}
	}
	tie = true;
	if (tie == true)
		cout << "We have a tie." << endl;
	return true;
}
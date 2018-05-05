#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include <cctype>
#include <conio.h>
#include "sokoban.h"

Floor::Floor(const char name[MAX_MAP_NAME+1])
{
	strcpy(this->name, name);
}
Floor::~Floor()
{
	for (int i = 0; i < sizeY; ++i)
		delete [] body[i];
	delete [] body;
}

void Floor::play()
{
	char nav;
	Console cmd;

	if (openFile())
	{
		while (true)
		{
			draw();
			nav = tolower(char(_getch()));

			if (nav == p.up) move(-1, 0);
			else if (nav == p.down) move(1, 0);
			else if (nav == p.left) move(0, -1);
			else if (nav == p.right) move(0, 1);
			else if (nav == '/') cmd.get();
		}
	}
}
void Floor::create(void)
{
	std::ofstream file;

	file.open(name, std::ios::out);
	if (!file) std::cout << "An error occured while creating the file.\n";
	else
		file << "USE \EDIT <FILE_NAME> TO MODIFY THIS FILE.n";
	file.close();
}
void Floor::edit(void)
{
	char nav;
	Console cmd;

	while (true)
	{
		nav = _getch();

		if (nav == p.up) move(-1, 0);
		else if (nav == p.down) move(1, 0);
		else if (nav == p.left) move(0, -1);
		else if (nav == p.right) move(0, 1);
		else if (nav == '/') cmd.get();
	}
}

bool Floor::openFile(void)
{
	std::fstream file;
	
	file.open(name, std::ios::binary | std::ios::in);
	if (!file)
	{
		std::cout << "An error occured while opening the file.\n";
		return false;
	}
	else
	{
		file.seekg(0, std::ios::end);
		int length = file.tellg();
		file.seekg(0, std::ios::beg);

		char * rawBody = new char[length + 1];
		file.get(rawBody, length + 1);

		rawToGood(rawBody, length);

		delete rawBody;
	}
	file.close();

	return true;
}
void Floor::rawToGood(const char * raw, const int length)
{
	int newLines = 0;

	for (int i = 0; i < length; ++i)
	{
		if (raw[i] == 'n') sizeY++;
		if (sizeY == 0 && raw[i] != 'n') sizeX++;
	}

	body = new char*[sizeY];
	for (int i = 0; i < sizeY; ++i)
		body[i] = new char[sizeX];

	for (int i = 0; i < sizeY; ++i)
		for (int j = 0; j < sizeX; ++j)
		{
			if (raw[(i*sizeX) + j + newLines] == 'n')
			{
				++newLines;
				body[i][j] = raw[(i*sizeX) + j + newLines];
			}
			else if(raw[(i*sizeX) + j + newLines] == P0)
			{
				posY = i;
				posX = j;
				body[i][j] = ' ';
			}
			else
				body[i][j] = raw[(i*sizeX) + j + newLines];
		}
}

void Floor::draw(void)
{
	system("cls");

	for (int i = 0; i < sizeY; ++i)
	{
		for (int j = 0; j < sizeX; ++j)
		{
			if (i == posY && j == posX && (body[posY][posX] == AIR || body[posY][posX] == DOCK))
				std::cout << p.icon;
			else
				std::cout << body[i][j];
		}
		std::cout << "\n";
	}
}
void Floor::move(const signed y, const signed x)
{
	switch (body[posY + y][posX + x])
	{
	case AIR:
	caseAIR:
	case DOCK:
		posY += y;
		posX += x;
		break;

	case BOX:
		if (body[posY + y + y][posX + x + x] == AIR)
		{
			body[posY + y][posX + x] = AIR;
			body[posY + y + y][posX + x + x] = BOX;
			goto caseAIR;
		}
		else if (body[posY + y + y][posX + x + x] == DOCK)
		{
			body[posY + y][posX + x] = AIR;
			body[posY + y + y][posX + x + x] = DBOX;
			goto caseAIR;
		}
		break;

	case DBOX:
		if (body[posY + y + y][posX + x + x] == AIR)
		{
			body[posY + y][posX + x] = DOCK;
			body[posY + y + y][posX + x + x] = BOX;
			goto caseAIR;
		}
		if (body[posY + y + y][posX + x + x] == DOCK)
		{
			body[posY + y][posX + x] = DOCK;
			body[posY + y + y][posX + x + x] = DBOX;
			goto caseAIR;
		}
		break;
	}
}
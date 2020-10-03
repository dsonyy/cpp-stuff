#include <iostream>
#include <cstdio>
#include <cstring>
#include "checkers.h"
using namespace std;


int main(int argc, char** argv) {
	// Domyslne wartosci wag
	int wl = 1;
	int wp = 1;
	int wb = 1;

	// Interpretowanie przekazanych do programu parametrow
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			helpPrint();
			return 0;
		}
		else if (strcmp(argv[i], "-wl") == 0 && i < argc - 1) {
			wl = atoi(argv[i + 1]);
			i++;
		}
		else if (strcmp(argv[i], "-wp") == 0 && i < argc - 1) {
			wp = atoi(argv[i + 1]);
			i++;
		}
		else if (strcmp(argv[i], "-wb") == 0 && i < argc - 1) {
			wb = atoi(argv[i + 1]);
			i++;
		}
		else {
			cout << "Wprowadzono bledny parametr." << endl;
			helpPrint();
			return 0;
		}
	}
	
	Game game = gameCreate(); // Stworzenie nowej planszy
	Pawn turn = Pawn::Black; // Aktualnie grajacy kolor

	// Petla glowna gry
	while (true) {
		// Narysowanie warcabnicy
		boardPrint(game.board);

		// Sprawdzenie czy przekroczono liczbe ruchow bez zbic dla damek
		// Jesli tak to uznaj remis i koniec gry
		if (game.movesCount == 20) {
			gameAnalyze(game, Pawn::None, wl, wb, wp);
			summaryPrint(game);
			break;
		}

		// Wybranie najopotymalniejszej drogi ruchu i zastosowanie jej
		bool decision = makeDecision(game, turn, wl, wb, wp);

		// Sprawdzenie wygranej i ewentualny koniec gry
		if (!decision) {
			gameAnalyze(game, Pawn::None, wl, wb, wp);
			summaryPrint(game);
			break;
		}

		// Zmiana koloru grajacego
		if (turn == Pawn::White) 
			turn = Pawn::Black;
		else if (turn == Pawn::Black) 
			turn = Pawn::White;
	}
	return 0;
}

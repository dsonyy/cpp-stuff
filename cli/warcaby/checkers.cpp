#include <iostream>
#include "checkers.h"
using namespace std;

Game gameCreate() {
	Game g; // Zwracana struktura Game

	g.board[0][1] = Pawn::Black;
	g.board[0][3] = Pawn::Black;
	g.board[0][5] = Pawn::Black;
	g.board[1][0] = Pawn::Black;
	g.board[1][2] = Pawn::Black;
	g.board[1][4] = Pawn::Black;

	g.board[4][1] = Pawn::White;
	g.board[4][3] = Pawn::White;
	g.board[4][5] = Pawn::White;
	g.board[5][0] = Pawn::White;
	g.board[5][2] = Pawn::White;
	g.board[5][4] = Pawn::White;

	return g;
}

void boardPrint(const Pawn board[6][6]) {
	cout << "+------+" << endl;
	for (int y = 0; y < 6; y++) {
		cout << '|';
		for (int x = 0; x < 6; x++) {
			if (board[y][x] == Pawn::White) cout << 'B';
			else if (board[y][x] == Pawn::Black) cout << 'C';
			else if (board[y][x] == Pawn::WhiteKing) cout << 'b';
			else if (board[y][x] == Pawn::BlackKing) cout << 'c';
			else if ((y + x) % 2) cout << '.';
			else cout << ' ';
		}
		cout << '|' << endl;
	}
	cout << "+------+" << endl;
}

int gameAnalyze(Game& game, Pawn turn, int wl, int wb, int wp) {
	
	// Wyzerowanie wartosci struktury Game
	game.lb = 0; // bierek bialych
	game.lc = 0; // bierek czarnych
	game.bb = 0; // bierek bialych bez ruchu
	game.bc = 0; // bierek czarnych bez ruchu
	game.pb = 0; // sytuacji gdzie za biala bierka jest puste pole
	game.pc = 0; // sytuacji gdzie za czarna bierka jest puste pole

	// Wykonywanie dla kazdego pola na planszy
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			// Jesli na polu znajduje sie biala bierka to wypelnij dla niej
			if (game.board[y][x] == Pawn::White || game.board[y][x] == Pawn::WhiteKing) {
				// Zwieksz liczbe bialych bierek
				game.lb++;

				// Zwieksz liczbe bialych bierek zablokowanych
				if (!(checkMoveRight(game, y, x) || checkMoveLeft(game, y, x) || 
					checkAttackRight(game, y, x) || checkAttackLeft(game, y, x))) {
					game.bb++;
				}

				// Zwieksz liczbe bialych bierek za ktorymi znajduje sie puste pole
				if (y < 5 && ((x > 0 && x < 5 && game.board[y + 1][x - 1] == Pawn::None) ||
					(x > 0 && x < 5 && game.board[y + 1][x + 1] == Pawn::None))) {
					game.pb++;
				}
			}
			// Jesli na polu znajduje sie czarna bierka to wypelnij dla niej
			else if (game.board[y][x] == Pawn::Black || game.board[y][x] == Pawn::BlackKing) {
				// Zwieksz liczbe czarnych bierek
				game.lc++;

				// Zwieksz liczbe czarnych bierek zablokowanych
				if (!(checkMoveRight(game, y, x) || checkMoveLeft(game, y, x) ||
					checkAttackRight(game, y, x) || checkAttackLeft(game, y, x))) {
					game.bc++;
				}

				// Zwieksz liczbe czarnych bierek za ktorymi znajduje sie puste pole
				if (y > 0 && ((x > 0 && x < 5 && game.board[y - 1][x - 1] == Pawn::None) ||
					(x > 0 && x < 5 && game.board[y - 1][x + 1] == Pawn::None))) {
					game.pc++;
				}
			}
		}
	}

	// Podstaw do wzoru na ocene sytuacji na planszy dla odpowiedniego koloru gracza
	int score =  wl * (game.lb - game.lc) + wb * (game.bc - game.bb) + wp * (game.pc - game.pb);
	if (turn == Pawn::White)
		return score;
	else
		return -score;
}

void helpPrint() {
	cout << "Program przeprowadza uproszczona gre w warcaby pomiedzy dwoma komputerowymi przeciwnikami." << endl;
	cout << "Do oceny kazdego z ruchow wykorzystywane sa nastepujace wspolczynniki:" << endl;
	cout << endl;
	cout << "\twl\twspolczynnik dla roznicy ilosci bierek danego koloru na planszy" << endl;
	cout << "\twb\twspolczynnik dla roznicy ilosci zablokowanych bierek danego koloru na planszy" << endl;
	cout << "\twp\twspolczynnik dla roznicy ilosci bierek danego koloru na planszy, ktore mozna przeskoczyc" << endl;
	cout << endl;
	cout << "Wymienione powyzej wagi nalezy okreslic w parametrach uruchamianego programu:" << endl;
	cout << "\tPROGRAM.EXE -wl <wartosc> -wb <wartosc> -wp <wartosc>" << endl;
	cout << endl;
}

void summaryPrint(Game& game) {
	cout << "Koniec gry." << endl;
	if (game.lb == 0)
		cout << "Czarne wygrywaja - zbito wszystkie biale!" << endl;
	else if (game.lc == 0)
		cout << "Biale wygrywaja - zbito wszystkie czarne!" << endl;
	else if (game.bb == game.lb)
		cout << "Czarne wygrywaja - brak ruchu dla bialych!" << endl;
	else if (game.bc == game.lc)
		cout << "Biale wygrywaja - brak ruchu dla czarnych!" << endl;
	else if (game.movesCount == 20)
		cout << "Remis - gracze wykonali po dziesiec ruchow bez zbic!" << endl;
}

bool checkMoveLeft(const Game& game, int y, int x) {
	// Jesli pionek jest bialy, nie przekroczy granic warcabnicy 
	// i wkroczy na puste pole to funkcja zwraca prawde
	if (game.board[y][x] == Pawn::White && y > 0 && x > 0 &&
		game.board[y - 1][x - 1] == Pawn::None) {
		return true;
	}
	// Jesli pionek jest czarny, nie przekroczy granic warcabnicy 
	// i wkroczy na puste pole to funkcja zwraca prawde
	else if (game.board[y][x] == Pawn::Black && y < 5 && x > 0 
		&& game.board[y + 1][x - 1] == Pawn::None) {
		return true;
	}

	// W przeciwnym wypadku funkcja zwraca falsz
	return false;
}

bool checkMoveRight(const Game& game, int y, int x) {
	// Jesli pionek jest bialy, nie przekroczy granic warcabnicy 
	// i wkroczy na puste pole to funkcja zwraca prawde
	if (game.board[y][x] == Pawn::White && y > 0 && x < 5 && game.board[y - 1][x + 1] == Pawn::None) {
		return true;
	}
	// Jesli pionek jest czarny, nie przekroczy granic warcabnicy 
	// i wkroczy na puste pole to funkcja zwraca prawde
	else if (game.board[y][x] == Pawn::Black && y < 5 && x < 5 && game.board[y + 1][x + 1] == Pawn::None) {
		return true;
	}

	// W przeciwnym wypadku funkcja zwraca falsz
	return false;
}

bool checkAttackLeft(const Game& game, int y, int x) {
	// Jesli pionek jest bialy, nie przekroczy granic warcabnicy,
	// wkroczy na puste pole i przeskoczy ponad pionkiem przeciwnika to funkcja zwraca prawde
	if (game.board[y][x] == Pawn::White && y > 2 && x > 1 && game.board[y - 2][x - 2] == Pawn::None &&
		(game.board[y - 1][x - 1] == Pawn::Black || game.board[y - 1][x - 1] == Pawn::BlackKing)) {
		return true;
	}
	// Jesli pionek jest czarny, nie przekroczy granic warcabnicy,
	// wkroczy na puste pole i przeskoczy ponad pionkiem przeciwnika to funkcja zwraca prawde
	else if (game.board[y][x] == Pawn::Black && y < 4 && x > 1 && game.board[y + 2][x - 2] == Pawn::None &&
		(game.board[y + 1][x - 1] == Pawn::White || game.board[y + 1][x - 1] == Pawn::WhiteKing)) {
		return true;
	}

	// W przeciwnym wypadku funkcja zwraca falsz
	return false;
}

bool checkAttackRight(const Game& game, int y, int x) {	
	// Jesli pionek jest bialy, nie przekroczy granic warcabnicy,
	// wkroczy na puste pole i przeskoczy ponad pionkiem przeciwnika to funkcja zwraca prawde
	if (game.board[y][x] == Pawn::White && y > 2 && x < 4 && game.board[y - 2][x + 2] == Pawn::None &&
		(game.board[y - 1][x + 1] == Pawn::Black || game.board[y - 1][x + 1] == Pawn::BlackKing)) {
		return true;
	}
	// Jesli pionek jest czarny, nie przekroczy granic warcabnicy,
	// wkroczy na puste pole i przeskoczy ponad pionkiem przeciwnika to funkcja zwraca prawde
	else if (game.board[y][x] == Pawn::Black && y < 4 && x < 4 && game.board[y + 2][x + 2] == Pawn::None &&
		(game.board[y + 1][x + 1] == Pawn::White || game.board[y + 1][x + 1] == Pawn::WhiteKing)) {
		return true;
	}

	// W przeciwnym wypadku funkcja zwraca falsz
	return false;
}

Game moveRight(const Game & game, int y, int x) {
	
	Game ret(game); // Zwracana struktura Game zbudowana na podstawie przekazanego wzorca

	// Jesli pionek jest bialy to pionek jest przesuwany w prawo do gory
	if (game.board[y][x] == Pawn::White) {
		if (y - 1 == 0) ret.board[y - 1][x + 1] = Pawn::WhiteKing;
		else ret.board[y - 1][x + 1] = Pawn::White;
		ret.board[y][x] = Pawn::None;
	}
	// Jesli pionek jest czarny to pionek jest przesuwany w prawo na dol
	else if (game.board[y][x] == Pawn::Black) {
		if (y + 1 == 5) ret.board[y + 1][x + 1] = Pawn::BlackKing;
		else ret.board[y + 1][x + 1] = Pawn::Black;
		ret.board[y][x] = Pawn::None;
	}

	// Wyzerowany zostaje licznik ruchow wykonywanych damkami bez zbic
	ret.movesCount = 0;
	return ret;
}

Game moveLeft(const Game& game, int y, int x) {

	Game ret(game); // Zwracana struktura Game zbudowana na podstawie przekazanego wzorca

	// Jesli pionek jest bialy to pionek jest przesuwany w lewo do gory
	if (game.board[y][x] == Pawn::White) {
		if (y - 1 == 0) ret.board[y - 1][x - 1] = Pawn::WhiteKing;
		else ret.board[y - 1][x - 1] = Pawn::White;
		ret.board[y][x] = Pawn::None;
	}
	// Jesli pionek jest czarny to pionek jest przesuwany w lewo na dol
	else if (game.board[y][x] == Pawn::Black) {
		if (y + 1 == 5) ret.board[y + 1][x - 1] = Pawn::BlackKing;
		else ret.board[y + 1][x - 1] = Pawn::Black;
		ret.board[y][x] = Pawn::None;
	}

	// Wyzerowany zostaje licznik ruchow wykonywanych damkami bez zbic
	ret.movesCount = 0;
	return ret;
}

Game attackRight(const Game& game, int y, int x) {

	Game ret(game); // Zwracana struktura Game zbudowana na podstawie przekazanego wzorca

	// Jesli pionek jest bialy to przesuwany jest w prawo do gory i zdejmowana zostaje bierka przeciwnika
	if (game.board[y][x] == Pawn::White) {
		if (y - 2 == 0) ret.board[y - 2][x + 2] = Pawn::WhiteKing;
		else ret.board[y - 2][x + 2] = Pawn::White;
		ret.board[y - 1][x + 1] = Pawn::None;
		ret.board[y][x] = Pawn::None;
	}
	// Jesli pionek jest czarny to przesuwany jest w prawo na dol i zdejmowana zostaje bierka przeciwnika
	else if (game.board[y][x] == Pawn::Black) {
		if (y + 2 == 5) ret.board[y + 2][x + 2] = Pawn::BlackKing;
		else ret.board[y + 2][x + 2] = Pawn::Black;
		ret.board[y + 1][x + 1] = Pawn::None;
		ret.board[y][x] = Pawn::None;
	}
	
	// Wyzerowany zostaje licznik ruchow wykonywanych damkami bez zbic
	ret.movesCount = 0;
	return ret;
}

Game attackLeft(const Game& game, int y, int x) {

	Game ret(game); // Zwracana struktura Game zbudowana na podstawie przekazanego wzorca

	// Jesli pionek jest bialy to przesuwany jest w lewo do gory i zdejmowana zostaje bierka przeciwnika
	if (game.board[y][x] == Pawn::White) {
		if (y - 2 == 0) ret.board[y - 2][x - 2] = Pawn::WhiteKing;
		else ret.board[y - 2][x - 2] = Pawn::White;
		ret.board[y - 1][x - 1] = Pawn::None;
		ret.board[y][x] = Pawn::None;
	}
	// Jesli pionek jest czarny to przesuwany jest w lewo na dol i zdejmowana zostaje bierka przeciwnika
	else if (game.board[y][x] == Pawn::Black) {
		if (y + 2 == 5) ret.board[y + 2][x - 2] = Pawn::BlackKing;
		else ret.board[y + 2][x - 2] = Pawn::Black;
		ret.board[y + 1][x - 1] = Pawn::None;
		ret.board[y][x] = Pawn::None;
	}

	// Wyzerowany zostaje licznik ruchow wykonywanych damkami bez zbic
	ret.movesCount = 0;
	return ret;
}

Game kingMove(const Game& game, int y, int x, int y2, int x2) {

	Game ret(game); // Zwracana struktura Game zbudowana na podstawie przekazanego wzorca

	// Przesuniecie damki z pozycji (x,y) na pozycje (x2,y2)
	ret.board[y2][x2] = ret.board[y][x];
	ret.board[y][x] = Pawn::None;
	// Zwiekszenie o jeden licznika ruchow damkami bez zbic
	ret.movesCount++;

	return ret; 
}

Game kingAttack(const Game& game, int y, int x, int y2, int x2) {

	Game ret(game); // Zwracana struktura Game zbudowana na podstawie przekazanego wzorca

	// Przesuniecie damki z pozycji (x,y) na pozycje (x2,y2) oraz zdjecie bierki przeciwnika
	ret.board[y2][x2] = ret.board[y][x];
	for (int jump = 0; jump < ((y2 - y) > 0 ? (y2 - y) : (y - y2)); jump++) {
		ret.board[y + (y2 > y ? (jump) : (-jump))][x + (x2 > x ? (jump) : (-jump))] = Pawn::None;
	}
	// Wyzerowany zostaje licznik ruchow wykonywanych damkami bez zbic
	ret.movesCount = 0;

	return ret;
}

void kingsMovementAppend(TreeNode& tree, Pawn turn, int y, int x) {
	Pawn opponent; // Kolor przeciwnika
	if (turn == Pawn::White)
		opponent = Pawn::Black;
	else if (turn == Pawn::Black)
		opponent = Pawn::White;

	// Algorytm, zaczynajac od pozycji damki (x,y), przeszukuje przekatne po jednym polu w czterech kierunkach
	// Jesli napodka puste pole (x+jump,y+jump) - dodaje ruch damki na to pole (x+jump,y+jump) do drzewa
	// Jesli napodka pole, ktore zajmowane jest przez zaprzyjazniona bierke - konczy przeszukiwanie kierunku
	// Jesli napodka pole, ktore zajmowane jest przez bierke przeciwnika - istnieje szansza na jej zbicie - kontynuuje przeszukiwanie kierunku
	
	// Kazda z ponizszych zmiennych odpowiada jednemu kierunkowi i ilosci 'przeszkod' (bierek) jakie napotka na swojej drodze damka
	// Sytuacja gdzie wartosc zmiennej wynosi 0 - nie znaleziono zadnych bierek na drodze, mamy do czynienia z przesunieciem damki
	// Sytuacja gdzie wartosc zmiennej wynosi 1 - znaleziono bierke przeciwnika, bicie bedzie dozwolone jesli od razu napotkane zostanie wolne pole
	// Sytuacja gdzie wartosc zmiennej jest wieksza - znaleziono przynajmniej jedna bierke zaprzyjazniona, lub wiecej niz jedna bierke wroga 
	int upRight = 0;
	int upLeft = 0;
	int downRight = 0;
	int downLeft = 0;

	// zmienna jump oznacza ilosc pol po przekatnej do pokonania
	for (int jump = 1; jump < 6; jump++) {

		// Jesli damka po wykonaniu przeskoku nie wypadnie z planszy i spelnia powyzsze zasady to dodawana jest do drzewa
		if (y + jump <= 5 && x + jump <= 5) {
			if (tree.getGame().board[y + jump][x + jump] == Pawn::None && downRight == 0) {
				tree.append(kingMove(tree.getGame(), y, x, y + jump, x + jump));
			}
			else if (tree.getGame().board[y + jump][x + jump] == Pawn::None && downRight == 1) {
				tree.append(kingAttack(tree.getGame(), y, x, y + jump, x + jump));
			}
			else if ((tree.getGame().board[y + jump][x + jump] == opponent || 
				tree.getGame().board[y + jump][x + jump] == Pawn(int(opponent) + 2)) && downRight == 0) {
				downRight++;
			}
			else
				downRight = 2;
		}

		// Jesli damka po wykonaniu przeskoku nie wypadnie z planszy i spelnia powyzsze zasady to dodawana jest do drzewa
		if (y - jump >= 0 && x + jump <= 5) {
			if (tree.getGame().board[y - jump][x + jump] == Pawn::None && upRight == 0) {
				tree.append(kingMove(tree.getGame(), y, x, y - jump, x + jump));
			}
			else if (tree.getGame().board[y - jump][x + jump] == Pawn::None && upRight == 1) {
				tree.append(kingAttack(tree.getGame(), y, x, y - jump, x + jump));
			}
			else if ((tree.getGame().board[y - jump][x + jump] == opponent ||
				tree.getGame().board[y - jump][x + jump] == Pawn(int(opponent) + 2)) && upRight == 0) {
				upRight++;
			}
			else
				upRight = 2;
		}

		// Jesli damka po wykonaniu przeskoku nie wypadnie z planszy i spelnia powyzsze zasady to dodawana jest do drzewa
		if (y + jump <= 5 && x - jump >= 0) {
			if (tree.getGame().board[y + jump][x - jump] == Pawn::None && downLeft == 0) {
				tree.append(kingMove(tree.getGame(), y, x, y + jump, x - jump));
			}
			else if (tree.getGame().board[y + jump][x - jump] == Pawn::None && downLeft == 1) {
				tree.append(kingAttack(tree.getGame(), y, x, y + jump, x - jump));
			}
			else if ((tree.getGame().board[y + jump][x - jump] == opponent ||
				tree.getGame().board[y + jump][x - jump] == Pawn(int(opponent) + 2)) && downLeft == 0) {
				downLeft++;
			}
			else
				downLeft = 2;
		}

		// Jesli damka po wykonaniu przeskoku nie wypadnie z planszy i spelnia powyzsze zasady to dodawana jest do drzewa
		if (y - jump >= 0 && x - jump >= 0) {
			if (tree.getGame().board[y - jump][x - jump] == Pawn::None && upLeft == 0) {
				tree.append(kingMove(tree.getGame(), y, x, y - jump, x - jump));
			}
			else if (tree.getGame().board[y - jump][x - jump] == Pawn::None && upLeft == 1) {
				tree.append(kingAttack(tree.getGame(), y, x, y - jump, x - jump));
			}
			else if ((tree.getGame().board[y - jump][x - jump] == opponent ||
				tree.getGame().board[y - jump][x - jump] == Pawn(int(opponent) + 2)) && upLeft == 0) {
				upLeft++;
			}
			else
				upLeft = 2;
		}
	}
}

void treeDecisionBuild(TreeNode& tree, Pawn turn) {

	// Wykonywanie dla kazdego pola na planszy
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {

			// Jesli na polu znajduje sie damka to dodaj wszystkie jej mozliwe ruchy do drzewa jako 'wezly-dzieci'
			if ((tree.getGame().board[y][x] == Pawn::WhiteKing && turn == Pawn::White) ||
				(tree.getGame().board[y][x] == Pawn::BlackKing && turn == Pawn::Black)) {
				kingsMovementAppend(tree, turn, y, x);
			}
			// Jesli napolu znajduje sie pionek to dodaj wszystkie jego mozliwe ruchy do drzewa jako 'wezly-dzieci'
			else if (tree.getGame().board[y][x] == turn) {
				if (checkMoveRight(tree.getGame(), y, x))
					tree.append(moveRight(tree.getGame(), y, x));

				if (checkMoveLeft(tree.getGame(), y, x))
					tree.append(moveLeft(tree.getGame(), y, x));

				if (checkAttackRight(tree.getGame(), y, x))
					tree.append(attackRight(tree.getGame(), y, x));

				if (checkAttackLeft(tree.getGame(), y, x))
					tree.append(attackLeft(tree.getGame(), y, x));
			}
		}
	}
}

bool makeDecision(Game& game, Pawn turn, int wl, int wb, int wp) {
	TreeNode tree(game); // Drzewo na przechowywanie przyszlych ruchow
	int bestScore, bestMove = -1; // Najlepszy uzyskany wynik za ruch, numer 'wezla-dziecka', ktory do tego ruchu ma zaprowadzic
	Pawn opponentTurn; // Kolor przeciwnika
	if (turn == Pawn::White)
		opponentTurn = Pawn::Black;
	else if (turn == Pawn::Black)
		opponentTurn = Pawn::White;

	// Budowanie drzewa posiadajacego wszystkie mozliwe kombinacje ruchow o 3 tury do przodu
	// Korzeniem drzewa jest plansza poczatkowa
	// Pierwszy poziom 'dzieci' to mozliwe ruchy w 1 turze
	// Drugi poziom 'dzieci' to mozliwe ruchy w 2 turze
	// Trzeci poziom 'dzieci' to mozliwe ruchy w 3 turze
	treeDecisionBuild(tree, turn); // Budowa pierwszego poziomu
	for (int i = 0; i < tree.children(); i++) {
		treeDecisionBuild(tree.getChildNode(i), opponentTurn); // Budowa drugiego poziomu (tura przeciwnika)

		for (int j = 0; j < tree.getChildNode(i).children(); j++) {
			treeDecisionBuild(tree.getChildNode(i).getChildNode(j), turn); // Budowa trzeciego poziomu

			// Przejerzenie wszystkich obiektow Game 'wezlow-dzieci' trzeciego poziomu w celu obliczenia ich wynikow za ruch
			for (int k = 0; k < tree.getChildNode(i).getChildNode(j).children(); k++) {
				// Obliczenie liczby punktow
				int score = gameAnalyze(tree.getChildNode(i).getChildNode(j).getChildGame(k), turn, wl, wb, wp);
				// Zestapienie aktualnej liczby punktow jesli jest nizsza (lepszy ruch zastepuje gorszy)
				if (bestMove == -1 || score > bestScore) {
					bestMove = i;
					bestScore = score;
				}
			}
		}

		// Jesli na poziomie drugim (tura przeciwnika) nie ma zadnych 'wezlow-dzieci' to oznacza to ze przeciwnik nie ma ruchu
		if (tree.getChildNode(i).children() == 0) {
			// Natychmiast ustawiany jest ten ruch jako najlepszy i opuszczana jest petla
			bestMove = i;
			break;
		}
	}

	// Brak ruchu, koniec gry
	if (bestMove == -1)
		return false;
	// Ruch istnieje, gra sie toczy
	game = tree.getChildGame(bestMove);
	return true;
}

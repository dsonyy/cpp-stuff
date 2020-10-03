#ifndef _CHECKERS_H_
#define _CHECKERS_H_


// Rodzaje pol na warcabnicy
enum class Pawn {
	None, // pole pusty
	White, // pionek bialy
	Black, // pionek czarny
	WhiteKing, // damka biala
	BlackKing, // damka czarna
};


// Struktura zawierajace wszystkie informacje dotyczace rozgrywki
struct Game {
	Pawn board[6][6] = {}; // warcabnica
	int movesCount = 0; // ilosc ruchow samymi damkami pod rzad bez zadnych zbic
	int lb = 0;	// bierek bialych
	int lc = 0;	// bierek czarnych
	int bb = 0;	// bierek bialych bez ruchu
	int bc = 0;	// bierek czarnych bez ruchu
	int pb = 0;	// sytuacji gdzie za biala bierka jest puste pole
	int pc = 0;	// sytuacji gdzie za czarna bierka jest puste pole
};

// Klasa implementujaca proste drzewo, w ktorym kazdy wezel przechowuje strukture Game
class TreeNode {
public:
	// Konstruktor za argument przyjmuje strukture Game, ktora zostanie 'korzeniem' drzewa
	//  (Po stworzeniu obiektu, 'korzen' nie posiada 'dzieci')
	TreeNode(const Game& game);
	
	~TreeNode();

	// Dodaje przekazana strukture Game do 'dzieci' i zwraca nowa ilosc wykorzystywanych 'dzieci'
	int append(const Game& game);
	
	// Usuwa wszystkie 'dzieci'
	void clear();

	// Zwraca ilosc wykorzystywanych 'dzieci'
	int children() const;

	// Zwraca referencje na 'dziecko' o wskazanej pozycji
	TreeNode& getChildNode(int index);

	// Zwraca referencje na strukture Game 'dziecka' o wskazanej pozycji
	Game& getChildGame(int index);

	// Zwraca referencje na strukture Game 'korzenia' (nalezaca do tego obiektu)
	Game& getGame();

private:
	Game _game; // 'korzen'
	int _children; // liczba 'dzieci'
	TreeNode** _treeNodes; // tablica wskaznikow na 'dzieci'
};


// Zwraca nowa gre wypelniona odpowiednio ulozonymi pionkami
Game gameCreate();


// Wypisuje na standardowe wyjscie zawartosc warcabnicy
void boardPrint(const Pawn board[6][6]);

// Zwraca liczbe punktow na ile zostanie oceniona sytuacja na planszy dla wskazanego
//  koloru z podanymi wspolczynnikami
int gameAnalyze(Game& game, Pawn turn, int wl, int wb, int wp);


// Wypisuje na standardowe wyjscie pomoc programu
void helpPrint();


// Wypisuje na standardowe wyjscie podsumowanie zakonczonej gry
void summaryPrint(Game& game);


// Zwraca prawde jesli pionek o wspolrzednych (x,y) moze wykonac ruch w lewo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
bool checkMoveLeft(const Game& game, int y, int x);


// Zwraca prawde jesli pionek o wspolrzednych (x,y) moze wykonac ruch w prawo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
bool checkMoveRight(const Game& game, int y, int x);


// Zwraca prawde jesli pionek o wspolrzednych (x,y) moze wykonac atak w lewo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
bool checkAttackLeft(const Game& game, int y, int x);


// Zwraca prawde jesli pionek o wspolrzednych (x,y) moze wykonac atak w prawo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
bool checkAttackRight(const Game& game, int y, int x);


// Wykonuje ruch pionka w lewo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
Game moveLeft(const Game& game, int y, int x);


// Wykonuje ruch pionka w prawo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
Game moveRight(const Game& game, int y, int x);


// Wykonuje atak pionka w lewo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
Game attackLeft(const Game& game, int y, int x);


// Wykonuje atak pionka w prawo
// Funkcja automatycznie wykrywa kolor pionka i ustala kierunek jego ruchu (w gore lub dol)
Game attackRight(const Game& game, int y, int x);


// Wykonuje ruch damki z pozycji (x,y) na pozycje (x2,y2)
Game kingMove(const Game& game, int y, int x, int y2, int x2);


// Wykonuje atak damki z pozycji (x,y) na pozycje (x2,y2)
Game kingAttack(const Game& game, int y, int x, int y2, int x2);


// Dodaje do drzewa (przekazanego w pierwszym argumencie) wszystkich mozliwych ruchow damki 
//  o danym kolorze na pozycji (x,y)
void kingsMovementAppend(TreeNode& tree, Pawn turn, int y, int x);


// Dodaje do drzewa (nieposiadajacego 'dzieci') jeden poziom wszystkich mozliwych ruchow
//  dla danego koloru bierek
void treeDecisionBuild(TreeNode& tree, Pawn turn);


// Analizuje aktualny stan gry i aktualizuje plansze o optymalny ruch dla pionka o kolorze przekazanym 
//  w drugim argumencie (prawidlowe wartosci to tylko Pawn::White i Pawn::Black)
// Zwraca prawde jesli gra sie dalej toczy i falsz jesli gra jest zakonczona
bool makeDecision(Game& game, Pawn turn, int wl, int wb, int wp);


#endif

#define AIR ' '
#define BOX 'O'
#define DOCK '+'
#define DBOX 'X'
#define P0 '@'
const int MAX_MAP_NAME = 32;
const int MAX_CMD_NAME = MAX_MAP_NAME + 8;

struct Player
{
	char icon = P0;

	char up = 'w';
	char down = 's';
	char left = 'a';
	char right = 'd';
};

class Console
{
public:
	char cmd[MAX_CMD_NAME + 1];

public:
	void get(void);
	void help(void);
private:
	void execute(void);
};

class Floor
{
	char name[MAX_MAP_NAME + 1];
	Player p;
	char ** body;
	int sizeX;
	int sizeY;
	int posX;
	int posY;

public:
	Floor(const char name[MAX_MAP_NAME + 1]);
	~Floor(void);

	void play(void);
	void create(void);
	void edit(void);

private:
	bool openFile(void);
	void rawToGood(const char * raw, const int length);
	void draw(void);
	void move(const signed y, const signed x);
};
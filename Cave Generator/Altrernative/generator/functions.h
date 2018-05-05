// functions.h
// all global functions used in program

#ifndef _H_FUNCTIONS
#define _H_FUNCTIONS


#include "headers.h"


#define INFO(...)		{ printf("[  i  ] "); printf(__VA_ARGS__); /*fflush(stdout);*/ }
#define WARNING(...)	{ printf("[  !  ] "); printf(__VA_ARGS__); /*fflush(stdout);*/ }
#define ERROR(...)		{ printf("[ERROR] "); printf(__VA_ARGS__); /*fflush(stdout);*/ }

struct Point { int x; int y; };

typedef Point LocalPoint;
typedef Point GlobalPoint;

//void Message(message_type type, char * str, ...);
void Help();


#endif // _H_FUNCTIONS
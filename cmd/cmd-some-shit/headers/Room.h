#ifndef _H_ROOM
#define _H_ROOM

#include <string>
#include <random>
#include "GemBox.h"

#define MAX_PROBABILITY 50

class Room
{
    public:
    std::string m_descr;
    int m_boxes;
    int m_npcs;
    int m_mobs;

public:
    Room(unsigned);
    ~Room();

private:
    int random(int, unsigned);
};

#endif
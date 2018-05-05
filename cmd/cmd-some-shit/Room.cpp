#include <cstdlib>
#include <random>
#include "headers/Room.h"

Room::Room(unsigned skill)
{
    m_descr = "skill: " + skill;
    m_boxes = random(20);
    m_npcs = random(20);
    m_mobs = random(30);
    
}

Room::~Room()
{

}

int Room::random(int perc, unsigned)
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<> distro(0, 100);

    int count = 0;

    if (perc > MAX_PROBABILITY) perc = MAX_PROBABILITY;

    if ( distro(generator) < perc)
    {
        count += random(perc*2) + 1;
        return count;
    }
    else return 0;
}
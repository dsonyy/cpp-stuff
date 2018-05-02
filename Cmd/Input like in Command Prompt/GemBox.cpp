#include <cstdlib>
#include "headers/GemBox.h"

GemBox::GemBox()
{
    for (int i = 0; i < BOX_SIZE; ++i)
    {
        m_box[i] = rand()%5;
    }
    m_name = "Bag?";
}

bool GemBox::swap(signed num, unsigned gem)
{
    if (gem < BOX_SIZE  &&  m_box[gem] + num >= 0)
    {
        m_box[gem] += num;
        return true;
    }
    else return false;
}

int GemBox::get(unsigned gem) const
{
    if (gem < BOX_SIZE) return m_box[gem];
    else return -1;
}
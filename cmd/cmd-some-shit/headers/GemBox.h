#ifndef _H_GEMBOX
#define _H_GEMBOX

#include <string>

#define COAL 0
#define GOLD 1
#define DIAMOND 2
#define BOX_SIZE 3


class GemBox
{
    std::string m_name;
    int m_box[BOX_SIZE];

public:
    GemBox();
    bool swap(signed, unsigned); 
    int get(unsigned) const;
};


#endif

#pragma once
#include "Matter.h"
class Block :
    public Matter
{

    private:
        uint32_t* sprite;

    public:
        Block();
        ~Block();
        uint32_t* getSprite();
};


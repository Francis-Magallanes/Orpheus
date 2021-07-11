#pragma once
#include "Matter.h"

// this will distinguish the different type of slab and it characteristics
// each type of slab will have a unique color, whether can be damage or not, and hitpoints
enum class TypeSlab {
    
    //this cannot be damaged by the player
    //Color: Light Blue (0x67B7D1)
    DIAMOND = 1,

    // it takes 3 hits before it gets destroyed
    // Color: Light grey (0xD3D3D3)
    CONCRETE = 2,

    // it takes 2 hits before it gets destroyed
    // Color: Light Brown (0xB5651D)
    WOOD = 3
};

class Slab :
    public Matter
{

    private:
        uint32_t* sprite;
        TypeSlab ts;
        
    public:
        Slab(TypeSlab type);
        ~Slab();
        uint32_t* getSprite();
};


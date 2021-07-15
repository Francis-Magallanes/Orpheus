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
        uint32_t* WOOD_SPRITE_1; //this is for the sprite of the wood slab at full health
        uint32_t* WOOD_SPRITE_2; //this is for the sprite of the wood slab at half health (25)
        TypeSlab ts;
        
    public:
        Slab(TypeSlab type);
        ~Slab();
        
        //this will get the 20x20 pixel sprite from the object in one-dimensional array
        uint32_t* getSprite();
        
        //this is for handling any "damage" (i.e. player's attack) towards the object
        void absorbDamage(int damage);

};


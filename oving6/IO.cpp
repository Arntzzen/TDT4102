#include "IO.h"
#include "Utilities.h"

// BEGIN: 3a

// END: 3a

// BEGIN: 3b

// END: 3b

std::istream& operator>> (std::istream& inStream, Dungeon::Chest& chest) {
    int locationX;
    int locationY;
    inStream >> locationX;
    inStream >> locationY;
    chest.moveTo({float(locationX), float(locationY)});
    return inStream;
}

// BEGIN: 3c

// END: 3c

void Dungeon::loadRoom(TDT4102::Point currentRoomCoordinate, Dungeon::Map& map, Interactables& interactables) {
    // BEGIN: 3d

    // END: 3d
}
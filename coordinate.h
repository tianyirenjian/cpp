#include <iostream>

class Coordinate
{
    int x;
    int y;
    int z;

public:

    Coordinate(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    friend std::ostream& operator<<(std::ostream &os, Coordinate &coor) {
        os << "x = " << coor.x << ", y = " << coor.y << ", z = " << coor.z;
        return os;
    }
};

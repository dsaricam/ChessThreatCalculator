#include "Piece.h"

Piece::Piece(const std::string& representation) 
    : type(1, representation[0]), color(1, representation[1]), threatened(false) {}

std::string Piece::getType() const { return type; }

std::string Piece::getColor() const { return color; }

bool Piece::isThreatened() const { return threatened; }

void Piece::setThreatened(bool status) { threatened = status; }

int Piece::getValue(){
    if (this->type == "k")
        return 5;
    else if (this->type == "f")
        return 3;
    else if (this->type == "a")
        return 3;
    else if (this->type == "p")
        return 1;
    else if (this->type == "v")
        return 9;
    else if (this->type == "s")
        return 100;
    else
        return 0;
}

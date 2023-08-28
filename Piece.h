#pragma once
#include <string>

class Piece {
public:
    Piece(const std::string& representation);

    std::string getType() const;
    std::string  getColor() const;
    bool isThreatened() const;
    void setThreatened(bool status);
    int getValue();

private:
    std::string type;   // p, k, f, a, v, s
    std::string color;  // b, s
    bool threatened;
};

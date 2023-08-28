#include <iostream>
#include <fstream>
#include <vector>
#include "ScoreCalculator.h"
#include "ChessBoard.h"


int main() {
    std::ifstream inputFile("/Users/doneyildiz/Documents/Projects/ChessThreatCalculator/ChessThreatCalculator/chessboard.txt");
    std::vector<std::vector<std::string>> boardRepresentation;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Couldn't open the file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> row;
        for (size_t i = 0; i < line.size(); i += 3) {
            
            row.push_back(line.substr(i, 2)); // Get the piece code
        }
        boardRepresentation.push_back(row);
    }

    inputFile.close();

    ChessBoard chessBoard(boardRepresentation);
    chessBoard.determineThreats();
    
    ScoreCalculator scoreCalcultor(chessBoard);
    std::cout<< "Beyaz: ";
    scoreCalcultor.getScore("b");
    std::cout<< "Siyah: ";
    scoreCalcultor.getScore("s");
 
    return 0;
}

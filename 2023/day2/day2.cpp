#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <tuple>
#include <sstream>


std::vector<std::string> getInputs() { 
    std::ifstream inFile;
    inFile.open("./input.txt");

    if (!inFile) {
        std::cout << "Unable to read txt file";
        exit(1);
    }

    std::string line;
    std::vector<std::string> inputs;

    while (std::getline(inFile, line)) {
        inputs.push_back(line);
    }

    return inputs;
}

void partOne() {

    std::vector<std::string> inputs = getInputs();
    int total = 0;

    std::vector<std::vector<std::string>> colon_delim;
    std::string seg;

    for (std::string input : inputs) {
        std::stringstream curr(input);
        std::vector<std::string> split;
        while (std::getline(curr, seg, ':')) {
            split.push_back(seg);
        }

        std::cout << split[0] << "\n" << split[1] << "\n";
    }

    


}

int main() {
    partOne();
}
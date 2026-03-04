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

    std::string seg;

    for (std::string input : inputs) {
        
        std::stringstream curr(input);
        std::vector<std::string> split;

        while (std::getline(curr, seg, ':')) {
            split.push_back(seg);
        }

        std::string game_num = split[0];
        std::string converted;
        
        for (auto &ch : game_num) {
            if (std::isdigit(ch)) {
                converted.append(std::string(1, ch));
            }
        }

        int int_value = stoi(converted);

        std::string seg2;
        std::stringstream curr2 (split[1]);
        std::vector<std::string> split2;

        while (std::getline(curr2, seg2, ';')) {
            split2.push_back(seg2);
        }
        
        std::string seg3;
        std::vector<std::string> individual_picks;
        std::vector<std::string> split3;
        for (const std::string& s : split2) {
            std::stringstream curr3 (s);
            while (std::getline(curr3, seg3, ',')) {
                split3.push_back(seg3);
            }
        }    
        

        bool valid = true;

        for (const std::string& s : split3) {
            std::stringstream ss(s);
            int num;
            std::string colour;

            ss >> num >> colour;

            if (colour == "red" && num > 12) {valid = false;}
            if (colour == "green" && num > 13) {valid = false;}
            if (colour == "blue" && num > 14) {valid = false;}
        }
        
        if (valid) {
            total += int_value;
        }
    }
    std::cout << "The answer for Part 1 is " << total << "\n"; 
}

int main() {
    partOne();
}
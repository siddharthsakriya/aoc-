#include <iostream>
#include <vector>
#include<fstream>
#include<map>

std::vector<std::string> getInputs() { 
    std::ifstream inFile;
    inFile.open("./input.txt");

    if (!inFile) {
        std::cout << "Unable to read txt file";
        exit(1);
    }

    std::string x;
    std::vector<std::string> inputs;

    while (inFile >> x) {
        inputs.push_back(x);
    }

    return inputs;
}

void partOne () {
    std::vector<std::string> inputs = getInputs();
    int total = 0;

    for (std::string input : inputs) {
        char first_int = ' ';
        char last_int = ' ';

        for (char c: input) {
            
            if (!std::isdigit(c)) {
                continue;
            }

            if (isblank(first_int)) {
                first_int = c;
                continue;
            }
            
            last_int = c;
        }

        if (isblank(last_int)) {
            last_int = first_int;
        }

        std::string final_num = std::string(1, first_int) + last_int;
        total += stoi(final_num);
    }
    std::cout << "The answer for Part 1 is " << total << "\n"; 
}

void partTwo() {
    std::vector<std::string> inputs = getInputs();
    std::map<std::string, char> mappings = {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };

    int total = 0;

    for (std::string input : inputs) {
        std::string word = "";
        char firstInt = ' ';
        char lastInt = ' ';

        for (char c : input) {
            if (std::isdigit(c)) {
                if (isblank(firstInt)) {
                    firstInt = c;
                } else {
                    lastInt = c;
                }
                word = "";
                continue;
            }
            
            
            word += c;
            //check for every number if it is at the end 
            for (auto &pair : mappings) {
                const std::string &key = pair.first;
                char val = pair.second;

                if (word.size() >= key.size() &&
                    word.substr(word.size() - key.size()) == key) {
                    if (isblank(firstInt)) {
                        firstInt = val;
                    } else {
                        lastInt = val;
                    }
                    if (word.size() > 2) {
                        word = word.substr(word.size() - 2);
                    }
                }
            }
        }

        if (isblank(lastInt)) {
            lastInt = firstInt;
        }
        
        std::string final_num = std::string(1, firstInt) + lastInt;
        total += stoi(final_num);   
    }

    std::cout << "The answer for Part 2 is " << total << "\n"; 

}

int main() {
    partOne();
    partTwo();    
}
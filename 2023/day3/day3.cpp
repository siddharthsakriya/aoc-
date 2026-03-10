#include <iostream>
#include <vector>
#include <fstream>


std::vector<std::string> getInputs() {
    std::ifstream inFile;
    inFile.open("./input.txt");

    if (!inFile) {
        std::cout << "unable to read txt file";
        exit(1);
    }

    std::string line;
    std::vector<std::string> inputs;

    while (std::getline(inFile, line))
    {
        inputs.push_back(line);
    }

    return inputs;
}

void partOne() {

    // get inputs 
    std::vector<std::string> inputs = getInputs();
    // loop through, whenever i encounter integers, build an array of indices, and keep going until number is built
    int ROWS = inputs.size();
    int COLS = inputs[0].size();

    int dirs[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1},  {1, 0},  {1, 1} };
    int total = 0;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (isdigit(inputs[r][c])) {
                std::vector<std::vector<int>> toExplore;

                std::string converted;

                while (c < COLS and isdigit(inputs[r][c])) {
                    toExplore.push_back({r, c});
                    converted.append(std::string(1, inputs[r][c]));
                    c += 1;
                }

                bool isValid = false;
                int convertedInt = stoi(converted);
                for (auto& curr: toExplore) {
                    for (auto& direction : dirs) {
                        int rx = direction[0] + curr[0];
                        int cx = direction[1] + curr[1];

                        if ((rx < 0) or (rx > ROWS - 1) or (cx < 0) or (cx > COLS - 1)) {
                            continue;
                        }

                        if (!isdigit(inputs[rx][cx]) and inputs[rx][cx] != '.') {
                            isValid = true;
                        }
                    }
                }

                if (isValid) {
                    total += convertedInt;
                }
            }
        }
    }

    std::cout << "The answer for Part 1 is " << total << "\n"; 
}

int main() {
    partOne();
}
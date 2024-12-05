#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main() {
    std::string filename = "Input.txt";

    std::vector<int> left_list, right_list;

    std::ifstream input_file(filename);
    if (!input_file) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    int left, right;
    while (input_file >> left >> right) {
        left_list.push_back(left);
        right_list.push_back(right);
    }

    input_file.close();

    std::unordered_map<int, int> right_count;
    for (int num : right_list) {
        right_count[num]++;
    }

    int similarity_score = 0;
    for (int num : left_list) {
        similarity_score += num * right_count[num];
    }

    std::cout << "Similarity score: " << similarity_score << std::endl;

    return 0;
}


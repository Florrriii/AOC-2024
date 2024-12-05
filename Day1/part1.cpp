#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());

    // Calculate the total distance
    int total_distance = 0;
    for (size_t i = 0; i < left_list.size(); ++i) {
        total_distance += std::abs(left_list[i] - right_list[i]);
    }

    std::cout << "Total distance: " << total_distance << std::endl;

    return 0;
}

#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <vector>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    std::vector<int> numberList = convertToNumber(numbers);
    int add = 0;
    for (int num : numberList) {
        add += num;
    }

    return add;
}

std::vector<int> StringCalculator::convertToNumber(const std::string& numbers) {
    std::vector<int> numList;
    std::stringstream strnum(numbers);
    std::string num;

    while (std::getline(strnum, num, ',')) {
        numList.push_back(std::stoi(num));
    }

    return numList
}

#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    std::vector<int> numberList = convertToNumber(numbers);
    std::vector<int> negatives = avoidNegativeNumbers(numberList);

    if (!negatives.empty()) {
        throwNegativeNumbersException(negatives);
    }
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

    return numList;
}

std::vector<int> StringCalculator::avoidNegativeNumbers(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int num : numbers) {
        if (num < 0) {
            negatives.push_back(num);
        }
    }
    return negatives;
}

void StringCalculator::throwNegativeNumbersException(const std::vector<int>& negatives) {
    std::ostringstream oss;
    oss << "negatives not allowed: ";
    for (size_t i = 0; i < negatives.size(); ++i) {
        if (i > 0) {
            oss << ", ";
        }
        oss << negatives[i];
    }
    throw std::runtime_error(oss.str());
}

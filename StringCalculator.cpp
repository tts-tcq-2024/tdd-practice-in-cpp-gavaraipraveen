#include "StringCalculator.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <regex>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    return summation(numbers);
}

int StringCalculator::summation(const std::string& numbers) {
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
    std::string sanitizedNumbers = numbers;
    std::string delimiter = ",";

    // Check for custom delimiter
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find('\n');
        delimiter = numbers.substr(2, delimiterEnd - 2);
        sanitizedNumbers = numbers.substr(delimiterEnd + 1);
    }

    // Replace newline characters with commas to unify the delimiters
    std::replace(sanitizedNumbers.begin(), sanitizedNumbers.end(), '\n', ',');

    // Use regex to split by either comma or custom delimiter
    std::string regexPattern = delimiter == "," ? "," : std::regex_escape(delimiter) + "|,";
    std::regex re(regexPattern);
    std::sregex_token_iterator it(sanitizedNumbers.begin(), sanitizedNumbers.end(), re, -1);
    std::sregex_token_iterator end;

    for (; it != end; ++it) {
        numList.push_back(filterNumber(*it));
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

int StringCalculator::filterNumber(const std::string& numbers) {
    int num = std::stoi(numbers);
    return num > 1000 ? 0 : num;
}

#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);
private:
    int summation(const std::string& numbers);
    std::vector<int> convertToNumber(const std::string& numbers);
    std::string extractDelimiter(const std::string& numbers, std::string& sanitizedNumbers);
    std::vector<int> splitNumbers(const std::string& sanitizedNumbers, const std::string& delimiter);
    std::vector<int> avoidNegativeNumbers(const std::vector<int>& numbers);
    void throwNegativeNumbersException(const std::vector<int>& negatives);
    int filterNumber(const std::string& numStr);
};

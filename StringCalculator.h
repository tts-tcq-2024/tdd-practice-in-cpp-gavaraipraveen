#include <string>
#include <vector>

class StringCalculator {
public:
    int add(const std::string& numbers);
private:
    int summation(const std::string& numbers);
    std::vector<int> convertToNumber(const std::string& numbers);
    std::vector<int> avoidNegativeNumbers(const std::vector<int>& numbers);
    void throwNegativeNumbersException(const std::vector<int>& negatives);
};

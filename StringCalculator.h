#include <string>

class StringCalculator {
public:
    int add(const std::string& numbers);
private:
    std::vector<int> convertToNumber(const std::string& numbers);
};

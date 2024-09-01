#include <bits/stc++.h>
using namespace std;

int main() {
    auto add = [](int a, int b) -> int { return a + b; };

    int sum = add(3, 4);
    cout << "Sum: " << sum << endl; // Output: Sum: 7

    int factor = 2;

    auto multiply = [factor](int a) -> int { return a * factor; };

    int result = multiply(5);
    cout << "Result: " << result << endl;

    int value = 5;

    auto increment = [&value]() { value++; };

    increment();
    std::cout << "Value: " << value << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use lambda to print all elements
    std::for_each(numbers.begin(), numbers.end(),
                  [](int n) { std::cout << n << " "; });
    std::cout << std::endl;

    return 0;
}

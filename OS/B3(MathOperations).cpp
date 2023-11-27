#include <iostream>
#include <sstream>
#include <string>

double performOperation(double operand1, double operand2, char operation) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                std::cerr << "Error: Division by zero!\n";
                return 0;
            }
        default:
            std::cerr << "Error: Invalid operation!\n";
            return 0;
    }
}

int main() {
    std::string input;
    double operand1, operand2;
    char operation;

    std::cout << "Simple Shell for Mathematical Operations\n";
    std::cout << "Enter an expression (operand operator operand), e.g., 2 + 3: \n";

    while (true) {
        std::getline(std::cin, input);

        std::istringstream iss(input);
        if (iss >> operand1 >> operation >> operand2) {
            double result = performOperation(operand1, operand2, operation);
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cerr << "Error: Invalid input format!\n";
        }
        std::cout << "Enter another expression or 'q' to quit: ";
        std::getline(std::cin, input);
        if (input == "q") {
            std::cout << "Exiting program.\n";
            break;
        }
    }

    return 0;
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }

        stack<int> numbers;

        for (const auto& token : tokens) {
            if (isOperation(token)) {
                const string& operation = token;
                
                int secondNumber = numbers.top();
                numbers.pop();
                
                int firstNumber = numbers.top();
                numbers.pop();

                int result = performCalculation(firstNumber, secondNumber, operation);
                numbers.push(result);
            } else {
                numbers.push(getInt(token));
            }
        }

        return numbers.top();
    }

    int getInt(const string& str) {
        return stoi(str);
    }

    bool isOperation(const string& str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }

    int performCalculation(int firstNumber, int secondNumber, const string& operation) {
        if (operation == "+") {
            return firstNumber + secondNumber;
        } else if (operation == "-") {
            return firstNumber - secondNumber;
        } else if (operation == "*") {
            return firstNumber * secondNumber;
        } else if (operation == "/") {
            return firstNumber / secondNumber;
        }

        return -1;
    }
};


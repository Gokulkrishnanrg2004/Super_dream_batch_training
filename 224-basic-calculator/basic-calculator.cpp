class Solution {
public:
    int calculate(string s) 
    {
        stack<int> stk; // Stack to store intermediate results
        int result = 0; // Current result
        int sign = 1;   // Current sign (1 for positive, -1 for negative)
        int num = 0;    // Current number

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                // Build the number
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                // Add the current number to the result with the current sign
                result += sign * num;
                num = 0; // Reset the current number
                sign = 1; // Update sign for the next number
            } else if (c == '-') {
                // Subtract the current number from the result
                result += sign * num;
                num = 0;
                sign = -1; // Update sign for the next number
            } else if (c == '(') {
                // Push the current result and sign onto the stack
                stk.push(result);
                stk.push(sign);
                result = 0;  // Reset result for the new sub-expression
                sign = 1;    // Reset sign
            } else if (c == ')') {
                // Add the current number to the result
                result += sign * num;
                num = 0;

                // Pop the sign and previous result from the stack
                result *= stk.top(); // Multiply by the sign before the parenthesis
                stk.pop();
                result += stk.top(); // Add the result before the parenthesis
                stk.pop();
            }
        }

        // Add the last number to the result
        result += sign * num;

        return result;
    }
};
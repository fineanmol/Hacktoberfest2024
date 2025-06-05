#include <stdio.h>
#include <stdlib.h>

int parseExpression(char **expr);

int parseNumber(char **expr) {
    int result = 0;
    while (**expr >= '0' && **expr <= '9') {
        result = result * 10 + (**expr - '0');
        (*expr)++;
    }
    return result;
}

int parseTerm(char **expr) {
    int left = parseNumber(expr);

    while (**expr == '*' || **expr == '/') {
        char op = **expr;
        (*expr)++;

        int right = parseNumber(expr);

        if (op == '*') {
            left *= right;
        } else {
            if (right != 0) {
                left /= right;
            } else {
                printf("Division by zero is not allowed.\n");
                exit(1);
            }
        }
    }

    return left;
}

int parseExpression(char **expr) {
    int left = parseTerm(expr);

    while (**expr == '+' || **expr == '-') {
        char op = **expr;
        (*expr)++;

        int right = parseTerm(expr);

        if (op == '+') {
            left += right;
        } else {
            left -= right;
        }
    }

    return left;
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    char *expr = expression;
    int result = parseExpression(&expr);

    printf("Result: %d\n", result);

    return 0;
}

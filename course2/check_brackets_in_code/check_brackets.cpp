#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(int type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket *newB = new Bracket(next, position);
            opening_brackets_stack.push(*newB);
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty()) {
              std::cout << position + 1;
              return 0;
            }
            Bracket compare = opening_brackets_stack.top();
            if (!compare.Matchc(next)) {
              std::cout << position + 1;
              return 0;
            } else {
              opening_brackets_stack.pop();
            }
        }
    }

    if (opening_brackets_stack.empty()) {
      std::cout << "Success";
    } else {
      std::cout << opening_brackets_stack.top().position + 1;
    }

    return 0;
}

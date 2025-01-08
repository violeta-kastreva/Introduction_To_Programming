#include <iostream>
#include <cstring>

const std::size_t MAX_CAPACITY = 2048+1;

bool isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

void removeRepeatingSpaces(char* s) {
    int n = strlen(s);
    int newIndex = 0, originalIndex = 0;

    for (; originalIndex < n; ) {
        if (!isWhiteSpace(s[originalIndex])) {
            s[newIndex] = s[originalIndex];
            newIndex++;
            originalIndex++;
            continue;
        }

        for (; isWhiteSpace(s[originalIndex]); originalIndex++) {

        }
        s[newIndex] = ' ';
        newIndex++;
    }

    s[newIndex] = '\0';
}

int main () {
    // Line by line (takes the delimiter out of the stream but does not put it inside the buffer)
    char buffer[MAX_CAPACITY], str[MAX_CAPACITY] = {'\0',};
    while (std::cin.getline(buffer, MAX_CAPACITY)) {
        strcat(str, buffer);
    }
    
    removeRepeatingSpaces(str);
    std::cout << str << '\n';

    return 0;
}
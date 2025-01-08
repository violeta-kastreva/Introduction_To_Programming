#include <iostream>
#include <cstring>

const std::size_t MAX_CAPACITY = 2048+1;

bool isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int wordCount(const char* s) {
    // Trim leading spaces
    for (; isWhiteSpace(s[0]);) {
        s++;
    }

    // Trim trailing spaces
    int n = strlen(s);
    for (int i = n-1; i >= 0 && isWhiteSpace(s[i]); i--) {
        n--;
    }


    int res = 0;
    for (int i = 0; i < n; i++) {
        if (!isWhiteSpace(s[i])) {
            continue;
        }

        // isWhiteSpace
        for (; isWhiteSpace(s[i]); i++) {

        }

        res++;
    }

    return res + 1;
}

int main () {
    // Line by line (takes the delimiter out of the stream but does not put it inside the buffer)
    char buffer[MAX_CAPACITY], str[MAX_CAPACITY] = {'\0',};
    while (std::cin.getline(buffer, MAX_CAPACITY)) {
        strcat(str, buffer);
    }
    
    std::cout << "words: " << wordCount(str) << '\n';

    return 0;
}
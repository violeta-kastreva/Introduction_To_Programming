#include <iostream>
#include <cstring>

const std::size_t MAX_CAPACITY = 2048+1;

bool isWhiteSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

bool hasPrefix(const char* s1, const char* s2, int n) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n) {
        i++;
    }

    return i >= n;
}

void removeAllOccurances(char* s, const char* w) {
    int n = strlen(s);
    int m = strlen(w);

    int wi = 0;
    for (int i = 0; i <= n; ) {
        if (!hasPrefix(s+i, w, m)) {
            s[wi++] = s[i++];
            continue;
        }

        // Remove
        i += m;
    }
}

int main () {
    // Line by line (takes the delimiter out of the stream but does not put it inside the buffer)
    char s[] = "My name is Gosho. Gosho is from Varna. Gosho is 14-year-old boy.";
    const char *w = "Gosho";
    
    removeAllOccurances(s, w);
    std::cout << s << '\n';

    return 0;
}
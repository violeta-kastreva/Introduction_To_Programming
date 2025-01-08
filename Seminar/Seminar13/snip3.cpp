#include <iostream>
#include <cstring>

const std::size_t MAX_CAPACITY = 1024;

int mystrcmp(const char* s1, const char* s2) {
    int i = 0, j = 0;
    while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j]) {
        i++;
        j++;
    }

    return s1[i] - s2[j];
}

std::size_t mystrlen(const char* s) {
    std::size_t i = 0;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}

void swap(char* str1, char* str2);

int main ()
{
    char str1[MAX_CAPACITY] = "Pesho";
    char str2[MAX_CAPACITY] = "Lyubo";

    std::cout << mystrlen(str1) << std::endl;
    std::cout << mystrcmp(str1, str2) << std::endl;
    std::cout << mystrcmp(str1, str1) << std::endl;
    std::cout << mystrcmp(str2, str1) << std::endl;

    std::cout << str1 << " " << str2 << std::endl;
    swap(str1, str2);
    std::cout << str1 << " " << str2 << std::endl;

    char str3[MAX_CAPACITY] = {'\0', };
    strcat(str3, "My favourite ");
    strcat(str3, "tennis player ");
    strcat(str3, "is Grigor Dimitrov");

    std::cout << str3 << std::endl;

    return 0;
}

void swap(char* str1, char* str2)
{
    char temp[MAX_CAPACITY];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
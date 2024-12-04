#include <iostream>
#include <fstream>


int main() {
    // Initialization
    std::ifstream in("test.txt");

    // Check if the stream is good
    if (!in) {
        std::cerr << "Could not open a file.";
        return 1;
    }

    // Using the stream
    char buffer[1024];

    // Delimiter reading (takes the delimiter out of the stream but does not put it inside the buffer)
    // while (in.getline(buffer, 1024, ' ')) {
    //     std::cout << buffer << '\n';
    // }

    // Line by line (takes the delimiter out of the stream but does not put it inside the buffer)
    // while (in.getline(buffer, 1024)) {
    //     std::cout << buffer << '\n';
    // }

    // Line by line (takes the delimiter out of the stream but does not put it inside the buffer)
    // while (in.getline(buffer, 1024)) {
    //     std::cout << buffer << '\n';
    // }

    // get does not take the delimiter form the stream
    // while (in.get(buffer, 1024, '\n')) {
    //     in.get();
    //     std::cout << buffer << '\n';
    // }

    // Word by word
    // while (in >> buffer) {
    //     std::cout << buffer << '\n';
    //     // for (int i = 0; buffer[i] != '\0'; i++) {
    //     //     std::cout << buffer[i];
    //     // }
    //     // std::cout << '\n';
    // }

    // Char by char
    char c;
    while (in.get(c)) {
        std::cout << c;
    }

    // Closing the stream
    in.close();

    return 0;
}
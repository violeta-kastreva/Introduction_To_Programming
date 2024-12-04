#include <iostream>
#include <fstream>


int main() {
    // Initialization
    std::ifstream in("test.txt");
    std::ofstream out("output.txt", std::ios::app | std::ios::ate);

    // Check if the stream is good
    if (!in) {
        std::cerr << "Could not open a file for reading.";
        return 1;
    }

    // Check if the stream is good
    if (!out) {
        std::cerr << "Could not open a file for writing.";
        in.close();

        return 1;
    }

    char buffer[1024];
    while (in.getline(buffer, 1024)) {
        out << buffer << '\n';
    }

    // Closing the stream
    in.close();
    out.close();

    return 0;
}
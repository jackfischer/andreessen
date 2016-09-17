#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file;
    file.open("html.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout<<line<<'\n';
    }
    file.close();
}

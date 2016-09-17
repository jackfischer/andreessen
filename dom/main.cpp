#include "Parser.h"
#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file;
    file.open("html.txt");
    std::string html = "";
    std::string line;
    while (std::getline(file, line)) {
        html += line + "\n";
    }
    file.close();

    Parser p;
    p.parseHTML(html);
}

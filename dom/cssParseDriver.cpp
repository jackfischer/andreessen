#include "Parser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>


int main() {
    std::ifstream t("temp.css");
    std::string str((std::istreambuf_iterator<char>(t)),
            std::istreambuf_iterator<char>());

    Parser parser;
    auto css = parser.parseCSS(str);
    
    std::cout << css["yellow-block"]["display"] <<std::endl;
}

#include <iostream>

#include "http/Http.h"
#include "dom/Parser.h"
#include "layout/LayoutEngine.h"


int main() {

    Http http;
    std::string doc = http.entryPoint("andreessen.jackfischer.me");

    Parser parser;
    parser.parseHTML(doc);
    
    LayoutEngine layout(parser.root, parser.css);
    layout.startLayout();
    std::cout << layout.toString();
    
}

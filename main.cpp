#include <iostream>

#include "http/Http.h"
#include "dom/Parser.h"
#include "layout/LayoutEngine.h"


int main() {
    Http http;
    std::string doc = http.makeRequest("andreessen.jackfischer.me");
    
    std::cout << doc <<std::endl;

    //Parser parser;
    //Node* root = parser.parseHTML(doc);
    
    //LayoutEngine layout(root);
    //layout.startLayout();
    
}

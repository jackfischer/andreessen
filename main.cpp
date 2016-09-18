#include <iostream>

#include "http/Http.h"
#include "dom/Parser.h"
#include "layout/LayoutEngine.h"
#include "render/render.h"


// int main(int argc, char **argv) {
int startApp() {

    Http http;
    std::string doc = http.entryPoint("andreessen.jackfischer.me");

    Parser parser;
    parser.parseHTML(doc);
   
    parser.root->print("","");
    std::cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    std::map< std::string, std::map<std::string, std::string> > css = parser.css;
    for (auto iter : css) {
        std::map<std::string, std::string> s = iter.second;
        for (auto i : s) {
            std::cout<<"F: "<<iter.first<<" S: "<<i.first<<" E: "<<i.second<<'\n';
        }
    }
    std::cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    LayoutEngine layout(parser.root, parser.css);
    layout.startLayout();
    // startBrowser(argc, argv, layout.toLayoutData());
    loadLayoutData(layout.toLayoutData());
    // std::cout << layout.toString();

    // for (auto ld : layout.toLayoutData()) {
    //     std::cout << ld.voff << std::endl;
    //     std::cout << ld.hoff << std::endl;
    //     std::cout << ld.width << std::endl;
    //     std::cout << ld.height << std::endl;
    //     std::cout << ld.bottomColor[0] << std::endl;
    //     std::cout << ld.bottomColor[1] << std::endl;
    //     std::cout << ld.bottomColor[2] << std::endl;
    //     std::cout << ld.topColor[0] << std::endl;
    //     std::cout << ld.topColor[1] << std::endl;
    //     std::cout << ld.topColor[2] << std::endl << std::endl;
    //     break;
    //     // std::cout << ld.text << std::endl;
    //     // std::cout << ld.topColor[0] << std::endl;
    //     // std::cout << ld.topColor[1] << std::endl;
    //     // std::cout << ld.topColor[2] << std::endl;
    // }

    return 0;
}

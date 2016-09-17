#include "Http.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::string url = argv[1];
    Http h;
    h.connect(url);
    std::string req = "GET /index.html HTTP/1.1\nHost: "+url+"\n\n";
    std::string response = h.makeRequest(req.c_str());
}

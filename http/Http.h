#include <string>

#ifndef HTTP_H
#define HTTP_H

class Http {
    public:
        // variables
        int sck;
        // functions
        void connect(std::string url);
        std::string makeRequest(const char *req);
        std::string dropHeaders(std::string);
        std::string entryPoint(std::string url);
};

#endif


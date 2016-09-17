#include "Node.h"
#include <string>

#ifndef PARSER_H
#define PARSER_H

class Parser {
    public:
        Node * parseHTML(std::string html);
};

#endif

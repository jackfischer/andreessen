#include "Node.h"
#include <map>
#include <string>

#ifndef PARSER_H
#define PARSER_H

class Parser {
    public:
        Node *root;
        std::map<std::string, std::map<std::string, std::string> > css;
        Node * parseHTML(std::string html);
        std::map<std::string, std::map<std::string, std::string> > parseCSS(std::string in);
        std::string findCSS(Node *r);
        std::string removeWS(std::string s);
        void deleteStyle(Node *n);
        Node * findNode(Node *n, std::string name);
};

#endif

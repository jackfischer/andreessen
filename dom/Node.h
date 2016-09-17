#include <vector>
#include <map>
#include <string>
#include "../layout/LayoutData.h"

#ifndef NODE_H
#define NODE_H

class Node {
    public:
        //Data members
        Node *parent;
        std::vector<Node *> children;
        std::string name;
        std::map<std::string, std::string> attributes;
        std::string textData;
        LayoutData ld;
        
        //functions
        Node();
        Node(Node *p);
        void addChild(Node *n);
        void giveParent(Node *p);
        void addAttribute(std::string key, std::string data);
        void print(std::string before, std::string beforeLast);
};

#endif

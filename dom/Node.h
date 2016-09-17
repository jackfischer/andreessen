#include <vector>
#include <map>
#include <string>
#ifndef NODE_H
#define NODE_H
#include "../layout/LayoutData.h"

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
};
#endif

#include <vector>
#include <map>
#include <string>
#ifndef NODE_H
#define NODE_H
class Node {
    public:
        // variables
        Node *parent;
        std::vector<Node *> children;
        std::string name;
        std::map<std::string, std::string> attributes;
        std::string textData;
        //functions
        Node();
        Node(Node *p);
        void addChild(Node *n);
        void giveParent(Node *p);
        void addAttribute(std::string key, std::string data);
};
#endif

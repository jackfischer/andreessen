#include "Node.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

Node::Node() {
    Node::parent = 0;
}
Node::Node(Node *p) {
    Node::parent = p;
}
void Node::addChild(Node *n) {
    Node::children.push_back(n);
}
void Node::giveParent(Node *p) {
    Node::parent = p;
}
void Node::addAttribute(std::string key, std::string data) {
    Node::attributes[key] = data;
}
void Node::print(std::string before, std::string beforeLast) {
    int numChildren = Node::children.size();
    std::cout<<Node::name<<" | ";
    for (auto iter : Node::attributes) {
        std::cout<<"key: "<<iter.first<<" = "<<iter.second<<"\t";
    }
    std::cout<<textData<<std::endl;
    // bool first = (before.compare("") == 0) ? true : false;
    std::cout<<numChildren<<"\n";
    for (int i = 0; i < numChildren; i++) {
        if (i != numChildren - 1) {
            std::cout<<"|-->";
            before+="|   ";
            Node::children[i]->print(before, beforeLast);
        } else {
            std::cout<<beforeLast<<"`-->";
            beforeLast += "    ";
            Node::children[i]->print(before, beforeLast);
        }
    }
}

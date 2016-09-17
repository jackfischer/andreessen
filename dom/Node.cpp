#include "Node.h"
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

#include <vector>
#include <map>
#include <string>

class Node {
    public:
        // variables
        Node *parent;
        std::vector<Node *> children;
        std::string name;
        std::map<std::string, std::string> data;
        //functions
        Node();
        Node(Node *p);
        void addChild(Node *n);
        void giveParent(Node *p);
};

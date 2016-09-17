#include "Parser.h"
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>

std::vector<Node*> DFS(Node * root) {
    std::stack<Node*> stack;
    stack.push(root);
    std::vector<Node*> result;
    while (!stack.empty()) {
        Node* n = stack.top();
        stack.pop();
        result.push_back(n);
        for (int i = n->children.size() - 1; i >=0; i--)
            stack.push(n->children[i]);
        }
    return result;
}

int main() {
    std::ifstream file;
    file.open("html.txt");
    std::string html = "";
    std::string line;
    while (std::getline(file, line)) {
        html += line + "\n";
    }
    file.close();

    Parser p;
    Node *hi = p.parseHTML(html);
    std::vector<Node *> ns = DFS(hi);
    for (int i = 0; i < ns.size(); i++) {
        std::cout<<ns[i]->name<<"\n";
    }
}

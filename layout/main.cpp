#include "../DOM/Node.h"
#include "Layout.cpp"
#include <map>
#include <string>

/*
 * dev environment for building layout engine in parallel with parser
 * and dom creation
 */

int main() {
    std::map<std::string, std::map<std::string, std::string>> styles;
    styles["yellow-block"]["background-color"] = "yellow";
    styles["yellow-block"]["display"] = "block";
    styles["yellow-block"]["height"] = "50px";
    styles["yellow-block"]["width"] = "200px";
    styles["yellow-block"]["margin-bottom"] = "20px";
    styles["yellow-block"]["margin-left"] = "20px";
    styles["blue-inline"]["display"] = "inline";
    styles["blue-inline"]["background-color"] = "blue";


    Node root;
    root.name = "body";

    Node* y1 = new Node();
    y1->name = "div";
    y1->data.insert("class", "yellow-block");
    Node* b1 = new Node();
    b1->name = "div";
    b1->data.insert("class", "blue-inline");
    Node* b2 = new Node();
    b2->name = "div";
    b2->data.insert("class", "blue-inline");
    Node* y2 = new Node();
    y2->name = "div";
    y2->data.insert("class", "yellow-block");
    Node* b3 = new Node();
    b3->name = "div";
    b3->data.insert("class", "blue-inline");
    Node* b4 = new Node();
    b4->name = "div";
    b4->data.insert("class", "blue-inline");

    root.addChild(y1);
    root.addChild(b1);
    root.addChild(b2);
    root.addChild(y2);
    root.children[3]->addChild(b3);
    root.children[3]->addChild(b4);

    performLayout(root, styles);
}



#include "../DOM/Node.h"
#include "LayoutEngine.h"
//#include <map>
//#include <string>
#include <iostream>

/*
 * dev environment for building layout engine in parallel with parser
 * and dom creation
 */

int main() {
    //std::map<std::string, std::map<std::string, std::string>> styles;
    css styles;

    styles["yellow-block"]["background-color"] = "yellow";
    styles["yellow-block"]["display"] = "block";
    styles["yellow-block"]["height"] = "50px";
    styles["yellow-block"]["width"] = "200px";
    styles["yellow-block"]["margin-bottom"] = "20px";
    styles["yellow-block"]["margin-left"] = "20px";
    styles["blue-inline"]["display"] = "inline";
    styles["blue-inline"]["background-color"] = "blue";

Node* root = new Node(); root->name = "body"; root->addAttribute("id", "body");

    Node* y1 = new Node();
    y1->name = "div";
    y1->addAttribute("class", "yellow-block");
    y1->addAttribute("id", "y1");
    Node* b1 = new Node();
    b1->name = "div";
    b1->addAttribute("class", "blue-inline");
    b1->addAttribute("id", "b1");
    Node* b2 = new Node();
    b2->name = "div";
    b2->addAttribute("class", "blue-inline");
    b2->addAttribute("id", "b2");
    Node* y2 = new Node();
    y2->name = "div";
    y2->addAttribute("class", "yellow-block");
    y2->addAttribute("id", "y2");
    Node* b3 = new Node();
    b3->name = "div";
    b3->addAttribute("class", "blue-inline");
    b3->addAttribute("id", "b3");
    Node* b4 = new Node();
    b4->name = "div";
    b4->addAttribute("class", "blue-inline");
    b4->addAttribute("id", "b4");

    root->addChild(y1);
    root->addChild(b1);
    root->addChild(b2);
    root->addChild(y2);
    root->children[3]->addChild(b3);
    root->children[3]->addChild(b4);


    LayoutEngine le(root, styles);
    le.startLayout();
    std::cout << le.toString();
}



#include "Parser.h"
#include <sstream>
#include <iostream>
#include "Node.h"
#include <string>

Node * Parser::parseHTML(std::string html) {
    // std::stringstream ss;
    // ss<<html;
    std::cout<<html;
    Node *parent = 0;
    Node *currentNode;
    int state = 0;
    bool run = true;
    std::string holder;
    char lastChar;
    int charNum = 0;
    char currentChar;
    std::string keyHolder;
    bool equalSign = false;
    bool tagName = false;
    bool inbetweenTag = false;
    while (run) {
        std::cout<<html[charNum]<<"\n";
        // determine state, if no state change required nothing happens
        lastChar = currentChar;
        currentChar = html[charNum];
        if (state != 1) {
            if (currentChar == '\t' || currentChar == '\r' || currentChar == '\n' || (currentChar == ' ' && state != 0)) { state = -1;}
        }
        if (lastChar == '<' && currentChar != '/') {
            state = 0;
            tagName = true;
        }   
        if ((currentChar != '<' || currentChar != '>' || currentChar != '/') && state == 1) {state = 1;}
        if (currentChar == '/' && lastChar == '<') {state = 2;}
        if (currentChar == '<' || currentChar == '>') {state = -1;} // drop character
        // execute state
        switch (state) {
            case 0: { // IN TAG
                if (std::isalpha(currentChar) && currentChar != ' '/* && currentChar != '\"'*/) {
                    holder += currentChar;
                }
                if (parent == 0 && lastChar == '<') {
                    Node *n = new Node();
                    currentNode = n;
                } else if (lastChar == '<') {
                    Node *n = new Node(currentNode);
                    currentNode->addChild(n);
                    currentNode = n;
                }
                if ((currentChar == ' ' || currentChar == '>')  && !tagName) {
                    currentNode->name = holder;
                    holder = "";
                } else if ((currentChar == ' ' || currentChar == '>') && equalSign) {
                    currentNode->addAttribute(keyHolder, holder);
                    keyHolder = "";
                    holder = "";
                    equalSign = false;
                }
                if (currentChar == '=') {
                    equalSign = true;
                    keyHolder = holder;
                    holder = "";
                }
                break;
            }
            case 1: { // BETWEEN TAGS
                holder += currentChar;
                inbetweenTag = true;
                break;
            }
            case 2: { // END TAG
                if (inbetweenTag) {
                    Node *n = new Node(currentNode);
                    currentNode->addChild(n);
                    n->name = "text";
                    n->textData = holder;
                    holder = "";
                }
                // if (std::isalpha(currentChar) && currentChar != ' ') {
                //     holder += currentChar;
                // }
                if (currentChar == '>') {
                    currentNode = currentNode->parent;
                }
                break;
            }
            default: // Drop character
                break;
        }
        charNum++;
        if (charNum == html.length()) run = false;
    }
    parent->print("","");
    return parent;
}

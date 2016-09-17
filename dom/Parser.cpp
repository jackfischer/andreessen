#include "Parser.h"
#include <sstream>
#include <iostream>
#include "Node.h"
#include <string>

Node * Parser::parseHTML(std::string html) {
    std::cout<<html;
    Node *currentNode;
    Node *parent = 0;
    bool equalSign = false;
    bool inbetweenTag = false;
    bool run = true;
    bool tagName = false;
    char currentChar = html[0];
    char lastChar;
    int charNum = 1;
    int state = 0;
    std::string holder;
    std::string keyHolder;
    while (run) {
        // determine state, if no state change required nothing happens 
        lastChar = currentChar;
        currentChar = html[charNum];
        
        if (lastChar == '<') tagName = false;

        // if ((currentChar != '<' || currentChar != '>' || currentChar != '/') && state == 1) state = 1;
        if (lastChar == '<' && currentChar != '/') state = 0;
        if (lastChar == '>' && currentChar != '<') state = 1;
        if (currentChar == '/' && lastChar == '<') state = 2;
        // execute state
        // std::cout<<"equal Bool: "<<equalSign<<" InTag bool: "<<inbetweenTag<<" TagName bool: "<<tagName<<" current Char: "<<currentChar<<" l char: "<<lastChar<<" state: "<<state<<"\n";
        switch (state) {
            case 0: { // IN TAG
                if ((currentChar == '-' || std::isalpha(currentChar)) && currentChar != ' '/* && currentChar != '\"'*/) {
                    holder += currentChar;
                }
                if (parent == 0 && lastChar == '<') {
                    Node *n = new Node();
                    parent = n;
                    currentNode = n;
                } else if (lastChar == '<') {
                    Node *n = new Node(currentNode);
                    currentNode->addChild(n);
                    currentNode = n;
                }
                if ((currentChar == ' ' || currentChar == '>')  && !tagName) {
                    currentNode->name = holder;
                    std::cout<<holder<<" -name\n";
                    holder = "";
                    tagName = true;
                }
                if (holder.size() != 0 && (currentChar == ' ' || currentChar == '>') && equalSign) {
                    currentNode->addAttribute(keyHolder, holder);
                    std::cout<<holder<<" -data\n";
                    keyHolder = "";
                    holder = "";
                    equalSign = false;
                }
                if (currentChar == '=') {
                    std::cout<<holder<<" -key\n";
                    equalSign = true;
                    keyHolder = holder;
                    holder = "";
                }
                break;
            }
            case 1: { // BETWEEN TAGS
                if (currentChar == '<') {
                    holder = "";
                    state = 2;
                    break;
                }
                holder += currentChar;
                inbetweenTag = true;
                break;
            }
            case 2: { // END TAG
                if (inbetweenTag && holder != "") {
                    int posB;
                    int posE;
                    for (int i = 0; i < holder.size(); i++) {
                        if (!std::iswspace(holder[i])) {
                            posB = i;
                            break;
                        }
                    }
                    for (int i = holder.size()-1; i >=0; i++) {
                        if (!std::iswspace(holder[i])) {
                            posE = i+1;
                            break;
                        }
                    }
                    bool junk = (posE <= posB) ? true : false;
                    if (!junk) {
                        holder = holder.substr(posB, posE);
                        std::cout<<holder<<"~~~NOT JUNK~~~\n";
                        Node *n = new Node(currentNode);
                        currentNode->addChild(n);
                        n->name = "text";
                        n->textData = holder;
                        holder = "";
                        inbetweenTag = false;
                    } else {
                        holder = "";
                        inbetweenTag = false;
                    }
                }
                // if (std::isalpha(currentChar) && currentChar != ' ') {
                //     holder += currentChar;
                // }
                if (currentChar == '>') {
                    if (currentNode == parent) break;
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
    // parent->print("","");
    return parent;
}

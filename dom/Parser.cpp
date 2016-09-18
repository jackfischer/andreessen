#include "Parser.h"
#include <vector>
#include <sstream>
#include <iostream>
#include "Node.h"
#include <string>

Node * Parser::parseHTML(std::string html) {
    Node *currentNode;
    Node *parent = 0;
    bool equalSign = false;
    bool inbetweenTag = false;
    bool run = true;
    bool tagName = false;
    char currentChar = html[0];
    char lastChar;
    uint charNum = 1;
    int state = 0;
    std::string holder;
    std::string keyHolder;
    while (run) {
        // determine state, if no state change required nothing happens 
        lastChar = currentChar;
        currentChar = html[charNum];

        if (lastChar == '<') tagName = false;

        if (lastChar == '<' && currentChar != '/') state = 0;
        if (lastChar == '>' && currentChar != '<') state = 1;
        if (currentChar == '/' && lastChar == '<') state = 2;
        // execute state
        // std::cout<<"equal Bool: "<<equalSign<<" InTag bool: "<<inbetweenTag<<" TagName bool: "<<tagName<<" current Char: "<<currentChar<<" l char: "<<lastChar<<" state: "<<state<<"\n";
        switch (state) {
            case 0: { // IN TAG
                        if ((currentChar == '-' || std::isalpha(currentChar)) && currentChar != ' ') {
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
                            holder = removeWS(holder);
                            currentNode->name = holder;
                            // std::cout<<holder<<" -name\n";
                            holder = "";
                            tagName = true;
                        }
                        if (holder.size() != 0 && (currentChar == ' ' || currentChar == '>') && equalSign) {
                            currentNode->addAttribute(keyHolder, holder);
                            // std::cout<<holder<<" -data\n";
                            keyHolder = "";
                            holder = "";
                            equalSign = false;
                        }
                        if (currentChar == '=') {
                            // std::cout<<holder<<" -key\n";
                            equalSign = true;
                            keyHolder = holder;
                            holder = "";
                        }
                        break;
                    }
            case 1: { // BETWEEN TAGS
                        if (currentChar == '<') {
                            state = 2;
                            break;
                        }
                        holder += currentChar;
                        inbetweenTag = true;
                        break;
                    }
            case 2: { // END TAG
                        if (inbetweenTag) {
                            int posB;
                            int posE;
                            for (uint i = 0; i < holder.size(); i++) {
                                if (!std::iswspace(holder[i])) {
                                    posB = i;
                                    break;
                                } else {
                                    posB = i;
                                }
                            }
                            for (int i = holder.size()-1; i >=0; i--) {
                                if (!std::iswspace(holder[i])) {
                                    posE = i + 1;
                                    break;
                                } else {
                                    posE = i;
                                }
                            }
                            bool junk = (posE <= posB) ? true : false;
                            if (!junk) {
                                holder = holder.substr(posB, posE);
                                currentNode->textData = holder;
                                inbetweenTag = false;
                            } else {
                                inbetweenTag = false;
                            }
                            holder = "";
                        }
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
    css = parseCSS(findCSS(parent));
    root = parent;
    deleteStyle(root);
    return parent;
}

Node * Parser::findNode(Node *n, std::string name) {
    if (n->name.compare(name) == 0) {
        return n;
    } else {
        for (uint i = 0; i < n->children.size(); i++) {
            return findNode(n->children[i], name);
        }
    }
    return 0;
}

void Parser::deleteStyle(Node *n) {
    if (n->name.compare("style") && n->parent != 0) {
        Node *p = n->parent;
        for (uint i = 0; i < p->children.size(); i++) {
            if (p->children[i] == n) {
                p->children.erase(p->children.begin() + i);
            }
        }
    } else {
        for (uint i = 0; i < n->children.size(); i++) {
            deleteStyle(n->children[i]);
        }
    }
}

std::string Parser::findCSS(Node *r) {
    if (r->name.compare("style") == 0) {
        return r->textData;
    } else if (r->children.size() > 1) {
        for (uint i = 1; i < r->children.size(); i++) {
            return findCSS(r->children[i-1]) + findCSS(r->children[i]);
        }
    } else if (r->children.size() == 1) {
        return findCSS(r->children[0]);
    } else {
        return "";
    }
}

std::map<std::string, std::map<std::string, std::string> > Parser::parseCSS(std::string in) {
    in.erase(std::remove(in.begin(), in.end(), '\n'), in.end());
    in.erase(std::remove(in.begin(), in.end(), ' '), in.end());
    // std::cout <<in<<std::endl;
    std::map<std::string, std::map<std::string, std::string> > cssMap;

    int state = 0;
    std::string clss;
    std::string field;
    std::string value;

    for (char c : in) {
        if (state == 0 && c == '.') {
            state = 1;
        }
        else if (state == 1 && c != '{') {
            clss.push_back(c);
        }
        else if (state == 1 && c == '{') {
            state = 2;
        }
        else if (state == 2 && c != ':' && c != '}') {
            field.push_back(c);
        }
        else if (state == 2 && c == ':') {
            state = 3;
        }
        else if (state == 2 && c == '}') {
            clss = "";
            state = 0;
        }
        else if (state == 3 && c != ';') {
            value.push_back(c);
        }
        else if (state == 3 && c == ';') {
            std::cout <<clss<<std::endl;
            std::cout <<field<<std::endl;
            std::cout <<value<<std::endl <<std::endl;
            cssMap[clss][field] = value;
            field = "";
            value = "";
            state = 2;
        }

    }
    return cssMap;
}

std::string Parser::removeWS(std::string s) {
    int posB;
    int posE;
    for (uint i = 0; i < s.size(); i++) {
        if (!std::iswspace(s[i])) {
            posB = i;
            break;
        } else {
            posB = i;
        }
    }
    for (int i = s.size()-1; i >=0; i--) {
        if (!std::iswspace(s[i])) {
            posE = i + 1;
            break;
        } else {
            posE = i;
        }
    }
    return s.substr(posB, posE);
}

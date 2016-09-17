#include "Parser.h"
#include <sstream>
#include <iostream>
#include "Node.h"
#include <string>

Node * Parser::parseHTML(std::string html) {
    // std::stringstream ss;
    // ss<<html;
    std::cout<<html;
    html.erase( std::remove_if( html.begin(), html.end(), ::isspace ), html.end() );
    Node *parent;
    Node *currentNode;
    int state = 0;
    bool run = false;
    std::string holder;
    char lastChar;
    int charNum = 0;
    char currentChar;
    while (run) {
        // determine state, if no state change required nothing happens
        lastChar = currentChar;
        currentChar = html[charNum];
        if (lastChar == '<' && currentChar != '/') {state = 0;}   
        if ((currentChar != '<' || currentChar != '>' || currentChar != '/') && state == 1) {state = 1;}
        if (currentChar == '/' && lastChar == '<') {state = 2;}
        if (currentChar == '<' || currentChar == '>') {state = -1;} // drop character
        // execute state
        switch (state) {
            case 0: { // IN TAG
                break;
            }
            case 1: { // BETWEEN TAGS
                break;
            }
            case 2: { // END TAG
                break;
            }
            default: // Drop character
                break;
        }
    }
}

#ifndef LAYOUTENGINE_H
#define LAYOUTENGINE_H

#include "../DOM/Node.h"
#include <map>
#include <string>
#include <stack>

/*
 * Layout Engine
 */

typedef std::map<std::string, std::map<std::string, std::string> > css;

class LayoutEngine {
    public:
        const int BROWSER_WIDTH = 960;
        Node* root;
        css style;
        LayoutEngine(Node* root, css style) : root(root), style(style) {}

        std::string toString();
        void startLayout();
        LayoutData layoutText(std::string);

    private:
        void layout(Node* n, int voff, int hoff);
        int parsePixels(std::string);
        

};


#endif

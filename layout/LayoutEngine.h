#ifndef LAYOUTENGINE_H
#define LAYOUTENGINE_H

#include "../dom/Node.h"
#include <map>
#include <string>
#include <stack>
#include <set>

/*
 * Layout Engine
 */

class LayoutEngine {
  using css = std::map<std::string, std::map<std::string, std::string>>;
    public:
        const int BROWSER_WIDTH = 960;
        Node* root;
        css style;
        LayoutEngine(Node* root, css style) : root(root), style(style) {}


        std::string toString();
        void startLayout();
        std::vector<LayoutData> toLayoutData();

    private:
        LayoutData layoutText(std::string);
        void layout(Node* n, int voff, int hoff);
        int parsePixels(std::string);
        std::vector<Node*> DFS();
        std::set<std::string> blocks = {"img", "div", "body"};

};


#endif

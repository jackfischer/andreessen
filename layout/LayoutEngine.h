#ifndef LAYOUTENGINE_H
#define LAYOUTENGINE_H

#include "../DOM/Node.h"
#include <map>

/*
 * Layout Engine
 */

typedef std::map<std::string, std::map<std::string, std::string>> css;

class LayoutEngine {
    public:
        css style;
        Node root;

        LayoutEngine(css style, Node root);
        void performLayout();

};


#endif

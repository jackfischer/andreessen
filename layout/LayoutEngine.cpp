#include "LayoutEngine.h"
#include <iostream>
/*
 * Layout Engine
 */

std::string LayoutEngine::toString() {
    std::string result = ""; //feel like this isnt right
    std::stack<Node*> stack;
    stack.push(root);
    while (!stack.empty()) {
        Node* n = stack.top();
        stack.pop();
        //result.append(n->name);
        result.append(n->attributes["id"]);
        result.append("\n");
        for (int i = n->children.size() - 1; i >=0; i--)
            stack.push(n->children[i]);
    }
    return result;
}

void LayoutEngine::startLayout() {
    layout(root, root->ld.voff, root->ld.hoff);
    return;
}

void LayoutEngine::layout(Node* n, int voff_, int hoff_) {
    /*
     * base case: no children. persist dimensions into LD by style or text wrapping
     *  (margin stored implicitly as delta against voffset/hoffset)
     *
     * for each child
     *  call layout recursively
     *  
     * if style:
     *  persist into ld
     *  (margin gives offset, size gives width/height)
     * elif no style and block:
     *  sum sizes of children
     *  
     * elif no style and inline (assume leaf):
     *  perform text wrap, persist into ld
     *
     *
     */

    if (n->children.empty()) { //leaf
        n->ld.voff = voff_;
        n->ld.hoff = hoff_;
    }

}

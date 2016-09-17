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
        //result.append(n->attributes["id"]);
        auto t = n->attributes["id"] + " width: " + std::to_string(n->ld.width);
        result.append(t);
        result.append("\n");
        for (int i = n->children.size() - 1; i >=0; i--)
            stack.push(n->children[i]);
    }
    return result;
}

void LayoutEngine::startLayout() {
    //TODO: PREPROCESSING
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

    for (Node* c : n->children)
        layout(c, voff_, hoff_);
    //TODO Caller offsets!


    std::string cssClass = n->attributes["class"];

    /* LEAF */
    if (n->children.empty()) {
        /* Margin and inherit offsets */
        n->ld.voff = voff_;
        std::string mt = style[cssClass]["margin-top"];
        if (!mt.empty())
            n->ld.voff += parsePixels(mt);
        n->ld.hoff = hoff_;
        std::string ml = style[cssClass]["margin-left"];
        if (!ml.empty())
            n->ld.hoff += parsePixels(ml);
        
        /* Width and height based on style for blocks or text wrap for inline */
        if (n->ld.block) { //Block element
            std::string w = style[cssClass]["width"];
            std::cout << cssClass <<std::endl;
            if (!w.empty())
                n->ld.width += parsePixels(w);
            std::string h = style[cssClass]["height"];
            if (!h.empty())
                n->ld.height += parsePixels(w);
        } else { //Inline element
            LayoutData textLD = layoutText(n->textData);
            n->ld.width = textLD.width;
            n->ld.height = textLD.height;
        }
    }


}

LayoutData LayoutEngine::layoutText(std::string in) {
    in.length();
    LayoutData d;
    d.width = 100;
    d.height = 10;
    return d;
}

int LayoutEngine::parsePixels(std::string value) {
    value.pop_back();
    value.pop_back();
    int px = std::stoi(value);
    return px;
}




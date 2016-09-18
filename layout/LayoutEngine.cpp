#include "LayoutEngine.h"
#include <iostream>
#include <stdlib.h>

/*
 * Layout Engine
 */

std::vector<Node*> LayoutEngine::DFS() {
    std::stack<Node*> stack;
    stack.push(root);
    std::vector<Node*> result;
    while (!stack.empty()) {
        Node* n = stack.top();
        stack.pop();
        result.push_back(n);
        for (int i = n->children.size() - 1; i >=0; i--)
            stack.push(n->children[i]);
    }
    return result;
}

std::vector<LayoutData> LayoutEngine::toLayoutData() {
    std::map<std::string, int> colorNames = {
        {"yellow", 0},
        {"blue", 1},
        {"red", 2},
        {"black", 3},
        {"cyan", 4},
        {"green", 5},
        {"pink", 6}
    };

    int colorVals[7][3] = {
        {255,255,0},
        {0,0,255},
        {255,0,0},
        {0,0,0},
        {0,255,255},
        {0,128,0},
        {255,192,203}
    };

    std::vector<Node*> nodes = DFS();
    std::vector<LayoutData> result;
    for (Node* n : nodes) {
        std::string bgcolor = style[n->attributes["class"]]["background"];
        if (bgcolor.empty()) {
            bgcolor = style[n->attributes["class"]]["background-color"];
            bcopy(colorVals[colorNames[bgcolor]], n->ld.topColor, 3*sizeof(int));
            bcopy(colorVals[colorNames[bgcolor]], n->ld.bottomColor, 3*sizeof(int));
        } else {
            uint first = bgcolor.find("("); //first color
            uint second = bgcolor.find(" "); //second color
            uint end = bgcolor.size() - second - 2;
            std::string color1 = bgcolor.substr(first + 1, second-first-2);
            std::string color2 = bgcolor.substr(second+1, end);
            bcopy(colorVals[colorNames[color1]], n->ld.topColor, 3*sizeof(int));
            bcopy(colorVals[colorNames[color2]], n->ld.bottomColor, 3*sizeof(int));
        }
        result.push_back(n->ld);
    }
    return result;
}

std::string LayoutEngine::toString() {
    std::vector<Node*> nodes = DFS();
    std::string result;
    for (Node* n : nodes) {
        std::string temp = n->attributes["id"];
        temp += " hoff: " + std::to_string(n->ld.hoff);
        temp += " width: " + std::to_string(n->ld.width);
        temp += "\t";
        temp += " voff: " + std::to_string(n->ld.voff);
        temp += " height: " + std::to_string(n->ld.height);
        temp += "\n";
        result.append(temp);
    }
    return result;
}

void LayoutEngine::startLayout() {
    //TODO: PREPROCESSING
    std::vector<Node*> nodes = DFS();
    for (Node* n : nodes) {
        std::string display = style[n->attributes["class"]]["display"];
        if (display.empty()) //no display property set
            n->ld.block = ( blocks.find(n->name) != blocks.end() );
        else
            n->ld.block = (display.compare("block") == 0);
    }

    layout(root, root->ld.voff, root->ld.hoff);
    return;
}

void LayoutEngine::layout(Node* n, int voff_, int hoff_) {
    /*
     * Super-duper-formal layout algo:
     *
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

    std::string cssClass = n->attributes["class"];

    /* Margin and inherit offsets */
    n->ld.voff = voff_;
    std::string mt = style[cssClass]["margin-top"];
    if (!mt.empty())
        n->ld.voff += parsePixels(mt);
    n->ld.hoff = hoff_;
    std::string ml = style[cssClass]["margin-left"];
    if (!ml.empty())
        n->ld.hoff += parsePixels(ml);


    /* Calculate node width & height */
    if (n->ld.block) { //Assume either has set size or has children
        std::string w = style[cssClass]["width"];
        if (!w.empty()) { //width set in style
            n->ld.width += parsePixels(w);
        } else { //add up widths of children
            //for (Node* c : n->children) //only relevant to body; breaks on inline
            //    n->ld.width += c->ld.width;
        }
        std::string h = style[cssClass]["height"];
        if (!h.empty()) { //height set in style
            n->ld.height += parsePixels(h);
        } else { //add up heights of children
            //for (Node* c : n->children) //only relevant to body; breaks on inline
            //    n->ld.height += c->ld.height;
        }
    } else { //Inline! Assume there is text
        LayoutData textLD = layoutText(n->textData);
        n->ld.width = textLD.width;
        n->ld.height = textLD.height;
    }

    int vsib = n->ld.voff;
    bool prevWasInline = false;
    int eventualInlineHeight = 0;
    int runningInlineWidth = n->ld.hoff;
    for (Node* c : n->children) {
        if (c->ld.block) {
            if (prevWasInline) {
                vsib = eventualInlineHeight;
                eventualInlineHeight = 0;
                runningInlineWidth = n->ld.hoff;
                prevWasInline = false;
            }
            layout(c, vsib, n->ld.hoff);
            vsib = c->ld.hoff + c->ld.height;
        } else {
            prevWasInline = true;
            layout(c, vsib, runningInlineWidth);
            runningInlineWidth = c->ld.hoff + c->ld.width;
            eventualInlineHeight = c->ld.voff + c->ld.height;
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




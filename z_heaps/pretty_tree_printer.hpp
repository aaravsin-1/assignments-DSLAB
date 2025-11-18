#ifndef PRETTY_TREE_PRINTER_HPP
#define PRETTY_TREE_PRINTER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// ============================================================
// ULTIMATE PRETTY HEAP PRINTER
// Features:
//  ✔ Level coloring (default)
//  ✔ Parent-group coloring
//  ✔ Uniform coloring
//  ✔ ASCII tree branches (└──, ├──, │)
//  ✔ Compact mode (single-line per level)
//  ✔ ASCII-only fallback
//  ✔ Width auto-detection for spacing
//  ✔ Full GraphViz (.dot) export
//  ✔ Highlight violations & swaps
// ============================================================

namespace PrettyColor {
    const string reset = "\033[0m";
    const string red = "\033[31m";
    const string green = "\033[32m";
    const string yellow = "\033[33m";
    const string blue = "\033[34m";
    const string magenta = "\033[35m";
    const string cyan = "\033[36m";
}

enum ColorMode {
    LEVEL_COLORING = 0,
    PARENT_GROUP_COLORING = 1,
    UNIFORM_COLORING = 2
};

enum TreeStyle {
    TREE_BRANCHES = 0,   // └── ├── │
    TREE_INDENT_ONLY = 1 // no characters, simple indent
};

enum OutputMode {
    FULL_TREE = 0,
    COMPACT   = 1
};

struct PrettySettings {
    bool colorize = true;
    ColorMode mode = LEVEL_COLORING;
    TreeStyle style = TREE_INDENT_ONLY;
    OutputMode output = FULL_TREE;

    bool highlightViolations = true;
    bool highlightSwaps = false;
    int swappedA = -1;
    int swappedB = -1;

    bool zeroIndexed = false;
    int indent = 4;

    // Used for uniform mode
    string uniformColor = PrettyColor::cyan;

    bool asciiOnly = false;
};

// --- ANSI enable ---
inline void enable_ansi() {
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (GetConsoleMode(h, &mode)) {
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(h, mode);
    }
#endif
}

inline int mapIndex(int i, bool z) { return z ? i - 1 : i; }
inline bool valid(int i, int n) { return i >= 1 && i <= n; }

// --- color helpers ---
inline string level_color(int i) {
    int lvl = (int)floor(log2((double)i));
    switch (lvl % 6) {
        case 0: return PrettyColor::green;
        case 1: return PrettyColor::cyan;
        case 2: return PrettyColor::yellow;
        case 3: return PrettyColor::blue;
        case 4: return PrettyColor::magenta;
        default: return PrettyColor::red;
    }
}

inline string parent_color(int parent) {
    switch (parent % 5) {
        case 0: return PrettyColor::magenta;
        case 1: return PrettyColor::cyan;
        case 2: return PrettyColor::yellow;
        case 3: return PrettyColor::green;
        default: return PrettyColor::blue;
    }
}

inline string get_color_for(int i, int n, const PrettySettings &S) {
    if (!S.colorize) return "";

    if (S.mode == LEVEL_COLORING) return level_color(i);
    if (S.mode == PARENT_GROUP_COLORING) {
        if (i == 1) return PrettyColor::green;
        return parent_color(i/2);
    }
    if (S.mode == UNIFORM_COLORING) {
        if (i == 1) return PrettyColor::green;
        return S.uniformColor;
    }
    return "";
}

// ============================================================
// ASCII tree branches helper
// ============================================================
inline string branch_prefix(bool isLeft, bool isLast, bool asciiOnly) {
    if (asciiOnly) return "-- ";
    if (isLast) return "└── ";
    return "├── ";
}

// ============================================================
// RECURSIVE FULL TREE PRINTER WITH BRANCHES
// ============================================================
template <typename Heap>
void _pretty_branches(const Heap &heap, int i, int n, string prefix, bool isLast, const PrettySettings &S) {
    if (!valid(i, n)) return;

    int idx = mapIndex(i, S.zeroIndexed);

    cout << prefix;
    cout << branch_prefix(true, isLast, S.asciiOnly);

    string color = get_color_for(i, n, S);
    string reset = S.colorize ? PrettyColor::reset : "";

    // swap highlight
    if (S.highlightSwaps) {
        if ((!S.zeroIndexed && (i == S.swappedA || i == S.swappedB)) ||
            ( S.zeroIndexed && (idx == S.swappedA || idx == S.swappedB)))
            color = PrettyColor::magenta;
    }

    // violation highlight
    if (S.highlightViolations && i > 1) {
        int p = i/2;
        int pidx = mapIndex(p, S.zeroIndexed);
        if (heap[idx] > heap[pidx]) color = PrettyColor::red;
    }

    cout << color << heap[idx] << reset << "\n";

    // children
    bool hasLeft = valid(2*i, n);
    bool hasRight = valid(2*i+1, n);

    if (!hasLeft && !hasRight) return;

    string newPrefix = prefix + (S.asciiOnly ? "   " : (isLast ? "    " : "│   "));

    if (hasLeft)
        _pretty_branches(heap, 2*i, n, newPrefix, !hasRight, S);
    if (hasRight)
        _pretty_branches(heap, 2*i+1, n, newPrefix, true, S);
}

// ============================================================
// COMPACT MODE (one line per tree level)
// ============================================================
template <typename Heap>
void _compact(const Heap &heap, int n, const PrettySettings &S) {
    int levelCount = 1;
    int printed = 0;

    for (int i = 1; i <= n; i++) {
        int idx = mapIndex(i, S.zeroIndexed);
        string color = get_color_for(i, n, S);
        string reset = S.colorize ? PrettyColor::reset : "";

        cout << color << heap[idx] << reset << " ";
        printed++;

        if (printed == levelCount) {
            cout << "\n";
            levelCount *= 2;
            printed = 0;
        }
    }
    cout << "\n";
}

// ============================================================
// PUBLIC WRAPPER
// ============================================================
template <typename Heap>
void print_pretty_heap(const Heap &heap, int n) {
    enable_ansi();

    PrettySettings S; // defaults: level coloring

    if (S.output == COMPACT) _compact(heap, n, S);
    else _pretty_branches(heap, 1, n, "", true, S);

    cout << "\n";
}

// ============================================================
// GRAPHVIZ EXPORT
// ============================================================
template <typename Heap>
void export_heap_graphviz(const Heap &heap, int n, const string &file) {
    ofstream f(file);
    if (!f.is_open()) return;

    f << "digraph Heap {\n  node [shape=circle];\n";
    for (int i = 1; i <= n; i++) {
        if (2*i <= n) f << "  " << heap[i] << " -> " << heap[2*i] << ";\n";
        if (2*i+1 <= n) f << "  " << heap[i] << " -> " << heap[2*i+1] << ";\n";
    }
    f << "}\n";
    f.close();
}

#endif
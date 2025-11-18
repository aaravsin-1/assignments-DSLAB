# Pretty Tree Printer — Settings Guide

This document explains **every setting** available in the Pretty Tree Printer, **how to edit them**, and **where in the header to change defaults**.

It also provides an optional **external settings file structure**, allowing you to manage configuration cleanly without touching the main `.hpp` implementation.

---

# ✅ 1. Where settings live (PrettySettings struct)

All configuration options reside inside the following struct in `pretty_tree_printer.hpp`:

```cpp
struct PrettySettings {
    bool colorize;            
    ColorMode mode;          
    TreeStyle style;
    OutputMode output;

    bool highlightViolations;
    bool highlightSwaps;
    int swappedA;
    int swappedB;

    bool zeroIndexed;
    int indent;

    string uniformColor;

    bool asciiOnly;
};
```

This struct controls ALL behavior of the printer.

---

# ✅ 2. What each setting does

## 🎨 COLOR OPTIONS

### **`colorize`**

Turns colored output on/off.

```cpp
true  = use ANSI colors
false = plain text
```

### **`mode` — Color style**

```cpp
enum ColorMode {
    LEVEL_COLORING,        // depth-based
    PARENT_GROUP_COLORING, // siblings share color
    UNIFORM_COLORING       // all nodes one color
};
```

### **`uniformColor`**

Used only when mode = `UNIFORM_COLORING`.

Example:

```cpp
S.uniformColor = PrettyColor::magenta;
```

---

## 🌲 TREE DRAWING STYLE

### **`style` — ASCII tree rendering mode**

```cpp
enum TreeStyle {
    TREE_BRANCHES,    // └── │ ├──
    TREE_INDENT_ONLY  // spaces only, no branch graphics
};
```

### **`asciiOnly`**

Forces fallback to ASCII characters:

```
-- 16
   -- 14
```

Use this when Windows PowerShell prints garbage characters.

---

## 📐 SPACING AND INDENTATION

### **`indent`**

Number of spaces added per depth level.

```cpp
indent = 4; // default
```

Increase if your numbers are wide.

### **`zeroIndexed`**

Controls expected heap indexing:

```
false = heap starts at index 1 (typical for heaps)
true  = heap starts at index 0
```

---

## ⚠ HIGHLIGHTING

### **`highlightViolations`**

Marks nodes **red** when child > parent.

### **`highlightSwaps` / `swappedA` / `swappedB`**

Used to highlight nodes during heapify animations.

* Both nodes are printed in **magenta**.

Example:

```cpp
S.highlightSwaps = true;
S.swappedA = 3;
S.swappedB = 7;
```

---

## 🧩 OUTPUT MODE

### **`output`** (full tree vs compact)

```cpp
enum OutputMode {
    FULL_TREE, // pretty sideways full tree
    COMPACT    // prints level by level
};
```

Example compact output:

```
16
14 10
8 7 9 3
2 4 1
```

---

# ✅ 3. How to set defaults **inside the header**

You modify defaults here:

```cpp
PrettySettings S; // create settings
S.mode = LEVEL_COLORING;      // default mode
S.style = TREE_BRANCHES;      // default rendering
S.output = FULL_TREE;         // default output
S.colorize = true;            // colors on
S.asciiOnly = false;          // enable Unicode
S.highlightViolations = true; // mark errors
S.highlightSwaps = false;
S.zeroIndexed = false;
S.indent = 4;
```

These lines are inside:

```
print_pretty_heap(const Heap &heap, int n)
```

You can modify them directly in the header to change global defaults.

---

# ✅ 4. (NEW) External Settings File Format (Recommended)

If you don’t want to edit the `.hpp` repeatedly, you can create a standalone file:

### `pretty_tree_printer_settings.hpp`

```cpp
#ifndef PRETTY_TREE_SETTINGS_HPP
#define PRETTY_TREE_SETTINGS_HPP

#include <string>
#include "pretty_tree_printer.hpp"

inline PrettySettings LOAD_PRETTY_SETTINGS() {
    PrettySettings S;

    // ---- USER-EDITABLE DEFAULTS ----
    S.colorize = true;
    S.mode = LEVEL_COLORING;
    S.style = TREE_BRANCHES;
    S.output = FULL_TREE;

    S.highlightViolations = true;
    S.highlightSwaps = false;

    S.zeroIndexed = false;
    S.indent = 4;
    S.asciiOnly = false;

    // uniform coloring option
    S.uniformColor = PrettyColor::cyan;

    return S;
}

#endif
```

Then replace inside the main header:

```cpp
PrettySettings S;
```

with:

```cpp
PrettySettings S = LOAD_PRETTY_SETTINGS();
```

Now you can modify all defaults **in one separate settings file**.

---

# 📌 5. Summary: Everything You Can Customize

| Feature                | Setting               | Values                   |
| ---------------------- | --------------------- | ------------------------ |
| Color on/off           | `colorize`            | `true/false`             |
| Coloring mode          | `mode`                | LEVEL / PARENT / UNIFORM |
| Uniform color          | `uniformColor`        | any ANSI color code      |
| Use ASCII tree         | `asciiOnly`           | `true/false`             |
| Draw branches          | `style`               | BRANCHES / INDENT_ONLY   |
| Full vs Compact        | `output`              | FULL_TREE / COMPACT      |
| Highlight bad children | `highlightViolations` | `true/false`             |
| Highlight swaps        | `highlightSwaps`      | `true/false` + indices   |
| Heap indexing          | `zeroIndexed`         | `true/false`             |
| Indent width           | `indent`              | integer                  |

---

# 🎉 Want auto-detection?

I can add:

* auto detection of Unicode support
* auto switch to ASCII when needed
* theme presets (dark/light/pastel/neon)
* ability to load settings from JSON

Just tell me!

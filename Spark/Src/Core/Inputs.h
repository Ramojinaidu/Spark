#ifndef INPUTS_H
#define INPUTS_H

#include "../pch.h"
#include "Keys.h"

namespace Spark {

class Input {
  public:
    Input() = delete;
    ~Input() = delete;

    static bool IsKeyState(int key, int state);
    static bool IsMouseKeyState(int key, int state);
    static void GetMousePos(double* x, double* y);
};

} // namespace Spark

#endif

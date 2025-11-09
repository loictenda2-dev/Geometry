#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"

int main() {
    Point2f p = MakeP2f(2.0f, 3.0f);
    Print("Point:", ToString(p));

    Vector2f v = MakeV2f(1.0f, -1.0f);
    Point2f p2 = Translate(p, v);
    Print("Translated:", ToString(p2));

    return 0;
}

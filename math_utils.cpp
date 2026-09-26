#include "math_utils.h"

double getDis(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double calcAngle(double xa, double ya, double xb, double yb)
{
    double dx = xb - xa;
    double dy = yb - ya;

    // 坐标轴特殊情况
    if (dx == 0)
    {
        if (dy > 0) return 90.0;
        if (dy < 0) return 270.0;
        return 0.0; // A、B重合
    }

    // atan2(dy, dx) 返回 [-π, π] 弧度
    double rad = atan2(dy, dx);
    double deg = rad * 180.0 / kPi; // 转角度

    if (deg < 0)
        deg += 360.0;

    return deg;
}
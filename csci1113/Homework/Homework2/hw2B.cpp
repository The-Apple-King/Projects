#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

int main(int argc, char const *argv[])
{
    std::cout << std::setprecision(15);
    double a = 0;
    double b = 1;
    double c = 1 / sqrt(2);
    double d = 1.0 / 4.0;
    double e = 1;
    double f = 0;
    double g = 0;

    std::cout << "        f                   g              |f - pi|                 |g - pi|\n";
    std::cout << "----------------------------------------------------------------------------\n";

    for (size_t i = 0; i < 5; i++)
    {
        a = b;
        b = ((b + c) / 2);
        c = sqrt((c * a));
        d = d - (e * ((b - a) * (b - a)));
        e = e * 2.0;
        f = (b*b)/d;
        g = ((b+c)*(b+c))/(4*d);
        std::cout << f << "  " << g << "  " << abs(f - M_PI) << "   " << abs(g - M_PI) << "\n";
    }

    return 0;
}

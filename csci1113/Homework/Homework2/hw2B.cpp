#include <iostream>
#include <stdlib.h>
#include <cmath>

int main(int argc, char const *argv[])
{
    double a = 0;
    double b = 1;
    double c = 1 / sqrt(2);
    double d = 1 / 4;
    double e = 1;
    double f = 0;
    double g = 0;

    std::cout << "              f                                 g                       |f - pi|                                   |g - pi|";
    std::cout << "--------------------------------------------------------------------------------------------------------------------------- ";

    for (size_t i = 0; i < 6; i++)
    {
        a = b;
        b = ((b + c) / 2);
        c = sqrt((c * a));
        d = d - e * ((b - a) * (b - a));
        e *= 2;

        f = (b*b)/d;
        g = ((b+c)*(b+c))/(4*d);

        std::cout << f << " " << g << " " << f - M_PI << " " << g - M_PI;
    }

    return 0;
}

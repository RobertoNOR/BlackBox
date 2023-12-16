#include <iostream>
#include <cmath>

double checker(double param)
{
    while (true)
    {
        try
        {
            if (!(std::cin >> param))
            {
                std::cin.clear();

                while (std::cin.get() != '\n');

                throw "Value is non digit!";
            }
            else
                break;
        }

        catch (const char* exception)
        {
            std::cout << exception << '\n';

            std::cout << "Type new agument value: ";
        }
    }
    return param;
}

int main() {
    double a = 0, b = 0, c = 0;

    std::cout << "Type arguments value:";

    a = checker(a);

    b = checker(b);

    c = checker(c);

    if (a == 0 && b == 0 && c == 0) {
        std::cout << "The equation has infinitely many solutions\n";
        return 0;
    }

    if (a == 0 && b == 0 && c != 0) {
        std::cout << "The equation has no solutions\n";
        return 0;
    }

    // Линейное уравнение
    if (a == 0 && b != 0) {
        std::cout << "x = " << -c / b << "\n";
        return 0;
    }

    // Квадратное уравнение
    double D = b * b - 4 * a * c;
    if (D < 0) {
        std::cout << "The equation has no real solutions\n";
    }
    else if (D == 0) {
        std::cout << "x = " << -b / (2 * a) << "\n";
    }
    else {
        std::cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << "\n";
        std::cout << "x2 = " << (-b - sqrt(D)) / (2 * a) << "\n";
    }

    return 0;
}

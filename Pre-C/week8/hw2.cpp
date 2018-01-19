#include <iostream>

int main()
{

    int n = 0;
    std::cin >> n;
    double d = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> d;
        double t_bike = 27 + 23 + d / 3.0;
        double t_walk = d / 1.2;

        if (t_bike > t_walk)
        {
            std::cout << "Walk" << std::endl;
        }
        else if (t_bike < t_walk)
        {
            std::cout << "Bike" << std::endl;
        }
        else
        {
            std::cout << "All" << std::endl;
        }
    }

    return 0;
}
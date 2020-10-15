//
// Created by Genes on 2020/10/11.
//

//三角形
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a)
        printf("Perimetro = %.1lf\n", a + b + c);
    else
        printf("Area = %.1lf\n", (a + b) * c / 2);

    return 0;
}
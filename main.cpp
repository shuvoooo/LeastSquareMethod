#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
    int i, j, k, n;

    cout << "Enter total Pair's : ";
    cin >> n;

    double x[n], y[n], a, b, xsum = 0, x2sum = 0, ysum = 0, xysum = 0, y_fit[n];

    cout << "\nEnter x-axis values:\n";
    for (i = 0; i < n; i++)
        cin >> x[i];

    cout << "\nEnter y-axis values:\n";
    for (i = 0; i < n; i++)
        cin >> y[i];


    for (i = 0; i < n; i++) {
        xsum = xsum + x[i];
        ysum = ysum + y[i];
        x2sum = x2sum + pow(x[i], 2);
        xysum = xysum + x[i] * y[i];
    }

    a = (n * xysum - xsum * ysum) / (n * x2sum - xsum * xsum);
    b = (x2sum * ysum - xsum * xysum) / (x2sum * n - xsum * xsum);

    for (i = 0; i < n; i++)
        y_fit[i] = a * x[i] + b;

    cout << "S.no" << setw(5) << "x" << setw(19) << "y" << setw(19) << "y(calculated)" << setw(19) << "error" << endl;
    cout << "-----------------------------------------------------------------\n";

    for (i = 0; i < n; i++)
        cout << i + 1 << "." << setw(8) << x[i] << setw(15) << y[i] << setw(18) << y_fit[i] << setw(18)
             << abs(y[i] - y_fit[i]) << endl;



    return 0;
}
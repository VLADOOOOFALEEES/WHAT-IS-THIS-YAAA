#include <iostream>
#include<Windows.h>
#include <cmath>
#include <iomanip>
#include <string>

void start();
const int MAX_SIZE = 42;
void gaus(double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], int n);

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    int n;
    double a[MAX_SIZE][MAX_SIZE];
    double b[MAX_SIZE];
    std::cout << "¬ведите количество переменных:\n";
    std::cin >> n;
    std::cout << "¬ведите коэффициенты матрицы и свободные члены:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            std::cin >> a[i][j];
        }
        std::cin >> b[i];
    }
    gaus(a, b, n);
    
    return 0;
}
void gaus(double a[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], int n){
   
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            double clone = a[j][i] / a[i][i];
            for (int k = i; k < n; k++){
                a[j][k] -= clone * a[i][k];
            }
            b[j] -= clone * b[i];
        }
    }

    double x[MAX_SIZE];
    for (int i = n - 1; i >= 0; i--){
        x[i] = b[i];
        for (int j = i + 1; j < n; j++){
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    std::cout << "–ешение слу:\n";
    for (int i = 0; i < n; i++){
        std::cout << "x" << i + 1 << " = " << std::fixed << std::setprecision(6) << x[i] << "\n";
    }
}

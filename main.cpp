#include <iostream>
#include <fstream>
#include <cmath>

bool readCoefficients(const std::string& filename, double& a, double& b, double& c) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "Не удалось открыть файл для чтения." << std::endl;
        return false;
    }

    inputFile >> a >> b >> c;
    if (inputFile.fail()) {
        std::cout << "Ошибка чтения коэффициентов из файла." << std::endl;
        return false;
    }

    return true;
}


void solveQuadratic(double a, double b, double c, double& root1, double& root2, int& numRoots) {
    if (a == 0) {
        if (b == 0){
             numRoots = 0;
        }else{
            numRoots = 1;
            root1 = root2 = -c / b;
        }
    }else{
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            numRoots = 2;
            root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        } else if (discriminant == 0) {
            numRoots = 1;
            root1 = root2 = -b / (2 * a);
        } else {
            numRoots = 0;
        }
    }
}

void writeRoots(const std::string& filename, double root1, double root2, int numRoots) {
    std::ofstream outputFile(filename, std::ios::out | std::ios::trunc);

    if (numRoots == 2) {
        outputFile << "Корни уравнения: " << root1 << " и " << root2 << std::endl;
    } else if (numRoots == 1) {
        outputFile << "Корень уравнения: " << root1 << std::endl;
    } else {
        outputFile << "Нет действительных корней." << std::endl;
    }
}

int main() {
    double a, b, c;
    double root1, root2;
    int numRoots;


    if (readCoefficients("coefficients.txt", a, b, c)){
        solveQuadratic(a, b, c, root1, root2, numRoots);
        writeRoots("roots.txt", root1, root2, numRoots);
        std::cout << "Решение записано в файл roots.txt." << std::endl;
    }
    return 0;
}

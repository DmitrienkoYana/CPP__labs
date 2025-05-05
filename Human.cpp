#include "Human.hpp"

Coefficients::Coefficients(int a, int b, int c) : a(a), b(b), c(c) {}


Human::~Human() {
    for (const auto& Coeff : this->CoefficientsVector) {
        delete Coeff;
    }
}

std::vector<double> Human::solution(Coefficients const coeffs) {
    double D = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
    std::vector<double> roots;

    if (D > 0) {
        double x1 = (-coeffs.b + sqrt(D)) / (2 * coeffs.a);
        double x2 = (-coeffs.b - sqrt(D)) / (2 * coeffs.a);
        roots.push_back(x1);
        roots.push_back(x2);
    } else if (D == 0) {
        double x = -coeffs.b / (2 * coeffs.a);
        roots.push_back(x);
    }
    return roots;
}

Coefficients Human::read_line(const std::string& line) {
    int a, b, c;
    char signB, signC;

    sscanf(line.c_str(), "%d * x^2 %c %d * x %c %d", &a, &signB, &b, &signC, &c);
    if (signB == '-') { b = -b; }
    if (signC == '-') { c = -c; }

    return Coefficients(a, b, c);
}

Student::Student(const std::string& studentName) : name(studentName) {}

void Student::append_to_file(const std::string& filename, const std::string& line, const std::vector<double> result) {
    std::ofstream outputFile(filename, std::ios::app);
    outputFile << line << " solution:";
    for (const double& value : result) {
        outputFile << value << ", ";
    }
    outputFile << "Name: " <<  this->name << std::endl;
    outputFile.close();
}


GoodStudent::GoodStudent(const std::string& studentName) : Student(studentName) {}

void GoodStudent::study(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream input(inputFilename);
    std::string line;

    while (std::getline(input, line)) {
        Coefficients coeffs = this->read_line(std::string(line));
        std::vector<double> result = solution(coeffs);
        append_to_file(outputFilename, line, result);
    }

    input.close();
}

NormalStudent::NormalStudent(const std::string& studentName, int successRate) : Student(studentName), successRate(successRate) {}

void NormalStudent::study(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream input(inputFilename);
    std::string line;

    while (std::getline(input, line)) {
        Coefficients coeffs = this->read_line(std::string(line));
        std::vector<double> result;
        if (std::rand() % 100 < 50) {
            result = solution(coeffs);
        } else {
            result = {0, 0};
        }
        append_to_file(outputFilename, line, result);
    }

    input.close();
}

BadStudent::BadStudent(const std::string& studentName) : Student(studentName) {}

void BadStudent::study(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream input(inputFilename);
    std::string line;

    while (std::getline(input, line)) {
        Coefficients coeffs = this->read_line(std::string(line));
        std::vector<double> result = {0, 0};
        append_to_file(outputFilename, line, result);
    }

    input.close();
}

void Teacher::teach(const std::string& inputFilename) {
    std::ifstream input(inputFilename);
    std::string line;
    std::vector<double> result;

    while (std::getline(input, line)) {
        int a, b, c;
        char signB, signC;
        double root1, root2;
        char name[100];

            sscanf(line.c_str(), "%d * x^2 %c %d * x %c %d = 0 solution:%lf, %lf, Name: %s", &a, &signB, &b, &signC, &c, &root1, &root2, name);
        if (signB == '-') { b = -b; }
        if (signC == '-') { c = -c; }
        
        result = solution(Coefficients(a, b, c));
        std::string studentName(name);
        if (studentResult.find(studentName) == studentResult.end()) {
            studentResult[studentName] = Grades();
        }
        studentResult[studentName].totalSolved += 1;
        if (std::abs(root1 - result[0]) < 1e-1 && std::abs(root2 - result[1]) < 1e-1) {
            studentResult[studentName].totalCorrect += 1;
        }
    }
    input.close();
}
void Teacher::printStudentResults() const {
        for (const auto& entry : studentResult) {
            const std::string& studentName = entry.first;
            const Grades& grades = entry.second;
            std::cout << "Студент: " << studentName 
                      << ", Всего решено: " << grades.totalSolved 
                      << ", Правильных ответов: " << grades.totalCorrect << std::endl;
        }
        std::ofstream file("student_results.csv");
        file << "Имя,Всего решено,Правильных ответов\n";

        for (const auto& entry : studentResult) {
            const std::string& studentName = entry.first;
            const Grades& grades = entry.second;
            file << studentName << ","
            << grades.totalSolved << ","
            << grades.totalCorrect << "\n";
        }

        file.close();
        std::cout << "Результаты записаны в student_results.csv" << std::endl;
    }

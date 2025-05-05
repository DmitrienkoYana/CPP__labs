#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <unordered_map>

#pragma once

struct Coefficients {
    int a;
    int b;
    int c;
    Coefficients(int a, int b, int c);
};

class Human {
protected:
    std::vector<Coefficients*> CoefficientsVector;
    std::vector<double> solution(Coefficients const coeffs);
    Coefficients read_line(const std::string& line);

public:
    virtual ~Human();
};

class Student : public Human {
protected:
    std::string name;
    void append_to_file(const std::string& filename, const std::string& line, const std::vector<double> result);
public:
    Student(const std::string& studentName);
    std::vector<std::vector<double>*> getSolution();
    virtual void study(const std::string& inputFilename, const std::string& outputFilename) = 0;
};

class GoodStudent : public Student {
public:
    GoodStudent(const std::string& studentName);
    void study(const std::string& inputFilename, const std::string& outputFilename) override;
};

class NormalStudent : public Student {
protected:
    int successRate;
public:
    NormalStudent(const std::string& studentName, int successRate);
    void study(const std::string& inputFilename, const std::string& outputFilename) override;
};

class BadStudent : public Student {
public:
    BadStudent(const std::string& studentName);
    void study(const std::string& inputFilename, const std::string& outputFilename) override;
};

struct Grades {
    int totalSolved;
    int totalCorrect;
    Grades() : totalSolved(0), totalCorrect(0) {}
};

class Teacher : public Human {
private:
    std::unordered_map<std::string, Grades> studentResult;
public:
    void teach(const std::string& inputFilename);
    void printStudentResults() const;

};
#include "Human.hpp"

int main() {

    const std::string& inputFilename = "./coefficients.txt";
    const std::string& outputFilename = "./output.txt";

    std::ofstream outFile(outputFilename, std::ios::trunc);
    outFile.close();

    std::vector< Student*> StudentList;
    for(int i = 0; i<10; i++){
        int category = rand() % 3;
        std::string name = "Name" + std::to_string(i);
        Student* student = nullptr;
        switch (category) {
            case 0:
                student = new GoodStudent(name);
                break;
            case 1:
                student = new NormalStudent(name, rand() % 100);
                break;
            case 2:
                student = new BadStudent(name);
                break;
        }
        StudentList.push_back(student);
    }


    Teacher* teacher = new Teacher();

    for (const auto& student : StudentList) {
        student->study(inputFilename, outputFilename);
    }

    teacher->teach(outputFilename);
    teacher->printStudentResults();

    for (const auto& student : StudentList) {
        delete student;
    }
    delete teacher;
    return 0;
}
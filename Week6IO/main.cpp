#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

struct StudentGrade {
    std::string name;
    float grade;

    StudentGrade(std::string const &name, float grade) : name(name), grade(grade) {}
};

void WriteToFile(std::string const &filename, std::vector<StudentGrade> const &grades) {
    std::ofstream output(filename);
    for (auto const &grade : grades) {
        output << grade.name << " " << grade.grade << std::endl;
    }
}

std::vector<StudentGrade> ReadFromFile(std::string const &filename) {
    std::vector<StudentGrade> grades;
    std::ifstream input(filename);

    while (true) {
        std::string name;
        float grade;
        input >> name;
        if (input.eof())
            break;

        if (input.fail())
            throw std::runtime_error("Failed to parse file");

        input >> grade;
        if (input.fail())
            throw std::runtime_error("Failed to parse file");

        grades.emplace_back(name, grade);
    }

    return grades;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<StudentGrade> grades = {
            StudentGrade("Jantje", 5.0),
            StudentGrade("Pietje", 7.5),
            StudentGrade("Klaasje", 6.7),
    };

    WriteToFile("grades.txt", grades);

    std::vector<StudentGrade> readGrades = ReadFromFile("grades.txt");
    for (StudentGrade const &grade: grades) {
        std::cout << grade.name << " " << grade.grade << std::endl;
    }

    return 0;
}

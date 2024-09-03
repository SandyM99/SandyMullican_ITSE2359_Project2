#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int MAX_STUDENTS = 100;

struct Student {
    std::string name;
    int age;
    float gpa;
};

void displayStudents(const Student students[], int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "Name: " << students[i].name 
                  << ", Age: " << students[i].age 
                  << ", GPA: " << students[i].gpa << std::endl;
    }
}

void searchStudent(const Student students[], int count, const std::string& name) {
    for (int i = 0; i < count; ++i) {
        if (students[i].name == name) {
            std::cout << "Found: Name: " << students[i].name 
                      << ", Age: " << students[i].age 
                      << ", GPA: " << students[i].gpa << std::endl;
            return;
        }
    }
    std::cout << "Student not found!" << std::endl;
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    std::ifstream file("/workspaces/SandyMullican_ITSE2359_Project2/student_data.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line) && studentCount < MAX_STUDENTS) {
        std::istringstream iss(line);
        std::string name;
        int age;
        float gpa;

        std::getline(iss, name, ' ');
        iss >> age >> gpa;

        students[studentCount].name = name;
        students[studentCount].age = age;
        students[studentCount].gpa = gpa;

        studentCount++;
    }

    file.close();

    int choice;
    std::string searchName;

    do {
        std::cout << "1. Display all students\n2. Search for a student\n3. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayStudents(students, studentCount);
                break;
            case 2:
                std::cout << "Enter name to search: ";
                std::cin.ignore();
                std::getline(std::cin, searchName);
                searchStudent(students, studentCount, searchName);
                break;
            case 3:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}



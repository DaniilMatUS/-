#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Student {
public:
    int id;
   string name;
   vector<int> courses; 

    Student(int id, const string& name) : id(id), name(name) {}
};


class Teacher {
public:
    int id;
   string name;
    int experience;
   vector<int> courses; 

    Teacher(int id, const string& name, int experience) : id(id), name(name), experience(experience) {}
};


class Course {
public:
    int id;
   string name;
    int teacher_id; 
   vector<int> students; 

    Course(int id, const string& name, int teacher_id) : id(id), name(name), teacher_id(teacher_id) {}
};


class Database {
public:
   vector<Student> students;
   vector<Teacher> teachers;
   vector<Course> courses;

    void load(const string& filename) {
       ifstream file(filename);
        if (!file.is_open()) {
           cerr << "Не удалось открыть файл для чтения!" <<endl;
            return;
        }

       string line;
        while (getline(file, line)) {
           istringstream iss(line);
           string type;
            iss >> type;

            if (type == "student") {
                int id;
               string name;
               vector<int> course_ids;
                iss >> id >> name;
                int course_id;
                while (iss >> course_id) {
                    course_ids.push_back(course_id);
                }
                students.emplace_back(id, name);
                students.back().courses = course_ids;
            }
            else if (type == "teacher") {
                int id, experience;
               string name;
               vector<int> course_ids;
                iss >> id >> name >> experience;
                int course_id;
                while (iss >> course_id) {
                    course_ids.push_back(course_id);
                }
                teachers.emplace_back(id, name, experience);
                teachers.back().courses = course_ids;
            }
            else if (type == "course") {
                int id, teacher_id;
               string name;
               vector<int> student_ids;
                iss >> id >> name >> teacher_id;
                int student_id;
                while (iss >> student_id) {
                    student_ids.push_back(student_id);
                }
                courses.emplace_back(id, name, teacher_id);
                courses.back().students = student_ids;
            }
        }

        file.close();
    }

    void save(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Не удалось открыть файл для записи!" << endl;
            return;
        }

        for (const auto& student : students) {
            file << "student\t" << student.id << "\t" << student.name;
            for (const auto& course_id : student.courses) {
                file << "\t" << course_id;
            }
            file << "\n";
        }

        for (const auto& teacher : teachers) {
            file << "teacher\t" << teacher.id << "\t" << teacher.name << "\t" << teacher.experience;
            for (const auto& course_id : teacher.courses) {
                file << "\t" << course_id;
            }
            file << "\n";
        }

        for (const auto& course : courses) {
            file << "course\t" << course.id << "\t" << course.name << "\t" << course.teacher_id;
            for (const auto& student_id : course.students) {
                file << "\t" << student_id;
            }
            file << "\n";
        }

        file.close();
    }
};

int main() {
    Database db;

    
    db.students.emplace_back(1, "Alice");
    db.students.back().courses.push_back(101);
    db.teachers.emplace_back(1, "Dr. Smith", 10);
    db.teachers.back().courses.push_back(101);
    db.courses.emplace_back(101, "Mathematics", 1);
    db.courses.back().students.push_back(1);

    
    db.save("database.tsv");

    
    db.load("database.tsv");

    
    for (const auto& student : db.students) {
        cout << "Student: " << student.name << " (ID: " << student.id << ")\n";
    }

    for (const auto& teacher : db.teachers) {
        cout << "Teacher: " << teacher.name << " (ID: " << teacher.id << ", Experience: " << teacher.experience << " years)\n";
    }

    for (const auto& course : db.courses) {
        cout << "Course: " << course.name << " (ID: " << course.id << ")\n";
    }

    return 0;
}

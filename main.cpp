#include <iostream>
#include <string>
#include <iomanip>
#include <ios>

using namespace std;

struct points {
    int visa_1;
    int visa_2;
    int the_final;
};

struct subjects {
    points student_points;
};

struct students {
    string student_name;
    int student_number;
    subjects lessons[4];
};

void print_data(students student[] , string Lessons[4] , int student_count);

int main() {

    int lesson_index = 0;
    int student_count;

    cout << "student count" << endl;
    cin >> student_count;

    students student[10];

    string Lessons[4] = {"Calculus" , "Structural Programming" , "Circuit Theory" , "Semiconductor Physics"};

   
    for (int i = 0 ; i < student_count ; i++){
        
        cout << "Enter student name: ";
        cin >> student[i].student_name;
        
        cout << "Enter student number: ";
        cin >> student[i].student_number;
        
        
        for (int j = 0 ; j < 4 ; j++){
            
            cout << "Enter " << Lessons[j] << "  exam  points\n" << endl;

            cout << "Fist visa:  ";
            cin >> student[i].lessons[j].student_points.visa_1;
        
            cout << "\nSecond visa:  ";
            cin >> student[i].lessons[j].student_points.visa_2;

            cout << "\nFinal:   ";
            cin >> student[i].lessons[j].student_points.the_final;

        }
       
        

    }

    print_data(student , Lessons , student_count);

    return 0;
}

void print_data(students student[], string Lessons[4], int student_count) {
    int col_width = 12;

    cout << "Printing student data" << endl;
    cout << left << setw(col_width) << "Name"
         << setw(col_width) << "Number";

    for (int j = 0; j < 4; j++) {
        cout << " | "
             << setw(col_width * 3) << Lessons[j];
    }
    cout << endl;

    cout << setw(col_width) << ""
         << setw(col_width) << "";

    for (int j = 0; j < 4; j++) {
        cout << " | "
             << setw(col_width) << "Visa 1"
             << setw(col_width) << "Visa 2"
             << setw(col_width) << "Final";
    }
    cout << endl;

    for (int i = 0; i < student_count; i++) {
        cout << setw(col_width) << student[i].student_name
             << setw(col_width) << student[i].student_number;

        for (int j = 0; j < 4; j++) {
            cout << " | "
                 << setw(col_width) << student[i].lessons[j].student_points.visa_1
                 << setw(col_width) << student[i].lessons[j].student_points.visa_2
                 << setw(col_width) << student[i].lessons[j].student_points.the_final;
        }
        cout << endl;
    }
}

#include <iostream>
#include <string>
#include <iomanip>
#include <ios>

using namespace std;

struct points {
    int visa_1;
    int visa_2;
    int the_final;
    double grade;
    string result;
};

struct subjects {
    points student_points;
};

struct students {
    string student_name;
    int student_number;
    subjects lessons[4];
};

void get_point(students student[] , string Lessons[4] , int student_count);
int check_data(int temp_point);
void print_data(students student[] , string Lessons[4] , int student_count);
void grade_calculator(students student[] ,  int student_count);


int main() {

    int lesson_index = 0;
    int student_count;

    string flag;

    cout << "Enter quantity of students: ";
    cin >> student_count;

    students student[10];

    string Lessons[4] = {"Calculus" , "Structural Programming" , "Circuit Theory" , "Semiconductor Physics"};
    string note_gap[9] = {"AA" , "BA" , "BB" , "CB" , "CC" , "DC" , "DD" , "FD" , "FF"};

    get_point(student , Lessons , student_count);
    grade_calculator(student , student_count);
    print_data(student , Lessons , student_count);
    cout << "Press any key to exit" << endl;
    cin >> flag;
    return 0;
}


void get_point(students student[] , string Lessons[4] , int student_count){
    int temp_point;
    for (int i = 0 ; i < student_count ; i++){
        
        cout << "Enter student name: ";
        cin >> student[i].student_name;
        
        cout << "Enter student number: ";
        cin >> student[i].student_number;
        
        
        for (int j = 0 ; j < 4 ; j++){
            
            cout << "Enter " << Lessons[j] << "  Exam  points\n" << endl;

            cout << "Fist visa:  ";
            cin >> temp_point;
            student[i].lessons[j].student_points.visa_1=check_data(temp_point);
        
            cout << "\nSecond visa:  ";
            cin >> temp_point;
            student[i].lessons[j].student_points.visa_2=check_data(temp_point);

            cout << "\nFinal:   ";
            cin >> temp_point;
            student[i].lessons[j].student_points.the_final=check_data(temp_point);

        }
    }

}

int check_data(int temp_point){
    
    while(!(temp_point>=0 && temp_point<=100)){
        
        cout << "Please enter a valid value";
        cin >> temp_point;
    }
    return temp_point;
}    

void print_data(students student[], string Lessons[4], int student_count) {
    int col_width = 8;

    cout << "Printing student data" << endl;
    cout << left << setw(col_width) << "Name"
         << setw(col_width) << "Number";
              

    for (int j = 0; j < 4; j++) {
        
        int padding = (32 - Lessons[j].length()) / 2;
        string space(padding, ' ');
        cout << " | " << space << Lessons[j] << space;

    }
    cout << "|";
    cout << endl;
    cout << setw(col_width) << ""
         << setw(col_width) << "";

    for (int j = 0; j < 4; j++) {

        cout << " | "
             << setw(col_width) << "Visa 1"
             << setw(col_width) << "Visa 2"
             << setw(col_width) << "Final"
             << setw(col_width) << "grade";
    }
    cout << endl;

    for (int i = 0; i < student_count; i++) {
        cout << setw(col_width) << student[i].student_name
             << setw(col_width) << student[i].student_number;

        for (int j = 0; j < 4; j++) {
            cout << " | "
                 << setw(col_width) << student[i].lessons[j].student_points.visa_1
                 << setw(col_width) << student[i].lessons[j].student_points.visa_2
                 << setw(col_width) << student[i].lessons[j].student_points.the_final
                 << setw(col_width) << student[i].lessons[j].student_points.grade;
        }
       
        cout << endl;
    }

}

void grade_calculator(students student[] ,  int student_count){

    double sum = 0;

    for (int i = 0 ; i < student_count ; i++){

        for (int j = 0 ; j < 4 ; j++){
            sum  +=  (student[i].lessons[j].student_points.visa_1 * 0.3);
            sum  +=  (student[i].lessons[j].student_points.visa_2 * 0.3);
            sum  +=  (student[i].lessons[j].student_points.the_final * 0.4);

            student[i].lessons[j].student_points.grade = sum;

            sum = 0;
        }

    }




}
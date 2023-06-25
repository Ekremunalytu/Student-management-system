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

void print_data(students student[] , string Lessons[4]);

int main() {

    int lesson_index = 0;

    students student[10];

    string Lessons[4] = {"Calculus" , "Structural Programming" , "Circuit Theory" , "Semiconductor Physics"};

   
    for (int i = 0 ; i < 3 ; i++){
        
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

    print_data(student , Lessons);

    return 0;
}

void print_data(struct students student[] ,string  Lessons[4]){
    

    int col_width=30; // width 6 nin kati olmali, yoksa int oldugundan 3 ve 2'ye bolerken sikinti cikarir
    

    cout << "Printing student data" << endl;
    left;
    cout << setw(col_width/2) << "Name" <<  setw(col_width) << "Number" << setw(col_width)  <<  Lessons[0] << setw(col_width) << Lessons[1] <<  setw(col_width) << Lessons[2] << setw(col_width) << Lessons[3] << endl;
    cout <<"\n";
    
    for (int i = 0 ; i  <  3 ; i++){

        cout << setw(col_width/2) << student[i].student_name  << setw(col_width) << student[i].student_number << setw(col_width/2) ;

        for(int j = 0 ; j < 4 ; j++){
            left;
            cout << student[i].lessons[j].student_points.visa_1  ;
            cout << setw(col_width/3) << student[i].lessons[j].student_points.visa_2  ;
            cout << setw(col_width/3) << student[i].lessons[j].student_points.the_final  ;
            cout << "  |  ";

        }
        cout << "\n";
        
    }
}
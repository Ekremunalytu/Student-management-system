#include <iostream>
#include <string>
#include "..\include_cpp\libxl.h"

using namespace std;
using namespace libxl;

struct default_letter_grade_ranges {
    int base;
    double ceiling;
    string letter_grade;
};

struct points {
    int visa_1;
    int visa_2;
    int the_final;
    double grade;
    string result;
    string letter_grade;

};

struct subjects {
    points student_points;
};

struct students {
    string student_name;
    int student_number;
    subjects lessons[4];
};

void get_point(students student[], string Lessons[4], int student_count);
int check_data(int temp_point);
void print_data(students student[], string Lessons[4], int student_count);
void grade_calculator(students student[], int student_count);
void calculateLetterGrade(students student[], int student_count);



int main() {

    int lesson_index = 0;
    int student_count;

    string flag;

    cout << "Enter quantity of students: ";
    cin >> student_count;

    students student[10];

    string Lessons[4] = { "Calculus" , "Structural Programming" , "Circuit Theory" , "Semiconductor Physics" };

    get_point(student, Lessons, student_count);
    grade_calculator(student, student_count);
    calculateLetterGrade(student, student_count);
    print_data(student, Lessons, student_count);
    cout << "Press any key to exit" << endl;
    cin >> flag;
    return 0;
}


void get_point(students student[], string Lessons[4], int student_count) {
    int temp_point;
    for (int i = 0; i < student_count; i++) {

        cout << "Enter student full name: ";
        cin.ignore();
        getline(cin, student[i].student_name);

        cout << "Enter student number: ";
        cin >> student[i].student_number;


        for (int j = 0; j < 4; j++) {

            cout << "Enter " << Lessons[j] << "  Exam  points\n" << endl;

            cout << "Fist visa:  ";
            cin >> temp_point;
            student[i].lessons[j].student_points.visa_1 = check_data(temp_point);

            cout << "\nSecond visa:  ";
            cin >> temp_point;
            student[i].lessons[j].student_points.visa_2 = check_data(temp_point);

            cout << "\nFinal:   ";
            cin >> temp_point;
            student[i].lessons[j].student_points.the_final = check_data(temp_point);

        }
    }

}

int check_data(int temp_point) {

    while (!(temp_point >= 0 && temp_point <= 100)) {

        cout << "Points can not be greater than 100 and less than 0.\nPlease enter a new value: ";
        cin >> temp_point;
    }
    return temp_point;
}

void print_data(students student[], string Lessons[4], int student_count) {
    Book* book = xlCreateBook();
    int col_width = 8;

    cout << "Printing student data" << endl;

    if (book)
    {
        Sheet* sheet = book->addSheet(L"Sheet1");


        if (sheet)
        {
            Font* font = book->addFont();
            font->setBold(true);

            Format* defaultFormat = book->addFormat();
            defaultFormat->setAlignH(ALIGNH_CENTER);
            defaultFormat->setAlignV(ALIGNV_CENTER);
            defaultFormat->setBorder(BORDERSTYLE_THIN);
            defaultFormat->setBorderColor(COLOR_BLACK);


            Format* lessonsFormat = book->addFormat();
            lessonsFormat->setAlignH(ALIGNH_CENTER);
            lessonsFormat->setAlignV(ALIGNV_CENTER);
            lessonsFormat->setBorder(BORDERSTYLE_THIN);
            lessonsFormat->setBorderColor(COLOR_BLACK);
            lessonsFormat->setFont(font);


            sheet->setCol(1, sheet->lastCol(), 20);
            sheet->setCol(2, 2, 25);
            sheet->writeStr(2, 2, L"Name", lessonsFormat);
            sheet->writeStr(2, 3, L"Number", lessonsFormat);
            sheet->writeStr(3, 3, L" ", defaultFormat);
            sheet->writeStr(3, 2, L" ", defaultFormat);

            for (int j = 2; j <= 5; j++) {

                std::wstring wLesson_name_formatted(Lessons[j - 2].begin(), Lessons[j - 2].end());
                const wchar_t* Lesson_name_formatted = wLesson_name_formatted.c_str();

                sheet->writeStr(2, 5 * j - 6, Lesson_name_formatted, lessonsFormat);
                sheet->setMerge(2, 2, 5 * j - 6, 5 * j - 2);
                sheet->writeStr(3, 5 * j - 6, L"Visa 1", defaultFormat);
                sheet->writeStr(3, 5 * j - 5, L"Visa 2", defaultFormat);
                sheet->writeStr(3, 5 * j - 4, L"Final", defaultFormat);
                sheet->writeStr(3, 5 * j - 3, L"Grade", defaultFormat);
                sheet->writeStr(3, 5 * j - 2, L"Letter", defaultFormat);


                for (int i = 0; i < student_count; i++) {

                    wstring wstudent_name_formatted(student[i].student_name.begin(), student[i].student_name.end());
                    const wchar_t* student_name_formatted = wstudent_name_formatted.c_str();

                    sheet->writeStr(i + 4, 2, student_name_formatted, defaultFormat);
                    sheet->writeNum(i + 4, 3, student[i].student_number, defaultFormat);

                    for (int j = 2; j <= 5; j++) {

                        sheet->writeNum(i + 4, 5 * j - 6, student[i].lessons[j - 2].student_points.visa_1, defaultFormat);
                        sheet->writeNum(i + 4, 5 * j - 5, student[i].lessons[j - 2].student_points.visa_2, defaultFormat);
                        sheet->writeNum(i + 4, 5 * j - 4, student[i].lessons[j - 2].student_points.the_final, defaultFormat);
                        sheet->writeNum(i + 4, 5 * j - 3, student[i].lessons[j - 2].student_points.grade, defaultFormat);

                        wstring wletter_grade_formatted(student[i].lessons[j - 2].student_points.letter_grade.begin(), student[i].lessons[j - 2].student_points.letter_grade.end());
                        const wchar_t* letter_grade_formatted = wletter_grade_formatted.c_str();

                        sheet->writeStr(i + 4, 5 * j - 2, letter_grade_formatted, defaultFormat);


                    }

                }
            }




        }
        book->save(L"notes.xls");
        book->release();
    }
}

void grade_calculator(students student[], int student_count) {

    double sum = 0;

    for (int i = 0; i < student_count; i++) {

        for (int j = 0; j < 4; j++) {
            sum += (student[i].lessons[j].student_points.visa_1 * 0.3);
            sum += (student[i].lessons[j].student_points.visa_2 * 0.3);
            sum += (student[i].lessons[j].student_points.the_final * 0.4);

            student[i].lessons[j].student_points.grade = sum;

            sum = 0;
        }

    }
}

void calculateLetterGrade(students student[], int student_count) {
    struct default_letter_grade_ranges ranges[9] = {
        {74 , 100 , "AA"},
        {67 , 73.9999 , "BA"},
        {60 , 66.9999, "BB"},
        {54, 59.9999, "CB"},
        {53, 47.9999, "CC"},
        {40, 46.9999, "DC"},
        {33, 39.9999, "DD"},
        {29, 32.9999, "FD"},
        {0, 28.9999, "FF"}
    };


    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 9; k++) {
                if (student[i].lessons[j].student_points.grade >= ranges[k].base && student[i].lessons[j].student_points.grade <= ranges[k].ceiling) {
                    student[i].lessons[j].student_points.letter_grade = ranges[k].letter_grade;
                    k = 9;
                }
            }
        }
    }
}
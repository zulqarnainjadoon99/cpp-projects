/*
 * Student Grade Calculator
 * Developer : Zulqarnain Khan Jadoon
 * Language  : C++
 * Description: Calculate grades, GPA and generate result card
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Subject {
    string name;
    int    marks;
    int    total;
    float  percentage;
    char   grade;
};

char getGrade(float percent) {
    if (percent >= 90) return 'A';
    if (percent >= 80) return 'B';
    if (percent >= 70) return 'C';
    if (percent >= 60) return 'D';
    return 'F';
}

string getGradeLabel(char grade) {
    switch(grade) {
        case 'A': return "Excellent";
        case 'B': return "Very Good";
        case 'C': return "Good";
        case 'D': return "Pass";
        default : return "Fail";
    }
}

float getGPA(float percent) {
    if (percent >= 90) return 4.0;
    if (percent >= 80) return 3.5;
    if (percent >= 70) return 3.0;
    if (percent >= 60) return 2.0;
    return 0.0;
}

void printLine(int n = 55) {
    cout << string(n, '-') << endl;
}

void printResultCard(string name, string rollNo, string className,
                     vector<Subject>& subjects) {
    int   totalObtained = 0;
    int   totalMarks    = 0;
    float totalGPA      = 0;

    cout << "\n";
    printLine();
    cout << setw(30) << " RESULT CARD" << endl;
    cout << setw(33) << "Zulqarnain Khan Jadoon" << endl;
    printLine();
    cout << " Student Name : " << name     << endl;
    cout << " Roll Number  : " << rollNo   << endl;
    cout << " Class        : " << className << endl;
    printLine();
    cout << left
         << setw(18) << "Subject"
         << setw(10) << "Obtained"
         << setw(10) << "Total"
         << setw(10) << "Grade"
         << "Result" << endl;
    printLine();

    for (auto& s : subjects) {
        s.percentage = (float)s.marks / s.total * 100;
        s.grade      = getGrade(s.percentage);
        totalObtained += s.marks;
        totalMarks    += s.total;
        totalGPA      += getGPA(s.percentage);

        cout << left
             << setw(18) << s.name
             << setw(10) << s.marks
             << setw(10) << s.total
             << setw(10) << s.grade
             << getGradeLabel(s.grade) << endl;
    }

    float overallPct = (float)totalObtained / totalMarks * 100;
    float avgGPA     = totalGPA / subjects.size();

    printLine();
    cout << left
         << setw(18) << "TOTAL"
         << setw(10) << totalObtained
         << setw(10) << totalMarks
         << setw(10) << getGrade(overallPct)
         << getGradeLabel(getGrade(overallPct)) << endl;
    printLine();
    cout << fixed << setprecision(1);
    cout << " Overall Percentage : " << overallPct << "%" << endl;
    cout << " GPA                : " << avgGPA     << " / 4.0" << endl;
    cout << " Final Result       : "
         << (overallPct >= 60 ? "PASSED ✓" : "FAILED ✗") << endl;
    printLine();
}

int main() {
    cout << "========================================" << endl;
    cout << "     Student Grade Calculator" << endl;
    cout << "  Developer: Zulqarnain Khan Jadoon" << endl;
    cout << "========================================" << endl;

    string name, rollNo, className;
    int    numSubjects;

    cout << "\nEnter Student Name  : "; getline(cin, name);
    cout << "Enter Roll Number   : "; getline(cin, rollNo);
    cout << "Enter Class         : "; getline(cin, className);
    cout << "Number of Subjects  : "; cin >> numSubjects;
    cin.ignore();

    vector<Subject> subjects(numSubjects);

    cout << "\n--- Enter Subject Details ---" << endl;
    for (int i = 0; i < numSubjects; i++) {
        cout << "\nSubject " << (i+1) << " Name   : ";
        getline(cin, subjects[i].name);
        cout << "Marks Obtained : "; cin >> subjects[i].marks;
        cout << "Total Marks    : "; cin >> subjects[i].total;
        cin.ignore();

        if (subjects[i].marks > subjects[i].total) {
            cout << "⚠  Marks cannot exceed total. Setting to total." << endl;
            subjects[i].marks = subjects[i].total;
        }
    }

    printResultCard(name, rollNo, className, subjects);

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// convert letter grade to grade points
double getPoints(string g) {
    if (g == "A" || g == "A+") return 4.0;
    if (g == "A-") return 3.7;
    if (g == "B+") return 3.3;
    if (g == "B") return 3.0;
    if (g == "B-") return 2.7;
    if (g == "C+") return 2.3;
    if (g == "C") return 2.0;
    if (g == "C-") return 1.7;
    if (g == "D") return 1.0;
    if (g == "F") return 0.0;
    return -1;  // invalid grade
}

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    string grade[50];
    double credits[50];
    double points[50];
    double totalCredits = 0, totalPoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade (A, B+, C...): ";
        cin >> grade[i];
        points[i] = getPoints(grade[i]);
        while (points[i] == -1) {
            cout << "Wrong grade, enter again: ";
            cin >> grade[i];
            points[i] = getPoints(grade[i]);
        }

        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalCredits += credits[i];
        totalPoints += points[i] * credits[i];
    }

    double gpa = totalPoints / totalCredits;

    // previous semesters
    double oldCredits, oldCgpa = 0;
    cout << "\nCredits completed before this semester (0 if none): ";
    cin >> oldCredits;
    if (oldCredits > 0) {
        cout << "Your CGPA before this semester: ";
        cin >> oldCgpa;
    }

    double cgpa = (oldCgpa * oldCredits + totalPoints) / (oldCredits + totalCredits);

    // show results
    cout << "\n------ Result ------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1 << ": Grade " << grade[i]
             << ", Credits " << credits[i]
             << ", Points " << points[i] * credits[i] << endl;
    }

    cout << "\nTotal credits: " << totalCredits << endl;
    cout << "Total grade points: " << totalPoints << endl;
    cout << "Semester GPA: " << gpa << endl;
    cout << "Overall CGPA: " << cgpa << endl;

    return 0;
}
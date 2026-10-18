
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses.";
        return 0;
    }

    vector<double> grades(n), credits(n);
    double totalCredits = 0, totalPoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter grade points for course " << i + 1 << ": ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> credits[i];

        if (grades[i] < 0 || grades[i] > 10 || credits[i] <= 0) {
            cout << "Invalid grade points or credits.";
            return 0;
        }

        totalCredits += credits[i];
        totalPoints += grades[i] * credits[i];
    }

    cout << fixed << setprecision(2);
    cout << "\nCourse Details\n";

    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade Points: " << grades[i]
             << " | Credits: " << credits[i] << '\n';
    }

    double gpa = totalPoints / totalCredits;

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nSemester GPA: " << gpa;

    double previousCGPA;
    double previousCredits;

    cout << "\n\nEnter previous CGPA (0 if first semester): ";
    cin >> previousCGPA;

    cout << "Enter previously completed credits (0 if first semester): ";
    cin >> previousCredits;

    if (previousCGPA < 0 || previousCGPA > 10 ||
        previousCredits < 0) {
        cout << "Invalid previous academic details.";
        return 0;
    }

    double cgpa = (previousCGPA * previousCredits + totalPoints)
                  / (previousCredits + totalCredits);

    cout << "\nOverall CGPA: " << cgpa << '\n';

    return 0;
}

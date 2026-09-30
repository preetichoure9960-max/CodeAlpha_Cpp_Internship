#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Course
{
    string name;
    double credit;
    string grade;
    double gradePoint;
};

// Converts grade into grade point
double getGradePoint(string grade)
{
    if (grade == "A+" || grade == "a+")
        return 10.0;
    else if (grade == "A" || grade == "a")
        return 9.0;
    else if (grade == "B+" || grade == "b+")
        return 8.0;
    else if (grade == "B" || grade == "b")
        return 7.0;
    else if (grade == "C+" || grade == "c+")
        return 6.0;
    else if (grade == "C" || grade == "c")
        return 5.0;
    else if (grade == "D" || grade == "d")
        return 4.0;
    else if (grade == "F" || grade == "f")
        return 0.0;

    return -1.0;
}

// Returns performance based on GPA
string getPerformance(double gpa)
{
    if (gpa >= 9.0)
        return "Outstanding";
    else if (gpa >= 8.0)
        return "Excellent";
    else if (gpa >= 7.0)
        return "Very Good";
    else if (gpa >= 6.0)
        return "Good";
    else if (gpa >= 5.0)
        return "Average";
    else
        return "Needs Improvement";
}

// Calculates GPA using credit-weighted grade points
double calculateGPA(const vector<Course>& courses)
{
    double totalCredits = 0;
    double totalGradePoints = 0;

    for (const Course& course : courses)
    {
        totalCredits += course.credit;
        totalGradePoints += course.credit * course.gradePoint;
    }

    if (totalCredits == 0)
        return 0;

    return totalGradePoints / totalCredits;
}

// Displays course-wise result
void displayResult(const vector<Course>& courses)
{
    cout << "\n";
    cout << left
         << setw(25) << "Course"
         << setw(12) << "Credits"
         << setw(10) << "Grade"
         << setw(15) << "Grade Point"
         << endl;

    cout << string(62, '-') << endl;

    for (const Course& course : courses)
    {
        cout << left
             << setw(25) << course.name
             << setw(12) << course.credit
             << setw(10) << course.grade
             << setw(15) << course.gradePoint
             << endl;
    }
}

// Main GPA calculation
void calculateGPA()
{
    int numberOfCourses;

    cout << "\nEnter number of courses: ";
    cin >> numberOfCourses;

    while (cin.fail() || numberOfCourses <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Enter a positive number: ";
        cin >> numberOfCourses;
    }

    vector<Course> courses;

    for (int i = 0; i < numberOfCourses; i++)
    {
        Course course;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        getline(cin, course.name);

        cout << "Enter credit hours: ";
        cin >> course.credit;

        while (cin.fail() || course.credit <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid credit hours. Enter again: ";
            cin >> course.credit;
        }

        cout << "Enter grade (A+, A, B+, B, C+, C, D, F): ";
        cin >> course.grade;

        course.gradePoint = getGradePoint(course.grade);

        while (course.gradePoint == -1)
        {
            cout << "Invalid grade. Enter again: ";
            cin >> course.grade;

            course.gradePoint = getGradePoint(course.grade);
        }

        courses.push_back(course);
    }

    double totalCredits = 0;

    for (const Course& course : courses)
        totalCredits += course.credit;

    double gpa = calculateGPA(courses);

    cout << "\n========================================";
    cout << "\n          ACADEMIC REPORT";
    cout << "\n========================================\n";

    displayResult(courses);

    cout << fixed << setprecision(2);

    cout << "\nTotal Credits : " << totalCredits;
    cout << "\nFinal GPA     : " << gpa;
    cout << "\nPerformance   : " << getPerformance(gpa);

    cout << "\n========================================\n";
}

// Shows highest and lowest performing subjects
void performanceAnalysis()
{
    int numberOfCourses;

    cout << "\nEnter number of courses: ";
    cin >> numberOfCourses;

    if (numberOfCourses <= 0)
    {
        cout << "Invalid number of courses.\n";
        return;
    }

    vector<Course> courses;

    for (int i = 0; i < numberOfCourses; i++)
    {
        Course course;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        getline(cin, course.name);

        cout << "Enter credit hours: ";
        cin >> course.credit;

        cout << "Enter grade: ";
        cin >> course.grade;

        course.gradePoint = getGradePoint(course.grade);

        while (course.gradePoint == -1)
        {
            cout << "Invalid grade. Enter again: ";
            cin >> course.grade;

            course.gradePoint = getGradePoint(course.grade);
        }

        courses.push_back(course);
    }

    int highest = 0;
    int lowest = 0;

    for (int i = 1; i < courses.size(); i++)
    {
        if (courses[i].gradePoint > courses[highest].gradePoint)
            highest = i;

        if (courses[i].gradePoint < courses[lowest].gradePoint)
            lowest = i;
    }

    double gpa = calculateGPA(courses);

    cout << "\n========================================";
    cout << "\n       PERFORMANCE ANALYSIS";
    cout << "\n========================================\n";

    cout << fixed << setprecision(2);

    cout << "Current GPA       : " << gpa << endl;
    cout << "Performance Level : " << getPerformance(gpa) << endl;

    cout << "\nHighest Performing Course:";
    cout << "\n" << courses[highest].name
         << " (" << courses[highest].grade << ")" << endl;

    cout << "\nCourse Requiring Attention:";
    cout << "\n" << courses[lowest].name
         << " (" << courses[lowest].grade << ")" << endl;

    cout << "\n========================================\n";
}

// Calculates GPA required to reach a target CGPA
void targetCGPA()
{
    double currentCGPA;
    double completedCredits;
    double nextSemesterCredits;
    double targetCGPA;

    cout << "\n========================================";
    cout << "\n       TARGET CGPA CALCULATOR";
    cout << "\n========================================\n";

    cout << "Enter current CGPA: ";
    cin >> currentCGPA;

    cout << "Enter completed credits: ";
    cin >> completedCredits;

    cout << "Enter next semester credits: ";
    cin >> nextSemesterCredits;

    cout << "Enter desired CGPA: ";
    cin >> targetCGPA;

    if (completedCredits < 0 || nextSemesterCredits <= 0)
    {
        cout << "\nInvalid credit values.\n";
        return;
    }

    double requiredGPA =
        ((targetCGPA * (completedCredits + nextSemesterCredits))
        - (currentCGPA * completedCredits))
        / nextSemesterCredits;

    cout << fixed << setprecision(2);

    if (requiredGPA > 10)
    {
        cout << "\nThe target CGPA cannot be achieved in one semester.\n";
    }
    else if (requiredGPA <= 0)
    {
        cout << "\nYou have already achieved your target CGPA.\n";
    }
    else
    {
        cout << "\nRequired GPA in next semester: "
             << requiredGPA << endl;
    }

    cout << "\n========================================\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n========================================";
        cout << "\n          SMART CGPA ANALYZER";
        cout << "\n========================================";

        cout << "\n1. Calculate GPA";
        cout << "\n2. Performance Analysis";
        cout << "\n3. Target CGPA Calculator";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                calculateGPA();
                break;

            case 2:
                performanceAnalysis();
                break;

            case 3:
                targetCGPA();
                break;

            case 4:
                cout << "\nThank you for using SmartCGPA!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

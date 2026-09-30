#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Course
{
    string name;
    double credit;
    string grade;
    double gradePoint;
};

double getGradePoint(string grade)
{
    if (grade == "A+" || grade == "a+") return 10.0;
    if (grade == "A"  || grade == "a")  return 9.0;
    if (grade == "B+" || grade == "b+") return 8.0;
    if (grade == "B"  || grade == "b")  return 7.0;
    if (grade == "C+" || grade == "c+") return 6.0;
    if (grade == "C"  || grade == "c")  return 5.0;
    if (grade == "D"  || grade == "d")  return 4.0;
    if (grade == "F"  || grade == "f")  return 0.0;

    return -1.0;
}

string getPerformance(double cgpa)
{
    if (cgpa >= 9.0)
        return "Outstanding";
    else if (cgpa >= 8.0)
        return "Excellent";
    else if (cgpa >= 7.0)
        return "Very Good";
    else if (cgpa >= 6.0)
        return "Good";
    else if (cgpa >= 5.0)
        return "Average";
    else
        return "Needs Improvement";
}

void displayCourseTable(const vector<Course>& courses)
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

double calculateGPA(const vector<Course>& courses)
{
    double totalCredits = 0;
    double totalPoints = 0;

    for (const Course& course : courses)
    {
        totalCredits += course.credit;
        totalPoints += course.credit * course.gradePoint;
    }

    if (totalCredits == 0)
        return 0;

    return totalPoints / totalCredits;
}

void calculateCGPA()
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

    displayCourseTable(courses);

    cout << "\nTotal Credits : " << totalCredits;
    cout << fixed << setprecision(2);
    cout << "\nFinal GPA     : " << gpa;
    cout << "\nPerformance   : " << getPerformance(gpa);

    cout << "\n========================================\n";
}

void performanceAnalysis(const vector<Course>& courses)
{
    if (courses.empty())
    {
        cout << "\nNo course data available.\n";
        return;
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

void targetCGPA()
{
    double currentCGPA;
    double completedCredits;
    double nextCredits;
    double target;

    cout << "\n========================================";
    cout << "\n         TARGET CGPA CALCULATOR";
    cout << "\n========================================\n";

    cout << "Enter current CGPA: ";
    cin >> currentCGPA;

    cout << "Enter completed credits: ";
    cin >> completedCredits;

    cout << "Enter credits for next semester: ";
    cin >> nextCredits;

    cout << "Enter desired CGPA: ";
    cin >> target;

    if (nextCredits <= 0 || completedCredits < 0)
    {
        cout << "\nInvalid credit values.\n";
        return;
    }

    double requiredGPA =
        ((target * (completedCredits + nextCredits))
        - (currentCGPA * completedCredits))
        / nextCredits;

    cout << fixed << setprecision(2);

    if (requiredGPA > 10)
    {
        cout << "\nTarget CGPA cannot be achieved in one semester";
        cout << " with a maximum GPA of 10.\n";
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
    vector<Course> courses;

    int choice;

    do
    {
        cout << "\n\n========================================";
        cout << "\n          SMART CGPA ANALYZER";
        cout << "\n========================================";

        cout << "\n1. Calculate GPA";
        cout << "\n2. View Performance Analysis";
        cout << "\n3. Calculate Target CGPA";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int numberOfCourses;

                cout << "\nEnter number of courses: ";
                cin >> numberOfCourses;

                while (cin.fail() || numberOfCourses <= 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter a valid number of courses: ";
                    cin >> numberOfCourses;
                }

                courses.clear();

                for (int i = 0; i < numberOfCourses; i++)
                {
                    Course course;

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "\nCourse " << i + 1 << endl;

                    cout << "Course name: ";
                    getline(cin, course.name);

                    cout << "Credit hours: ";
                    cin >> course.credit;

                    while (cin.fail() || course.credit <= 0)
                    {
                        cin.clear();
                        cin.ignore(
                            numeric_limits<streamsize>::max(),
                            '\n'
                        );

                        cout << "Enter valid credit hours: ";
                        cin >> course.credit;
                    }

                    cout << "Grade: ";
                    cin >> course.grade;

                    course.gradePoint =
                        getGradePoint(course.grade);

                    while (course.gradePoint == -1)
                    {
                        cout << "Invalid grade. Enter again: ";
                        cin >> course.grade;

                        course.gradePoint =
                            getGradePoint(course.grade);
                    }

                    courses.push_back(course);
                }

                double gpa = calculateGPA(courses);

                cout << "\n\n========================================";
                cout << "\n          ACADEMIC REPORT";
                cout << "\n========================================\n";

                displayCourseTable(courses);

                double totalCredits = 0;

                for (const Course& course : courses)
                    totalCredits += course.credit;

                cout << fixed << setprecision(2);

                cout << "\nTotal Credits : "
                     << totalCredits;

                cout << "\nFinal GPA     : "
                     << gpa;

                cout << "\nPerformance   : "
                     << getPerformance(gpa);

                cout << "\n========================================\n";

                break;
            }

            case 2:
                performanceAnalysis(courses);
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

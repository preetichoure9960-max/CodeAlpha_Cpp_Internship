# SmartCGPA – Academic Performance Analyzer

## 1. Project Overview

SmartCGPA is a console-based academic performance analyzer
developed using C++ as part of the CodeAlpha C++ Programming
Internship.

The primary purpose of the project is to calculate a student's
GPA using course grades and credit hours. Along with the required
CGPA calculation functionality, the application provides
additional features that help students understand and plan their
academic performance.

---

## 2. Internship Task

**Organization:** CodeAlpha

**Internship Domain:** C++ Programming

**Task:** Task 1 – CGPA Calculator

The project implements the core requirements of the CodeAlpha
CGPA Calculator task and extends them with additional academic
analysis features.

---

## 3. Problem Statement

Students often need to calculate their academic performance based
on different courses, grades and credit hours.

When these calculations are performed manually, calculating
credit-weighted grade points and overall GPA can become
time-consuming and may lead to calculation errors.

The SmartCGPA application provides a simple console-based solution
that automates these calculations and presents the results in an
organized format.

---

## 4. Objectives

The main objectives of this project are:

- To calculate GPA using course grades and credit hours.
- To calculate credit-weighted grade points.
- To display course-wise academic information.
- To validate user input.
- To classify overall academic performance.
- To identify high and low performing courses.
- To provide a target CGPA calculation feature.
- To create a simple and user-friendly C++ application.

---

## 5. Core Features

### 5.1 GPA Calculation

The application accepts the number of courses and collects the
following information for each course:

- Course name
- Credit hours
- Grade

The grade is converted into its corresponding grade point and
used along with the credit hours to calculate the GPA.

---

### 5.2 Course-wise Academic Report

After the calculation, the application displays an academic report
containing:

- Course name
- Credit hours
- Grade
- Grade point
- Total credits
- Final GPA
- Performance level

This provides the user with a clear summary of the entered
academic information.

---

### 5.3 Grade Validation

The application validates the grade entered by the user.

Supported grades are:

- A+
- A
- B+
- B
- C+
- C
- D
- F

If an invalid grade is entered, the program asks the user to
enter a valid grade.

---

### 5.4 Credit Validation

The application checks whether the entered credit hours are valid.

Invalid or non-positive credit values are rejected and the user
is asked to enter the value again.

---

### 5.5 Performance Classification

The application classifies the calculated GPA into a performance
category.

The categories used by the application include:

- Outstanding
- Excellent
- Very Good
- Good
- Average
- Needs Improvement

This gives the student a quick understanding of the calculated
academic performance.

---

### 5.6 Performance Analysis

The project provides an additional performance analysis feature.

It identifies:

- Current GPA
- Overall performance level
- Highest performing course
- Course requiring attention

This feature provides more information than a basic GPA calculator.

---

### 5.7 Target CGPA Calculator

The project also includes a target CGPA calculator.

The user can enter:

- Current CGPA
- Completed credits
- Credits for the next semester
- Desired CGPA

The application then calculates the approximate GPA required in
the next semester to reach the desired CGPA.

This feature can help students understand their future academic
target.

---

## 6. Grade Point System

The application uses the following grade-point mapping:

| Grade | Grade Point |
|-------|-------------|
| A+    | 10          |
| A     | 9           |
| B+    | 8           |
| B     | 7           |
| C+    | 6           |
| C     | 5           |
| D     | 4           |
| F     | 0           |

---

## 7. GPA Calculation Method

The GPA is calculated using credit-weighted grade points.

For each course:

Course Grade Points = Credit Hours × Grade Point

The overall GPA is calculated as:

GPA = Total Grade Points / Total Credit Hours

This ensures that courses with different credit values are
appropriately considered during the calculation.

****8. Technology Used****
Programming Language

C++

Libraries

The project uses standard C++ libraries including:

iostream
iomanip
vector
string
limits
Programming Concepts

The project demonstrates:

Structures
Functions
Vectors
Loops
Conditional statements
Mathematical calculations
Input validation
String handling
Menu-driven programming

****9. Program Workflow****

The basic workflow of the application is:

Start
  ↓
Display Main Menu
  ↓
Select Operation
  ↓
Enter Course Details
  ↓
Validate Input
  ↓
Convert Grade to Grade Point
  ↓
Calculate Credit-Weighted Points
  ↓
Calculate GPA
  ↓
Generate Academic Report
  ↓
Performance Analysis / Target CGPA
  ↓
Return to Main Menu
  ↓
Exit

****10. Project Structure****
Task1_SmartCGPA/
│
├── src/
│   └── main.cpp
│
├── screenshots/
│   ├── dashboard.png
│   ├── calculation.png
│   ├── performance.png
│   └── target_cgpa.png
│
├── docs/
│   └── project_report.md
│
└── README.md

****11. Input Validation****

Input validation is included to make the program more reliable.

The application checks:

Number of courses
Credit hours
Grade values
Menu choices

When invalid input is detected, the program provides an
appropriate message and asks the user to enter the information
again.

****12. User Interface****

The application uses a menu-driven console interface.

The main menu provides the following options:

1. Calculate GPA
2. Performance Analysis
3. Target CGPA Calculator
4. Exit

This makes the program easy to navigate without requiring
additional software or a graphical interface.

****13. Testing****

The application was tested using different course combinations,
credit hours and grade values.

The testing focused on:

Valid course input
Different credit values
Different grade values
Invalid grade handling
Invalid credit handling
GPA calculation
Performance classification
Performance analysis
Target CGPA calculation

Screenshots of the working application are included in the
screenshots directory.

****14. Future Scope****

The project can be further enhanced with:

Multiple Semester Records

Allow students to store and compare results from multiple
semesters.

Graphical User Interface

A GUI could make the application more visually interactive.

Performance Graphs

Graphs could show GPA changes and subject-wise performance.

Student Profile

A student profile system could store basic academic information.

Database Integration

A database could be used to store semester and course records.

Report Generation

The application could generate downloadable academic reports.

****15. Learning Outcomes****

This project provided practical experience with:

C++ programming
Functions and modular programming
Structures
STL vectors
Input validation
Mathematical calculations
Menu-driven applications
Problem solving
Project organization
GitHub-based project documentation

****16. Conclusion****

SmartCGPA demonstrates how fundamental C++ programming concepts
can be combined to create a practical academic application.

The project fulfills the core requirements of the CodeAlpha
CGPA Calculator task while adding performance analysis and
target CGPA functionality.

The project also provides a foundation for future improvements
such as multi-semester tracking, graphical visualization,
database integration and report generation.

****17. Author****

Name: Preeti Choure
Project: SmartCGPA – Academic Performance Analyzer

Internship: CodeAlpha C++ Programming Internship

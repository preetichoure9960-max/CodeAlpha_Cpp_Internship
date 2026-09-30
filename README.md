
# 🎓 SmartCGPA – Academic Performance Analyzer

> A C++ console-based academic performance analyzer developed as part of the **CodeAlpha C++ Programming Internship – Task 1: CGPA Calculator**.


## 📌 Project Overview

**SmartCGPA** is a menu-driven C++ application designed to simplify academic performance calculation.

The application accepts course details, credit hours, and grades, calculates the credit-weighted GPA, and provides additional academic insights such as performance classification, highest-performing course, course requiring attention, and target CGPA planning.

The project extends the basic CGPA calculator concept with features focused on **academic performance analysis and planning**.


## ✨ Key Features

### 📊 GPA Calculation
- Enter multiple courses
- Enter credit hours for each course
- Enter grades
- Automatically convert grades into grade points
- Calculate credit-weighted GPA

### 📋 Academic Report
Displays:
- Course name
- Credit hours
- Grade
- Grade point
- Total credits
- Final GPA
- Performance level

### 🏆 Performance Classification

The application classifies academic performance as:

| GPA Range | Performance |
|-----------|-------------|
| 9.0 – 10.0 | Outstanding |
| 8.0 – 8.99 | Excellent |
| 7.0 – 7.99 | Very Good |
| 6.0 – 6.99 | Good |
| 5.0 – 5.99 | Average |
| Below 5.0 | Needs Improvement |

### 🔎 Performance Analysis
The application identifies:
- Current GPA
- Overall performance level
- Highest-performing course
- Course requiring attention

### 🎯 Target CGPA Calculator

Students can enter:
- Current CGPA
- Completed credits
- Next semester credits
- Desired CGPA

The application calculates the approximate GPA required in the next semester to reach the desired target.

### 🛡️ Input Validation
The program validates:
- Number of courses
- Credit hours
- Grade values
- Menu choices

Invalid inputs are handled without terminating the application.


## 🧮 Grade Point System

| Grade | Grade Point |
|-------|-------------|
| A+ | 10 |
| A | 9 |
| B+ | 8 |
| B | 7 |
| C+ | 6 |
| C | 5 |
| D | 4 |
| F | 0 |


## 📐 GPA Calculation

For every course:

Course Grade Points = Credit Hours × Grade Point

The final GPA is calculated as:

GPA = Total Grade Points / Total Credit Hours


## 🛠️ Technologies Used

**Language**

* C++

**Libraries**

* `iostream`
* `iomanip`
* `vector`
* `string`
* `limits`

**Concepts**

* Structures
* Functions
* Vectors
* Loops
* Conditional statements
* Input validation
* String handling
* Mathematical calculations
* Menu-driven programming


## 📂 Project Structure

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


## ▶️ How to Run

### 1. Clone the Repository

git clone https://github.com/YOUR-USERNAME/CodeAlpha_Cpp_Internship.git


### 2. Navigate to the Project

cd CodeAlpha_Cpp_Internship/Task1_SmartCGPA


### 3. Compile the Program

Using g++:

g++ src/main.cpp -o SmartCGPA


### 4. Run the Program

**Windows:**

SmartCGPA.exe

**Linux / macOS:**

./SmartCGPA


## 🖥️ Application Menu

========================================
          SMART CGPA ANALYZER
========================================

1. Calculate GPA
2. Performance Analysis
3. Target CGPA Calculator
4. Exit


## 📸 Screenshots

### Main Dashboard

![Dashboard](screenshots/dashboard.png)

### GPA Calculation

![GPA Calculation](screenshots/calculation.png)

### Performance Analysis

![Performance Analysis](screenshots/performance.png)

### Target CGPA Calculator

![Target CGPA](screenshots/target_cgpa.png)


## 💡 What Makes This Project Different?

Instead of limiting the project to a basic GPA calculation, SmartCGPA combines calculation with academic analysis.

The additional features include:

* Performance classification
* Highest-performing course identification
* Course requiring attention
* Target CGPA planning
* Input validation
* Structured academic reporting

This makes the application more useful as an academic planning tool while still maintaining a simple console-based interface.


## 🔮 Future Improvements

Possible future enhancements include:

* 📚 Multiple semester tracking
* 📈 GPA performance graphs
* 👤 Student profile management
* 💾 Database integration
* 🖥️ Graphical User Interface
* 📄 Automated academic report generation
* 📊 Semester-to-semester performance comparison


## 📖 Documentation

For the complete project documentation, including objectives, methodology, workflow, testing, learning outcomes, and future scope:

👉 [View Project Report](docs/project_report.md)


## 🎯 Internship Details

**Organization:** CodeAlpha
**Internship:** C++ Programming Internship
**Task:** Task 1 – CGPA Calculator
**Project:** SmartCGPA – Academic Performance Analyzer


## 👨‍💻 Author

**Preeti Choure**

C++ Programming Internship – CodeAlpha


## ⭐ Acknowledgement

This project was developed as part of the **CodeAlpha C++ Programming Internship** to demonstrate practical application of C++ programming concepts and problem-solving skills.

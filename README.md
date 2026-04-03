# Student Grade Management System (C) 🎓

A structured C program designed to automate the calculation of academic results, featuring a "Best 5" subject evaluation logic.

## 👥 Team Project
Developed as a collaborative effort by a team of 4. My primary contributions included:
- Implementing the **Grade Calculation Logic** (dropping the lowest score).
- Designing the **Student Data Structure**.

## 🚀 Features
- **Smart Evaluation:** Automatically identifies and excludes the lowest subject score for a fairer final percentage.
- **Data Management:** Supports adding up to 100 students with unique roll numbers.
- **Search Functionality:** Efficiently search for specific student records by Roll Number.
- **Pass/Fail Logic:** Automated status assignment based on percentage thresholds.

## 🛠️ Technical Concepts
- **Structures:** Used `struct Student` to group heterogeneous data (name, marks, status).
- **Pointers:** Implemented pass-by-reference in the `calculate()` function for memory efficiency.
- **Arrays & Loops:** Managed subject lists and student databases.

# Student-Result-Management-System
# 🎓 Result Management System in C

A simple console-based **Result Management System** developed in **C language** to manage student records efficiently using **Structures**, **Dynamic Memory Allocation**, **Merge Sort**, and **Binary Search**.

## 📌 Features

* Store details of multiple students.
* Accept student **Roll Number**, **Name**, and **Marks**.
* Sort student records by marks using **Merge Sort**.
* Display students in ascending order of marks.
* Find the **Highest Scorer** and **Lowest Scorer**.
* Search for a student using **Roll Number** with **Binary Search**.
* Dynamically allocate memory using `malloc()`.
* Release allocated memory using `free()`.

## 🛠 Technologies Used

* C Programming Language
* Structures
* Dynamic Memory Allocation
* Merge Sort Algorithm
* Binary Search Algorithm

## 📂 Project Structure

```text
Result-Management-System/
│
├── result_management.c
└── README.md
```

## 🧠 Algorithms Used

### Merge Sort

Used to sort student records according to marks.

* **Time Complexity:** `O(n log n)`
* **Purpose:** Efficient sorting of student results.

### Binary Search

Used to search for a student by roll number.

* **Time Complexity:** `O(log n)`
* **Condition:** Data must be sorted by roll number before searching.

### Roll Number Sorting

Student records are sorted according to roll number before performing binary search.

* **Time Complexity:** `O(n²)`

## 📋 Student Structure

```c
typedef struct Student {
    int roll;
    char name[50];
    float marks;
} student;
```

## ▶️ Sample Input

```text
Enter number of students: 3

Enter Roll, Name, Marks:
101 Rahul 85

Enter Roll, Name, Marks:
103 Priya 92

Enter Roll, Name, Marks:
102 Aman 78
```

## ✅ Sample Output

```text
--- Sorted by Marks ---
Roll: 102 Name: Aman Marks: 78.00
Roll: 101 Name: Rahul Marks: 85.00
Roll: 103 Name: Priya Marks: 92.00

Lowest Scorer: Aman (78.00)
Highest Scorer: Priya (92.00)

Enter roll number to search: 101
Found: Rahul (85.00)
```

## 📚 Concepts Demonstrated

* Structures in C
* Arrays of Structures
* Dynamic Memory Allocation
* Divide and Conquer Algorithm
* Searching Techniques
* Sorting Techniques
* Modular Programming using Functions

## 🔮 Future Enhancements

* Add file handling to store records permanently.
* Add update and delete operations.
* Add grade calculation based on marks.
* Create a menu-driven interface.
* Add subject-wise marks management.


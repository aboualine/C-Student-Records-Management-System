# Student Records Management System

## Overview
The **Student Records Management System** is a simple **C** program that allows users to manage student records efficiently. It uses **file handling** for persistent storage, **structures** for organizing data, **exception handling**, and a **stack-based undo feature** for deletions.

## Features
- 📂 **File Storage**: Saves and loads student data from a file (`students.dat`).
- 📝 **Add Student**: Register new students with an **ID, Name, and Grade**.
- 📜 **View Students**: Display a list of all registered students.
- ❌ **Delete Student**: Remove a student from the system.
- 🔄 **Undo Last Deletion**: Uses a **stack** to restore the last deleted student.

## Requirements
- A **C compiler** (GCC, Clang, or MSVC).
- **VS Code** or any **C IDE**.

## Installation & Usage

### 1️⃣ Clone the Repository
```sh
git clone https://github.com/aboualine/Student-Records-Management.git
cd Student-Records-Management
```

### 2️⃣ Compile the Code
```sh
gcc student_records.c -o student_records
```

### 3️⃣ Run the Program
```sh
./student_records
```

## File Structure
```
Student-Records-Management/
│── student_records.c   # Main C source file
│── students.dat        # Data file (created after first run)
│── README.md           # Documentation
│── LICENSE             # MIT License
```

## How It Works
1. **Add a Student**: Input **ID, Name, and Grade**.
2. **View Students**: Displays all stored student records.
3. **Delete a Student**: Removes a student based on their ID.
4. **Undo Deletion**: Restores the last deleted student.

## Example Usage
```
Student Records Management
1. Add Student
2. Display Students
3. Delete Student
4. Exit
Enter choice: 1
Enter ID: 101
Enter Name: Alice
Enter Grade: 85.5
Student added successfully!
```

## Contributing
Pull requests are welcome! Feel free to improve the system and submit your PR.

## License
This project is licensed under the **MIT License** - see the `LICENSE` file for details.


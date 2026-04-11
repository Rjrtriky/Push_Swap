# 📜 Push_Swap

## 📖 Description

### Objective

Push_Swap is a 42 algorithm project that consists of sorting a stack of
integers using a limited set of operations on two stacks (A and B),
using the minimum number of moves possible.

### Design decisions

Each part has been encapsulated by dividing modules into folders,
grouping small and specialized functions into files. Descriptive names
are used for modules, files, and functions to improve handling,
maintenance, testing, and readability.

#### Data structure

-   Using doubly linked lists allows circular rotations in constant
    time, which is essential for the 11 project operations.
-   Including cost-related fields in each node allows unified and easy
    access to decision-making data.
-   Each stack structure includes the number of elements it contains.
-   Adding a reference to the target node in A provides direct access
    and avoids ambiguity.
-   A modular design improves readability and maintainability.
-   Optimizing the structure reduces memory and CPU usage.

------------------------------------------------------------------------

## ⚙️ Usage

``` bash
./push_swap 5 2 8 1 9
./push_swap "5 2 8 1 9"
./push_swap 5 2 "8 1" 9
```

------------------------------------------------------------------------

## 📚 Notes

This is a translated version of the original README.

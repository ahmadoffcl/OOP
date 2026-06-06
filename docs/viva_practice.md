# Viva Practice Notes

Use these questions to practice before showing the project.

Group members:
- Ahmad Ali | Reg No: 25-CS-067
- Umer Altaf | Reg No: 25-CS-057
- Muhammed Ahmad | Reg No: 25-CS-252

## Person Module
1. Why is `Person` abstract?
2. Why is `displayInfo()` virtual?
3. What is the difference between `Student`, `Faculty`, and `Staff`?
4. Where is multi-level inheritance used?

## Course Module
1. What does `Course::operator==` compare?
2. Why does `Course` store `Faculty*` instead of a full `Faculty` object?
3. What happens when course capacity is full?
4. What does the `friend` keyword do in `operator<<`?

## Library Module
1. Why does `Library` use `LibraryItem* items[]`?
2. What is the purpose of the destructor in `Library`?
3. How does `searchByTitle()` work?
4. Where is file handling used?

## Finance Module
1. Why is `invoiceCounter` static?
2. What does `FeeRecord& operator-=(double payment)` do?
3. Why does `Invoice` use `new` and `delete[]`?
4. What is copied in the `FeeRecord` copy constructor?

## Hostel Module
1. What is multiple inheritance?
2. What is virtual inheritance in `Accommodation` and `Reportable`?
3. What is composition in `HostelManager`?
4. Why does `Room` store `Student* occupants[]`?

## Reports Module
1. What does `std::sort` do in `Reports.cpp`?
2. How is the campus report file created?
3. What is the difference between searching and sorting?

# Full Viva Questions and Short Answers

## Basic C++ Questions

1. What is a class?
   A class is a user-defined type that keeps data and functions together.

2. What is an object?
   An object is a variable made from a class.

3. What is encapsulation?
   Encapsulation means keeping data private and accessing it through public functions.

4. Why are getters and setters used?
   They control access to private data members.

5. What is a constructor?
   A constructor is called automatically when an object is created.

6. What is a destructor?
   A destructor is called automatically when an object is destroyed.

7. What is a pointer?
   A pointer stores the address of another variable or object.

8. What is dynamic memory?
   Memory allocated at runtime using `new`.

9. Why do we use `delete`?
   To free memory allocated with `new`.

10. What is an array?
    An array stores multiple values of the same type.

## Person Module

11. Why is `Person` abstract?
    Because it has pure virtual function `displayInfo()`.

12. Can we create a direct object of `Person`?
    No, because it is abstract.

13. What is single inheritance in this project?
    `Student` inherits from `Person`.

14. What is multi-level inheritance in this project?
    `GradStudent` inherits from `Student`, and `Student` inherits from `Person`.

15. What is runtime polymorphism?
    Calling derived class functions using a base class pointer.

16. Where is runtime polymorphism used?
    In `main.cpp`, `Person* people[]` calls different `displayInfo()` methods.

17. Why is `displayInfo()` virtual?
    So the correct derived class version runs at runtime.

18. What does protected mean?
    Protected members can be used inside the class and its derived classes.

## Course Module

19. What does `Course::operator==` do?
    It compares two courses by course code.

20. Why is `operator<<` a friend function?
    So it can print private course data directly.

21. What does `Course::operator+` do?
    It merges two course waiting lists.

22. What is aggregation in the Course class?
    Course stores a `Faculty*` but does not own the Faculty object.

23. What happens when course capacity is full?
    `CapacityExceededException` is thrown.

24. Why is exception handling used?
    To handle runtime problems without crashing the program.

## Library Module

25. Why is `LibraryItem` abstract?
    Book and Journal have different checkout/display behavior.

26. Why does Library store `LibraryItem*`?
    To store both Book and Journal objects in one array.

27. What is `searchByTitle()`?
    It loops through all items and compares their title.

28. What is `searchByID()`?
    It loops through all items and compares their item ID.

29. Where is file input used?
    `Library::loadCatalog()` reads `data/library_catalog.txt`.

30. Where is file output used?
    `Library::saveCatalog()` writes a text catalog file.

31. Why does Library have a destructor?
    It deletes dynamically allocated Book and Journal objects.

32. What is `OverdueException`?
    A custom exception for late library return fine.

## Finance Module

33. What does `FeeRecord` store?
    Student fee, hostel fee, library fine, paid amount, and balance.

34. What does `operator-=` do in FeeRecord?
    It records payment and updates balance.

35. What is a copy constructor?
    A constructor that creates an object by copying another object.

36. Where is copy assignment used?
    In `FeeRecord::operator=` and `Invoice::operator=`.

37. What is a static member?
    A member shared by all objects of a class.

38. Where is static member used?
    `Invoice::invoiceCounter`.

39. Why does Invoice use dynamic memory?
    It stores invoice item names in a runtime array.

40. Why does Invoice need a destructor?
    To delete the dynamic item array.

## Hostel Module

41. What is multiple inheritance?
    A class inheriting from more than one base class.

42. Where is multiple inheritance used?
    `HostelManager` inherits from `Accommodation` and `Reportable`.

43. What is virtual inheritance?
    It prevents duplicate base class copies in a diamond style hierarchy.

44. What is composition?
    A class containing another object as its data member.

45. Where is composition used?
    `HostelManager` contains a `HostelBlock`.

46. Why does Room store `Student*`?
    Room only references students, it does not own them.

## Reports Module

47. What does `std::sort` do?
    It sorts the student pointer array by GPA.

48. What file does the report function create?
    `data/campus_report.txt`.

49. What utility function gives the date?
    `Utils::getTodayDate()`.

50. What is the purpose of reports?
    To print or save summary information about the campus system.

## Code Review Questions

51. How do you compile the project?
    Run `build.bat`.

52. How do you run the project?
    Run `scms.exe` or `run.bat`.

53. What is the main function doing?
    It creates sample objects and shows a menu.

54. What would you change if asked to add a new student?
    Add a new Student object and include it in the arrays.

55. What is still simple in this project?
    It uses fixed sample data and simple arrays instead of a full database.

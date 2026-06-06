# Module 3 Status - Library System

Status: Complete and tested.

## Required Classes

- `LibraryItem`: abstract base class
- `Book`: derived from `LibraryItem`
- `Journal`: derived from `LibraryItem`
- `Library`: manages an array of `LibraryItem*`

## Required Data Members

- `LibraryItem`: itemID, title, author, publicationYear
- `Book`: ISBN, genre, copiesAvailable
- `Journal`: ISSN, volume, issueNumber
- `Library`: items array, itemCount, issued records array, issuedCount

## Required Operations

- `LibraryItem::checkout()` is pure virtual.
- `Book::checkout()` decreases available copies.
- `Journal::checkout()` records a journal reading entry.
- `Library::searchByTitle()` loops through catalog and finds matching title.
- `Library::saveCatalog()` writes catalog to a text file using `ofstream`.
- `Library::loadCatalog()` reads catalog from a text file using `ifstream`.
- `Library::issueItem()` stores rollNo and itemID in a simple issued record array.
- `Library::returnItem()` marks the record returned and throws `OverdueException` when late.
- `Library::displayIssuedRecords()` prints issued item records.

## OOP Concepts Covered

- Abstract class
- Pure virtual function
- Inheritance
- Runtime polymorphism
- Array of base-class pointers
- File I/O with `fstream`
- Searching with loops
- Exception handling
- Dynamic memory using `new` and `delete`

## Where It Is Tested

Run:

```text
Home -> 3. Library Module -> 1. Load catalog from file
Home -> 3. Library Module -> 2. Show catalog
Home -> 3. Library Module -> 3. Search by title
Home -> 3. Library Module -> 4. Issue item B001 to 25-CS-067
Home -> 3. Library Module -> 5. Return item B001 with overdue fine
Home -> 3. Library Module -> 6. Show issued records
Home -> 3. Library Module -> 7. Save catalog to file
```

Expected result:

- Catalog loads from `data/library_catalog.txt`.
- Book and journal display correctly.
- Search finds `C++ Basics`.
- Issued record stores roll no and item ID.
- Overdue return throws and catches fine exception.
- Catalog saves to `data/library_catalog_saved.txt`.

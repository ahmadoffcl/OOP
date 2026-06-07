# Module 3 Status - Library System

Status: Complete and tested as a real saved library management module.

## Required Classes

- `LibraryItem`: abstract base class
- `Book`: derived from `LibraryItem`
- `Journal`: derived from `LibraryItem`
- `Library`: manages an array of `LibraryItem*` and issued records

## Required Data Members

- `LibraryItem`: itemID, title, author, publicationYear
- `Book`: ISBN, genre, copiesAvailable
- `Journal`: ISSN, volume, issueNumber
- `Library`: items array, itemCount, issued records array, issuedCount

## Saved Files

Catalog file:

```text
data/library_catalog.txt
```

Catalog format:

```text
Book|itemID|title|author|publicationYear|isbn|genre|copiesAvailable
Journal|itemID|title|author|publicationYear|issn|volume|issueNumber
```

Issued records file:

```text
data/library_issued.txt
```

Issued format:

```text
rollNo|itemID|daysLate|returned
```

`returned` is `0` for not returned and `1` for returned.

## Required Operations

- `LibraryItem::checkout()` is pure virtual.
- `Book::checkout()` decreases available copies.
- `Journal::checkout()` records a journal reading entry.
- `Library::searchByTitle()` loops through catalog and finds a matching title.
- `Library::searchByID()` loops through catalog and finds a matching ID.
- `Library::addItem()` adds a real book or journal from keyboard input.
- `Library::deleteItemByID()` removes a saved item if it is not currently issued.
- `Library::saveCatalog()` and `Library::loadCatalog()` save/load catalog records.
- `Library::saveIssuedRecords()` and `Library::loadIssuedRecords()` save/load issue history.
- `Library::issueItem()` stores rollNo and itemID in a simple issued record array.
- `Library::returnItem()` marks the record returned and throws `OverdueException` when late.
- `Library::displayIssuedRecords()` prints issued item records.

## Library Module Menu

```text
1. Show catalog
2. Add Book
3. Add Journal
4. Search by title
5. Search by item ID
6. Issue item
7. Return item
8. Show issued records
9. Delete item by ID
10. Save library records
11. Reload library records
0. Back to Home
```

## OOP Concepts Covered

- Abstract class
- Pure virtual function
- Inheritance
- Runtime polymorphism
- Array of base-class pointers
- File I/O with `fstream`
- Searching with loops
- Exception handling with custom exception
- Dynamic memory using `new` and `delete`

## Where It Is Tested

Run:

```text
Home -> 3. Library Module -> 2. Add Book
Home -> 3. Library Module -> 3. Add Journal
Home -> 3. Library Module -> 4. Search by title
Home -> 3. Library Module -> 5. Search by item ID
Home -> 3. Library Module -> 6. Issue item
Home -> 3. Library Module -> 7. Return item
Home -> 3. Library Module -> 8. Show issued records
Home -> 3. Library Module -> 9. Delete item by ID
Home -> 3. Library Module -> 10. Save library records
Home -> 3. Library Module -> 11. Reload library records
```

Expected result:

- Catalog loads from `data/library_catalog.txt`.
- Book and journal records can be added from keyboard input.
- Search finds saved records by title or item ID.
- Issue item uses a saved student roll number and real item ID.
- Duplicate issue for the same active roll/item is blocked.
- Return with more than 7 late days catches and prints the overdue fine.
- Delete removes a non-issued item.
- Catalog and issued records persist after save and reload.

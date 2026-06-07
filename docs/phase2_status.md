# Phase 2 Status

Phase 2 modules are Library and Finance.

## Library Module

Implemented files:

- `src/library/LibraryItem.h`
- `src/library/LibraryItem.cpp`
- `src/library/Book.h`
- `src/library/Book.cpp`
- `src/library/Journal.h`
- `src/library/Journal.cpp`
- `src/library/Library.h`
- `src/library/Library.cpp`

Features:

- Abstract `LibraryItem` class
- `Book` and `Journal` derived classes
- Array of `LibraryItem*`
- `searchByTitle()`
- `searchByID()`
- `issueItem()`
- `returnItem()` with overdue fine exception
- `saveCatalog()`
- `loadCatalog()`
- `saveIssuedRecords()`
- `loadIssuedRecords()`
- Real add/search/delete/issue/return menu actions

## Finance Module

Implemented files:

- `src/finance/FeeRecord.h`
- `src/finance/FeeRecord.cpp`
- `src/finance/Invoice.h`
- `src/finance/Invoice.cpp`

Features:

- Fee balance calculation
- Payment using `operator-=`
- Copy constructor in `FeeRecord`
- Copy assignment in `FeeRecord`
- Static `Invoice::invoiceCounter`
- Dynamic invoice item array
- Copy constructor in `Invoice`
- Copy assignment in `Invoice`
- Destructor in `Invoice`

## Test Result

Phase 2 menu options tested:

- Option 3: Library real management module
- Option 4: Finance module

Both run successfully after compiling with `build.bat`.

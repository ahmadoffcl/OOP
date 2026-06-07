# Module 4 Status - Fee and Finance Management

Status: Complete and tested as a real saved finance management module.

## Required Classes

- `FeeRecord`
- `Invoice`
- `FinanceManager`

## FeeRecord Data Members

- studentRef
- semesterFee
- hostelFee
- libraryFine
- totalPaid
- balance
- payments dynamic array
- paymentCount

## Invoice Data Members

- static invoiceCounter
- invoiceID
- date
- items dynamic array
- itemCount
- totalAmount

## FinanceManager Data Members

- `FeeRecord records[MAX_FEE_RECORDS]`
- recordCount
- fileName

## Saved File

Fee record file:

```text
data/fee_records.txt
```

Format:

```text
rollNo|semesterFee|hostelFee|libraryFine|paymentCount|payment1|payment2
```

## Required Operations

- `Invoice::invoiceCounter` is a static data member shared by all Invoice objects.
- `Invoice::getInvoiceCounter()` is a static member function.
- `FeeRecord` has copy constructor and copy assignment operator.
- `FeeRecord` deep-copies the dynamic payment history array.
- `FeeRecord::operator-=` records a payment and updates balance.
- `Invoice` destructor deletes the dynamic item array.
- `operator<<` prints invoice details.
- `FinanceManager::addRecord()` adds a real student fee record.
- `FinanceManager::recordPayment()` uses overloaded `-=` to record payments.
- `FinanceManager::saveToFile()` and `loadFromFile()` save/reload fee records.

## Finance Module Menu

```text
1. Show all fee records
2. Add fee record
3. Search fee record by roll no
4. Record payment using -=
5. Add library fine
6. Show payment history
7. Generate invoice
8. Show FeeRecord copy constructor/assignment
9. Save finance records
10. Reload finance records
0. Back to Home
```

## OOP Concepts Covered

- Static data member
- Static member function
- Copy constructor
- Copy assignment
- Deep copy
- Destructor
- Dynamic memory
- Operator overloading
- Friend function
- File I/O with `fstream`

## Where It Is Tested

Run:

```text
Home -> 4. Fee and Finance Module -> 2. Add fee record
Home -> 4. Fee and Finance Module -> 3. Search fee record by roll no
Home -> 4. Fee and Finance Module -> 4. Record payment using -=
Home -> 4. Fee and Finance Module -> 5. Add library fine
Home -> 4. Fee and Finance Module -> 6. Show payment history
Home -> 4. Fee and Finance Module -> 7. Generate invoice
Home -> 4. Fee and Finance Module -> 8. Show FeeRecord copy constructor/assignment
Home -> 4. Fee and Finance Module -> 9. Save finance records
Home -> 4. Fee and Finance Module -> 10. Reload finance records
```

Expected result:

- Fee records load from `data/fee_records.txt`.
- New fee record can be added using a saved student roll number.
- Payment updates `totalPaid` and `balance` through overloaded `-=`.
- Library fine increases balance.
- Payment history prints saved payments.
- Invoice IDs auto-increment through static counter.
- Copied and assigned fee records show copied payment history.
- Save/reload keeps fee records and payments.

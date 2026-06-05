# Module 4 Status - Fee and Finance Management

Status: Complete and tested.

## Required Classes

- `FeeRecord`
- `Invoice`

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

## Required Operations

- `Invoice::invoiceCounter` is a static data member shared by all Invoice objects.
- `Invoice::getInvoiceCounter()` is a static member function.
- `FeeRecord` has copy constructor.
- `FeeRecord` has copy assignment operator.
- `FeeRecord` deep-copies the dynamic payment history array.
- `FeeRecord::operator-=` records a payment and updates balance.
- `Invoice` has copy constructor.
- `Invoice` has copy assignment operator.
- `Invoice` destructor deletes the dynamic item array.
- `operator<<` prints invoice details.

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

## Where It Is Tested

Run:

```text
Home -> 4. Fee and Finance Module -> 1. Show fee record and payment
Home -> 4. Fee and Finance Module -> 2. Show fee copy constructor and assignment
Home -> 4. Fee and Finance Module -> 3. Show invoice, copies, and static counter
```

Expected result:

- Fee balance changes after payment.
- Payment history is displayed.
- Copied and assigned fee records show copied payment history.
- Invoice IDs auto-increment.
- Invoice copy constructor and assignment print copied invoice data.

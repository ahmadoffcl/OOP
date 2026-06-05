# Module 5 Status - Hostel Management

Status: Complete and tested.

## Required Classes

- `CampusService`
- `Accommodation`
- `Reportable`
- `Room`
- `HostelBlock`
- `HostelManager`

## Required Data Members

- `Room`: roomNumber, type, floor, occupants array, occupantCount
- `HostelBlock`: blockName, rooms array, roomCount
- `HostelManager`: HostelBlock object

## Required Operations

- `Accommodation::allocateRoom()` is pure virtual.
- `Accommodation::vacateRoom()` is pure virtual.
- `Reportable::generateReport()` is pure virtual.
- `Room::addStudent()` adds a student pointer to occupants array.
- `Room::removeStudent()` removes a student by roll number.
- `Room::hasStudent()` checks duplicate allocation.
- `HostelBlock` stores Room objects by composition.
- `HostelManager::allocateRoom()` assigns student to first available room.
- `HostelManager::vacateRoom()` removes student from room.
- `HostelManager::generateReport()` prints occupancy report.
- `HostelManager::showSummary()` prints room and occupant totals.

## OOP Concepts Covered

- Multiple inheritance
- Virtual inheritance
- Abstract classes
- Pure virtual functions
- Composition
- Aggregation
- Arrays of objects
- Arrays of pointers
- Destructor

## Where It Is Tested

Run:

```text
Home -> 5. Hostel Module -> 1. Show hostel service name
Home -> 5. Hostel Module -> 2. Allocate sample students
Home -> 5. Hostel Module -> 3. Try duplicate allocation
Home -> 5. Hostel Module -> 4. Show hostel summary
Home -> 5. Hostel Module -> 5. Show occupancy report
Home -> 5. Hostel Module -> 6. Vacate Ahmad Ali room
```

Expected result:

- Hostel service name prints.
- Three students allocate to room 101.
- Duplicate allocation is blocked.
- Summary shows total rooms and occupants.
- Occupancy report shows rooms and occupants.
- Vacate option removes Ahmad Ali from the hostel.

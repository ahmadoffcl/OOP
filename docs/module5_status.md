# Module 5 Status - Hostel Management

Status: Complete, real input-based, saved to files, and tested.

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
- `HostelManager`: HostelBlock object, room file name, allocation file name

## Data Files

```text
data/hostel_rooms.txt
data/hostel_allocations.txt
```

Room format:

```text
roomNumber|type|floor
```

Allocation format:

```text
rollNo|roomNumber
```

## Required Operations

- `Accommodation::allocateRoom()` is pure virtual.
- `Accommodation::vacateRoom()` is pure virtual.
- `Reportable::generateReport()` is pure virtual.
- `Room::addStudent()` adds a saved student pointer to the occupants array.
- `Room::removeStudent()` removes a student by roll number.
- `Room::hasStudent()` checks duplicate allocation.
- `Room::getCapacity()` supports single, double, and triple rooms.
- `HostelBlock` stores `Room` objects by composition.
- `HostelBlock::findRoomByNumber()` searches rooms.
- `HostelBlock::removeRoom()` deletes only empty rooms.
- `HostelManager::allocateRoom()` assigns a student to the first available room.
- `HostelManager::allocateRoomToNumber()` assigns a student to a selected room.
- `HostelManager::vacateRoom()` removes student allocation by roll number.
- `HostelManager::saveToFile()` and `loadFromFile()` save/reload rooms and allocations.
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
- File I/O
- Destructor

## Menu Options

```text
1. Show hostel service name
2. Show all rooms
3. Add room
4. Search room by number
5. Allocate student to room
6. Auto allocate student
7. Vacate student room
8. Show student's room
9. Show hostel summary
10. Show occupancy report
11. Save hostel records
12. Reload hostel records
13. Delete empty room
0. Back to Home
```

## Where It Is Tested

Run:

```text
Home -> 5. Hostel Module -> 2. Show all rooms
Home -> 5. Hostel Module -> 3. Add room
Home -> 5. Hostel Module -> 4. Search room by number
Home -> 5. Hostel Module -> 5. Allocate student to room
Home -> 5. Hostel Module -> 8. Show student's room
Home -> 5. Hostel Module -> 6. Auto allocate student
Home -> 5. Hostel Module -> 7. Vacate student room
Home -> 5. Hostel Module -> 13. Delete empty room
Home -> 5. Hostel Module -> 11. Save hostel records
Home -> 5. Hostel Module -> 12. Reload hostel records
Home -> 5. Hostel Module -> 10. Show occupancy report
```

Expected result:

- Saved hostel rooms load from `data/hostel_rooms.txt`.
- Saved allocations load from `data/hostel_allocations.txt`.
- New rooms can be added and searched.
- Saved students can be allocated by roll number.
- Duplicate allocation is blocked.
- Vacate removes a student from the room.
- Empty rooms can be deleted.
- Save/reload keeps room and allocation data.
- Occupancy report shows room-wise occupants.

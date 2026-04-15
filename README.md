# CSE-115 Assignment 1 — User Defined Data Types

Four separate solutions to the Lecture-15 assignment (user-defined `struct`,
array of at least 5 elements, with searching and sorting). Pick the one you
want to submit — they all follow the same style from the class slides.

## Assignment Brief (short)

Write a C program using a user-defined data type (structure). Design your own
struct (not Student, Teacher, Employee, Book, ComplexNumber, Address,
BirthDate, BirthCertificate, Person, Distance). Make an array of at least 5
elements and perform a valid operation such as searching or sorting. Submit
only the `.c` file, named `Assignment1_<your-id>.c`.

## Files

| File | Struct idea | Search key | Sort key |
|------|-------------|------------|----------|
| [Assignment1_parcel.c](Assignment1_parcel.c) | Courier Parcel Tracking | `trackingID` | `cost` |
| [Assignment1_busticket.c](Assignment1_busticket.c) | Intercity Bus Ticket | `ticketNo` | `fare` |
| [Assignment1_tiffin.c](Assignment1_tiffin.c) | Tiffin Lunch Delivery | `orderID` | `price` |
| [Assignment1_drone.c](Assignment1_drone.c) | Drone Flight Log | `flightID` | `duration` |

Each file is self-contained: one `struct`, one `typedef`, one array of 6
elements, and three functions (`Display`, `Search`, `Sort...`).

## How this matches the lecture

| Lecture slide | Concept | Where it appears |
|---------------|---------|------------------|
| 4 | `struct` declaration | `struct parcel { ... };` |
| 10 | Dot operator `.` | `p[i].trackingID`, etc. |
| 11 | `=` copies a whole struct | swap step inside the bubble sort |
| 15–17 | `typedef` alias | `typedef struct parcel ParcelData;` |
| 18 | `#define` for array size | `#define SIZE 6` |
| 18–20 | Array of struct + helper functions | `Display`, `Search`, `SortByCost` |
| 22 | Pass struct (array) to a function | All three helpers take `ParcelData p[]` |

## How to build & run

```bash
gcc Assignment1_parcel.c -o parcel && ./parcel
gcc Assignment1_busticket.c -o bus && ./bus
gcc Assignment1_tiffin.c -o tiffin && ./tiffin
gcc Assignment1_drone.c -o drone && ./drone
```

Each program:

1. prints the original list,
2. asks you for one ID and runs a linear search,
3. sorts the array using bubble sort, and
4. prints the sorted list.

Test with a valid ID (e.g. `1023` for parcel, `502` for bus, `9003` for
tiffin, `7004` for drone) and with a bogus ID to confirm the "not found"
branch works.

## Before submitting to Canvas

1. Rename the file you pick to `Assignment1_<your-id>.c` — for example
   `Assignment1_2312345042.c`.
2. Change a couple of the sample rows (IDs, names, prices) so the data is
   clearly yours.
3. Compile and run once to make sure it builds cleanly.
4. Upload only the `.c` file. No `.exe`, no zip.

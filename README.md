# CSE-115 Assignment 1 — User Defined Data Types

Eleven separate solutions to the Lecture-15 assignment (user-defined `struct`,
array of at least 5 elements, with searching and sorting). Pick **one** to
submit — they all follow the same style from the class slides.

## Assignment brief (short)

Write a C program using a user-defined data type (structure). Design your own
struct — not Student, Teacher, Employee, Book, ComplexNumber, Address,
BirthDate, BirthCertificate, Person, or Distance. Make an array of at least 5
elements and perform at least one valid operation (e.g. searching, sorting).
Submit only the `.c` file, named `Assignment1_<your-id>.c`.

## Files

| File | Struct idea | Search key | Sort key |
|------|-------------|------------|----------|
| [Assignment1_parcel.c](Assignment1_parcel.c) | Courier Parcel Tracking | `trackingID` | cost |
| [Assignment1_busticket.c](Assignment1_busticket.c) | Intercity Bus Ticket | `ticketNo` | fare |
| [Assignment1_tiffin.c](Assignment1_tiffin.c) | Tiffin Lunch Delivery | `orderID` | price |
| [Assignment1_drone.c](Assignment1_drone.c) | Drone Flight Log | `flightID` | duration |
| [Assignment1_cricket.c](Assignment1_cricket.c) | Cricket Match Record | `matchID` | winning margin |
| [Assignment1_solar.c](Assignment1_solar.c) | Solar Panel Installation | `installID` | cost |
| [Assignment1_bakery.c](Assignment1_bakery.c) | Bakery Cake Order | `orderID` | price |
| [Assignment1_gym.c](Assignment1_gym.c) | Gym Workout Session | `sessionID` | calories burned |
| [Assignment1_recharge.c](Assignment1_recharge.c) | Mobile Recharge Transaction | `txnID` | amount |
| [Assignment1_movie.c](Assignment1_movie.c) | Movie Screening / Show | `showID` | seats booked |
| [Assignment1_chess.c](Assignment1_chess.c) | Chess Tournament Game | `gameID` | move count |
| [Assignment1_nursery.c](Assignment1_nursery.c) | Plant Nursery Stock | `plantID` | price per pot |
| [Assignment1_foodtruck.c](Assignment1_foodtruck.c) | Food Truck Sale | `saleID` | total amount |
| [Assignment1_taxi.c](Assignment1_taxi.c) | Taxi / CNG Ride Log | `rideID` | fare |

Every file is self-contained: one `struct`, one `typedef`, one array of 6
elements, and three functions (`Display`, `Search`, `Sort...`).

## How this matches the lecture

| Lecture slide | Concept | Where it appears |
|---------------|---------|------------------|
| 4 | `struct` declaration | `struct parcel { ... };` |
| 10 | Dot operator `.` | `p[i].trackingID`, etc. |
| 11 | `=` copies a whole struct | swap step inside bubble sort |
| 15–17 | `typedef` alias | `typedef struct parcel ParcelData;` |
| 18 | `#define` for array size | `#define SIZE 6` |
| 18–20 | Array of struct + helper functions | `Display`, `Search`, `SortBy...` |
| 22 | Passing a struct (array) to a function | All three helpers take an array |

## Build & run

```bash
gcc Assignment1_parcel.c     -o parcel     && ./parcel
gcc Assignment1_busticket.c  -o bus        && ./bus
gcc Assignment1_tiffin.c     -o tiffin     && ./tiffin
gcc Assignment1_drone.c      -o drone      && ./drone
gcc Assignment1_cricket.c    -o cricket    && ./cricket
gcc Assignment1_solar.c      -o solar      && ./solar
gcc Assignment1_bakery.c     -o bakery     && ./bakery
gcc Assignment1_gym.c        -o gym        && ./gym
gcc Assignment1_recharge.c   -o recharge   && ./recharge
gcc Assignment1_movie.c      -o movie      && ./movie
gcc Assignment1_chess.c      -o chess      && ./chess
gcc Assignment1_nursery.c    -o nursery    && ./nursery
gcc Assignment1_foodtruck.c  -o foodtruck  && ./foodtruck
gcc Assignment1_taxi.c       -o taxi       && ./taxi
```

Each program:

1. prints the original list,
2. asks you for one ID and runs a linear search,
3. sorts the array using bubble sort, and
4. prints the sorted list.

Test with a valid ID and with a bogus ID to confirm the "not found" branch.

## Before submitting to Canvas

1. Rename the file you pick to `Assignment1_<your-id>.c` — e.g.
   `Assignment1_2312345042.c`.
2. Change a few of the sample rows (IDs, names, prices) so the data is
   clearly yours.
3. Compile and run once to make sure it builds cleanly with no warnings.
4. Upload only the `.c` file. No `.exe`, no zip.

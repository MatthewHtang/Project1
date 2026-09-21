# Contribution Report

**Project:** Reservation System\
**Course:** CSCE 2110: Foundations of Data Structures\
**Last Updated:** 09-05-2026

---

## Summary Table
| Team Member | Component(s) | Specific Tasks Completed | Testing/Debugging | GitHub Contributions |
|-------------|--------------|--------------------------|-------------------|----------------------|
| Matthew | •ReservationList.h<br>•ReservationList.cpp<br>•WaitingList.h<br>•WaitingList.cpp<br>•main.cpp<br>•CancellationHistory.cpp<br>•Readme.md | Please see the Detailed Work Log below | •Rename variable names to match with the caller<br>•Merge Conflicts<br>•Branch Conflicts<br>•Bug Fixed: Commit Tunnel Problems | •Resource.h<br>•Resource.cpp<br>•ResourceManager.h<br>•ResourceManager.cpp| Please see the Detailed Work Log below | None | Please see the Detailed Work Log below
| Alka |•Reservation.h<br>•Reservation.cpp<br>•ReservationManager.cpp<br>•ReservationManager.h| •Designed the Reservation class<br>•Wrote Reservation constructors, getters, and display<br>•Wrote ReservationManager to connect all the classes<br>•Implemented create, cancel, and undo reservation<br>•Added one waiting list per resource using a map<br>•Wrote complexity breakdown for my classes | •Tested reserving an available and an unavailable resource<br>•Tested cancelling with and without a waiting list<br>•Tested undoing a cancellation<br>•Fixed errors in ReservationManager.cpp | •Reservation.h<br>•Reservation.cpp<br>•ReservationManager.h<br>•ReservationManager.cpp |


---

# Detailed Work Log

## Matthew
- **09-07-2026** — Added main menu to the program. [`f92d8c9`](https://github.com/MatthewHtang/Project1/commit/f92d8c935d8da24139412f8815dc8150ea99eeca)

- **09-08-2026** — Enhance main menu display and add new header/source files for resource management. [`29cea2b`](https://github.com/MatthewHtang/Project1/commit/29cea2b8eba540fd980db74aa61b58d9d0b354f3)

- **09-09-2026** — Add ReservationList class with Node structure (to be Continue)and update .gitignore. [`da005e0`](https://github.com/MatthewHtang/Project1/commit/da005e090b73ac5d7889159e91c28fa6ea068930)

- **09-09-2026** — Refactor ReservationList class and Node structure for clarity and organization. [`f52ea94`](https://github.com/MatthewHtang/Project1/commit/f52ea9437e807797425f2af2572b4a4bd30a09a5)

- **09-11-2026** — Fix memory management in ReservationList class and correct insert method implementation
[`281c103`](https://github.com/MatthewHtang/Project1/commit/281c103425c92075b0ab52150eba4e059d90f3a2)

- **09-12-2026** — Refactor ReservationList class: improve comments, implement remove method, and fix insert logic
[`6fe25e4`](https://github.com/MatthewHtang/Project1/commit/6fe25e4bc5409dab8ae4094e4053bb6318bd05c7)

- **09-13-2026** — Refactor Reservation class: change resourceId type to string and update constructor and getter methods. And finally wrapped up ReservationList.cpp (Review might require later)[`43276b4`](https://github.com/MatthewHtang/Project1/commit/43276b4ab886aa4c48d5f433fe904030e961a4cb)

- **09-15-2026** — Implement WaitingList.h and WaitingList.cpp's class with enqueue. (Dequeue methods, not finish yet- to be continue)[`f33b9d3`](https://github.com/MatthewHtang/Project1/commit/f33b9d3442a239c80d5f100b901ff5a779165bff)

- **09-16-2026** — Continue implementing the dequeue, peekFront,  displayAll, isEmpty, and getCount methods in WaitingList class[`4466870`](https://github.com/MatthewHtang/Project1/commit/44668704f2abe5342a91e86f5a7e778803da4bfa)

- **09-17-2026** — Implement CancellationHistory class with stack functionality for managing cancelled reservations[`fe86596`](https://github.com/MatthewHtang/Project1/commit/fe86596e0e7b8626975fe20ea436c7da5c5dc114)

- **09-17-2026** — Change Resource class to use string for resourceId and rename availability status
[`752db98`](https://github.com/MatthewHtang/Project1/commit/752db987c692f2a5b3fd5422b0137d771c99e360)

- **09-17-2026** — Changed some of the data types and name from Reseource Manager.h/.cpp
[`d822958`](https://github.com/MatthewHtang/Project1/commit/d822958969eb6951b39bf6f0fe8606ea808ba51c)

- **09-17-2026** — implement a method to flushes the pipe and case 1 in main.cpp
[`34794e1`](https://github.com/MatthewHtang/Project1/commit/34794e1fddb0406d2b5009e6afff3a65839ed61b)

- **09-18-2026** — Refactor main.cpp: Remove ResourceManager instantiation and clean up input handling
[`6d431e8`](https://github.com/MatthewHtang/Project1/commit/6d431e85ca79d5133b8619fce893861f6530541a)

- **09-19-2026** — Update complexity analysis and fix typos in WaitingList implementation; add tempCodeRunnerFile.h
[`bf7ff41`](https://github.com/MatthewHtang/Project1/commit/bf7ff4158c40f52bf50d6eaa911f57f569f0b199)

- **09-19-2026** — Update contributions log and README; modify resource availability in resources.txt
[`76eecd5`](https://github.com/MatthewHtang/Project1/commit/76eecd52f6f660e53bde46cfe01db6ad4347d8ed)
---


## Sankalp
- **09-08-2026** — Testing from Sankalp Branch. [`780e914`](https://github.com/MatthewHtang/Project1/commit/780e914e2da494096fc1eb2a406ec09851d14e21)
- **09-10-2026** — Added the Resource class header file (Resource.h) and added variables for resource ID, name, type, and availability. Also added  constructor functions. [`a1b2c3d`](../../commit/a1b2c3d)
- **09-13-2026** — Added resource.cpp class. [`427e3bd`](https://github.com/MatthewHtang/Project1/commit/427e3bda29c3c6157f77e9d7d318f12b8ad4bb4b)
- **09-15-2026** — Added resourceManager class header with comments. [`
95e32d8`](https://github.com/MatthewHtang/Project1/commit/95e32d84733e075d6410fb2b49537f22e24008f0)
- **09-17-2026** — Added resourceManager.cpp, reservation.txt, resource.txt files in the github. [`01cbf9c`](https://github.com/MatthewHtang/Project1/commit/01cbf9c4603dc5af269986cdc1387e9287f49a4c)
- **09-19-2026** — Edited contributions.md and reosurceManager file. [`a1b2c3d`](../../commit/a1b2c3d)
- **MM-DD-YYYY** — [Write what you did and why here]. [`a1b2c3d`](../../commit/a1b2c3d)

---

## Alka
- **09-10-2026** — Initial commit. [`335d9d3`](https://github.com/MatthewHtang/Project1/commit/335d9d31a67b271892aa9c6ae1bd517e09a8453a)
- **09-17-2026** — Added ReservationManager.h to define the structures and functions for resources, reservations, waiting list, and cancellation history. [`137dafa`](https://github.com/MatthewHtang/Project1/commit/137dafa71ecefaaa24baec0b3f4662f9f638a2be)
- **09-17-2026** — Updates and debugging reservation.h. [`a614795`](https://github.com/MatthewHtang/Project1/commit/a614795a2bb4fe01eef1eb5013e29c3cdd6b8f1a)
- **09-17-2026** — Merge branch 'main' of https://github.com/MatthewHtang/Project1 into alka. [`35f8624`](https://github.com/MatthewHtang/Project1/commit/35f86241d486fab8f909a09061d3e1fe8dc0f5c9)
- **09-17-2026** — Fixed bug2: Commit tunnel problem. [`4f67b27`](https://github.com/MatthewHtang/Project1/commit/4f67b27d948cab0f538f18e91002d220d948e9bc)
- **09-17-2026** — Updated CONTRIBUTIONS.md with detailed task descriptions and added string include in Reservation.cpp. [`715bcf6`](https://github.com/MatthewHtang/Project1/commit/715bcf6dee3615ca4846ec3abd56b6371833bffa)
- **09-17-2026** — Update contributions to include ReservationManager files.['a2e0bb3'](https://github.com/MatthewHtang/Project1/commit/a2e0bb3b41e5b07741e2fe4e40f7fae984adb3c8)

- **09-18-2026** — Add ReservationManager implementation. ['7a4e496'](https://github.com/MatthewHtang/Project1/commit/7a4e496575dc6789778675adf0a8e7400a8ee34e)

- **09-18-2026** — Update Reservation manager header. ['057327f'](https://github.com/MatthewHtang/Project1/commit/057327f95bacd92190e34c4fd07c499b813f9500)
- **09-18-2026** — Update ReservationManager implementation.[' 
c4b20ae'](https://github.com/MatthewHtang/Project1/commit/c4b20aef46b3093d4b0d93242e136b297d7b8761)




- Repository: https://github.com/MatthewHtang/Project1.git


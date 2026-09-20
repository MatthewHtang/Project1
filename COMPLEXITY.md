# Complexity Analysis - Milestone 1

# Sankalp's Complexity

- Resource
- ResourceManager

# Matthew's Complexity Breakdown

- ReservationList (Linked List)
In this ReservationList, I have implemented insertion, deletion and rearching algorithm using Linked List. The Big O Notation for this is O(N). Imagine this reservation list as a train. A train has a head and a tail. In our case, we have 'head' and 'nullptr'. Each and every section (node) of the train points their behind. If the boss wanted to add or insert or delete, he has to go from the head, and since the node or a train section only has one pointer, the boss doesn't know where to go, other than follwing each pointer. He check node A, if he can't find it, check where node A is connected with, then node A points to node B, now the boss goes to node B and so on until he reach the tail.

- WaitingList (Queue)
Queue is used for creating waiting list system. It has three major function: dequeue, enqueue and peek front. I magine you are waiting a line in a reception, the receptionist add new more people at the end, and who ever first line get served first (FIFO). The boss wanted to add a student so he just put him at the back (Enqueue - O(1)). If the boss wanted to start helping student, he just call the first person (Dequeue - 0(1)). For a queue system, we don't need to put student in the middle or take the student from the middle. That's why we have two pointer, front and end. 

- CancellationHistory (Stacked)
The big O notation for the cancellation history is 0(1). Since it's a stack, we only need one single pointer, which is the top (LIFO). Imagine a student cancel a reservation, the boss put that reservaiton his desk. If the boss needed to hack back that cancellation, he doesn't need to go all the way down, it's alwaying sitting on the top, so he just grab it. First, he slaps it on his desk (push), he grab it off the table (pop). The boss has to access the top one on the stack no matter what. That's why big O notation for this stack is 0(1).

# Alka's Complexity Breakdown

* Reservation (Data Class)
 The Reservation class is a simple record that stores the reservation ID, student ID, student
 name, resource ID, and date. It doesn't use a data structure. The constructors, getters, and
 display function all work with a fixed number of fields, so they take O(1) time. These records
 are stored in the linked list, the waiting list, and the cancellation stack.

* ReservationManager
 ReservationManager connects the resource list, the active reservation linked list, the waiting
 lists (queues), and the cancellation history (stack). The only structure it owns is a map that
 gives each resource its own waiting list. Its running time comes from the operations it calls.

 n = active reservations, r = resources, k = resources with a waiting list,
 w = students waiting, h = cancelled reservations

 - Finding a waiting list: O(log k). The map is a balanced tree, so it doesn't check every entry.
 - Finding a resource: O(r). Resources are checked one by one until the ID matches.
 - createReservation: O(r + n). It finds the resource, then either adds the reservation to the
 linked list (O(n)) or adds the student to the waiting list (O(log k) lookup, O(1) enqueue).
 - cancelReservation: O(n). Finding and removing the reservation from the linked list is O(n).
 Pushing it onto the stack and dequeuing the next student are O(1). Adding the new reservation
 for that student is O(n) again, so the total is O(n).
 - restoreLastCancellation: O(n + r). Popping the stack is O(1), finding the resource is O(r),
 and inserting back into the linked list is O(n).
 - displayActiveReservations / traverseReservations: O(n). Each reservation is visited once.
 - displayWaitingList: O(k + w). Each waiting list and each student in it is visited once.
 - displayCancellationHistory: O(h). Each cancelled reservation is visited once.
 - loadResourcesFromFile / displayAllResources: O(r). This is handled by ResourceManager.

 Overall, the slowest operations are O(n) because the linked list has to be searched from the
 head one node at a time. The queue and stack operations are O(1).
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


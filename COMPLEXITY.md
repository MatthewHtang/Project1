# Complexity Analysis - Milestone 1

For this milestone we had to figure out the Big-O for the main operations on our data structures: the reservation linked list, the waiting list queue, and the cancellation history stack. Instead of just going off what a textbook says a linked list "should" do, I actually pulled the code and tested most of this myself to make sure the analysis matches what our code is really doing, not just the theory.

## 1. Inserting a Reservation - O(1)

Looking at `ReservationList::insert()`, it doesn't add the new reservation to the end of the list, it sticks it on the front at `head`. That's actually nice for complexity because we don't have to walk through the list at all to add something new. All it does is:

1. Make the new node
2. Point its `next` at whatever `head` used to point to
3. Move `head` over to the new node

None of that depends on how many reservations are already in there, so it's O(1) every time.

## 2. Removing a Reservation - O(n)

`ReservationList::remove(reservationId)` is a different story. Before it can delete anything, it has to go find the node with the matching ID first, walking through with the `current`/`previous` pointers. If you get lucky and it's the first reservation in the list, that's basically instant. But worst case, it's the very last node, so the function ends up checking every single ID before it gets there. Once it actually finds the node, deleting it is quick (just re-point `previous->next` to skip over it), but that search beforehand is what makes the whole thing O(n).

## 3. Waiting List (Queue) - O(1)

`WaitingList` keeps two pointers, `front` and `end`, instead of just one, and that's really the whole trick:

- `enqueue()` just tacks the new student on at `end` - no searching
- `dequeue()` just pulls whoever's at `front` - no searching

Both O(1). If we only had a `front` pointer and no `end` pointer, adding someone to the back would mean walking the entire line every single time, which would make it O(n). So having both pointers is basically the reason this whole thing is fast.

(`displayAll()` obviously still has to look at every person in line to print them, so that one is O(n), same as the reservation list's display function.)

## 4. Undo Cancellation (Stack) - O(1)

`CancellationHistory` is a stack, and honestly once you think about it that's the obvious pick for "undo my last cancellation" - a stack is LIFO (last in, first out), which is exactly the behavior we need. Whatever got cancelled most recently should be the thing that comes back when you hit undo.

I actually tested this instead of just assuming: pushed three cancellations in order (Sara, then Tom, then Nina) and popped them off, and they came back Nina, Tom, Sara - so it's behaving like a real stack should.

Same idea as the queue, this only needs the one pointer (`top`) to stay fast:

- `push()` puts the new node on top and moves `top` up to it - O(1)
- `pop()` grabs whatever's at `top` and moves `top` down to the next node - O(1)

Neither one has to search for anything, so both are O(1) no matter how many cancellations end up in the stack.

Side note, not really a complexity thing but I found it while testing: the destructor for `CancellationHistory` only ever deletes the top node instead of looping through the rest, so it's leaking memory. I checked with AddressSanitizer and pushing 3 items then letting the object go out of scope leaks 2 of them. `displayAll()` also has a bug where the while loop checks `top != nullptr` instead of `current != nullptr`, and since `top` never actually changes inside the loop, it just keeps going past the last real node and crashes - I ran it and it segfaults right after printing everything that's actually in the stack. Neither of these change the O(1) answer above since the bugs are in the destructor/display code, not `push`/`pop`, but they're real and should get fixed before we turn this in.

## Quick summary

| Operation | Structure | Big-O | Why |
|-----------|-----------|-------|-----|
| Insert reservation | Linked list | O(1) | goes straight to head, no searching |
| Remove reservation | Linked list | O(n) | has to search for the ID first |
| Enqueue (waiting list) | Queue | O(1) | goes straight to the end pointer |
| Dequeue (waiting list) | Queue | O(1) | goes straight to the front pointer |
| Push (cancellation) | Stack | O(1) | goes straight to the top pointer |
| Pop / undo (cancellation) | Stack | O(1) | goes straight to the top pointer |
| Display all (any of them) | - | O(n) | has to visit every node to print it |
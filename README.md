*Project from 42's Common Core, finished in December 2022.*

# push_swap
This project consists in writing an algorithm to sort a set of integers using two stacks, with the least amount of moves.

Available moves are:
- **swap** - Swap the first two elements at the top of a stack
- **push** - Push the element at the top of a stack on top of the other.
- **rotate** - Shift up all elements of a stack by 1.
- **reverse rotate** - Shift down all elements of a stack by 1.

The set of integers is passed as argument to the program, which will print out the list of moves it performs to sort it.

Example:
```bash
./push_swap 3 2 1
sa
rra
```

The algorithm used is a custom one, and is in turn a bit inefficient / unoptimized for larger stacks compared to popular sorting algorithms.

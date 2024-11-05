# Push_swap

`push_swap` is a sorting algorithm project written in C that sorts a stack of integers with a minimal set of operations. It implements a custom instruction language to move values between two stacks, aiming to sort with the fewest possible commands.

## How It Works

The program takes a series of integer values as input and outputs a list of commands to sort them in ascending order. It uses two stacks, `a` and `b`, and has access to specific operations to swap, push, and rotate elements in both stacks.

### Instructions

The following operations are used to manipulate the stacks:

- `sa`, `sb`, `ss`: Swap the top two elements of stack `a`, stack `b`, or both simultaneously.
- `pa`, `pb`: Push the top element of one stack to the other.
- `ra`, `rb`, `rr`: Rotate all elements in `a`, `b`, or both upwards.
- `rra`, `rrb`, `rrr`: Reverse rotate all elements in `a`, `b`, or both downwards.

## Usage

To run the program, use:
```bash
./push_swap <int1> <int2> <int3> ...
```

Example:
```bash
./push_swap 1000000 -1 0 23
```

Sample output:
```
ra
pb
pb
pa
pa
```

## Visualized Execution

To see how push_swap works in action, I used the Push_swap Visualizer which you can find following this link:
https://push-swap-visualizer.vercel.app

https://github.com/user-attachments/assets/93296d20-1905-476e-8c1d-5412577bca54

## Error Handling

If invalid arguments are provided, the program outputs:
```
Error
```

## Requirements

- Compiles with `make`
- Developed according to the 42 School Norms, with no memory leaks.

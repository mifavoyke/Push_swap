# Push_swap
[your-video-file.mp4](https://github.com/user-attachments/assets/2bcce691-a469-4fd1-a97b-c7cefca4e287)

I used the existing Push_swap Visualizer to create this video: https://push-swap-visualizer.vercel.app

`push_swap` is a sorting algorithm project written in C that sorts a stack of integers with a minimal set of operations.

## How It Works

The program takes a series of integer values as input and outputs a list of commands to sort them in ascending order. It uses two stacks, `a` and `b`, and has access to specific operations to swap, push, and rotate elements in both stacks.

### Instructions

The following operations are used to manipulate the stacks:

- `sa`, `sb`, `ss`: Swap the top two elements of stack `a`, stack `b`, or both simultaneously.
- `pa`, `pb`: Push the top element of one stack to the other.
- `ra`, `rb`, `rr`: Rotate all elements in `a`, `b`, or both upwards.
- `rra`, `rrb`, `rrr`: Reverse rotate all elements in `a`, `b`, or both downwards.

Example:
```bash
./push_swap 5 2  9 4 -4
```

Sample output:
```
Operations:
ra
pb
ra
ra
pb
sb
rra
pa
pa
Sorted stack:
-4 2 4 5 9
```


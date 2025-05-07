# Jumping Jim Solver

This project reads a grid of trampoline jump distances from an input file, computes a sequence of jumps from the top-left to the bottom-right cell (if possible), and writes the sequence of directions to an output file.

---

## Requirements

- A C++ compiler supporting C++ (e.g. g++).
- A terminal or command prompt.

---

## File Structure

```text
/your-project-folder
├── main.cpp      # C++ source code
├── input.txt     # Input file must be named exactly "input.txt"
└── output.txt    # Solution
```

### `input.txt` Format

1. **First line:** Two integers, R and C, separated by a space, representing the number of rows and columns.
2. **Next `R` lines:** Each line contains C integers (jump distances), separated by spaces.

Example:
```text
4 5
2 3 1 1 4
3 2 1 2 2
1 1 2 3 1
4 2 1 1 0
```

---

## Compilation & Execution

Open a terminal in the project directory and run:

```bash
# Compile the code
g++ main.cpp -o jim //can be anything but make sure to use the same name while executing the complied file

# Run the program (reads from input.txt, writes to output.txt)
./jim   
```

- **Input file:** Must be named `input.txt` and located alongside the executable.
- **Output file:** The program will create or overwrite `output.txt` in the same directory.

---

## Problem Approach

1. **Model as a graph:** Each cell `(i,j)` is a node. From that node, you can "jump" exactly `grid[i][j]` cells in one of four cardinal directions (North, East, South, West).
2. **Breadth-First Search (BFS):** Start from `(0,0)` and explore reachable nodes. Track:
   - A `visited` flag to avoid revisiting.
   - A `parent` pointer for each node to reconstruct the path.
   - A `moveDir` character (`'N'`,`'E'`,`'S'`,`'W'`) taken to reach that node.
3. **Path reconstruction:** Once the bottom-right `(R-1,C-1)` is reached, backtrack via `parent` pointers, collect the directions, reverse them, and output the sequence.
4. **No path:** If the goal is never visited, output `No path found`.

---

## Output

- If a path exists, `output.txt` will contain a space-separated list of directions, e.g.: 

  E E S S E

- If no path is possible, `output.txt` will contain:
 
  No path found



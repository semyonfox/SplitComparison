# Split Comparison

CLI tool for comparing swim split times between two races. Enter your times, see where you gained or lost.

## Usage

```bash
gcc SplitsCompare.c -o splitscompare
./splitscompare
```

Then follow the prompts:

1. Enter event distance (e.g., 1500)
2. Enter split interval (e.g., 50)
3. Enter times for Event 1 (mm.ss.ss format)
4. Enter times for Event 2
5. See side-by-side comparison with differences

## Example

```
Enter event distance (m): 1500
Enter split interval (e.g., 50 for splits every 50m): 50

----- Event 1 -----
Split 1: 28.50
...

----- Event 2 -----
Split 1: 27.80
...
```

## License

MIT

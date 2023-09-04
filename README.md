# NonogramSolver

Nonogram solver (what is [Nonogram](https://en.wikipedia.org/wiki/Nonogram))

# Building
```
cmake -B build
cmake --build build --target Nonogram
```

# Usage
Run application with input file

```./Nonogram <file>```

or provide data as input stream.

## Input format
```
<rows line by line>
-
<cols line by line>
```

Example:
```
1 1 1
3 4
-
3 5
4 2
```

# Unit tests

```
cmake -B build
cmake --build build --target UnitTests
build/UnitTests
```
# Coverage
```
cmake -B build
cmake --build build --target TestsGcovTarget
```
Results will be available in form of html under `build/coverage`

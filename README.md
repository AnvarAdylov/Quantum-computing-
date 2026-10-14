# PLA to Reversible Circuit Converter

Final project for a quantum computing course at Nazarbayev University. The goal: read a logic function written as a `.pla` truth table and turn it into a reversible (quantum-realisable) circuit in RevLib's `.real` format.

## What the program does

[`src/FinalProjectQC.c`](src/FinalProjectQC.c) asks for a `.pla` file and:

1. parses the header (`.i`, `.o`, `.ilb`, `.ob`) to get the input and output sizes and variable names
2. skips comment lines and prints the truth table
3. writes a `.real` circuit file with the header (`.numvars`, `.variables`, `.inputs`, …)

The gate synthesis step (mapping rows where bits flip onto Toffoli and controlled-V gates) is sketched in comments at the end of the file and described in the [report](docs/Report.pdf), but isn't implemented, so the output circuit has an empty body.

## Try it

```bash
gcc src/FinalProjectQC.c -o qc
./qc
# Enter name of a file you wish to see:      examples/toffoli_1.pla
# Enter name of a file you wish to save as:   out.real
# Enter comment for the circuit file:          Toffoli
```

## Repository layout

| Folder | Contents |
|---|---|
| [src](src) | The converter (C) |
| [examples](examples) | A Toffoli gate truth table and the matching circuit |
| [benchmarks](benchmarks) | RevLib benchmark functions: 133 `.pla` truth tables and 317 `.real` circuits |
| [docs](docs) | Project report and presentation slides |
| [papers](papers) | Background reading on reversible logic synthesis, including the RevLib paper |

Benchmark files come from [RevLib](http://www.revlib.org).

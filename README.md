# YAC - Yet Another Calculator

YAC is a command-line calculator for evaluating mathematical expressions and functions over a specified range with given steps.

## Installation

steps to install YAC:

```bash
git clone https://github.com/rmtfpp/yac-cli
cd yac-cli
sudo make install
```

This will compile the source code and install the yac binary to your system's /usr/local/bin directory.

## Usage

YAC can evaluate:
- Mathematical expressions.
- Functions over a range with a step size.

### Evaluate an Expression

To evaluate a single mathematical expression, use the -e flag:

```bash
yac -e "expression"
```
example:
```bash
yac -e "2 * (3 + 4)"
# Output: 14
```
### Evaluate a Function Over a Range

To evaluate a function across a range of values with a specified step size, use the -f flag:
```bash
yac -f "function" min max step
```
example:
```bash
yac -f "sin" 0 3.14 0.1
# Output: A table of sine values from 0 to π with a step of 0.1
```
### Supported Mathematical Functions

YAC supports some common built-in mathematical functions:

| Function | Description                              |
|----------|------------------------------------------|
| sin      | Sine of an angle (in radians)           |
| cos      | Cosine of an angle (in radians)         |
| tan      | Tangent of an angle (in radians)        |
| asn      | Arcsine (inverse sine)                  |
| acs      | Arccosine (inverse cosine)              |
| atn      | Arctangent (inverse tangent)            |
| lne      | Natural logarithm (ln)                  |
| exp      | Exponential function (e^x)              |
| log      | Logarithm (base 10)                     |
| srt      | Square root                             |
| crt      | Cube root                               |
| nrt      | Nth root (generalized)                  |
| max      | Maximum of two numbers                  |
| min      | Minimum of two numbers                  |

### Examples
Calculate the Natural Logarithm
```bash
yac -e "lne(5)"
# Output: 1.6094379
```
Evaluate Cosine Function Over a Range
```bash
yac -f "cos" 0 3.14 0.5
# Output:
# x: 0.00, cos(x): 1.000
# x: 0.50, cos(x): 0.877
# x: 1.00, cos(x): 0.540
# ...
```
Find the Maximum of Two Numbers
```bash
yac -e "max(3, 7)"
# Output: 7
```
## License

YAC is open-source and available under the MIT License.
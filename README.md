# PIC10C Final
## Code description
Created a simple calculator from scratch using Qt and C++.

## Complete
* UI, with buttons all connected.
* All operations (+ - * / %) work...
  * But in a specific format `a + b = c`
* Ability to change signs, clear entry, backspace.
* Decimals work.

## Persisting problems
* Second number (`b` in the previous example) cannot change signs.
* Negative operations don't work, i.e. `-5 + -3` does not become `-8`
* Cannot chain operations `a + b - c * ...`
  * First operation `a + b` works, but everything after that defaults to `b`.

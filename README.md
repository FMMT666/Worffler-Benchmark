
Worffler Benchmark
==================

A wordlist shuffler experiment in several programming languages.  

---

### Wat?

While working on a syllables based wordlist generator and shuffler,
I just became curious about the performance of different programming languages.

Because the size of the files is in the giga to tera range, the rules are simple:

  - read one line from file #1
  - append all lines from file #2
  - print to stdout
  - rewind file #2
  - read next line from #1 and repeat
 
 
### Supported Curiosities

 - Lua
 - Python
 - C
 - ...

 
### Usage

 The compilatiom, if necessary, is not yet built-in globally.  
 For now, you need to manually create
 
 - the C executable, by typing "make" in the "c" directory,
 - ...*insert new language here*...
 
 After compiling, a complete benchmark can be performed by executing the
 bash script, guess what, "benchmark", in the root directory.

 By default, a list of numbers (0..7999) is concatenated to each other.
 
 This number file, as well as a tiny Lua script to generate a new one,
 can be found in the "zdata" directory.


---
Have fun
FMMT666(ASkr)

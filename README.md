
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


As it turned out, squeezing every last bit of performance out of the code is
the ultimate fun :-)


### Supported Curiosities

 - Lua
 - Python
 - C
 - ...


### Requirements

 - Linux
 - installed Lua interpreter
 - installed Python interpreter
 - installed gcc
 - md5sum (if enabled in the "benchmark" Bash script
 - ...
 
 
### Usage

 The compilatiom, if necessary, is not yet built-in globally.  
 For now, you need to manually create
 
 - the C executable, by typing "make" in the "c" directory,
 - ...


 After compiling, a complete benchmark can be performed by executing the
 bash script, guess what, "benchmark", in the root directory.

 By default, a list of numbers (0..7999) is concatenated to each other.
 
 This number file, as well as a tiny Lua script to generate a new one,
 can be found in the "zdata" directory.

 With the default settings, two files will be created:
 
 a) "data.md5", to make sure newly generated code creates the right output
 
    ---------
    ea67db580bed73b377ffdab5a016f960  data_lua
    ea67db580bed73b377ffdab5a016f960  data_c
    ea67db580bed73b377ffdab5a016f960  data_py

 b) "results.log"
 
    ---------
    So 26. Apr 16:09:36 CEST 2015
    askr on LinAx2
    Processing 8000 lines:
    
    Lua   : 31s
    C     : 8s
    Python: 30s
    
    ---------
    So 26. Apr 16:20:55 CEST 2015
    askr on LinAx2
    Processing 8000 lines:
    
    Lua   : 31s
    C     : 8s
    Python: 22s


  New output is always appended to these two files and they are never deleted.


---
Have fun
FMMT666(ASkr)

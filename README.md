
Worffler Benchmark
==================

A wordlist shuffler experiment in several programming languages.  

---

### Wat?

While working on a syllables based wordlist generator and shuffler,
I just became curious about the disk-read and string concatenation performance
of different programming languages.

Because the size of the files is in the giga to tera range,
**they cannot (completely) be loaded into memory**, hence the rules are:

  - read one line from file #1
  - append all lines from file #2
  - print to stdout
  - rewind file #2
  - read next line from #1 and repeat
  
Example:

    FILE1  FILE2
  
      a      a
      b      b
      c      c
      d      d
    
    RESULT:
  
      aa
      ab
      ac
      ad
      ba
      bb
      ...
      dd


If you need to buffer something, please make sure it **always** fits into memory!  
Solutions that operate purely from RAM, e.g. programs that completely load the
input files into memorym are now marked with **-mem**.

As it turned out, squeezing every last bit of performance out of the code is
the ultimate fun :-)


### Supported Curiosities

 - Lua
 - Python 2/3
 - C
 - CPP
 - Elixir
 - ...


### Requirements

 - Linux
 - installed Lua 5.2 interpreter
 - installed Python 2.7/3.x interpreter (*1*)
 - installed gcc/g++
 - installed [Elixir](http://elixir-lang.org)
 - md5sum (if enabled in the "benchmark" Bash script)
 - ...

 (*1*) For now, the benchmark script expects the executables "python2" and "python3".


### Usage

 A complete benchmark can be performed by executing the bash script,
 guess what, "benchmark", in the root directory.

 By default, a list of numbers (0..7999) is concatenated to each other.

 This number file, as well as a tiny Lua script to generate a new one,
 can be found in the "zdata" directory.

 With the default settings, two files will be created:

 a) "data.md5", to make sure newly generated code creates the right output


    ---------
    ea67db580bed73b377ffdab5a016f960  data_lua
    ea67db580bed73b377ffdab5a016f960  data_c
    ea67db580bed73b377ffdab5a016f960  data_py2
    ea67db580bed73b377ffdab5a016f960  data_py3
    ea67db580bed73b377ffdab5a016f960  data_elixir
    ea67db580bed73b377ffdab5a016f960  data_cpp-mem


 b) "results.log"


    ---------
    So 26. Apr 16:09:36 CEST 2015
    askr on LinAx2
    Processing 8000 lines:

    Lua    : 31s
    C      : 8s
    Python2: 30s
    Python3: 42s

    ---------
    Mo 12. Mai 22:51:38 CEST 2015
    askr on LinAx2
    Processing 8000 lines:
    
    Lua    : 30s
    C      : 8s
    Python2: 20s
    Python3: 36s
    Elixir : 150s
    CPP-MEM: 3s


  New output is always appended to these two files and they are never deleted.  
  This comes in handy if one manages to improve the code to be faster (or worse).


---
Have fun
FMMT666(ASkr)

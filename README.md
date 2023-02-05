# Data Oriented Programming vs Object Oriented Programming
Data Oriented Design (DOD) vs. Object Oriented Design (OOD) in action with performance stats.

OOP is meant for the people. To express their ideas and thoughts and abstract them in more human-friendly way.
Computers however, don't like objects. They like well structured data.

Here is a small example of the two paradigms in the context of performace.
It uses multithreading and local machine instruction set level optimizations for maximum performance gains.

# Notes on compilation
The build system uses clang++ but you can change it in the Makefile.<br/>
It uses OpenMP to perform multithreading. Read the comments in the code for more info on how to tweak it and to what degree.

Build: ```make```<br/>
Run: ```make run```<br/>
Run static analysis: ```make analyze```<br/>
Clean: ```make clean```<br/>

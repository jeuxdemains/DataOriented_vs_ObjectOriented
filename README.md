# Data Oriented Programming vs Object Oriented Programming
A simple Data Oriented Design (DOD) vs. Object Oriented Design (OOD) demo example with performance stats for the performance oriented coders out there.

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


Here are some metrics:<br/><br/>
![Screenshot 2023-02-06 011712](https://user-images.githubusercontent.com/7083803/216851597-7f8f92d4-eee6-49d3-8027-cb0ae8504ff7.png)

# What is the idea behind DOD
![Screenshot 2023-02-06 013648](https://user-images.githubusercontent.com/7083803/216852432-98e9210e-0d02-40c0-8ada-cc99cde54e00.png)

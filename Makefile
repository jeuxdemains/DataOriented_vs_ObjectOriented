CC = clang++

# Note #1: -march=native flag enables automatic instruction-level 
# 			optimizations (intrinsics) based on the current machine CPU
#
# Note #2: note that we disable all -O type compiler optimizations
# 			so the compiler would not retouch our code and optimize anything
#			under the hood such like branching, cache optimizations, loop unrolling etc.

FLAGS = -O0 -Wall -fopenmp -march=native
SRC = *.cpp
OUTPUT = dod_vs_ood.exe
ANALYZER_FLAGS = -checks=*,-llvmlibc-restrict-system-libc-headers,-llvmlibc-implementation-in-namespace,-modernize-use-trailing-return-type,-bugprone-exception-escape,-google-readability-braces-around-statements,-hicpp-braces-around-statements,-readability-braces-around-statements,-cppcoreguidelines-pro-type-vararg,-hicpp-vararg,-cert-msc30-c,-cert-msc50-cpp,-concurrency-mt-unsafe,-llvmlibc-callee-namespace,-altera-unroll-loops

all:
	$(CC) $(FLAGS) $(SRC) -o $(OUTPUT)

run:
	./$(OUTPUT)

clean:
	rm *.exe

analyze:
	clang-tidy $(SRC) $(ANALYZER_FLAGS)
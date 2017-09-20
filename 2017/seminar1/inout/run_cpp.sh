echo "build program"
time g++ -O2 main_cpp.cpp

echo "run program"
time cat input.txt | ./a.out

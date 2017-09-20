echo "build program"
time g++ -O2 main_c.cpp

echo "run program"
time cat input.txt | ./a.out

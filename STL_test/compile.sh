g++ -Wall -std=gnu++14 -o $1.exe $1.cpp
for i in {1..10}
do
   ./$1.exe
done

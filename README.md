# printfTester (2019+)


Clone this tester in your printf repository. (works on linux and mac, no undefined behavior tests, handles timeout and sigsegv)  
![alt text](https://i.imgur.com/qRfDYuU.png)


# Commands
make m = launch mandatory tests  
make b = launch bonus tests (coming soon)  
make a = launch mandatory tests + bonus tests (coming soon)  

make vm = launch mandatory tests with valgrind  
make vb = launch bonus tests with valgrind (coming soon)  
make va = launch mandatory tests + bonus tests with valgrind (coming soon)  

make [category] = launch associated category ex: make s  
make v[category] = launch associated category with valgrind ex: make vs  

make [category] [test number] = launch associated test in category ex: make s 42  
make v[category] [test number] = launch associated test in category with valgrind ex: make vs 42  

X = upperx  
% = percent  

You can adjust the timeout limit in makefile for faster tests (reduce) or if you timeout (increase).
![alt text](https://i.imgur.com/RGTqT64.png)  

# Outputs

![alt text](https://i.imgur.com/FsgbPxO.png)


# Report bugs / Improvement
Contact me on slack or discord : jgambard

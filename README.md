# printfTester (2019+)

Tester for the ft_printf project of 42 school (with personalized leaks checking on mac, using valgrind on linux)  
Clone this tester in your ft printf repository. (works on linux and mac, no undefined behavior tests, handles timeout and sigsegv)  
![alt text](https://i.imgur.com/qRfDYuU.png)


# Commands
make m = launch mandatory tests   
make b = launch bonus tests   
make a = launch mandatory tests + bonus tests  
make [category] = launch associated category ex: make s  
make [category] [test number] = launch associated test in category ex: make s 42  

make dockerm = launch mandatory tests in linux container  
make dockerb = launch bonus tests in linux container  
make dockera = launch mandatory tests + bonus tests in linux container  
make docker[category] = launch associated category ex: make dockers    
make docker[category] [test number] = launch associated test in category ex: make dockers 42   
Thanks to gurival- for the docker idea (https://github.com/grouville/valgrind_42)  

X = upperx  
% = percent  

You can adjust the timeout limit in makefile for faster tests (reduce) or if you timeout (increase).
![alt text](https://i.imgur.com/RGTqT64.png)  

# Outputs

![alt text](https://i.imgur.com/FsgbPxO.png)  
![alt text](https://i.imgur.com/qJfhyeL.png)  

# Report bugs / Improvement
Contact me on slack or discord : jgambard

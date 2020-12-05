TIMEOUT_US 		= 150000 #if you timeout you can try to increase this value

.DEFAULT_GOAL	:= vm
SHELL			= bash

UTILS_PATH		= utils/
UTILS			= $(addprefix $(UTILS_PATH), sigsegv.cpp color.cpp check.cpp)

TESTS_PATH		= tests/
MANDATORY		= c s p d i u x upperx percent
VMANDATORY		= $(addprefix v, $(MANDATORY))

CC			= clang++ -std=c11 -Wno-everything
CFLAGS		= -g3 -std=c++11 -I utils/ -I.. -I`find .. -regex ".*/.*\.h" | grep -oh ".*\/"` #-I
VALGRIND	= valgrind -q --leak-check=full

TEST_NUMBER := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
$(eval $(TEST_NUMBER):;@:)

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) -fsanitize=address $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf && ./a.out $(TEST_NUMBER) && rm -f a.out

$(VMANDATORY): v%: mandatory_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf && $(VALGRIND) ./a.out $(TEST_NUMBER) && rm -f a.out

mandatory_start: update message
	@tput setaf 6
	make -C ..
	@tput setaf 4 && echo [Mandatory]

bonus_start: update message
	@tput setaf 6
	make bonus -C ..
	@tput setaf 5 && echo [Bonus]

update:
	@git pull origin master

message:

m: $(MANDATORY) 
b: $(BONUS)
a: m b 
vm: $(VMANDATORY) 
vb: $(VBONUS)
va: vm vb 

clean:
	make clean -C .. && rm -rf a.out

fclean:
	make fclean -C .. && rm -rf a.out

.PHONY:	mandatory_start m vm bonus_start b vb a va clean update message fclean
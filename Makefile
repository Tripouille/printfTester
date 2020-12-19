TIMEOUT_US 		= 150000 #if you timeout you can try to increase this value

.DEFAULT_GOAL	:= m
SHELL			= bash

UTILS_PATH		= utils/
UTILS			= $(addprefix $(UTILS_PATH), sigsegv.cpp color.cpp check.cpp)

TESTS_PATH		= tests/
MANDATORY		= c s p d i u x upperx percent mix
VMANDATORY		= $(addprefix v, $(MANDATORY))

BONUS			= n f g e l
VBONUS			= $(addprefix v, $(BONUS))

CC				= clang++ -std=c11 -Wno-everything
CFLAGS			= -g3 -std=c++11 -I utils/ -I.. $(addprefix -I, $(shell find .. -regex ".*/.*\.h" | grep -oh ".*\/"))
VALGRIND		= valgrind -q --leak-check=full

TEST_NUMBER := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
$(eval $(TEST_NUMBER):;@:)

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) -fsanitize=address $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf -o $*_test && ./$*_test $(TEST_NUMBER) && rm -f $*_test

$(VMANDATORY): v%: mandatory_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf -o $*_test && $(VALGRIND) ./$*_test $(TEST_NUMBER) && rm -f $*_test

$(BONUS): %: bonus_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) -fsanitize=address $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf -o $*_test && ./$*_test $(TEST_NUMBER) && rm -f $*_test

$(VBONUS): v%: bonus_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf -o $*_test && $(VALGRIND) ./$*_test $(TEST_NUMBER) && rm -f $*_test

mandatory_start: update message
	@tput setaf 6
	@make -C ..
	@tput setaf 4 && echo [Mandatory]

bonus_start: update message
	@tput setaf 6
	@make bonus -C ..
	@tput setaf 5 && echo [Bonus]

update:
	@git pull

message:

m: $(MANDATORY) 
b: $(BONUS)
a: m b 
vm: $(VMANDATORY) 
vb: $(VBONUS)
va: vm vb 

clean:
	make clean -C .. && rm -rf *_test && rm -rf *_test.dSYM

fclean:
	make fclean -C .. && rm -rf *_test && rm -rf *_test.dSYM

.PHONY:	mandatory_start m vm bonus_start b vb a va clean update message fclean
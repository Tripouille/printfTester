TIMEOUT_US 		= 150000 #if you timeout you can try to increase this value

.DEFAULT_GOAL	:= m
SHELL			= bash

UTILS_PATH		= utils/
UTILS			= $(addprefix $(UTILS_PATH), sigsegv.cpp color.cpp check.cpp leaks.cpp)

TESTS_PATH		= tests/
MANDATORY		= c s p d i u x upperx percent mix
VMANDATORY		= $(addprefix v, $(MANDATORY))

BONUS			= n f g e l ll h hh sharp space +
VBONUS			= $(addprefix v, $(BONUS))

CC				= clang++ -std=c11 -Wno-everything
CFLAGS			= -g3 -ldl -std=c++11 -I utils/ -I.. $(addprefix -I, $(shell find .. -regex ".*/.*\.h" | grep -oh ".*\/"))

TEST_NUMBER := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
$(eval $(TEST_NUMBER):;@:)

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
    VALGRIND = valgrind -q --leak-check=full
endif

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf -o $*_test && $(VALGRIND) ./$*_test $(TEST_NUMBER) && rm -f $*_test

$(BONUS): %: bonus_start
	@$(CC) $(CFLAGS) -D TIMEOUT_US=$(TIMEOUT_US) $(UTILS) $(TESTS_PATH)$*_test.cpp -L.. -lftprintf -o $*_test && $(VALGRIND) ./$*_test $(TEST_NUMBER) && rm -f $*_test

mandatory_start: update checkmakefile
	@tput setaf 6
	@make -C ..
	@tput setaf 4 && echo [Mandatory]

bonus_start: update checkmakefile
	@tput setaf 6
	@make bonus -C ..
	@tput setaf 5 && echo [Bonus]

update:
	@git pull

checkmakefile:
	@ls .. | grep Makefile > /dev/null 2>&1 || (tput setaf 1 && echo Makefile not found. && exit 1)

$(addprefix docker, $(MANDATORY)) $(addprefix docker, $(BONUS)) dockerm dockerb dockera: docker%:
	@docker rm -f mc > /dev/null 2>&1 || true
	docker build -qt mi .
	docker run -dti --name mc -v $(shell dirname $(shell pwd)):/project/ mi
	docker exec -ti mc make $* $(TEST_NUMBER) -C printfTester || true
	@docker rm -f mc > /dev/null 2>&1

m: $(MANDATORY) 
b: $(BONUS)
a: m b 

clean:
	make clean -C .. && rm -rf *_test && rm -rf *_test.dSYM

fclean:
	make fclean -C .. && rm -rf *_test && rm -rf *_test.dSYM

.PHONY:	mandatory_start m bonus_start b a clean update fclean
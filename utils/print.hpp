#ifndef PRINT_HPP
# define PRINT_HPP
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sstream>
# define B_SIZE 4096
# define TEST(nb, test) {if (ac == 1 || testNumber == nb) test;}
# define SUBCATEGORY(min, max, output) {if (ac == 1 || (testNumber >= min && testNumber <= max)) output}

using namespace std;

extern int iTest;
extern int testNumber;
extern char * testName;
extern bool showTest;
int pipeOut, stdOut;

void printTestNumber(char * n, int limit)
{
	testNumber = atoi(n);
	cout << FG_LYELLOW << ", number: " << testNumber << RESET_ALL;
	if (testNumber == 0 || testNumber > limit)
		throw std::runtime_error("invalid test number");
	showTest = true;
}

void showTestInfos(void)
{
	cout << FG_MAGENTA << "args:      [";
	std::ostringstream cmd; cmd << "cat tests/" << testName << ".cpp | grep \"TEST(" << testNumber << ",\" | cut -d \"(\" -f 3 | rev | cut -c4- | rev | tr -d '\n'";
	system(cmd.str().c_str());
	cout << "]" << ENDL;
}

template<typename... Args>
void print(const char * s, Args... args)
{
	pid_t actualTest = fork(); stdOut = 1;
	setbuf(stdout, NULL);
	if (actualTest < 0)
		throw std::runtime_error("I have dropped my fork");
	else if (actualTest == 0)
	{
		char	printfStr[B_SIZE], ft_printfStr[B_SIZE];
		int		printfRet, ft_printfRet;
		char	eof = EOF; 
		int		readReturn;
		int		p[2];

		if (pipe(p) < 0)
			throw std::runtime_error("pipe() failed");
		stdOut = dup(1); pipeOut = p[1]; dup2(pipeOut, 1);
	
		printfRet = printf(s, args...); write(1, &eof, 1);
		if ((readReturn = read(p[0], printfStr, B_SIZE)) < 0)
			throw std::runtime_error("read failed");
		printfStr[readReturn - 1] = 0;
		if (showTest)
		{
			dup2(stdOut, 1);
			showTestInfos();
			cout << FG_GREEN << "printf:    [" << printfStr << "] = " << printfRet << ENDL;
			dup2(pipeOut, 1);
		}
		ft_printfRet = ft_printf(s, args...); write(1, &eof, 1);
		if ((readReturn = read(p[0], ft_printfStr, B_SIZE)) < 0)
			throw std::runtime_error("read failed");
		ft_printfStr[readReturn - 1] = 0;
		close(p[0]); close(pipeOut); dup2(stdOut, 1);
		if (showTest)
			cout << FG_LGREEN << "ft_printf: [" << ft_printfStr << "] = " << ft_printfRet << ENDL;
		else
			check(!strcmp(ft_printfStr, printfStr) && printfRet == ft_printfRet);
		showLeaks();
		exit(EXIT_SUCCESS);
	}
	else
	{
		usleep(TIMEOUT_US); int status;
		if (waitpid(actualTest, &status, WNOHANG) == 0)
		{
			kill(actualTest, 9);
			if (showTest)
				cout << FG_BLUE << "ft_printf: " << FG_RED << "[TIMEOUT]" << ENDL;
			else
				cout << FG_RED << iTest << ".TIMEOUT ";
		}
		if (showTest)
			exit(EXIT_SUCCESS);
	}	
	++iTest;
}

template<typename requiredType=int, typename... Args>
void checkn(const char * s, Args... args)
{

	pid_t actualTest = fork(); stdOut = 1;
	setbuf(stdout, NULL);
	if (actualTest < 0)
		throw std::runtime_error("I have dropped my fork");
	else if (actualTest == 0)
	{
		char	printfStr[B_SIZE], ft_printfStr[B_SIZE];
		int		printfRet, ft_printfRet;
		char	eof = EOF; 
		int		readReturn;
		int		p[2];
		unsigned long long int printfn = -1 , ft_printfn = -1;
	
		if (pipe(p) < 0)
			throw std::runtime_error("pipe() failed");
		stdOut = dup(1); pipeOut = p[1]; dup2(pipeOut, 1);
	
		printfRet = printf(s, args..., &printfn); write(1, &eof, 1);
		if ((readReturn = read(p[0], printfStr, B_SIZE)) < 0)
			throw std::runtime_error("read failed");
		printfStr[readReturn - 1] = 0;
		if (showTest)
		{
			dup2(stdOut, 1);
			showTestInfos();
			cout << FG_CYAN << "printf:    [" << printfStr << "] = " << printfRet << " n = " << (unsigned long long int)static_cast<requiredType>(printfn) << ENDL;
			dup2(pipeOut, 1);
		}
		
		ft_printfRet = ft_printf(s, args..., &ft_printfn); write(1, &eof, 1);
		if ((readReturn = read(p[0], ft_printfStr, B_SIZE)) < 0)
			throw std::runtime_error("read failed");
		ft_printfStr[readReturn - 1] = 0;
		close(p[0]); close(pipeOut); dup2(stdOut, 1);
		if (showTest)
		{
			cout << FG_BLUE << "ft_printf: [" << ft_printfStr << "] = " << ft_printfRet << " n = " << (unsigned long long int)static_cast<requiredType>(ft_printfn) << ENDL;
			if (printfn == ft_printfn) cout << FG_GREEN << "cast:      [OK]" << ENDL;
			else cout << FG_RED << "cast:      [KO]" << ENDL;
		}
		else
			check(!strcmp(ft_printfStr, printfStr) && printfRet == ft_printfRet && printfn == ft_printfn);
		showLeaks();
		exit(EXIT_SUCCESS);
	}
	else
	{
		usleep(TIMEOUT_US); int status;
		if (waitpid(actualTest, &status, WNOHANG) == 0)
		{
			kill(actualTest, 9);
			if (showTest)
				cout << FG_BLUE << "ft_printf: " << FG_RED << "[TIMEOUT]" << ENDL;
			else
				cout << FG_RED << iTest << ".TIMEOUT ";
		}
		if (showTest)
			exit(EXIT_SUCCESS);
	}	
	++iTest;
}

#endif
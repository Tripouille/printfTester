#ifndef PRINT_HPP
# define PRINT_HPP
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# define B_SIZE 4096

using namespace std;

extern bool showTest;
extern int iTest;

template<typename... Args>
void print(const char * s, Args... args)
{
    char	printfStr[B_SIZE], ft_printfStr[B_SIZE];
    int		printfRet, ft_printfRet;
	char	eof = EOF; 
	int		readReturn;
	int		p[2];

	pid_t actualTest = fork();
	setbuf(stdout, NULL);
	if (actualTest < 0)
		throw std::runtime_error("I have dropped my fork");
	else if (actualTest == 0)
	{
		if (pipe(p) < 0)
			throw std::runtime_error("pipe() failed");
		int stdoutSave = dup(1);
		dup2(p[1], 1);
	
		printfRet = printf(s, args...); write(1, &eof, 1);
		if ((readReturn = read(p[0], printfStr, B_SIZE - 1)) < 0)
			throw std::runtime_error("read failed");
		printfStr[readReturn - 1] = 0;
		if (showTest)
		{
			dup2(stdoutSave, 1);
			cout << RESET_ALL << "[\"" << s << "\"]" << ENDL;
			cout << FG_CYAN << "printf:    [" << printfStr << "] = " << printfRet << ENDL;
			dup2(p[1], 1);
		}
		ft_printfRet = ft_printf(s, args...); write(1, &eof, 1);
		if ((readReturn = read(p[0], ft_printfStr, B_SIZE - 1)) < 0)
			throw std::runtime_error("read failed");
		ft_printfStr[readReturn - 1] = 0;
		close(p[0]); close(p[1]); dup2(stdoutSave, 1);
		if (showTest)
			cout << FG_BLUE << "ft_printf: [" << ft_printfStr << "] = " << ft_printfRet << ENDL;
		else
			check(!strcmp(ft_printfStr, printfStr) && printfRet == ft_printfRet);
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
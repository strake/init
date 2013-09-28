#include <unistd.h>

int main (int argc, char *argu[]) {
	pid_t pid;
	int c;
	
	for (;;) {
		pid = fork ();
		if (pid < 0) return 1;
		if (pid > 0) waitpid (pid, &c, 0);
		else return (setsid () < 0 || execv (argu[1], argu + 1));
	}
}

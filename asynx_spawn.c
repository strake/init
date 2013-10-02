#include <unistd.h>

int main (int argc, char *argu[]) {
	pid_t pid;
	int c;
	pid = fork ();
	if (pid < 0) return 1;
	if (pid > 0) {
		waitpid (pid, &c, 0);
		return c;
	}
	pid = fork ();
	if (pid < 0) return 1;
	if (pid > 0) return 0;
	return execvp (argu[1], argu + 1);
}

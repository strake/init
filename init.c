#include <signal.h>
#include <unistd.h>

int main () {
	sigset_t set;
	pid_t pid;
	int c;
	
	if (getpid () != 1) return 1;
	
	sigfillset (&set);
	sigprocmask (SIG_BLOCK, &set, 0);
	
	pid = fork ();
	if (pid < 0) return 1;
	if (pid > 0) for (;;) wait (&c); /* orphans */
	
	sigprocmask (SIG_UNBLOCK, &set, 0);
	
	setsid ();
	setpgid (0, 0);
	return execve ("/sbin/go", (char * []){ "go", 0 }, (char * []){ 0 });
}

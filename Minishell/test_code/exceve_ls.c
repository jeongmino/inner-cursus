#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    char    *cmd[] = {"ls", "-al", "../" , NULL};
    pid_t pid;

    pid = fork();
    
    if (pid)
    {
        printf("child\n");
        execve("/bin/ls", cmd, envp);
    }
    else
    {
        printf("it dosen't matter\n");   
    }
    return (0);
}

#include "minitalk.h"

void    send_char(char c, int pid)
{
    int bit;

    bit = 0;
    while(bit < 8)
    {
        if((c >> bit) & 1)
            kill(pid,SIGUSR2);
        else
            kill(pid,SIGUSR1);
        usleep(500);
        bit++;
    }
}

void    decomp(char *s, int pid)
{
    int i;

    i = 0;
    while(s[i])
    {
        send_char(s[i], pid);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int pid;
    if(argc == 3)
    {
        pid = ft_atoi(argv[1]);
        decomp(argv[2], pid);
    }
    return (0);
}
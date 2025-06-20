#include "config.h"

int	_raid();

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	if (_raid() != 0)
	{
		PRINT_ERROR("Raid failed to execute.");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
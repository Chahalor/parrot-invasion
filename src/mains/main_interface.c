#include "config.h"

int	_interface();
int	_raid();
int	_invasion(const char *const restrict name);
int	_takeover();
int	_quit(const char *const restrict name);

int	main(int argc, char *argv[])
{
	int	action = -1;

	(void)argc;
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

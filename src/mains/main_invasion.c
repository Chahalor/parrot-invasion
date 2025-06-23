#define _GNU_SOURCE

#include "config.h"
#include <signal.h>

int	_raid();

__attribute__((always_inline, used)) static inline int	_randint(
	int	min,
	int	max
)
{
	if (min > max)
	{
		int	tmp = min;
		min = max;
		max = tmp;
	}
	return (min + (rand() % (max - min + 1)));
}

__attribute__((always_inline, used)) static inline int	_signal(void)
{
	sigaction(SIGINT, &(struct sigaction){
		.sa_handler = SIG_IGN,
		.sa_flags = 0,
	}, NULL);
	sigaction(SIGTERM, &(struct sigaction){
		.sa_handler = SIG_IGN,
		.sa_flags = 0,
	}, NULL);
	sigaction(SIGQUIT, &(struct sigaction){
		.sa_handler = SIG_IGN,
		.sa_flags = 0,
	}, NULL);
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	_signal();
	while (1)
	{
		// Sleep between 40 and 120 minutes
		sleep(_randint(40 * 60, 120 * 60));
		if (_raid() != 0)
		{
			PRINT_ERROR("Raid failed to execute.");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
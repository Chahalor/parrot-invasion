#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	while (*argv)
		printf("Argument: %s\n", *argv++);

    return 0;
}

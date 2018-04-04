#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2) {
		printf("Usage:\n\t ./a.out <filename>\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0) {
		perror("Error: ");
		return fd;
	}
	
	close(fd);

	return 0;
}

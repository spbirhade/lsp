#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int fd, cnt;
	char c;

	if (argc != 3) {
		printf("Usage:\n\t ./a.out <filename> <string>\n");
		return -1;
	}

	fd = open(argv[1], O_WRONLY);
	if (fd == -1) {
		perror("Error..: ");
		return fd;
	}


	if (write(fd, argv[2], strlen(argv[2])) == -1) {
		close(fd);
		perror("Error ");
		return -1;
	}

	close(fd);

	return 0;
}

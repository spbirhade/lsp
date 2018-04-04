#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int fd, cnt;
	char c;

	if (argc != 2) {
		printf("Usage:\n\t ./a.out <filename>\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0) {
		perror("Error: ");
		return fd;
	}
		
	while ((cnt = read(fd, &c, 1))  > 0) {
		printf("%c", c);
	}

	close(fd);

	if (cnt < 0) {
		perror("Error: ");
		return cnt;
	}


	return 0;
}

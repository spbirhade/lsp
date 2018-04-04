#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX 5

int main(int argc, char *argv[])
{
	int fd, cnt;
	char buff[MAX];

	if (argc != 2) {
		printf("Usage:\n\t ./a.out <filename>\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0) {
		perror("Error: ");
		return fd;
	}
	
	memset(buff, 0, MAX);
	cnt = read(fd, buff, MAX);

	if (cnt < 0) {
		close(fd);
		perror("Error: ");
		return cnt;
	}

	printf("%s\n", buff);

	close(fd);

	return 0;
}

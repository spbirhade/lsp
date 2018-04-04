#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX 6

int main(int argc, char *argv[])
{
	int fd, cnt;
	char buff[MAX];

	if (argc != 2) {
		printf("Usage:\n\t ./a.out <filename>\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1) {
		perror("Error: ");
		return fd;
	}
	
	memset(buff, 0, MAX);
	cnt = read(fd, buff, 5);

	if (cnt == -1) {
		close(fd);
		perror("Error: ");
		return cnt;
	}

	printf("%s\n", buff);

	close(fd);

	return 0;
}

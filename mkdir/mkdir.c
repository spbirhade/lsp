#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("Usage:\nmkdir <dirname>\n");
		return -1;
	}

	if(mkdir(argv[1], S_IRUSR | S_IWUSR | S_IXUSR) == -1) {
		perror("Failed: ");
		return -1;
	}

	return 0;
}

#include "get_next_line.h"

char	*static_test(void)
{
	static char *buffer;
	// char *tmp;
	char *tmp2;
	// char *tmp3;

	printf("1: str = %s\n   ptr = %p\n\n", buffer, buffer);

	buffer = ft_substr("123", 0, 3);
	// buffer = tmp;
	printf("1: str = %s\n   ptr = %p\n\n", buffer, buffer);

	tmp2 = buffer; //tmp2 store static address
	printf("ber: str = %s\n   ptr = %p\n\n", buffer, buffer);
	buffer = ft_strjoin(buffer, "456"); //strjoin creates malloc address
	printf("aft: str = %s\n   ptr = %p\n\n", buffer, buffer);
	free(tmp2);

	// tmp2 = buffer; //tmp2 store static address
	// printf("ber: str = %s\n   ptr = %p\n\n", buffer, buffer);
	// buffer = ft_strjoin(buffer, "456"); //strjoin creates malloc address, 
	// printf("aft: str = %s\n   ptr = %p\n\n", buffer, buffer);
	// free(tmp2);

	// tmp2 = ft_strjoin(buffer, "456");
	// buffer = tmp2;
	// free(tmp);
	// printf("1: str = %s\n   ptr = %p\n\n", buffer, buffer);

	// tmp3 = ft_strjoin(buffer, "789");
	// buffer = tmp3;
	// free(tmp2);
	// printf("1: str = %s\n   ptr = %p\n\n", buffer, buffer);

	return (buffer);
} 

int	main(void)
{
	int fd;
	int	nbyte;
	char	*str = NULL;

	fd = open("gnlTester/files/empty", O_RDONLY);
	printf("%i\n", fd);
	nbyte = read(fd, str, 1);
	printf("%i %s %p\n", nbyte, str, str);
	for (int n = 0; n < 1; ++n)
    {
        printf("%2.2x ", *str);
    }

	close(fd);

	// static_test();
	// system("leaks test.out");
}

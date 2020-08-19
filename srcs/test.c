#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define OK	"\e[32m✓\e[39m"
#define ERR	"\e[31m✗\e[39m"

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

int	check_strlen()
{
	int		test = 0;
	char	test1[] = "1";
	char	test2[] = "ceci est un test !";
	char	test3[] = "lorem\tipsum\tdolor\nsit\namet\n";
	char	test4[] = "";
	char	test5[] = "\n\n\f\r\t";
	char	test6[] = "   ";

	printf("\e[36mft_strlen\e[39m\t\t");
	printf("%s", ((strlen(test1) == ft_strlen(test1) && ++test) ? OK : ERR));
	printf("%s", ((strlen(test2) == ft_strlen(test2) && ++test) ? OK : ERR));
	printf("%s", ((strlen(test3) == ft_strlen(test3) && ++test) ? OK : ERR));
	printf("%s", ((strlen(test4) == ft_strlen(test4) && ++test) ? OK : ERR));
	printf("%s", ((strlen(test5) == ft_strlen(test5) && ++test) ? OK : ERR));
	printf("%s", ((strlen(test6) == ft_strlen(test6) && ++test) ? OK : ERR));
	printf("\t\t%s\n", (test == 6) ? "\e[32mOK\e[39m" : "\e[31mError\e[39m\n");
	return (test);
}

int	check_strcpy()
{
	int			test = 0;
	const char	src1[] = "1";
	const char	src2[] = "ceci est un test !";
	const char	src3[] = "lorem\tipsum\tdolor\nsit\namet\n";
	const char	src4[] = "";
	const char	src5[] = "\n\n\f\r\t";
	const char	src6[] = "   ";
	char		dest1[2];
	char		dest2[19];
	char		dest3[28];
	char		dest4[1];
	char		dest5[6];
	char		dest6[4];

	printf("\e[36mft_strcpy\e[39m\t\t");
	printf("%s", ((!strcmp(ft_strcpy(dest1, src1), src1) && ++test) ? OK : ERR));
	printf("%s", ((!strcmp(ft_strcpy(dest2, src2), src2) && ++test) ? OK : ERR));
	printf("%s", ((!strcmp(ft_strcpy(dest3, src3), src3) && ++test) ? OK : ERR));
	printf("%s", ((!strcmp(ft_strcpy(dest4, src4), src4) && ++test) ? OK : ERR));
	printf("%s", ((!strcmp(ft_strcpy(dest5, src5), src5) && ++test) ? OK : ERR));
	printf("%s", ((!strcmp(ft_strcpy(dest6, src6), src6) && ++test) ? OK : ERR));
	printf("\t\t%s\n", (test == 6) ? "\e[32mOK\e[39m" : "\e[31mError\e[39m\n");
	return (test);
}

int	check_strcmp()
{
	int			test = 0;
	printf("\e[36mft_strcmp\e[39m\t\t");
	printf("%s", ((strcmp("salut", "salut") == ft_strcmp("salut", "salut")) && ++test) ? OK : ERR);
	printf("%s", ((strcmp("test", "testss") == ft_strcmp("test", "testss")) && ++test) ? OK : ERR);
	printf("%s", ((strcmp("testss", "test") == ft_strcmp("testss", "test")) && ++test) ? OK : ERR);
	printf("%s", ((strcmp("test", "tEst") == ft_strcmp("test", "tEst")) && ++test) ? OK : ERR);
	printf("%s", ((strcmp("", "test") == ft_strcmp("", "test")) && ++test) ? OK : ERR);
	printf("%s", ((strcmp("test", "") == ft_strcmp("test", "")) && ++test) ? OK : ERR);
	printf("%s", ((strcmp("test\200", "test\0") == ft_strcmp("test\200", "test\0")) && ++test) ? OK : ERR);
	printf("\t\t%s\n", (test == 7) ? "\e[32mOK\e[39m" : "\e[31mError\e[39m\n");
	return (test);
}

int	check_write()
{
	int			fd;
	ssize_t		ret1;
	ssize_t		ret2;
	int			test;
	char		str1[] = "This is test 1.\n";
	char		str2[] = "This is test 2.\n";

	printf("\e[36mft_write\e[39m\t\t");
	test = 0;
	fd = open("test_write.txt", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	ret1 = ft_write(fd, str1, strlen(str1));
	ret2 = write(fd, str2, strlen(str2));
	printf("%s", ((ret1 == ret2) && ++test) ? OK : ERR);
	write(fd, "\nEOF.\n", 7);
	close(fd);
	fd = open("test_write.txt", O_RDONLY, 0664);
	ret1 = ft_write(fd, str1, strlen(str1));
	ret2 = write(fd, str2, strlen(str2));
	printf("%s", ((ret1 == ret2) && ++test) ? OK : ERR);
	printf("\t\t%s\n", (test == 2) ? "\e[32mOK\e[39m" : "\e[31mError\e[39m\n");
	close(fd);
	sleep(1);
	printf("\e[36m\tErrno:\n");
	fd = open("test_write.txt", O_RDONLY, 0664);
	ft_write(fd, str1, strlen(str1));
	perror("\t- ft_write\t");
	close(fd);
	fd = open("test_write.txt", O_RDONLY, 0664);
	write(fd, str2, strlen(str2));
	perror("\t- write\t\t");
	close(fd);
	return (test);
}

int		check_read()
{
	int		test;
	char	buf[1024];
	int		fd;
	ssize_t	read1;
	ssize_t	read2;

	printf("\e[36mft_read\e[39m\t\t\t");
	fd = open("test_write.txt", O_RDONLY, 0664);
	read1 = ft_read(fd, buf, 1024);
	close(fd);
	fd = open("test_write.txt", O_RDONLY, 0664);
	read2 = read(fd, buf, 1024);
	close(fd);
	printf("%s", ((read1 == read2) && ++test) ? OK : ERR);
	fd = open("no_file.txt", O_RDONLY, 0664);
	read1 = ft_read(fd, buf, 1024);
	close(fd);
	fd = open("no_file.txt", O_RDONLY, 0664);
	read2 = read(fd, buf, 1024);
	close(fd);
	printf("%s", ((read1 == read2) && ++test) ? OK : ERR);
	printf("\t\t%s\n", (test == 2) ? "\e[32mOK\e[39m" : "\e[31mError\e[39m\n");
	printf("\e[36m\tErrno:\n");
	fd = open("no_file.txt", O_RDONLY, 0664);
	ft_read(fd, buf, 1024);
	perror("\t- ft_read\t");
	close(fd);
	fd = open("no_file.txt", O_RDONLY, 0664);
	read(fd, buf, 1024);
	perror("\t- read\t\t");
	close(fd);
	return (test);
}

int		check_strdup()
{
	int		test;
	char	src1[] = "Ceci est un test.";
	char	src2[] = "Lorem ipsum dolor sit amet, eum amet nonumes incorrupte ex.";
	char	src3[] = "Lorem ipsum dolor sit amet, graeci audiam vim ea, ea invidunt suscipiantur vis. Ne usu.";
	char	src4[] = "";
	char	*dst1;
	char	*dst2;
	char	*dst3;
	char	*dst4;

	test = 0;
	printf("\e[36mft_strdup\e[39m\t\t");
	dst1 = ft_strdup(src1);
	dst2 = ft_strdup(src2);
	dst3 = ft_strdup(src3);
	dst4 = ft_strdup(src4);
	printf("%s", ((strlen(dst1) == strlen(src1) && dst1 != src1) && ++test) ? OK : ERR);
	printf("%s", ((strlen(dst2) == strlen(src2) && dst2 != src2) && ++test) ? OK : ERR);
	printf("%s", ((strlen(dst3) == strlen(src3) && dst3 != src3) && ++test) ? OK : ERR);
	printf("%s", ((strlen(dst4) == strlen(src4) && dst4 != src4) && ++test) ? OK : ERR);
	free(dst1);
	free(dst2);
	free(dst3);
	free(dst4);
	printf("\t\t%s\n", (test == 4) ? "\e[32mOK\e[39m" : "\e[31mError\e[39m\n");
	return (test);
}

int		main(void)
{
	int	result;
	printf("\e[34m\e[4mFonction\e[24m\t\t\e[4mTests\e[24m\t\t\e[4mRésultat\e[24m\e[39m\n");
	result += check_strlen();
	result += check_strcpy();
	result += check_strcmp();
	result += check_write();
	result += check_read();
	result += check_strdup();
	printf("\n\e[33mTotal: %d/27\t\t\e[32m%.0f%%\n\e[39m", result, (double)((result / 27) * 100));
	return (0);
}

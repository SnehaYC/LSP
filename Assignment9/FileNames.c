
#include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>
 #include<dirent.h>
 #include<fcntl.h>
 #include<sys/stat.h>
 
 int main()
 {
	 int fd = 0;
	 struct stat buffer;
	 
	 DIR *dir;
	 struct dirent *direntx;
	 
	 dir = opendir("/home/sneha/Desktop/Assignments/Assignment9");
	 if(dir == 0)
	 {
		printf("Unable to open the file\n"); 
	 }
	 
	fd = open("demo.txt", O_WRONLY | O_CREAT, 0666);
	
	 while((direntx = readdir(dir)) != NULL)
	 {
		printf("%s\n", direntx->d_name);
		write(fd, direntx->d_name, strlen(direntx->d_name));
		write(fd, "\n", 1);
	 }
	
	close(fd);
	closedir(dir);
	return 0;
 }


#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main (int argc,char *argv[])
{

  struct stat buf;

  stat (argv[1], &buf);

          if(S_ISDIR(buf.st_mode)) printf("directory=Y");
          if(S_ISREG(buf.st_mode)) printf("file=Y");


  printf ("Inode = %d\n", (int) buf.st_ino);
  printf ("Mode=%o\n", (unsigned int) buf.st_mode);
  printf ("Nlink=%o\n", (unsigned int) buf.st_nlink);
  printf ("UID=%d\n", (int) buf.st_gid);
  printf ("SIZE=%d\n", (int) buf.st_size);
  printf ("Atime=%d\n", (int) buf.st_atime);
  printf ("Mtime=%d\n", (int) buf.st_mtime);
  printf ("Ctime=%d", (int) buf.st_ctime);
  printf ("Blksize\%d\n", (int) buf.st_blksize);
  printf ("Block=%d\n", (int) buf.st_blocks);

  chmod ("unix.txt", 0700);

  return 0;
}

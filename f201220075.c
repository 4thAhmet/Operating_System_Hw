#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(int argc, char* argv[])
{
  printf("[%s] %s saniye  %s calistirilacak...",argv[0],argv[2],argv[1]);
  float time=atof(argv[2]);
  fflush(stdout);
  int sub_Procces = fork();
  if(sub_Procces == -1)
  {
    printf("\nAlt islem hatali");
    return -1; 
  } 
  else if(sub_Procces == 0)
  {
    if(execv(argv[1],argv) == -1)
    {
      printf("\nProgram calistirma hatasi");
    }
  }
  else{
        printf("\n[%s] programiyim %.1f saniye calisacagim",argv[1],time);
        for(int i=1; i<=time; i++)
        {
          printf("\n[%s] %d saniye ",argv[1],i);
          sleep(1);
        }
        kill(sub_Procces,9);
        printf("\n[%s] %.2f sn sona erdi %s kapatiliyor.\n",argv[0],time,argv[1]);
    }
    return 0;
}
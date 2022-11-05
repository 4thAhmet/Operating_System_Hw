#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>




/*

*************************************************
*												*
*				 201220075						*
*			// Ahmet Akkeci //					*
*				201220075						*
*												*
*************************************************

			Kullanýlan Fonksiyonlar
		Atof= floata dönüþtürme
		fork Child oluþturmak için, execv alt program çalýþtýrmak için
		sleep bekleme için,kill Programý Sonlandýrmak için

*/


int main(int count, char* arguman[])
{
  printf("%s saniye  %s calistirilacak\n",arguman[2],arguman[1]);
  float sure=atof(arguman[2]);
  fflush(stdout);
  int alt = fork();
  if(alt == -1)
  {
    printf("hata\n");
    return -1; 
  } 
  else if(alt == 0)
  {
    if(execv(arguman[1],arguman) == -1)
    {
      printf("Program bulunamadi\n");
    }
  }
  else{
		printf("%s programiyim %.1f saniye calisacagim\n",arguman[1],sure);
        sleep(sure);
        printf("%.2f sn sona erdi %s kapatiliyor.\n",sure,arguman[1]);
        kill(alt,9);
    }
    return 0;
}

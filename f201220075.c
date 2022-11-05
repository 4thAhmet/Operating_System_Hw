#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


				/*
				**********************************
				*								 *
				*								 *
				*		//201220075//			 *
				*		//Ahmet Akke�i//		 *
				*								 *
				*								 *
				**********************************
				*/
				
int main(int argc,char* argv[])
{
    float time = atof(argv[2]);
    printf("[%s] %.1f saniye boyunca %s calistirilacak...\n",argv[0],time,argv[1]);
    int sub_proccess = fork();
    if(sub_proccess == -1)
    {
         printf("Sub proccess Error");
    }
    else if(sub_proccess == 0)
    {
        if(execv(argv[1],argv) == -1)
        {
            printf("program çalıştırma hatası.\n");
        }     
    }
    else 
    {
        printf("[%s] %s programiyim ve sürekli calisiyorum...\n",argv[1],argv[1]);
        for(int i=0; i<time; i++)
        {
            sleep(1);
            printf("[%s] %d. saniye\n",argv[1],i+1);          
        }
        sleep(1);
        printf("[%s] %.1f saniye sona erdi %s kapatılıyor\n",argv[0],time,argv[1]);
        kill(sub_proccess,9);
    }
    return 0;
}

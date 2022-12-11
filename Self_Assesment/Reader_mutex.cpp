#include<stdio.h>
#include<bits\stdc++.h>
#include<string.h>
int hours=23,mins=59,secs=53;
void update();
void display();
pthread_mutex_t timer_lock;
int main(void)
{
    void *status;
    pthread_t r_thr,w_thr;
    pthread_mutex_init(&timer_lock,0);
    pthread_create(&r_thr,NULL,(void *)&display,(void *)NULL);
    pthread_create(&w_thr,NULL,(void *)&update,(void *)NULL);
    pthread_join(r_thr,&status);
    pthread_join(w_thr,&status);
}

void update()
{
  void *status;
  while(1)
  {
        pthread_mutex_lock(&timer_lock);
        secs=secs+1;
        if(secs==60)
        {
                mins=mins+1;
                secs=0;
        }
        if(mins==60)
        {
                hours=hours+1;
                mins=0;
        }
        if(hours==24)
        {
                hours=0;
        }
  pthread_mutex_unlock(&timer_lock);
  sleep(1);
 }
 pthread_exit(&status);
}

void display()
{
  void *status;
  while(1)
  {
        pthread_mutex_lock(&timer_lock);
        printf("\n DISPLAY:");
        printf("\t %d %d %d",hours,mins,secs);
        pthread_mutex_unlock(&timer_lock);
       // sleep(1);
  }
 pthread_exit(&status);
}

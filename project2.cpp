#include<stdio.h> 
 
int main() 
{ 
      int i, n, total = 0, x, counter = 0, Time_Slice,j; 
      
	  int W_time = 0,  TA_time = 0,pos,z,p[20],prio[20], arr_time[20], bur_time[20], temp[20],b; 
      
	  float average_wait_time, average_turnaround_time;
      
	  printf("\nEnter Total Number of Processes:"); 
      
	  scanf("%d", &n); 
      
	  x = n; 
      for(i = 0; i < n; i++) 
      {
	    p[i]=i+1;
	   
	    prio[i]=0;
            printf("\nEnter total Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arr_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &bur_time[i]); 
            temp[i] = bur_time[i];
      }
	   
      printf("\nEnter the Time Quantum:"); 
      scanf("%d", &Time_Slice); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, i = 0; x != 0;) 
      { 

		    for(z=0;z<n;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<n;j++)
			{
			    if(prio[j]<prio[pos])
				pos=j;
			}
		 
		temp1=prio[z];
	
		prio[z]=prio[pos];
	
		prio[pos]=temp1;
		 
			temp1=bur_time[z];
			bur_time[z]=bur_time[pos];
			bur_time[pos]=temp1;
		 			temp1=arr_time[z];
				arr_time[z]=arr_time[pos];
			arr_time[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=temp[z];
				temp[z]=temp[pos];
			temp[pos]=temp1;
		    }
		{
		}
            
			if(temp[i] <= Time_Slice && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - Time_Slice; 
                  total = total + Time_Slice; 
            } 

	for(b=0;b<n;b++)
		{
			if(b==i)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[i], bur_time[i], total - arr_time[i], total - arr_time[i] - bur_time[i],prio[i]);
                  W_time = W_time + total - arr_time[i] - bur_time[i]; 
                   TA_time =  TA_time + total - arr_time[i]; 
                  counter = 0; 
            } 
            if(i == n - 1) 
            {
                  i = 0; 
            
			}
            else if(arr_time[i + 1] <= total) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      return 0; 
}

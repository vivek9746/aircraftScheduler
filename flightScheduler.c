#include<stdio.h>
#include<stdlib.h>
struct aircraft{
	int number,fuelRemaining;
	char name[40];
	char company[40];
	float time;
	char status[1]; //Domestic or International
	int delegate;  //1 if delegate on board else 0
	int interContinental;
	
	
}temp;
int main(){
	int i,j;
	int n,safeValue=5000;
	
	printf("enter number of aircrafts");
	scanf("%d",&n);
	struct aircraft flight[n];
	
	//taking input
	
	for(i=0;i<n;i++){
		
		//printf("enter time\n\n");
		//scanf("%f",&flight[i].time);
		
		
		printf("\nenter flight number\n\n");
		scanf("%d",&flight[i].number);
		
		
		printf("\nenter name\n\n");
		scanf("%s",flight[i].name);
		
		
		printf("\nenter company\n\n");
		scanf("%s",flight[i].company);
		
		
		printf("\nenter fuel remaining\n\n");
		scanf("%d",&flight[i].fuelRemaining);
		
		
		
		
		printf("enter status:\n\n D : Domestic \n I : International\n\n\n");
		scanf("%s",flight[i].status);
		
		if(flight[i].status[0]=='I'){
			

			printf("Any International Delegation on flight ?\n\n(Enter 1 for YES, or 0 for NO):      ");
			scanf("%d",&flight[i].delegate);
			
			
			printf("Intercontinental International ?\n\n(Enter 1 for YES, or 0 for NO):      ");
			scanf("%d",&flight[i].interContinental);
			
			
		}
		
		
		
	}
	
	//sorting
	
	
	for(i=0;i<n-1;i++){
		
		for(j=i+1;j<n;j++){
			if(flight[i].fuelRemaining > flight[j].fuelRemaining ){
				temp=flight[i];
				flight[i]=flight[j];
				flight[j]=temp;
			}
			
			//if fuel remaining is same
			
			if(flight[i].fuelRemaining == flight[j].fuelRemaining){
				
				//check for domestic or international. Land the International flight first
				
				if(flight[i].status[0]=='D' && flight[j].status[0]=='I'){
					
					temp=flight[i];
					flight[i]=flight[j];
					flight[j]=temp;
					
				}
				
				//if both flights are international
				
				if(flight[i].status[0]=='I' && flight[j].status[0]=='I'){
					
					//check for international delegates onboard
					
					if(flight[i].delegate < flight[j].delegate ){
					
					
						temp=flight[i];
						flight[i]=flight[j];
						flight[j]=temp;
						
					}
					
					//if both have international delegates. check for region, neighbours or intercontinental, if intercontinental, land first
					
					if(flight[i].delegate == flight[j].delegate==1){
						
						if(flight[i].interContinental < flight[j].interContinental ){
					
							temp=flight[i];
							flight[i]=flight[j];
							flight[j]=temp;
						
						}
						
						
						
					}
					
				}
				
				
			}
		}
	}
	
	//printing output
	printf("Flight Number\tFlight Name\tCompany\t     Status\tFuel Remaining \n");
	for(i=0;i<n;i++){
		printf("%d\t\t\%s\t\t\%s\t\t\%s\t\t%d\n\n",flight[i].number,flight[i].name,flight[i].company,flight[i].status,flight[i].fuelRemaining);
	}
	return 0;
		
}

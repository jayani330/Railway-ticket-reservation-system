#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream.h>

using namespace std;

char c;
int n,reservation_no,train_no;
string train_class,train_type,route;
			
			
class GetDetails
{
	private:
		char name[40];
		string start,destination;
		
	public:
		
		void getdata()
		{
			cout<<endl;
			
			for(int i=0;i<120;i++)
			{
				cout<<"*";
			}
			
			cout<<"\n\tMAKE YOUR RESERVATION"<<endl;			
			
			ofstream fout;
			fout.open("ticket.txt", ios::out);
			fout<<"\tTRAIN TICKET\n\n";
			
			cout<<"\n\nSelect combination : "<<endl
			<<"\t1.Route = A5 and Train type = slow train"<<endl
			<<"\t2.Route = A5 and Train type = intercity train"<<endl
			<<"\t3.Route = B4 and Train type = slow train"<<endl
			<<"\t4.Route = B4 and Train type = intercity train"<<endl;
			cout<<"Enter choice : ";
			cin>>n;
			
			
			switch(n)
			{
				case 1 : cout<<"\nName : ";
						 cin>>name;
						 
						 if(name>40)
						 {
						 	cout<<"maximum limit is 40, enter name again : ";
							cin>>name;
						 }
						 
						 route="A5";
						 cout<<"Route : A5"<<endl;
				
						 train_type="slow_train";
						 cout<<"Train type : slow train"<<endl;
				
						 cout<<"Train no (1/2) : ";
						 cin>>train_no;
						 
						 train_class="third";
						 cout<<"Class : third"<<endl;
						
						 cout<<"Startng point (A/A1/A2/A3/A4) : ";
						 cin>>start;
									
						 cout<<"Destination (A1/A2/A3/A4/A5) : ";
						 cin>>destination;
								
						 cout<<"Number of reservations : ";
						 cin>>reservation_no;
								
						 break;
						 
			
				case 2 : cout<<"\nName : ";
						 cin>>name;
			
						 route="A5";
						 cout<<"Route : A5"<<endl;
						
						 train_type="intercity_train";
						 cout<<"Rrain type : intercity train"<<endl;
						 
						 train_no=1;
						 cout<<"Train no : 1 "<<endl;
						 
						 cout<<"Class (first/second/third) : ";
						 cin>>train_class;	  	  
						
						 start="A";
						 cout<<"Startng point : A"<<endl;
						 
						 destination="A5";
						 cout<<"Destination : A5 "<<endl;
						 
						 cout<<"No of reservations : ";
						 cin>>reservation_no;
						
						 break;
						 
			
				case 3 : cout<<"\nName : ";
						 cin>>name;
		
						 route="B4";
						 cout<<"Route : B4"<<endl;
						
						 train_type="slow_train";
						 cout<<"Train type : slow train"<<endl;
						 
						 cout<<"Train no (1/2/3/4) : ";
						 cin>>train_no;
						
						 train_class="third";	  	  	  	  	  
						 cout<<"Class : third"<<endl;
						 	 	 	 	 
						 cout<<"Startng point (B/B1/B2/B3) : ";
						 cin>>start;
												
						 cout<<"Destination (B1/B2/B3/B4) : ";
						 cin>>destination;
						
						 cout<<"No of reservations : ";
						 cin>>reservation_no;
						
						 break;
						 
						
				case 4 : cout<<"\nName : ";
						 cin>>name;
					
						 route="B4";
						 cout<<"Route : B4"<<endl;
						 
						 train_type="intercity_train";
						 cout<<"Train type : intercity train "<<endl;
						 
						 cout<<"Train no (1/2) : ";
						 cin>>train_no;
											
						 cout<<"Class (first/second/third) : ";
						 cin>>train_class;
						
						 start="B";						
						 cout<<"Startng point : B"<<endl;
						 	 	 	 	 	 	 
						 destination="B4";
						 cout<<"Destination : B4"<<endl;
						 
						 cout<<"No of reservations : ";
						 cin>>reservation_no;
						
						 break;
						 
						
				default : cout<<"ERROR!"<<endl;	
			}
			
			
			fout<<"Name : "<<name<<endl
			<<"Route : "<<route<<endl
			<<"Train type : "<<train_type<<endl
			<<"Train no : "<<train_no<<endl
			<<"Class : "<<train_class<<endl
			<<"Starting point : "<<start<<endl
			<<"Destination : "<<destination<<endl
			<<"Number of reservations made : "<<reservation_no<<endl;	    	   	   	   
	   	   	   
			fout.close();
			
		}
			
};



class Reservation
{
	public:
		int count[15];
		
	public:
	
		void setdata()
		{
		
			for(int i=1; i<=15; i++)
			{
				count[i]=0;
			}
			
		}
		
		
		void reserve()
		{
			ofstream logging;
			logging.open("ticket.txt",ios::app);		
			
			switch(n)
			{
				case 1 : if(train_no==1){					
				 	 	 	count[n]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n]<<endl;	
							cout<<"More reservations to be make : "<<(120-count[n])<<endl;	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  
							logging<<"Ticket numbers : "<<(count[n]-reservation_no+1)<<" to "<<count[n]<<endl<<endl;														 	 	 	 	 	 	 	 	 	 
							}
						
						else if(train_no==2){	 	 	 	 	 	 	 
							count[n+1]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+1]<<endl;	  
							cout<<"More reservations to be make : "<<(120-count[n+1])<<endl;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							logging<<"Ticket numbers : "<<(count[n+1]-reservation_no+1)<<" to "<<count[n+1]<<endl<<endl;																								
							}
							
						break;
						
						
						
				case 2 : if(train_class=="first"){
							count[n+1]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+1]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+1])<<endl;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							logging<<"Ticket numbers : "<<(count[n+1]-reservation_no+1)<<" to "<<count[n+1]<<endl<<endl;							
							}
							
						 else if(train_class=="second"){						 
						 	count[n+2]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+2]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+2])<<endl;																
							logging<<"Ticket numbers : "<<(count[n+2]-reservation_no+1)<<" to "<<count[n+2]<<endl<<endl;
							}
							
						 else if(train_class=="third"){	   	   	   	   	   	    	
							count[n+3]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+3]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+3])<<endl;																
							logging<<"Ticket numbers : "<<(count[n+3]-reservation_no+1)<<" to "<<count[n+3]<<endl<<endl;						 							 	 	 	 	 	 	  	  
							}
							
						break;
						
						
				
				case 3 : if(train_no==1){	 
				
							count[n+3]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+3]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+3])<<endl;																
							logging<<"Ticket numbers : "<<(count[n+3]-reservation_no+1)<<" to "<<count[n+3]<<endl<<endl;													   	   	   	   	   
							}
							
						else if(train_no==2){
							count[n+4]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+4]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+4])<<endl;																
							logging<<"Ticket numbers : "<<(count[n+4]-reservation_no+1)<<" to "<<count[n+4]<<endl<<endl;																													
							}
							
						else if(train_no==3){
							count[n+5]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+5]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+5])<<endl;																
							logging<<"Ticket numbers : "<<(count[n+5]-reservation_no+1)<<" to "<<count[n+5]<<endl<<endl;																												
							}
							
						else if(train_no==4){
							count[n+6]+=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n+6]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+6])<<endl;																
							logging<<"Ticket numbers : "<<(count[n+6]-reservation_no+1)<<" to "<<count[n+6]<<endl<<endl;																							 	 	 	 
							}
							
						break;
						
						
						
				case 4 : if(train_no==1){
				
							if(train_class=="first"){
								count[n+6]+=reservation_no;
								cout<<"\nCurrently reserved : "<<count[n+6]<<endl;
								cout<<"More reservations to be make : "<<(120-count[n+6])<<endl;																
								logging<<"Ticket numbers : "<<(count[n+6]-reservation_no+1)<<" to "<<count[n+6]<<endl<<endl;																																	
								}
								
							else if(train_class=="second"){
								count[n+7]+=reservation_no;
								cout<<"\nCurrently reserved : "<<count[n+7]<<endl;
								cout<<"More reservations to be make : "<<(120-count[n+7])<<endl;																
								logging<<"Ticket numbers : "<<(count[n+7]-reservation_no+1)<<" to "<<count[n+7]<<endl<<endl;																																			
								}
								
							else if(train_class=="third"){	  	
								count[n+8]+=reservation_no;
								cout<<"\nCurrently reserved : "<<count[n+8]<<endl;
								cout<<"More reservations to be make : "<<(120-count[n+8])<<endl;																
								logging<<"Ticket numbers : "<<(count[n+8]-reservation_no+1)<<" to "<<count[n+8]<<endl<<endl;															  	  	  	  	  	  	  	  	  	  	  	    						
								}
							}
							
							
						else if(train_no==2){
						
							if(train_class=="first"){
								count[n+9]+=reservation_no;
								cout<<"\nCurrently reserved : "<<count[n+9]<<endl;
								cout<<"More reservations to be make : "<<(120-count[n+9])<<endl;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
								logging<<"Ticket numbers : "<<(count[n+9]-reservation_no+1)<<" to "<<count[n+9]<<endl<<endl;																																				
								}
								
							else if(train_class=="second"){	
								count[n+10]+=reservation_no;
								cout<<"\nCurrently reserved : "<<count[n+10]<<endl;
								cout<<"More reservations to be make : "<<(120-count[n+10])<<endl;   															
								logging<<"Ticket numbers : "<<(count[n+10]-reservation_no+1)<<" to "<<count[n+10]<<endl<<endl;	  	  	  	  	  	  	  	  	  	  	  	  	  	  	     	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
								}
								
							else if(train_class=="third"){	  
								count[n+11]+=reservation_no;
								cout<<"\nCurrently reserved : "<<count[n+11]<<endl;
								cout<<"More reservations to be make : "<<(120-count[n+11])<<endl;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
								logging<<"Ticket numbers : "<<(count[n+11]-reservation_no+1)<<" to "<<count[n+11]<<endl<<endl;	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  
								}
							}
							
						break;
						
						
						
				default : cout<<"ERROR!"<<endl;
											
			}
						
			logging<<"\tHAPPY JOURNEY!";
			logging.close();
			
		}
		
		
		void cancel()
		{
		switch(n)
			{
				case 1 : if(train_no==1){	 	 	 	 	 	 	 
							count[n]-=reservation_no;
							cout<<"\nCurrently reserved : "<<count[n]<<endl;	
							cout<<"More reservations to be make : "<<(120-count[n])<<endl;	  	  	  	  	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   
							}
						
						else if(train_no==2){
							count[n+1]-=reservation_no;	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   
							cout<<"\nCurrently reserved : "<<count[n+1]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+1])<<endl;								 
							}
							
						break;
						
						
						
				case 2 : if(train_class=="first"){	  	  	  	  	  	  	  
							count[n+1]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+1]<<endl;	   
							cout<<"More reservations to be make : "<<(120-count[n+1])<<endl;						
							}
							
						 else if(train_class=="second"){						 
						    count[n+2]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+2]<<endl;	 
							cout<<"More reservations to be make : "<<(120-count[n+2])<<endl;  	  	  	  	  	  	  
							}
							
						 else if(train_class=="third"){
							count[n+3]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+3]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+3])<<endl;							
							}
							
						break;
						
						
				
				case 3 : if(train_no==1){	 	 	 	 
							count[n+3]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+3]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+3])<<endl;							
							}
							
						else if(train_no==2){	 	 	 	 	 	 
						    count[n+4]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+4]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+4])<<endl;							
							}
							
						else if(train_no==3){	 	 	 	 	 	 
							count[n+5]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+5]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+5])<<endl;							
							}
							
						else if(train_no==4){	 	 	 	 	 	 
							count[n+6]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+6]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+6])<<endl;							
							}
							
						break;
						
						
						
				case 4 : if(train_no==1){
				
							if(train_class=="first"){	 	 	 	 	 	 	 
							count[n+6]-=reservation_no;	    																		
							cout<<"\nCurrently reserved : "<<count[n+6]<<endl;	 
							cout<<"More reservations to be make : "<<(120-count[n+6])<<endl;  	  	  	  	  	  	  
							}
								
							else if(train_class=="second"){	   	   	   	   	   	   	   
							count[n+7]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+7]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+7])<<endl;							
							}
								
							else if(train_class=="third"){	  	  	  	  	  	  	  
							count[n+8]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+8]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+8])<<endl;							
							}
							
						}
							
							
						else if(train_no==2){
						
							if(train_class=="first"){	 	 	 	 	 	 	 
							count[n+9]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+9]<<endl;	
							cout<<"More reservations to be make : "<<(120-count[n+9])<<endl;   	   	   	   	   	   	   
							}
								
							else if(train_class=="second"){	   	   	   	   	   	   	   
							count[n+10]-=reservation_no;	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  
							cout<<"\nCurrently reserved : "<<count[n+10]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+10])<<endl;							
							}
								
							else if(train_class=="third"){	  	  	  	  	  	  	  
							count[n+11]-=reservation_no;	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
							cout<<"\nCurrently reserved : "<<count[n+11]<<endl;
							cout<<"More reservations to be make : "<<(120-count[n+11])<<endl;							
							}
							
						}
							
						break;
																		
				default : cout<<"ERROR!"<<endl;
											
			}

		}	 	 

};




class FacadeClass
{

	private:
		GetDetails objG;
		Reservation objR;
	
	
	public:
	
		void call()
		{
			
			objR.setdata();
		
			while(1)
			{
			
				objG.getdata();
				objR.reserve();
				
					for(int i=1; i<=15; i++)
					{
						if(objR.count[i]>120)
						cout<<"\n\tYOU HAVE EXCEED THE MAXIMUM RESERVATION LIMIT!\n\tINVALIED RESERVATION!\n\tSHOULD CANCEL RESERVATION!"<<endl;
						break;
					}
														
															
					cout<<"\n\nWANNA CANCEL RESERVATION (Y/N) ? : ";
					cin>>c;
						if(c=='y' || c=='Y')
						{
							cout<<"\n\tRESERVATION HAS BEEN CANCELED!"<<endl;
							objR.cancel();
						}
												
						else if(c=='n' || c=='N')
						{
							cout<<"\n\n\tSUCCESS!"<<endl<<"YOUR RESERVATION HAS BEEN MADE"<<endl;
						}
						
					cout<<"\n\nWANNA CONTINUE (Y/N) ? : ";
					cin>>c;
						if(c=='n' || c=='N')
						break;
														
			}
			
						
			cout<<"\n\tRESERVATIONS CAN NOT BE DONE"<<endl<<"\tTHANK YOU!"<<endl;
			
		}
		
};



int main()
{
	
	FacadeClass objF;
	objF.call();
			
	return 0;
	
}


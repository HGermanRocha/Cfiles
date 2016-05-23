#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

void Status(int carId, char serviceType);

int main()
{
	char c = 's', serviceId = ' ';
	int randomService = 0, traffic = 0, positionRow1 = 0, positionRow2 = 0, positionRow3 = 0;
	int carId = 1, counter = 0, no_services = 0, carsOut = 0, z = 0;
	string serviceType = "";
	
	srand(time(NULL));
	
	//Matriz que representa las líneas de lavado
	int matrix[6][3];
	char types[19];
	
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] = 0;
		}
	}
	
	for(int i = 0; i < 19; i++)
	{
		types[i] = ' ';
	}
	
	while(c != 'n')
	{
		
		if(c != 'n')
		{
			randomService = 1 + rand()%4;
			cout<<randomService<<endl;
			
			switch(randomService)
			{
				case 1:
					serviceType = "Simple";
					serviceId = 'S';
					types[carId] = serviceId;
					
					for(int i = 0; i < 6; i++)
					{
						if(matrix[i][0] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic <= 4)
					{
						no_services++;
						
						if(no_services > 3)
						{
							Status(carId, types[carId]);
							
							for(z = 0; z < 5; z++)
							{
								if(types[matrix[z][0]] == 'S')
								{
									break;		
								}	
							}
							getch();
							matrix[z][0] = 0;
							
							for(int i = z; i < 5; i++)
							{
								matrix[i][0] =  matrix[i + 1][0];
							//	types[i] = types[i + 1];
							}
							no_services = 0;
						}
						else
						{
							matrix[positionRow1][0] = carId;
						
							positionRow1++;
							carId++;
						}	
					}
					
					else if(traffic >= 6)
					{
						cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
					}
					
					else
					{
						no_services++;
						
						if(no_services > 3)
						{
							Status(carId, types[carId]);
							
							for(z = 0; z < 6; z++)
							{
								if(types[matrix[z][2]] == 'S')
								{
									break;		
								}	
							}
							
							getch();
							matrix[z][2] = 0;
							
							for(int i = z; i < 5; i++)
							{
								matrix[i][2] =  matrix[i + 1][2];
							//	types[i] = types[i + 1];
							}
							no_services = 0;
						}
						
						else
						{
							matrix[positionRow3][2] = carId;
							positionRow3++;	
							carId++;	
						}	
					}
			
					traffic = 0;	
					break;
				case 2:
					serviceType = "Economico";
					serviceId = 'E';
					types[carId] = serviceId;
					
					for(int i = 0; i < 6; i++)
					{
						if(matrix[i][0] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic < 4)
					{
						matrix[positionRow1][0] = carId;
						positionRow1++;
						carId++;
						no_services++;
					}
					else if(traffic >= 6)
					{
						cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
					}
					
					else
					{
						matrix[positionRow2][1] = carId;
						positionRow2++;
						carId++;
						no_services++;
					}
					
					traffic = 0;
					
					break;
				case 3:
					serviceType = "Completo";
					serviceId = 'C';
					types[carId] = serviceId;
					
					for(int i = 0; i < 6; i++)
					{
						if(matrix[i][1] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic >= 6)
					{
						cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
					}
					
					else
					{
						matrix[positionRow2][1] = carId;
						positionRow2++;
						
						no_services++;
						carId++;
					}
					
					traffic = 0;
					break;
				case 4:
					serviceType = "Lujo";
					serviceId = 'L';
					types[carId] = serviceId;
					
					for(int i = 0; i < 6; i++)
					{
						if(matrix[i][2] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic >= 6)
					{
						cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
						
					}
					
					else
					{
						matrix[positionRow3][2] = carId;
						positionRow3++;
						
						no_services++;
						carId++;	
					}
					
					traffic = 0;
					break;
				default:
					cout<<"Error\n";
					break;
			}
			cout<<no_services;
			getch();
			
			system("cls");
			cout<<"\t\tAUTOLAVADO\n\n";
			
			for(int i = 5; i > -1; i--)										
			{
				cout<<"________\t\t________\t\t________\n";
				
				for(int j = 0; j < 3; j++)
				{
					
					if(matrix[i][j] == 0)
					{
						cout<<"|  "<<"  "<<"  |\t\t";	
					}
					
					else
					{
						cout<<"|  "<<matrix[i][j]<<types[matrix[i][j]]<<"  |\t\t";
					}
					
					counter++;
				}
				
				cout<<endl;
				cout<<"--------\t\t--------\t\t--------\n";
			}
			cout<<"Linea 1 \t\tLinea 2 \t\tLinea 3 \n\n";
			
			cout<<"Presione \'Enter\'\n";
			c = getch();
		}
	}
	
	
	getch();
	return 0;
}

void Status(int carId, char serviceType)
{
	string service = "";
	
	if(serviceType == 'S')
	{
		service = "Simple";
	}
	else if(serviceType == 'E')
	{
		service = "Economico";
	}
	else if(serviceType == 'C')
	{
		service = "Completo";
	}
	else if(serviceType == 'L')
	{
		service = "Lujo";
	}
	cout<<"\n\t\tSTATUS\n\n";
	cout<<"Car ID: "<<carId<<endl;
	cout<<"Type of service: "<<service<<endl;
	cout<<"Status: "<<"Finished"<<endl;
	
	getch();
	
}
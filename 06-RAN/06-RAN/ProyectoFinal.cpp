#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

void Status(int carId, char serviceType);
void DisplayTable(int linea1 [], int linea2 [], int linea3 [], char types[]);
char CheckIfContinue();

int main()
{
	char c = 's', serviceId = ' ';
	int randomService = 0, traffic = 0, positionLine1 = 0, positionLine2 = 0, positionLine3 = 0;
	int carId = 1, counter = 0, no_services = 0, carsOut = 0, z = 0;
	string serviceType = "";
	
	srand(time(NULL));
	
	//Matriz que representa las líneas de lavado
	int linea1[6] = {0};
	int linea2[6] = {0};
	int linea3[6] = {0};
	char types[300] = {' '};
	
	while(c != 'n')
	{
		DisplayTable(linea1, linea2, linea3, types);
		
		c = CheckIfContinue();
		
		if(c != 'n')
		{	
			randomService = 1 + rand()%4;
			cout<<randomService<<endl;
			cout<<no_services;
			getch();		
			switch(randomService)
			{
				case 1:
					serviceType = "Simple";
					serviceId = 'S';
					//types[carId] = serviceId;
					
					for(int i = 0; i < 6; i++)
					{
						if(linea1[i] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic <= 4)
					{
						no_services++;
						
						//Value of a certain position in the line
						linea1[positionLine1] = carId;
						types[carId] = serviceId;
						
						if(no_services > 3)
						{
							DisplayTable(linea1, linea2, linea3, types);
							
							for(z = 0; z < 5; z++)
							{
								if(types[linea1[z]] == 'S')
								{
									Status(carId, types[carId]);
									linea1[z] = 0;
											
									for(int i = z; i < 18; i++)
									{
										types[linea1[z]] = types[linea1[z + 1]]; 
									}
									
									for(int i = z; i < 5; i++)
									{
										linea1[i] =  linea1[i + 1];
									}
									
									break;		
								}	
							}
							//no_services = 0;
							DisplayTable(linea1, linea2, linea3, types);
						}
						else
						{
							linea1[positionLine1] = carId;
							types[carId] = serviceId;
							
							positionLine1++;
							carId++;
						}	
					}
					
					else if(traffic > 4)
					{
						traffic = 0;
						
						for(int i = 0; i < 6; i++)
						{
							if(linea3[i] != 0)
							{
								traffic++;		
							}
						}
						
						if(traffic >= 6)
						{
							cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
							getch();
						}	
						else
						{
							no_services++;
						
							linea3[positionLine3] = carId;
							types[carId] = serviceId;
							
							if(no_services > 3)
							{
								DisplayTable(linea1, linea2, linea3, types);
								
								for(z = 0; z < 5; z++)
								{
									if(types[linea3[z]] == 'S')
									{
										Status(carId, types[carId]);
										linea3[z] = 0;
												
										for(int i = z; i < 18; i++)
										{
											types[linea3[z]] = types[linea3[z + 1]]; 
										}
										
										for(int i = z; i < 5; i++)
										{
											linea3[i] =  linea3[i + 1];
										}
										
										break;		
									}	
								}
								
								DisplayTable(linea1, linea2, linea3, types);
							}
							
							else
							{
								linea3[positionLine3] = carId;
								types[carId] = serviceId;
								
								positionLine3++;
								carId++;	
							}	
						}
							
					}
			
					traffic = 0;	
					break;
				case 2:
					serviceType = "Economico";
					serviceId = 'E';
					
					for(int i = 0; i < 6; i++)
					{
						if(linea1[i] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic <= 4)
					{
						no_services++;
						
						//Value of a certain position in the line
						linea1[positionLine1] = carId;
						types[carId] = serviceId;
						
						/*if(no_services > 3)
						{
							Status(carId, types[carId]);
							
							for(z = 0; z < 5; z++)
							{
								if(types[linea1[z]] == 'S')
								{
									linea1[z] = 0;
											
									for(int i = z; i < 18; i++)
									{
										types[linea1[z]] = types[linea1[z + 1]]; 
									}
									
									for(int i = z; i < 5; i++)
									{
										linea1[i] =  linea1[i + 1];
									}
									
									break;		
								}	
							}
							//no_services = 0;
							
							DisplayTable(linea1, linea2, linea3, types);
						}
						else
						{
							line1[positionLine1] = carId;
							types[carId] = serviceId;
							
							positionLine1++;
							carId++;
						}
						*/	
						positionLine1++;
						carId++;
					}
					
					else if(traffic > 4)
					{
						traffic = 0;
						
						for(int i = 0; i < 6; i++)
						{
							if(linea2[i] != 0)
							{
								traffic++;		
							}
						}
						
						if(traffic >= 6)
						{
							cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
							getch();
						}
						else
						{
							no_services++;
							
							linea2[positionLine2] = carId;
							types[carId] = serviceId;
							
							/*if(no_services > 3)
							{
								Status(carId, types[carId]);
								
								for(z = 0; z < 5; z++)
								{
									if(types[linea3[z]] == 'S')
									{
										linea3[z] = 0;
												
										for(int i = z; i < 18; i++)
										{
											types[linea3[z]] = types[linea3[z + 1]]; 
										}
										
										for(int i = z; i < 5; i++)
										{
											linea3[i] =  linea3[i + 1];
										}
										
										break;		
									}	
								}
								
								DisplayTable(linea1, linea2, linea3, types);
							}
							
							else
							{
								line3[positionLine3] = carId;
								types[carId] = serviceId;
								
								positionLine3++;
								carId++;	
							}
							*/	
							carId++;	
							positionLine2++;
						}
						
					}
					
					traffic = 0;	
					break;
				case 3:
					serviceType = "Completo";
					serviceId = 'C';
					
					for(int i = 0; i < 6; i++)
					{
						if(linea2[i] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic < 5)
					{
						no_services++;
						
						//Value of a certain position in the line
						linea2[positionLine2] = carId;
						types[carId] = serviceId;
						
						/*if(no_services > 3)
						{
							Status(carId, types[carId]);
							
							for(z = 0; z < 5; z++)
							{
								if(types[linea1[z]] == 'S')
								{
									linea1[z] = 0;
											
									for(int i = z; i < 18; i++)
									{
										types[linea1[z]] = types[linea1[z + 1]]; 
									}
									
									for(int i = z; i < 5; i++)
									{
										linea1[i] =  linea1[i + 1];
									}
									
									break;		
								}	
							}
							//no_services = 0;
							
							DisplayTable(linea1, linea2, linea3, types);
						}
						else
						{
							line1[positionLine1] = carId;
							types[carId] = serviceId;
							
							positionLine1++;
							carId++;
						}
						*/	
						positionLine2++;
						carId++;
					}
					
					else if(traffic >= 6)
					{
						cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
						getch;
					}
					
					traffic = 0;	
					break;
				case 4:
					serviceType = "Lujo";
					serviceId = 'L';
					
					for(int i = 0; i < 6; i++)
					{
						if(linea3[i] != 0)
						{
							traffic++;		
						}
					}
					
					if(traffic < 5)
					{
						no_services++;
						
						//Value of a certain position in the line
						linea3[positionLine3] = carId;
						types[carId] = serviceId;
						
						/*if(no_services > 3)
						{
							Status(carId, types[carId]);
							
							for(z = 0; z < 5; z++)
							{
								if(types[linea1[z]] == 'S')
								{
									linea1[z] = 0;
											
									for(int i = z; i < 18; i++)
									{
										types[linea1[z]] = types[linea1[z + 1]]; 
									}
									
									for(int i = z; i < 5; i++)
									{
										linea1[i] =  linea1[i + 1];
									}
									
									break;		
								}	
							}
							//no_services = 0;
							
							DisplayTable(linea1, linea2, linea3, types);
						}
						else
						{
							line1[positionLine1] = carId;
							types[carId] = serviceId;
							
							positionLine1++;
							carId++;
						}
						*/	
						carId++;
						positionLine3++;
					}
					
					else if(traffic >= 6)
					{
						cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
						getch();
					}
					
					traffic = 0;	
					break;
				default:
					cout<<"Error\n";
					break;
			}
		}
	}
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

void DisplayTable(int linea1 [], int linea2 [], int linea3 [], char types[])
{	
	system("cls");
	cout<<"\t\tAUTOLAVADO\n\n";
	
	for(int i = 5; i > -1; i--)										
	{
		cout<<"________\t\t________\t\t________\n";
		
		if(linea1[i] == 0)
		{
			cout<<"|  "<<"  "<<"  |\t\t";
		}
		else if(linea1[i] != 0)
		{
			cout<<"|  "<<linea1[i]<<types[linea1[i]]<<"  |\t\t";
		}
		if(linea2[i] == 0)
		{
			cout<<"|  "<<"  "<<"  |\t\t";
		}
		else if(linea2[i] != 0)
		{
			cout<<"|  "<<linea2[i]<<types[linea2[i]]<<"  |\t\t";
		}
		if(linea3[i] == 0)
		{
			cout<<"|  "<<"  "<<"  |\t\t";
		}
		else if(linea3[i] != 0)
		{
			cout<<"|  "<<linea3[i]<<types[linea3[i]]<<"  |\t\t";
		}

		cout<<endl;
		cout<<"--------\t\t--------\t\t--------\n";
	}
	
	cout<<"Linea 1 \t\tLinea 2 \t\tLinea 3 \n\n";
	
	cout<<"Presione \'Enter\'\n";
	
	getch();
}

char CheckIfContinue()
{
	char c;
	int res = 5;
	
	do
	{
		cout<<"\nDesea continuar? (1.Si/0.No)\n";
		cin>>res;
		
		if(res == 1)
		{
			c = 's';
		}
		else if (res == 0)
		{
			c = 'n';
		}
		else
		{
			cout<<"Valor Invalido!\n";	
		}	
	}while(res != 0 && res != 1);
	
	return c;
}
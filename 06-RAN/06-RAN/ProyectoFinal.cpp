#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	char c = 's', serviceId = ' ';
	int randomService = 0, traffic = 0, positionRow1 = 0, positionRow2 = 0, positionRow3 = 0;
	int carId = 1, counter = 0;
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
	
	while(c != 'n')
	{
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
					matrix[positionRow1][0] = carId;
					positionRow1++;
					carId++;
				}
				else if(traffic >= 6)
				{
					cout<<"Lo sentimos, estamos saturados en este momento, por favor venga mas tarde.\n\n";
				}
				
				else
				{
					matrix[positionRow3][2] = carId;
					positionRow3++;	
					carId++;	
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
					
					carId++;	
				}
				
				traffic = 0;
				break;
			default:
				cout<<"Error\n";
				break;
		}
		
		cout<<"Presione \'Enter\'\n";
		
		c = getch();
	}
	
	
	getch();
	return 0;
}
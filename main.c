#include "header.h"
#include "source.c"

int main(int argc, char *argv[]) {
	char menu,  menu_ternak;
	int day=1, Pertaniancurrent_player_x=2, Pertaniancurrent_player_y=1, home_position_x=1, home_position_y=1, batas_lahan_x=2;
	int Pertanianportal_x=19, Pertanianportal_y=1;
	int Perternakanportal_x=4, Perternakanportal_y=0;
	int Perternakancurrent_player_x=5, Perternakancurrent_player_y=1;
	int currentGandum=5, currentJagung=5, minusGandum=0, minusJagung=0, plusGandum=0, plusJagung=0;
	int currentSusu=0, currentTelur=0, plusSusu=0, plusTelur=0;
	int arr_rumput[20][2];
	int arr_ayam[3][2], arr_sapi[3][2];

	randomRumput(arr_rumput);
	
		
		do{
			system("cls");
			printf("Hari ke-%d\n", day);
			printf("%d - %d\n\n", Pertaniancurrent_player_x, Pertaniancurrent_player_y);
			mapPertanian(Pertaniancurrent_player_x, Pertaniancurrent_player_y, home_position_x, home_position_y, batas_lahan_x, Pertanianportal_x, Pertanianportal_y, arr_rumput);
			printf("\n[Space]\t Menanam");
			printf("\n[Enter]\t Mengambil Hasil Tanaman");
			printf("\n[I]\t Inventory");
			printf("\n>>> ");
			printf("\n");
			menu=getch();

			if(menu==97 || menu==100 || menu==115 || menu==119){
				generatePosition(menu, &Pertaniancurrent_player_y, &Pertaniancurrent_player_x);
			}else{
				if(menu=='i'){
					printf("\n\n\t\t########### INVENTORY ###########");
					printf("\n[1] Inventory pertanian");
					printf("\n[2] Inventory perternakan");
					printf("\nPilih jenis >>> "); menu=getch();
					if(menu==49){
						inventoryPertanian(currentGandum, currentJagung, minusGandum, minusJagung, plusGandum, plusJagung);
					}else{
						printf("\n\nHelo");
					}
				}getch();
			}
			
		}while((Pertaniancurrent_player_x!= 19 || Pertaniancurrent_player_y!=1));

		randomAyam(arr_ayam);
		randomSapi(arr_sapi);
		do{
			mapPerternakan(Perternakancurrent_player_x, Perternakancurrent_player_y, Perternakanportal_x, Perternakanportal_y, arr_ayam, arr_sapi); 
			printf("\n[Enter]\t Mengambil Hasil Tanaman");
			printf("\n[I]\t Inventory");
			printf("\n>>> ");
			printf("\n");
			menu_ternak=getch();
			if(menu==97 || menu==100 || menu==115 || menu==119){
				generatePositionTernak(menu_ternak, &Perternakancurrent_player_y, &Perternakancurrent_player_x);
			}else{
				if(menu=='i'){
					printf("\n\n\t\t########### INVENTORY ###########");
					printf("\n[1] Inventory pertanian");
					printf("\n[2] Inventory perternakan");
					printf("\nPilih jenis >>> "); menu=getch();
					if(menu==49){
						inventoryPertanian(currentGandum, currentJagung, minusGandum, minusJagung, plusGandum, plusJagung);
					}else{
						printf("\n\nHelo");
					}
				}getch();
			}
		}while(Perternakancurrent_player_x!=4 || Perternakancurrent_player_y!=0);
	

	return 0;
}


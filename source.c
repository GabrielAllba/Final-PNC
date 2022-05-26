#include "header.h"

void red () {
  printf("\033[1;31m");
}

void reset () {
  printf("\033[0;37m");
}
void yellow(){
  printf ("\033[1;33m");
}

void green (){
  printf ("\033[1;32m");
}


void mapPertanian(int Pertaniancurrent_player_x, int Pertaniancurrent_player_y, int home_position_x, int home_position_y, int batas_lahan_x, int Pertanianportal_x, int Pertanianportal_y, int arr_rumput[20][2]){  

  int i, j;

  printf("\t\t\t===[ Pertanian ]===\n\n");

  for(i=0; i<15; i++){
    for(j=0; j<20; j++){
      if(i == 0 || i == 14){
          printf("[]");
      }else{
        if(j==0 || j==19){
            if(i==Pertanianportal_y && j==Pertanianportal_x){
              printf(" >");
            }else{
              printf("[]");
            }
        }else{
          if(i == batas_lahan_x){
            printf("--");
          }else if(i==home_position_y && j==home_position_x){
            printf("@]");
          }else if(i==Pertaniancurrent_player_y && j==Pertaniancurrent_player_x ){
            printf("P ");
          }else{            
            int x, inner_x=0, inner_y=1, status_ada_rumput=0;
            for(x=0; x<20; x++){
              if(arr_rumput[x][inner_x]==j && arr_rumput[x][inner_y]==i){
                printf("^^");
                status_ada_rumput=1;
                break;
              }else{
                status_ada_rumput=0;
              }
            }

            if(status_ada_rumput==0){
              printf("  ");
            }
          }
        }
      }
    }
      printf("\n");
  }
}

void inventoryPertanian(int currentGandum, int currentJagung, int minusGandum, int minusJagung, int plusGandum, int plusJagung){
  printf("\n\n\t#### INVENTORY PERTANIAN ####");
  printf("\n\tJumlah Gandum : %d", totalGandum(currentGandum, minusGandum, plusGandum));
  printf("\n\tJumlah Jagung : %d", totalJagung(currentJagung, minusJagung, plusJagung));
}

void inventoryPerternakan(int currentSusu, int currentTelur, int plusSusu, int plusTelur){
  printf("\n\n\t#### INVENTORY PERTANIAN ####");
  printf("\n\tJumlah Susu : %d", totalSusu(currentSusu, plusSusu));
  printf("\n\tJumlah Telur : %d", totalTelur(currentTelur, plusTelur));
}

int totalSusu(int currentSusu, int plusSusu){
  return currentSusu + plusSusu;
}

int totalTelur(int currentTelur, int plusTelur){
  return currentTelur + plusTelur;
}

int totalGandum(int currentGandum, int minusGandum, int plusGandum){
  return currentGandum + plusGandum - minusGandum;
}

int totalJagung(int currentJagung, int minusJagung, int plusJagung){
  return currentJagung + plusJagung - minusJagung;
}

void randomRumput(int arr_rumput[20][2]){
  int x,y, inner_x=0, inner_y=1, random_x, random_y, status_ada=0;

  for(x=0;x<20;x++){
      do{
        random_x=1 + rand() % 18;
        random_y=3 + rand() % 11;      
        for(y=0; y<20;y++){
          if(arr_rumput[y][inner_x]==random_x && arr_rumput[y][inner_y]==random_y){
            status_ada=1;
            break;
          }else{
            status_ada=0;
          }
        }
      }while(status_ada==1);
      
      arr_rumput[x][inner_x]=random_x;
      arr_rumput[x][inner_y]=random_y;
  }
}
void randomAyam(int arr_ayam[3][2]){
  int x,y, inner_x=0, inner_y=1, random_x, random_y, status_ada=0;

  for(x=0;x<3;x++){
      do{
        random_x=1 + rand() % 8;
        random_y=1 + rand() % 8;      
        for(y=0; y<3;y++){
          if(arr_ayam[y][inner_x]==random_x && arr_ayam[y][inner_y]==random_y){
            status_ada=1;
            break;
          }else{
            status_ada=0;
          }
        }
      }while(status_ada==1);
      
      arr_ayam[x][inner_x]=random_x;
      arr_ayam[x][inner_y]=random_y;
  }

  for(x=0; x<20;x++){
    printf("[%d][%d], ", arr_ayam[x][inner_x], arr_ayam[x][inner_y]);
  }
}

void randomSapi(int arr_sapi[3][2]){
  int x,y, inner_x=0, inner_y=1, random_x, random_y, status_ada=0;

  for(x=0;x<3;x++){
      do{
        random_x=1 + rand() % 8;
        random_y=1 + rand() % 8;      
        for(y=0; y<3;y++){
          if(arr_sapi[y][inner_x]==random_x && arr_sapi[y][inner_y]==random_y){
            status_ada=1;
            break;
          }else{
            status_ada=0;
          }
        }
      }while(status_ada==1);
      
      arr_sapi[x][inner_x]=random_x;
      arr_sapi[x][inner_y]=random_y;
  }

  for(x=0; x<20;x++){
    printf("[%d][%d], ", arr_sapi[x][inner_x], arr_sapi[x][inner_y]);
  }
}

void mapPerternakan(int Perternakancurrent_player_x, int Perternakancurrent_player_y, int Perternakanportal_x, int Perternakanportal_y, int arr_ayam[3][2], int arr_sapi[3][2]){  

  int i, j;

  printf("\t\t\t===[ Perternakan ]===\n\n");

  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      if(i == 0 || i == 9){
          printf("[]");
      }else{
        if(j==0 || j==9){
            if(j==Perternakanportal_y && i==Perternakanportal_x){
              printf("< ");
            }else{
              printf("[]");
            }
        }else{
          if(i==Perternakancurrent_player_y && j==Perternakancurrent_player_x){
            printf("P ");
          }else{            
            int x, inner_x=0, inner_y=1, status_ada_ayam=0, status_ada_sapi=0;
            for(x=0; x<3; x++){
              if(arr_ayam[x][inner_x]==j && arr_ayam[x][inner_y]==i){
                printf("A ");
                status_ada_ayam=1;
                break;
              }else{
                status_ada_ayam=0;
              }
            }

            for(x=0; x<3; x++){
              if(arr_sapi[x][inner_x]==j && arr_sapi[x][inner_y]==i){
                printf("S ");
                status_ada_sapi=1;
                break;
              }else{
                status_ada_sapi=0;
              }
            }

           if(status_ada_ayam==0 && status_ada_sapi==0){
             printf("  ");
           }
          
          }
        }
      }
    }
      printf("\n");
  }
}

void generatePosition(char move, int *Pertaniancurrent_player_y, int *Pertaniancurrent_player_x){

  // w
	if(move==119){
		if(*Pertaniancurrent_player_y==1){
			*Pertaniancurrent_player_y = 1;
		}else{
			*Pertaniancurrent_player_y-=1;
		}
	}

  // a
  else if(move==97){
		if(*Pertaniancurrent_player_x==1){
			*Pertaniancurrent_player_x = 1;
		}else{
			*Pertaniancurrent_player_x-=1;
		}
  
  // d
	}else if(move==100){

    if(*Pertaniancurrent_player_y==1){
			  *Pertaniancurrent_player_x+=1;
    }else{
      if(*Pertaniancurrent_player_x==19){
			  *Pertaniancurrent_player_x =19;
		  }else{
			  *Pertaniancurrent_player_x+=1;
		  }
    }

  // s
	}else if(move==115){
    if(*Pertaniancurrent_player_y==14){
			*Pertaniancurrent_player_y = 14;
		}else{
			*Pertaniancurrent_player_y+=1;
		}
	}
}

void generatePositionTernak(char move, int *Pertaniancurrent_player_y, int *Pertaniancurrent_player_x){

  // w
	if(move==119){
		if(*Pertaniancurrent_player_y==1){
			*Pertaniancurrent_player_y = 1;
		}else{
			*Pertaniancurrent_player_y-=1;
		}
	}

  // a
  else if(move==97){
		if(*Pertaniancurrent_player_x==1){
			*Pertaniancurrent_player_x = 1;
		}else{
			*Pertaniancurrent_player_x-=1;
		}
  
  // d
	}else if(move==100){

    if(*Pertaniancurrent_player_y==1){
			  *Pertaniancurrent_player_x+=1;
    }else{
      if(*Pertaniancurrent_player_x==9){
			  *Pertaniancurrent_player_x =9;
		  }else{
			  *Pertaniancurrent_player_x+=1;
		  }
    }

  // s
	}else if(move==115){
    if(*Pertaniancurrent_player_y==9){
			*Pertaniancurrent_player_y=9;
		}else{
			*Pertaniancurrent_player_y+=1;
		}
	}
}
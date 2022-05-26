#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define esc 27
typedef char string[100];

void red();
void yellow();
void green();
void reset();
void mapPertanian(int Pertaniancurrent_player_x, int Pertaniancurrent_player_y, int home_position_x, int home_position_y, int batas_lahan_x, int Pertanianportal_x, int Pertanianportal_y, int arr_rumput[20][2]);
void mapPerternakan(int Perternakancurrent_player_x, int Perternakancurrent_player_y, int Perternakanportal_x, int Perternakanportal_y, int arr_ayam[3][2], int arr_sapi[3][2]);
void randomRumput(int arr_rumput[20][2]);
void generatePosition(char move, int *Pertaniancurrent_player_y, int *Pertaniancurrent_player_x);

void inventoryPertanian(int currentGandum, int currentJagung, int minusGandum, int minusJagung, int plusGandum, int plusJagung);
void inventoryPerternakan(int currentSusu, int currentTelur, int plusSusu, int plusTelur);
int totalGandum(int currentGandum, int minusGandum, int plusGandum);
int totalJagung(int currentJagung, int minusJagung, int plusJagung);
void randomAyam(int arr_ayam[3][2]);
void randomSapi(int arr_sapi[3][2]);

int totalSusu(int currentSusu, int plusSusu);
int totalTelur(int currentTelur, int plusTelur);
int totalGandum(int currentGandum, int minusGandum, int plusGandum);
int totalJagung(int currentJagung, int minusJagung, int plusJagung);
void generatePositionTernak(char move, int *Pertaniancurrent_player_y, int *Pertaniancurrent_player_x);
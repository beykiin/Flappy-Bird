// Flappy Bird.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

int birdX = WIDTH / 4;
int birdY = HEIGHT / 2;
int point = 0;

int pipeX = WIDTH - 1;
int pipeY = HEIGHT / 2;

bool gameOver = false;

void updateScreen() {

    system("cls");

	for (int y = 0; y < HEIGHT; y++){

		for (int x = 0; x < WIDTH; x++)	{

			if ((x == birdX && y == birdY) || (x == pipeX && (y < pipeY - 3 || y > pipeY + 3))) {
				
				cout << "*";

			}

			else if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {

				cout << "#";

			}

			else {

				cout << " ";

			}

		}

		cout << endl;

	}

	cout << "Point: " << point << endl;

}

void getEntry() {

	if (_kbhit()) {

		char key = _getch();
		if (key == ' ')
			birdY--;

	}

}

void gameMechanics() {

	birdX++;
	if (birdX == pipeX) {

		point++;

	}

	if (birdX == pipeX + 1 && (birdY < pipeY - 3 || birdY > pipeY + 3)) {

		gameOver = true;

	}

}

int main()
{
    
	while (!gameOver) {

		updateScreen();
		getEntry();
		gameMechanics();
		Sleep(100);

	}

	system("cls");
	cout << "GAME OVER! TOTAL POINT: " << point << endl;
	return 0;

}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin

//�lk olarak, standart giri�/��k�� ve standart k�t�phaneleri dahil ediyoruz.
#include <stdio.h>
#include <stdlib.h>

// Fonksiyon, girilen 5 basamakl� say�y� �ifreler
//encrypt() fonksiyonunu tan�ml�yoruz. Bu fonksiyon, girilen 5 basamakl� bir say�y� �ifreler. Fonksiyon i�inde kullan�lacak de�i�kenleri tan�ml�yoruz.
void encrypt(int num) {
    // De�i�kenleri tan�mla
    int digit1, digit2, digit3, digit4, digit5, sum;

    // Say�y� basamaklar�na ay�rmak i�in girilen say�y� 10000'e b�lerek ilk basama�� buluyoruz.
    // Daha sonra say�y� 1000'e b�lerek ikinci basama�� buluyoruz ve %10 i�lemi ile bu basama�� al�yoruz. Bu i�lemi y�zler, onlar ve birler basama�� i�in de yap�yoruz.
    digit1 = num / 10000;
    digit2 = (num / 1000) % 10;
    digit3 = (num / 100) % 10;
    digit4 = (num / 10) % 10;
    digit5 = num % 10;

    // Basamaklar� �ifrelemek i�in her bir basama�� 9 ile toplayarak �ifreliyoruz. Sonra 10'a b�lerek modunu al�yoruz. B�ylece �ifrelenmi� basamaklar� elde ediyoruz.
    digit1 = (digit1 + 9) % 10;
    digit2 = (digit2 + 9) % 10;
    digit3 = (digit3 + 9) % 10;
    digit4 = (digit3 + 9) % 10;
    digit5 = (digit5 + 9) % 10;

	//�ifrelemenin ard�ndan, �ifrelenmi� basamaklar�n yerlerini de�i�tiriyoruz. �lk ve ���nc� basamaklar� yer de�i�tirerek, ikinci ve d�rd�nc� basamaklar� yer de�i�tiriyoruz.

 	int temp = digit1;
 		digit1 = digit3;
 		digit3 = temp;
 	int	temp2 = digit2;
 		digit2 = digit4;
 		digit4 = temp2;

    // �ifreli say�y� yazd�r
    printf("\nSifrelenmis sayi           : %d%d%d%d%d", digit1, digit2, digit3, digit4, digit5);
}
//Main fonksiyonunda, kullan�c�n�n girdi�i 5 basamakl� say�y� al�yoruz. Do-while d�ng�s� ile do�ru formatta olana kadar
int main() {
    // De�i�kenleri tan�mla
    int num;
    // en �stk g�r�n�m k�sm�n� olu�tur.
		printf("------------------------------------------------------------------------ \n ***************************Sifreleme Programi************************** \n------------------------------------------------------------------------\n \n \n"); 

    // Kullan�c�dan say� girmesini iste ve do�ru formatta oldu�unu kontrol et Do�ru formatta olana kadar tekrarla.
    do {
		printf("Lutfen 5 basamakli bir sayi giriniz: ");
        scanf("%d", &num);
    } while (num < 10000 || num > 99999);

    // Men�y� g�ster ve kullan�c�n�n se�imine g�re i�lem yap
    char choice;
    do {
        printf("Sayi girisiniz basarili, Girilen sayiyi sifrelemek icin 'P'ye, Cikmak icin 'E'ye basiniz: ");
        scanf(" %c", &choice);
		// switch ile istenilen se�imi yapt�r.
        switch (choice) {
        	// Bu case se�ilince Say�y� �ifrelet.
            case 'P':
                encrypt(num);
                break;
                // Bu case se�ilince programdan ��k�� yapt�r.
            case 'E':
                printf("Cikis Yaptiniz...\n");
                exit(0);
           // Yanl�� Se�im yap�lmas� do�rultusunda program� ge�ersiz se�im uyar�s� verip kapat.
		    default:
                printf("Gecersiz Secim.");
        }
    } while (0);

    return 0;
}

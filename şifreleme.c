//Ýlk olarak, standart giriþ/çýkýþ ve standart kütüphaneleri dahil ediyoruz.
#include <stdio.h>
#include <stdlib.h>

// Fonksiyon, girilen 5 basamaklý sayýyý þifreler
//encrypt() fonksiyonunu tanýmlýyoruz. Bu fonksiyon, girilen 5 basamaklý bir sayýyý þifreler. Fonksiyon içinde kullanýlacak deðiþkenleri tanýmlýyoruz.
void encrypt(int num) {
    // Deðiþkenleri tanýmla
    int digit1, digit2, digit3, digit4, digit5, sum;

    // Sayýyý basamaklarýna ayýrmak için girilen sayýyý 10000'e bölerek ilk basamaðý buluyoruz.
    // Daha sonra sayýyý 1000'e bölerek ikinci basamaðý buluyoruz ve %10 iþlemi ile bu basamaðý alýyoruz. Bu iþlemi yüzler, onlar ve birler basamaðý için de yapýyoruz.
    digit1 = num / 10000;
    digit2 = (num / 1000) % 10;
    digit3 = (num / 100) % 10;
    digit4 = (num / 10) % 10;
    digit5 = num % 10;

    // Basamaklarý þifrelemek için her bir basamaðý 9 ile toplayarak þifreliyoruz. Sonra 10'a bölerek modunu alýyoruz. Böylece þifrelenmiþ basamaklarý elde ediyoruz.
    digit1 = (digit1 + 9) % 10;
    digit2 = (digit2 + 9) % 10;
    digit3 = (digit3 + 9) % 10;
    digit4 = (digit3 + 9) % 10;
    digit5 = (digit5 + 9) % 10;

	//Þifrelemenin ardýndan, þifrelenmiþ basamaklarýn yerlerini deðiþtiriyoruz. Ýlk ve üçüncü basamaklarý yer deðiþtirerek, ikinci ve dördüncü basamaklarý yer deðiþtiriyoruz.

 	int temp = digit1;
 		digit1 = digit3;
 		digit3 = temp;
 	int	temp2 = digit2;
 		digit2 = digit4;
 		digit4 = temp2;

    // Þifreli sayýyý yazdýr
    printf("\nSifrelenmis sayi           : %d%d%d%d%d", digit1, digit2, digit3, digit4, digit5);
}
//Main fonksiyonunda, kullanýcýnýn girdiði 5 basamaklý sayýyý alýyoruz. Do-while döngüsü ile doðru formatta olana kadar
int main() {
    // Deðiþkenleri tanýmla
    int num;
    // en üstk görünüm kýsmýný oluþtur.
		printf("------------------------------------------------------------------------ \n ***************************Sifreleme Programi************************** \n------------------------------------------------------------------------\n \n \n"); 

    // Kullanýcýdan sayý girmesini iste ve doðru formatta olduðunu kontrol et Doðru formatta olana kadar tekrarla.
    do {
		printf("Lutfen 5 basamakli bir sayi giriniz: ");
        scanf("%d", &num);
    } while (num < 10000 || num > 99999);

    // Menüyü göster ve kullanýcýnýn seçimine göre iþlem yap
    char choice;
    do {
        printf("Sayi girisiniz basarili, Girilen sayiyi sifrelemek icin 'P'ye, Cikmak icin 'E'ye basiniz: ");
        scanf(" %c", &choice);
		// switch ile istenilen seçimi yaptýr.
        switch (choice) {
        	// Bu case seçilince Sayýyý þifrelet.
            case 'P':
                encrypt(num);
                break;
                // Bu case seçilince programdan çýkýþ yaptýr.
            case 'E':
                printf("Cikis Yaptiniz...\n");
                exit(0);
           // Yanlýþ Seçim yapýlmasý doðrultusunda programý geçersiz seçim uyarýsý verip kapat.
		    default:
                printf("Gecersiz Secim.");
        }
    } while (0);

    return 0;
}

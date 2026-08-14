#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text =
        get_string("Enter your text: "); //[0] diye ayırıyor tüm karakterleri aslında char da
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

// text inputu al
//  letters toplam kaç karakter var onu hesaplar counter gibi loop a alıp ++ yapıcaz boşluklar ihmal
//  edilecek
// kelime sayısınıda hesapla words boşluk sayısı +1 words olur
// cümle sayısı hesapla noktaları, ünlemleri soru işaretlerini falan saydır.
// coleman liau endeksini hesaplat endekse göre grade yazdır yuvarlama kullan 1 den öncekiler için
// sadece before 1 yazdır index = 0.0588 × L - 0.296 × S - 15.8 L: (Toplam harf sayısı / Toplam
// kelime sayısı) × 100 S: (Toplam cümle sayısı / Toplam kelime sayısı) × 100

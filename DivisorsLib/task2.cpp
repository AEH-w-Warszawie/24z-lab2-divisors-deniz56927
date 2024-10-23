#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>  // Zaman ölçümü için

// Bölenleri bulan fonksiyon (optimizasyonlu)
std::vector<long long> optimizedDivisors(long long n) {
    std::vector<long long> divisors;
    // Sadece sqrt(n)'e kadar iterasyon yapıyoruz
    for (long long i = 1; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);  // i bir bölen
            if (i != n / i) {
                divisors.push_back(n / i);  // n / i de bir bölen (i'ye eşit değilse)
            }
        }
    }
    // Bölenleri sıralı olarak geri döndürmek için sıralıyoruz
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    // Büyük sayılar için test (10^10, 10^15, 10^16, 10^17, 10^18)
    long long numbers[] = { 10000000000LL, 1000000000000000LL, 10000000000000000LL, 100000000000000000LL, 1000000000000000000LL };

    for (long long n : numbers) {
        // Zaman ölçümünü başlatıyoruz
        auto start = std::chrono::high_resolution_clock::now();

        // Bölenleri buluyoruz
        std::vector<long long> divisors = optimizedDivisors(n);

        // Zaman ölçümünü bitiriyoruz
        auto end = std::chrono::high_resolution_clock::now();

        // Çalışma süresini hesaplıyoruz
        std::chrono::duration<double> duration = end - start;

        // Sonuçları ekrana yazdırıyoruz
        std::cout << "Sayı: " << n << ", Bölen Sayısı: " << divisors.size();
        std::cout << ", Süre: " << duration.count() << " saniye" << std::endl;
    }

    return 0;
}

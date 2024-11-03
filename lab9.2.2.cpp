#include <iostream>
#include <fstream>
#include <cctype>  // Для функцій визначення типів символів
#include <string>

// Використовуємо простір імен std
using namespace std;

// Макроси для зручного виводу
#define PRINT_DIGIT(d) cout << "Digit: " << d << endl
#define PRINT_ALPHA(a) cout << "Alphabet: " << a << endl
#define PRINT_PUNCT(p) cout << "Punctuation: " << p << endl
#define PRINT_MISSING(type, count) cout << "Missing " << type << ": " << count << endl

// Функція для читання файлу та класифікації символів
void classifyCharacters(const string& filename, string& digits, string& alphabets, string& punctuations) {
    ifstream file(filename);  // Відкриваємо файл для читання
    if (!file.is_open()) {  // Перевіряємо, чи вдалося відкрити файл
        cerr << "Failed to open file " << filename << endl;  // Виводимо помилку, якщо файл не відкритий
        exit(1);  // Завершуємо програму з кодом помилки
    }

    char ch;  // Змінна для зберігання поточного символу
    while (file.get(ch)) {  // Читаємо файл по символах
        if (isdigit(ch)) {  // Якщо символ - цифра
            digits += ch;  // Додаємо його до рядка цифр
        }
        else if (isalpha(ch)) {  // Якщо символ - буква
            alphabets += ch;  // Додаємо його до рядка букв
        }
        else if (ispunct(ch) && ch != ' ') {  // Якщо символ - пунктуаційний (і не пробіл)
            punctuations += ch;  // Додаємо його до рядка пунктуаційних символів
        }
    }

    file.close();  // Закриваємо файл
}

// Функція для виводу символів за потрібним шаблоном
void printCharacters(const string& digits, const string& alphabets, const string& punctuations) {
    int d_index = 0, a_index = 0, p_index = 0;  // Індекси для цифр, букв та пунктуації
    int d_count = digits.size(), a_count = alphabets.size(), p_count = punctuations.size();  // Кількість символів у кожній категорії

    // Вивід символів за потрібним шаблоном
    while (d_index < d_count || a_index < a_count || p_index < p_count) {
        // 1. Виводимо цифру
        if (d_index < d_count) {
            PRINT_DIGIT(digits[d_index++]);  // Виводимо цифру та збільшуємо індекс
        }

        // 2. Виводимо букву
        if (a_index < a_count) {
            PRINT_ALPHA(alphabets[a_index++]);  // Виводимо букву та збільшуємо індекс
        }

        // 3. Виводимо знак пунктуації
        if (p_index < p_count) {
            PRINT_PUNCT(punctuations[p_index++]);  // Виводимо пунктуаційний символ та збільшуємо індекс
        }

        // 4. Виводимо ще одну цифру
        if (d_index < d_count) {
            PRINT_DIGIT(digits[d_index++]);  // Виводимо цифру та збільшуємо індекс
        }

        // 5. Виводимо ще одну букву
        if (a_index < a_count) {
            PRINT_ALPHA(alphabets[a_index++]);  // Виводимо букву та збільшуємо індекс
        }
    }
}

// Функція для виводу інформації про відсутні символи
void printMissing(int d_index, int d_count, int a_index, int a_count, int p_index, int p_count) {
    if (d_index >= d_count) {
        PRINT_MISSING("digits", 0);  // Виводимо повідомлення про відсутні цифри
    }
    if (a_index >= a_count) {
        PRINT_MISSING("alphabets", 0);  // Виводимо повідомлення про відсутні букви
    }
    if (p_index >= p_count) {
        PRINT_MISSING("punctuation marks", 0);  // Виводимо повідомлення про відсутні пунктуаційні знаки
    }
}

int main() {
    string filename;  // Змінна для зберігання назви файлу
    cout << "Enter file name: ";  // Запитуємо у користувача назву файлу
    cin >> filename;  // Зчитуємо назву файлу

    string digits, alphabets, punctuations;  // Змінні для зберігання символів різних типів

    // Класифікація символів з файлу
    classifyCharacters(filename, digits, alphabets, punctuations);

    // Вивід символів за потрібним шаблоном
    printCharacters(digits, alphabets, punctuations);

    // Вивід інформації про відсутні символи
    printMissing(digits.size(), digits.size(), alphabets.size(), alphabets.size(), punctuations.size(), punctuations.size());

    return 0;  // Завершуємо програму успішно
}

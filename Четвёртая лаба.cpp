#include <iomanip>
#include <iostream>
#include <math.h>
/*1 Вариант*/
/*Задан массив из k символов. Преобразовать массив следующим образом:
сначала должны стоять цифры, входящие в массив, а затем все остальные символы.
Взаимное расположение символов в каждой группе не должно изменяться. */
int main()
{
    int i, k = 8, f;
    char mass[8], mass2[8];

    for (i = 0; i < k; i++) {
        std::cout << "Input array elements: " << std::endl; std::cin >> mass[i];            //Ввод
        mass2[i] = 1;
    }

    for (i = 0; i < k; i++) {                                                               //Если не число, то записываю в другой массив на ту же позицию                                             
        if (!isdigit(mass[i])) {
            mass2[i] = mass[i];

        }
    }
            
    for (i = 0; i < k; i++) {                                                               //Если i-й элемент не число, то перемещаю весь массив влево, дабы убрать этот символ
            if (!isdigit(mass[i])) {
                for (int j = i + 1; j < k; j++) {
                    mass[j - 1] = mass[j];
                }                                                                           //Перемещаюсь назад на 1 элеент, чтобы проверить новый элемент, что стал на i-ю позицию и обрезаю конец,
                i--; k--;                                                                   //т.к. последний и предпоследний теперь оинаковы
            }
        }

        f = k;                                                                              //Присваиваю f позицию, следующую за последним числом
        k = 8;                                                                              //Восстанавливаю размер массива

    for (i = 0; i < k; i++) {                                                               
        if (!isdigit(mass2[i])) {                                                           //Ищу символы во втором массиве, которые находятся на тех же местах, что и в исхожном массиве
                mass[f] = mass2[i];                                                         //Записываю в позицию f символ, находящийся на позиции изначального массива
                f++;                                                                        //Для записи следующего символа увеличиваю f на единицу
        }
    }
        std::cout << "New array is: " << std::endl;                                         //Вывод
    for (i = 0; i < k; i++) {
        std::cout << "  " << mass[i];
    }
    
    system("pause");
    return 0;
}
/*2 Вариант*/
/*Задан массив из k символов. Преобразовать массив следующим образом:
расположить символы в обратном порядке. */
int main() {

    char arr[10], a; int n = 10, k;

    for (int i = 0; i < n; i++) {                                                   //Ввод
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;;
    }

    k = n - 1;
    for (int i = 0; i < n; i++) {                                                   //Перемещаю элементы
        for (int j = 0; j < k; j++) {
            a = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = a;
        }
        k--;                                                                        //Отнимаю от счётчика единицу, чтобы следующий элемент на следующую позицию с конца
    }

    std::cout << "New array is: " << std::endl;                                     //Вывод
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    system("pause");
    return 0;
}
/*3 Вариант*/
/*Задан массив из k чисел. Найти число, наиболее часто встречающееся в
этом массиве. */
int main()
{
    int arr[25], k = 1, n = 25, m = 1, number;

    for (int i = 0; i < n; i++) {                                                           //Ввод
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;
    }

    for (int j = 1; j < n; j++) {                                                           //Смотрю сколько раз встречается первый элемент и записываю это число в переменную k
        if (arr[0] == arr[j]) {
            k++;
        }
        number = arr[0];                                                                    //Принимаю первый элемент за эталон
    }

    for (int i = 1; i < n; i++) {                                                           //Прогоняю каждый элемент массива сравнивая с остальными элементами в поисках таких же
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {                                                         //Записываю в переменную m число повторение данного элемента
                m++;
            }
        }
        if (m > k) {                                                                        //Если число повторение данного элемента больше, чем то число повторений, что записано в k,
            k = m;                                                                          //то записываю в k новое число повторение, а в number - новое значение
            number = arr[i];
        } 
        m = 1;                                                                              //"Обнуляю" m для следующих итераций
    }

    std::cout << "Number " << number << " occurs most often, namely " << k <<               //Вывод
    " times." << std::endl;

    system("pause");
    return 0;
}
/*4 Вариант*/
/*Задан массив из k чисел. Отсортировать элементы массива по возрастанию. */
/*int main() {

    int arr[10], n=10, a;

    for (int i = 0; i < n; i++) {                                                               //Ввод
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;;
    }

    for (int i = 0; i < n; i++) {                                                               //Сортировка пузырьком
        for (int j = 0; j < n-1; j++) {
            if (arr[j] > arr[j + 1]) {
                a = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = a;
            }
        }
    }

    std::cout << "New array is: " << std::endl;                                                 //Вывод
    for (int i = 0; i < n; i++) {
        std::cout << arr[i]<<std::endl;
    }

    system("pause");
    return 0;
}*/
/*5 Вариант курильщика*/ 
/*Задан массив из k чисел. Найти числа, входящие в массив только один раз.*/
/*int main() {

    int arr[10], n = 10, u = 0, a;

    for (int i = 0; i < n; i++) {
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {                                                           //Если нахожу такой же элемент, то перемещаю этот самый ТАКОЙ же (не исходный) в конец
                for (int z = j + 1; z < n; z++) {
                    a = arr[z];
                    arr[z] = arr[z - 1];
                    arr[z - 1] = a;
                }
                n--; u++;                                                                     //Обрезаю конец и добавлю единицу к счётчику для следующего if
            }
        }
        if (u > 0) {                                                                          //Если прошлый if сработал хотя бы раз, то счётчик больше нуля,
            for (int x = i; x < n; x++) {                                                     //тогда перемещаю исходный элемент в конец (который уже обрезан) и обрезаю этот конец
                a = arr[x+1];
                arr[x] = arr[x + 1];
                arr[x] = a;
            }
            u = 0; i--; n--;                                                                  //Обнуляю счётчик u, перемещаюсь на элемент назад, чтобы проверить эту же позицию снова
        }                                                                                     //(т.к. там уже находится следующий по отношению к предыдущей итерации)
    }

    std::cout << "New array is: " << std::endl << std::endl;                                  //Вывод массива элементов, которые не повторяются
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    std::cout << std::endl;                                                                   //Вывод ответа
    std::cout << "The source array has  " << n << " non-repeating elements" <<
    std::endl << std::endl;

    system("pause");
    return 0;
}*/
/*5 Вариант обычного человека*/
/* // */
/*int main() {

    int arr[10], n = 10, u = 0, k = 0;

    for (int i = 0; i < n; i++) {                                                           //Ввод
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;
    }

    std::cout << "New array is: " << std::endl << std::endl;

    for (int i = 0; i < n; i++) {                                                           //Сравниваю каждый элемент с каждым, включая себя и увеличиваю счётчик в случае нахождения одинаковых
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                u++;
            }
        }
        if (u == 1) {                                                                       //Если таких же элементов не найдено, то увеличиваю счётчик неповторяющихся элементов и вывожу сам элемент
            k++;
            std::cout << arr[i] << "  ";
        }
        u = 0;
    }
    std::cout << std::endl << std::endl;                                                    //Вывод количества неповторяющихся элементов
    std::cout << "The source array has " << k << " non-repeating elements" <<       
    std::endl << std::endl;

    system("pause");
    return 0;
}*/
/*6 вариант*/
/*Задан массив из k чисел. Сдвинуть элементы массива циклически на n
позиций влево. */
/*int main() {

    int arr[10], k = 10, n, a;

    for (int i = 0; i < k; i++) {                                                               //Ввод
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;
    }

   std::cout << "Input n (1 -- 10) " << std::endl; std::cin >> n;                               //Ввод числа, на которое необходимо сместитить каждый элемент

    for (int i = 0; i < k-n; i++) {                                                             //Перемещаю последний элемент в начало и повторяю k-n раз. Другимм словом - сортирую
            for (int j = k - 1; j >= 1; j--) {
                a = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = a;
            }
        }

    std::cout << "New array is: " << std::endl << std::endl;                                   //Вывод

    for (int i = 0; i < k; i++) {
        std::cout << arr[i] << std::endl;
    }

    system("pause");
    return 0;
}*/
/*7 Вариант*/
/*Задан массив из k чисел. Сдвинуть элементы массива циклически на n
позиций вправо. */
/*int main() {

    int arr[10], k = 10, n, a;

    for (int i = 0; i < k; i++) {                                                               //Ввод
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;
    }

    std::cout << "Input n (1 -- 10) " << std::endl; std::cin >> n;                              //Ввод числа, на которое необходимо сместитить каждый элемент

    for (int i = 0; i < k - n; i++) {                                                           //Перемещаю последний элемент в начало и повторяю k-n раз. Другимм словом - сортирую
        for (int j = 1; j < k; j++) {
            a = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = a;
        }
    }

    std::cout << "New array is: " << std::endl << std::endl;                                    //Вывод

    for (int i = 0; i < k; i++) {
        std::cout << arr[i] << std::endl;
    }

    system("pause");
    return 0;
}*/
/*8 Вариант*/ 
/*Задан массив из k чисел. Преобразовать массив следующим образом:
все отрицательные элементы массива перенести в начало, а все остальные – в конец,
сохранив исходное взаимное расположение как среди отрицательных,
так и среди положительных элементов. */
/*int main() {

    int arr[10], n = 10, a, k = 0;

    for (int i = 0; i < n; i++) {                                                   //Ввод
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {                                                   //Нахожу количество отрицательных элементов в массиве,
        if (arr[i] < 0) {                                                           //чтобы узнать сколько итераций необходимо для сортировки
            k++;
        }
    }

    for (int i = 0; i < k; i++) {                                                   //Чтобы не сбить взаимное расположение чисел провожу ровно столько итераций,
        for (int j = n - 1; j >= 1; j--) {                                          //сколько отрицательных элементов в исходном массиве, т.е. k
            if (arr[j] < 0) {
                a = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = a;
            }
        }
    }

    std::cout << "New array is: " << std::endl << std::endl;                       //Вывод

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    system("pause");
    return 0;
}*/
/*9 Вариант*/
/*Задан массив из k символов. Создать два новых массива:
в первый перенести все цифры из исходного массива, во второй – все остальные символы*/
/*int main() {

    char arr[10], arr_numb[10], arr_other[10]; int n = 10, a, u = 0, k = 0;

    for (int i = 0; i < n; i++) {                                                           //Ввод массива
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> arr[i];
        std::cout << std::endl;
        arr_numb[i] = 0;
        arr_other[i] = 'a';
    }

    for (int i = 0; i < n; i++) {
        if (isdigit(arr[i])) {
            for (int j = k; j < k + 1; j++) {                                               //Если число, то записываю в массив чисел и увеличиваю счётчик,
                arr_numb[j] = arr[i];                                                       //который будет ограничением при выводе
            }
            k++;
        }
        else {
            for (int j = u; j < u + 1; j++) {                                               //Если не число, то записываю в массив остальных символов и увеличиваю счётчик,
                arr_other[j] = arr[i];                                                      //который будет ограничением при выводе
            }
            u++;
        }
    }

    std::cout << "Array of numbers: " << std::endl;                            //Вывод чисел
    for (int i = 0; i < k; i++) {
        std::cout << arr_numb[i] << "  ";
    }

    std::cout << std::endl << std::endl;
    std::cout << "Array of other symbols: " << std::endl;                   //Вывод остальных символов
    for (int i = 0; i < u; i++) {
        std::cout << arr_other[i] << "  ";
    }
    std::cout << std::endl << std::endl;

    system("pause");
    return 0;
}*/
/*10 Вариант*/
/*Задан массив из k символов. Определить, симметричен ли он,
т. е. читается ли он одинаково слева направо и справа налево. */
/*int main() {

    int arr[10], n = 10, k = 0;

    for (int i = 0; i < n; i++) {                                                   //Ввод
        std::cout << "Input " << i + 1 << " element of array: " << std::endl;
        std::cin >> arr[i];
    }

    for (int i = 0; i < (n / 2); i++) {                                             //Сравниваю симметричные элементы
        if (arr[i] != arr[n - i - 1]) {                                             //Если находится хотя бы один не равный, то прерываю фор и прибавляю единицу к счётчику
            k++; break;
        }
    }
    
    if (k != 0) {                                                                   //Если счётчик не равен нулю, т.е. прошлый цикл прервался, то цикл не симметричен
        std::cout << "This Array ISN'T symmetrical " << std::endl;
    }
    else
        std::cout << "This array IS symmetrical " << std::endl;                     //В противном случае - симметричен

    system("pause");
    return 0;
}*/
/*11 Вариант*/
/*Задано два массива. Найти наименьший среди элементов первого массива, который не входит во второй массив.*/
/*int main() {

    int arr[10], arr2[10], n = 10, a; bool k = false;

    for (int i = 0; i < n; i++) {                                                                   //Ввод первого массива
        std::cout << "Input " << i + 1 << " element of the first array" << std::endl;
        std::cin >> arr[i];
    }

    std::cout << std::endl << std::endl;

    for (int i = 0; i < n; i++) {                                                                   //Ввод второго массива
        std::cout << "Input " << i + 1 << " element of the second array" << std::endl;
        std::cin >> arr2[i];
    }

    for (int i = 0; i < n; i++) {                                                                   //Сортировка первого массива по возрастанию пузырьком
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                a = arr[j];
                arr[j] = arr[i];
                arr[i] = a;
            }
        }
    }
    
    std::cout << std::endl << std::endl;

    for (int i = 0; i < n; i++) {                                                                   //Сравниваю по очереди элементы первого (отсортированного) массива с каждым элементом второго,
        for (int j = 0; j < n; j++) {                                                               //если нахожу такой же, то беру следующий элемент первого массива и повторяю до тех пор,
            if (arr[i] != arr2[j]) {                                                                //пока не найётся эелемент, которого нет во втором массиве. Если такой элемент находится - 
                k = true;                                                                           //выхожу из циклов и вывожу этот элемент
            }else
                if (arr[i] == arr2[j]) {
                    k = false; break;
                }
        }
        if (k == true) {
            std::cout << "The smallest element of the first array that does not occur in the second is " << arr[i] 
            << std::endl << std::endl;
            break;
        }
    }

    if (k == false) {
        std::cout << "The second array contains all the same elements as the first " << std::endl << std::endl;
    }

    system("pause");
    return 0;
}*/
/*12 Вариант*/
/*Задан массив из k чисел. Определить количество инверсий в массиве,
т. е. таких пар элементов, в которых большее число находится слева от меньшего.*/
/*int main() {

    int arr[10], n = 10, k = 0;
    
    for (int i = 0; i < n; i++) {                                                           //Ввод
        std::cout << "Input " << i + 1 << " element of the array: ";
        std::cin >> arr[i];
    }
    //Первый вариант понимая это задания
    for (int i = 1; i < n; i += 2) {                                                      //Сравниваю пары 1-2, 3-4 и т.д.
        if (arr[i] < arr[i - 1]) {
            k++;
        }                                                                                 //НЕНУЖНЫЙ ВАРИАНТ ЗАКОММЕНТИТЬ
    }
    //Второй вариант понимания этого задания
    for (int i = 1; i < n; i++) {                                                         //Сравниваю первый-второй, второй-третий и т.д.
        if (arr[i-1] > arr[i]) {
            k++;
        }
    }

    std::cout << "There are " << k << " inevrsions in this array." << std::endl;            //Вывод             

    system("pause");
    return 0;
}*/
/*13 Вариант*/
/*Задан массив из k символов. Удалить из него повторные вхождения каждого символа. */
/*int main() {

    int arr[10], n = 10, a;

    for (int i = 0; i < n; i++) {                                                                           //Ввод
        std::cout << "Input " << i + 1 << " element oft the array: ";
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {                                                                           //Проверяю каждый элемент на повтор
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {                                                                         //Если встречаю, то перемещаю его в конец и обрезаю конец
                for (int z = j+1; z < n; z++) {
                    a = arr[z];
                    arr[z] = arr[z - 1];
                    arr[z - 1] = a;
                }
                n--;
            }
        }
    }
    std::cout << "New array is: " << std::endl;
        for (int i = 0; i < n; i++) {                                                                       //Вывод элементов до n (все повторы собраны в конце и не выводятся)
            std::cout << arr[i] << "  ";
        }
        
        std::cout << std::endl;

    system("pause");
    return 0;
}*/
/*14 Вариант*/
/*Задан массив из k символов. Определить количество различных элементов в массиве.*/
/*int main()
{

    char arr[7]; int n = 7, a = 7;

    for (int i = 0; i < n; i++) {
        std::cout << "Input " << i + 1 << " element of array" << std::endl;
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                a--;
                break;
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Array is: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl<<std::endl;
    std::cout << "This aray has " << a << " different elements."<<std::endl<<std::endl;
    system("pause");
    return 0;
}*/
/*15 Вариант*/
/*Задан массив из k символов латинского алфавита. Вывести на экран в
алфавитном порядке все символы, которые входят в этот массив по одному разу. */
/*int main() {
    
    char arr[10]; int n = 10, a, k;

    for (int i = 0; i < n; i++) {                                                               //Ввод
        std::cout << "Input " << i + 1 << " element of the array: ";
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {                                                               //Сортировка по алфавиту пузырьком
        for (int j = i + 1; j < n; j++) {
            if ((int)arr[i] > (int)arr[j]) {
                a = arr[j];
                arr[j] = arr[i];
                arr[i] = a;
            }
        }
    }

    for (int i = 0; i < n; i+= k) {                                                             
            
        k = 1;                                                                                   

        for (int j = i + 1; j < n; j++) {                                                        //Если встречается такой же элемен ткак текущий, то добавляю единицу к счётчику,
            if (arr[i] == arr[j]) {                                                              //который укажет сколько элементов пропустить, поскольку они повторяются
                k++;
            }
        }
        if (k == 1) {                                                                            //Если одинаковых элементов с текущим не было, то вывожу его на экран
            std::cout << arr[i] << std::endl;
        }
    }

    system("pause");
    return 0;
}*/
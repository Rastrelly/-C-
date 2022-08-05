﻿//ЗАГАЛЬНИЙ ПРИКЛАД ЩОДО ОСНОВНИХ СИНТАКСИЧНИХ
//КОНСТРУКЦІЙ C++

//оголошення файлів-включень
#include <iostream> //iostream умовно відповідає за операції взаємодії з консоллю
#include <string>   //string відповідає за розширені операції з рядками
#include <clocale>  //clocale дозволяє керувати локалізацією додатку 

//оголошення автоматично використаного простору імен
using namespace std; //std включає в себе більшість основних (стандартних) типів даних та функцій

//оголошення глобаліних змінних, які доступні всім функціям у межах цього модуля
int i_a = 0; //цілочислення змінна, ініціалізована як 0
float f_b;   //неініціалізована змінна - число з плаваючою точкою
string str_text = ""; //змінна, що містить рядок. ініціалізується як пустий рядок

//цей рядок - попередня декларація функції calculate. його наявність дозволяє
//забезпечити доступність цієї функції для кожної іншої функції в межах
//цього модуля.
float Calculate(float a, float b);
void PrintCalcResult(float r_a, float r_b, float r_c);

//функція main() вважається умовною точкою входу до програми
int main()
{
	//додаємо підтримку кирилічних символів
	setlocale(LC_CTYPE, "ukr"); //зверніть увагу: за замовчуванням консоль Windows
	//не здатна вивоодити українські літери і та ґ, навідь при коректно вказаній
	//локалі, без використання специфічних маніпуляцій зі способами передачі даних
	//або писати системозалежне рішення, яке буде розглянуто в розділі про
	//директиви компілятору

	//cout це метод виводу даних до консолі або до будь-якого потоку даних
	cout << "1. Операцiї зі змiнними" << endl;
	//прості математичні операції
	float a = 10; //присвоювання значення змінній
	//зверніть увагу, що змінна a була об'явлена в межах даної функції.
	//доступ до неї існує В МЕЖАХ ДАНОЇ ФУНКЦІЇ і тільки ПІСЛЯ її об'явлення
	float b = 5;
	float c = a + b; //змінна c ініціалізується результатом складання значень, що зберігаються
	//у змінних a та b

	//результат розрахунку можна вивести до консолі, наприклад, наступною конструкцією:
	cout << a << " + " << b << " = " << c << endl;
	//текст рядку, наприклад текстові позначки + та =, ьеруться у подвійні рядки якщо знаків більше за 1, 
	//або у одинарні, якщо передається один символ (string та char). різнотипні дані розіляються
	//оператором бітового зсуву <<

	//для вводу даних можна використовувати команду cin
	cout << "Введiть a:" << endl;
	cin >> a;
	cout << "Введiть b:" << endl;
	cin >> b;

	//код можна істотно спростити і зробити структурно більш простим, якщо використовувати підпрограми, або функції
	c = Calculate(a, b); //обчислюємо a+b
	PrintCalcResult(a,b,c); //виводимо результат обчислення

	cout << "2. Операцiї розгалуження" << endl;
	//розгалуження дозволяє виконувати ті чи інші фрагменти коду
	//в залежності від виконання чи невиконання певних умов. Наприклад:
	cout << "Введiть a:" << endl;
	cin >> a;
	cout << "2.1. Просте розгалуження" << endl;
	if (a > 10) //це умова розгалуження
	{
		//цей блок буде виконано, якщо умова розгалуження виконується
		cout << "Визначено, що а бiльша за 10" << endl;
	}
	else
	{
		//цей блок буде виконано, якщо умова розгалуження не виконується
		cout << "Визначено, що а менша за 10 чи дорiвнює 10" << endl;
	}
	
	cout << "2.2. Розгалуження else if" << endl;
	//розгалуження з if може бути ступінчастим, з проміжною перевіркою. такий
	//варіант називається else if
	if (a > 10) //це умова розгалуження
	{
		//цей блок буде виконано, якщо умова розгалуження виконується
		cout << "Визначено, що а бiльша за 10" << endl;
	}
	else if (a==10)
	{
		//цей блок буде виконано, якщо умова розгалуження не виконується,
		//але виконується проміжна умова
		cout << "Визначено, що а дорiвнює 10" << endl;
	}
	else
	{
		//цей блок буде виконано, якщо умова розгалуження не виконується
		//та проміжна умова ТЕЖ не виконується
		cout << "Визначено, що а менша за 10" << endl;
	}
	cout << "2.3. Перемикач" << endl;
	//окремим видом розгалуження э перемикач (switch), який краще всього використовувати,
	//якщо необхідно зробити вибір з переліку варіантів. Значення що подається на перемикач має
	//бути цілим або рядком

	int ans = 0;
	cout << "Введiть a:" << endl;
	cin >> ans;

	switch (ans)
	{
	case 0: //case та значення перевірки
		cout << "Обрано 0" << endl; //після цього йде послідовність операцій, яку належить виконати
		break; //ключове слово breakперериває виконання оператору. якщо його не викликати, 
		//буде виконано ВСІ ВАРІАНТИ ПІСЛЯ ТОГО, ЩО СПРАЦЮВАВ (що іноді є корисним і дозволяє групувати однотипні варианти,
		//як у прикладі нижче)
	case 1:
	case 10:
		cout << "Обрано 1 або 10" << endl;
		break;
	case 2:
		cout << "Обрано 2" << endl;
		break;
	case 3:
		cout << "Обрано 3" << endl;
		break;
	case 4:
		cout << "Обрано 4" << endl;
		break;
	default: //варіант daefult не є обов'язковим і спрацює
		//якщо жоден з інших варіантів не спрацював
		cout << "Введено значення, що не пiдтримується" << endl;
		break;
	}

	cout << "3. Цикли" << endl;
	//Цикли дозволяють виконувати операції чи блоки операцій багаторазово
	//Це дозволяє або повторювати певні дії дуже часто (як відмальовку),
	//або повторювати операції з великим відкладенням (наприклад, повторний
	//збір даних при перерахунках)

	//Цикли бувають наступних видів:
	//*Цикл з лічильником* чітко виконує задану кількість операцій
	cout << "3.1. Цикл з лiчильником" << endl;
	float c_a = 27;
	for (int i = 0 /*i - лічильник, 0 - стартове значення*/; i < 10/*кінець циклу - i=9*/; i++/*прирощення циклу на 1*/)
	{
		cout << i << ")" << c_a + i << endl;
	}

	//*Цикл з передумовою* виконується до тих пір, поки його не буде перервано при невиконанні умови
	cout << "3.2. Цикл з передумовою" << endl;
	int t = 0;
	while (t != 1)
	{
		cout << "Введiть 1 щоб вийти з циклу" << endl;
		cin >> t;
	}

	//*Цикл з постумовою* виконується так саме поки виконується умова, але перевірка умови виконується
	//після завершення ітерації циклу, таким чином цикл з постумовою
	//завжди виконається принаймні один раз
	cout << "3.3. Цикл з постумовою" << endl;
	int k = 0;
	do
	{
		k += 1; //збільшуємо k на 1
		cout << "k = "<< k << endl;
	} while (k < 20);

	system("pause"); //призводить примусове припинення виконання програми без її завершення, що можна використовувати
	//щоб призупиняти виконання у ключові моменти

	return 0; //закінчує виконання функції main() і, тим самим, вісєї програми

}

//часто попередньо задекларовані функції реалізують після функції main()
float Calculate(float in_a, float in_b)
{
	//функція виконується до виявлення ключового слова
	//return. якщо це слово зустрічається в межах виконання коду, 
	//виконання функції переривається та функція повертає значення,
	//наведене поряд з цим клчовим словом.
	return in_a + in_b;
}

void PrintCalcResult(float r_a, float r_b, float r_c)
{
	cout << "Виведення тексту функцiєю: " << r_a << " + " << r_b << " = " << r_c << endl;
}
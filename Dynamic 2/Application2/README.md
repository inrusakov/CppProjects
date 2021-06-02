

Задача о рюкзаке

Есть рюкзак, который может поднять максимально возможный вес W. Задан также набор предметов, каждый предмет имеет два параметра - вес P и стоимость C. Необходимо найти набор предметов максимальной стоимости, вес набора предметов не больше W. Необходимо решить задачу, используя динамическое программирование.

Все входные и выходные данные целочисленные и неотрицательные. Гарантируется, что они входят в тип int (4 байта) без переполнения.

Ссылка на исходный код https://yadi.sk/d/-_xIGqviUa2gsA
Формат ввода

Во входном файле 4 строки:

В первой строке целое число N - количество доступных предметов. 1 <= N <= 1000

Во второй строке целое число W - максимальный вес, который выдерживает рюкзак. 0 <= W <= 50000

В третьей строке N целых чисел - веса доступных предметов P. 1 <= P <= 2000 Могут встречаться предметы одинакового веса.

В четвертой строке N целых чисел - стоимости доступных предметов С. 1 <= С <= 2000

Могут встречаться предметы одинаковой стоимости. Внимание(!) Набор предметов никак не упорядочен.
Формат вывода

В выходной файл надо записать 5 строк:

В первой строке число A - это суммарная стоимость всех предметов, вошедших в решение. Предполагаемые ограничения: 0 <= A <= 2000000 ( 2 млн., из расчета 1000 предметов по 2000 стоимости каждый).

Во второй строке число B - суммарный вес всех предметов, вошедших в решение. Предполагаемые ограничения: 0 <= В <= W

В третьей строке число M - количество предметов, вошедших в решение. Предполагаемые ограничения: 0 <= M <= 1000

В четвертой строке M чисел - веса взятых предметов.

В пятой строке M чисел - стоимости взятых предметов.

Все комбинации веса и стоимости должны быть из входных данных. Можно выводить их в ответ в любом порядке (но не нарушая комбинаций вес-стоимость).
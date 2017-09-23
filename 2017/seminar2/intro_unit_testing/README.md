1. Контракты функций (precondition / postcondition)
  * контракты на примере double std::sqrt(double x)
    * ограничения на x
    * что функция должна возвращать
  * контракты на примере int binary_search(int a[], int n, int value);
    * какое ограничение на a (валидный указатель на память, доступную для чтения, хранятся int)
    * какое ограничение на n (>=0)
    * какое ограничение на value (any)
    * что функция должна возвращать
  * контракты на примере std::string get_weather_from_yandex_server(int day);
    * какое ограничение на day
	* какое ограничение на возращаемое значение
2. Что нужно тестировать
  * КОНТРАКТЫ!!!!!!!!11111адинадин
    * positive scenario
      * including boundary cases
    * negative scenario
3. Примеры на тесты:
  * std::sqrt
    * ps: any positive
	* bs: 0
  * binary_search:
    * ps: a - 5 элементов, ищем элемент из списка
	* ps: a - 5 элементов, ищем элемент НЕ из списка
	* bs: искомый элемент - первый
	* bs: искомый элемент - последний
	* bs: искомый элемент - последний
	* bs: a - пуст (n == 0)
  * std::string get_weather_from_yandex_server(int day);
    * ps: среда
	* bs: понедельник / воскресенье
	* ns: нет сети / сервер под DDOS-ом и не отвечает -  заикнуться про mock-и
4. Как нужно тестировать
  * arrange - act - assert
  * one assert per test (cause one scenario per test)
  * keep things as simple as you can
  * test name
  * test must be quick!
5. adding unit tests:
  * if you see error, do not cry, just wait for me to ask
  * cd tests
  * `git submodule add https://github.com/google/googletest.git gtest`
  * `git submodule update --init --recursive`
  * make specific error in tests
  * point out specific of i, count, 1

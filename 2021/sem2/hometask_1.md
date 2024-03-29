Реализовать решение [задачи коммивояжёра](https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BA%D0%BE%D0%BC%D0%BC%D0%B8%D0%B2%D0%BE%D1%8F%D0%B6%D1%91%D1%80%D0%B0) для полного графа [методом ветвей и границ](https://ru.wikipedia.org/wiki/%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B2%D0%B5%D1%82%D0%B2%D0%B5%D0%B9_%D0%B8_%D0%B3%D1%80%D0%B0%D0%BD%D0%B8%D1%86)

Идея метода ветвей и границ предполагает, что вы решаете задачу полным перебором, запоминая стоимость текущего минимального пути, и отсекаете ветви перебора, если они гарантировано не дадут лучшего решения.

* в качестве заготовки воспользуйтесь [материалами из репозитория курса](https://github.com/ivafanas/cpp_shad_students/tree/master/2021/sem2/lab1_stub)
* нужно иметь следующий UI:
  * поле ввода для числа городов (размерности задачи)
  * поле ввода для числа потоков
      * при чтении пользовательского ввода ограничьте число потоков в разумных пределах (например, от 1 до 24)
  * кнопка `start` для запуска решения
      * `start` на запущенной задаче должен её останавливать и запускать новую
      * (*) нажатие на `start` не должно заморозить UI
  * кнопка `stop` для прекращения вычислений
      * остановка вычислений без возможности продолжить
      * (*) нажатие на `stop` не должно заморозить UI
  * кнопка `dump` для вывода результата и входных данных последней посчитанной задачи в файл
      * если последняя задача не посчитана или в процессе расчёта, то выдать message box о незавершённой задаче

  * поле общего статуса задачи: `Idle` / `Running` / `Run completed. Execution time: {seconds} sec. Min weight = {weight}`
  * для каждого потока в процессе выполнения задачи периодически выводить статус в UI:
      * стоимость текущего решения
      * примерный процент выполненной работы
* веса - целые числа - время пути между городами в часах - задавайте случайно
* если поток-решатель находит меньшее по стоимости решение, то остальные потоки-
  решатели должны узнавать, что появился новый глобальный минимум, и отсекать
  свои ветви перебора по новому глобальному минимуму
* подготовьте отчёт:
  * сколько физических ядер на машинке, на которой вы тестировали (например, T)
  * нарисовать график зависимости времени решения от размера задачи для 1 потока и для T потоков
  * определить, начиная с какого размера задачи имеет смысл использовать многопоточное решение
  * выбрать достаточно большой размер задачи и вычислить эффективность
    распараллеливания для 1, 2 ... T-1, T, T+1, ... 2T потоков
  * сколько часов вы потратили на решение задачи
  * поскольку входные данные случайны, а от удачности нахождения глобального минимума зависит время расчёта всей задачи, для получения достоверных цифр по времени работы задайте стоимость перемещения между городами константой, например, 1.
  * не забудьте, что в отчёте кроме чисел должны быть выводы: что происходит, почему это происходит. Ожидается, что если у вас получится интересный результат, вы попытаетесь его объяснить и предложить текстом варианты исправления / ускорения.
* идея написания отчёта должна подтолкнуть вас к идее организации кода таким образом, чтобы отделить работу с UI (тексты, события, команды) от модели расчётов
* тесты для задания писать не нужно
* отчёт должен быть готов до первого дедлайна
* примитивы синхронизаций / потоки должны быть стандартными, не qt-выми

Вывод по кнопке dump организовать в формате:

```
{min_path_weigth}
{N=num_cities}
{a_11} {a_12} ... {a_1N}
{a_21} {a_22} ... {a_2N}
...
{a_N1} {a_N2} ... {a_NN}
```

где

* `min_path_weight` - вес наименьшего пути
* `N` - число городов (вершин графа)
* `a_ij` - вес пути из города `i` в город `j`

Распечатка задачи в файл нужна для проверки вашего решения на корректность.

Пример:

```
1
2
0 1
3 0
```



# Основы программирования. Лабораторная работа №3
[![Build Status](https://travis-ci.org/z8432k/feodorov-base-coding-lab3-29.svg?branch=master)](https://travis-ci.org/z8432k/feodorov-base-coding-lab3-29)

## Программирование поразрядных операций

### Вариант 29

![task](assets/task.png)

Сборка проекта:

```bash
make
```

В каталоге **bin** будут размещены две программы:

* pack - упаковщик даннх
* unpack - распаковщик данных

### Упаковка данных

```text
$ ./bin/pack
Pack.

Input task ident:31
Input activity flag:1
Input segment lengths:254

Task identifier :31
Activity flag :1
Segment length :254

Encoded data HEX :fafe
Encoded data BIN :1111101011111110

```

### Распаковка данных

```text
./bin/unpack
Unpack.

Input encoded data:fafe
Encoded data HEX :fafe
Encoded data BIN :1111101011111110

Task identifier :31
Activity flag :1
Segment length :254

```

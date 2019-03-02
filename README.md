# Основы программирования. Лабораторная работа №3

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
$ ./bin/pack 27 1 255
Pack.

Task ident      :27
Activity flag   :1
Segment length  :255

Encoded data    :DAFF
```

### Распаковка данных

```text
./bin/unpack DAFF
Unpack.

Encoded data    :DAFF

Task ident      :27
Activity flag   :1
Segment length  :255
```

# cpp_homework_2

## Назначение проекта
Для варианта 3 было разработано приложение, используя паттерн Model/View.
Основное окно программы состоит из дерева, содержащего список объектов, разбитый
на категории. По двойному нажатию на на объект открывается диалоговое окно для
редактирования информации об объекте. Реализована возможность загрузки
информации о композициях из xml-файла и сохранение информации об объектах в xml
файл.

## Описание файлов
* screenshoots (скриншоты для ридми)
---
Файлы-заголовки
* domitem.h
* dommodel.h
* win2.h
* mainwindow.h
---
Файлы-реализации
* domitem.cpp
* dommodel.cpp
* win2.cpp
* mainwindow.cpp
* main.cpp
---
Интерфейсы
* win2.ui
* mainwondow.ui

---
Структура
* buts_2.pro
---
Входной файл
* music.xml


## Структура базового xml-файла

```xml
<?xml version='1.0' encoding='UTF-8' standalone='yes'?>
<genres name="Жанры">
    <genre name="Pop"/>
    <genre name="Rock">
        <group name="Beatles">
            <album label="Capitol Records" desc="Rubber Soul — шестой студийный альбом группы The Beatles, выпущенный 3 декабря 1965 года" date="1965-12-06" group_name="The Beatles" name="Rubber soul" minut="35" second="50" studio="Martin"/>
            <album label="Capitol Records" desc="Revolver (с англ. — «Револьвер») — седьмой студийный альбом рок-группы The Beatles, выпущенный 5 августа 1966 года" date="1966-08-5" group_name="The Beatles 22" name="Revolver" minut="34" second="40" studio="Martin"/>
            <album label="Capitol Records" desc="Magical Mystery Tour (с англ. — «Волшебное таинственное путешествие») — девятый студийный альбом группы The Beatles" date="1967-04-25" group_name="The Beatles" name="Magical Mystery Tour" minut="36" second="53" studio="Martin"/>
        </group>
    </genre>
    <genre name="Country"/>
</genres>
</genres>
```

## Описание работы
* При запуске программы открывается первичное окно для отображения загруженного файла.
![GitHub Logo](/screenshots/Screenshot%20from%202021-06-16%2018-38-59.png)
* Выбираем входной xml-файл
![GitHub Logo](screenshots/Screenshot%20from%202021-06-16%2018-39-53.png)
* Получаем выгрузку данных в ui
![GitHub Logo](screenshots/Screenshot%20from%202021-06-16%2018-40-22.png)
* Выбираем элемент данных в интерфейсе
![GitHub Logo](screenshots/Screenshot%20from%202021-06-16%2018-41-19.png)
* Меняем название композиции

![GitHub Logo](screenshots/Screenshot%20from%202021-06-16%2018-41-50.png)
* Название композиции поменялось и в интерфейсе

![GitHub Logo](screenshots/Screenshot%20from%202021-06-16%2018-42-12.png)
* Название композиции поменялось в xml-файле
![GitHub Logo](screenshots/Screenshot%20from%202021-06-16%2018-51-21.png)
## Как запустить
```console
foo@bar:~$ cd ~/path
foo@bar:~/path$ git clone https://github.com/nikitabuts/cpp_homework_2.git
```
Выбираем в QT директорию проекта (~/path/cpp_homework_2), билдим, запускаем

## Ссылка на отчёт



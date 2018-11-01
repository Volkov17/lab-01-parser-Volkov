#ifndef JSON_LAB_JSON_H
#define JSON_LAB_JSON_H


//#include<boost/any.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<any.hpp>


using namespace std;
//using namespace boost;


class Json {
    any _data;
public:
    Json ( const map<string , any >& map );
    // Конструктор из строки, содержащей Json-данные.
    Json(const std::string& s);

    // Метод возвращает true, если данный экземпляр содержит в себе JSON-массив. Иначе false.
    bool is_array() const;
    // Метод возвращает true, если данный экземпляр содержит в себе JSON-объект. Иначе false.
    bool is_object() const;
    // Метод возвращает true, если данный экземпляр не содержит ничего, т.е. null. Иначе false.
    bool is_null() const;

    // Метод возвращает значение по ключу key, если экземпляр является JSON-объектом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-массивом, генерируется исключение.
    any& operator[](const std::string& key);

    // Метод возвращает значение по индексу index, если экземпляр является JSON-массивом.
    // Значение может иметь один из следующих типов: Json, std::string, double, bool или быть пустым.
    // Если экземпляр является JSON-объектом, генерируется исключение.
    any& operator[](int index);

    // Метод возвращает объект класса Json из строки, содержащей Json-данные.
    static Json parse(const std::string& s);

    // Метод возвращает объекта класса Json из файла, содержащего Json-данные в текстовом формате.
    static Json parseFile(const std::string& path_to_file);


   // vector <any> parse_array ()
};




#endif //JSON_LAB_JSON_H

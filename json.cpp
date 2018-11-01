#include "json.hpp"
//#include <boost/any.hpp>
#include <string>
#include <fstream>
#include <any>



using namespace std;
//using namespace boost;

Json ::Json(const string &s) {
    _data=s;
}

Json ::Json(const map<string, any> &map) {
    _data=map;
}

bool Json ::is_array() const {
    try
    {
        any_cast < vector<any> >(_data);
        return true;
    }
    catch(const bad_any_cast& e)
    {
        return false;
    }

}

bool Json ::is_object() const {
    try
    {
        any_cast<map<string, any>>(_data);
        return true;
    }
    catch(const bad_any_cast& e)
    {
        return false;
    }
}

bool Json ::is_null() const {
    if (_data.empty())
        return false;
    else
        return true;

}

any&  Json :: operator[](const string& key){
    if (is_object()){
        auto& map = any_cast< map<string , any>>(&_data);
        return map[key];
    }
    else
        cout<<"error , its array "<<endl;
}

any& Json ::operator[](int index){
    auto a = _data;
    if ( is_array() ) {
        auto& vector = any_cast <vector<any>>(&a);
        return vector[index];
    }
    else
        cout <<" error ,its object"<<endl;
}

Json Json ::parse(const std::string& s){
    return Json(s);
}

Json Json::parseFile (const std::string& path_to_file){
    ifstream fin;
    fin.open(path_to_file);
    string str;
    string s;
    if (fin.is_open()) {
        while (getline(fin , str)) {
            s += str;
        }
    }
    fin.close();
    return Json(s);
}

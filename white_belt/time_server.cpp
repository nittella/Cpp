#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
//    return "01:00:00";
//    throw system_error(error_code());
//    throw runtime_error("another exeption");
}

class TimeServer {
public:
    string GetCurrentTime() {
        string current_time;
        try{
            current_time = AskTimeServer();
        } catch (system_error&){
            return LastFetchedTime;
        }
        LastFetchedTime = current_time;
        return LastFetchedTime;
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля LastFetchedTime
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}

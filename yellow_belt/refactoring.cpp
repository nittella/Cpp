#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
public:
    Human(const string& type, const string& name) : type_(type), name_(name){}

    ostream& Log() const {
        cout << type_ << ": " << name_;
        return cout;
    }

    virtual void Walk(const string& destination) const {
        Log() << " walks to: " << destination << endl;
    }

    string GetType () const {
        return type_;
    }
    string GetName() const {
        return name_;
    }

private:
    const string type_;
    const string name_;
};


class Student : public Human{
public:

    Student(const string& name, const string& favourite_song)
    : Human("Student", name), favourite_song_(favourite_song) {}

    void Learn() const {
        Log() << " learns" << endl;
    }

    void Walk(const string& destination) const {
        Log() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong()  const {
        Log() << " sings a song: " << favourite_song_ << endl;
    }

public:
  const string favourite_song_;
};


class Teacher : public Human{
public:

    Teacher(const string& name, const string& subject) : Human("Teacher", name), subject_(subject){}

    void Teach()  const {
        Log() << " teaches: " << subject_ << endl;
    }

public:
    const string subject_;
};


class Policeman : public Human{
public:
    Policeman(const string& name) : Human("Policeman", name){}

    void Check(Human h) const {
        Log() << " checks " << h.GetType() << ". "
        << h.GetType() << "'s name is: " << h.GetName() << endl;
    }
};


void VisitPlaces(Human& h, const vector<string>& places) {
    for (auto p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}


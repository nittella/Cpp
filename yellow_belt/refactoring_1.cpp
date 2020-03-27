#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string& name, const string& job) : name_(name), job_(job) {}

	string GetName() const {
		return name_;
	}

	string GetJob() const {
		return job_;
	}

	virtual void Walk(const string& destination) {
		cout << GetJob() << " " << GetName() << " walks to: " << destination << endl;
	}

protected:
	const string name_;
	const string job_;
};

class Student : public Person {
public:

	Student(const string& name, const string& favouriteSong) : Person(name, "Student"), FavouriteSong_(favouriteSong) {}

	void Learn() {
		cout << "Student: " << GetName() << " learns" << endl;
	}

	void Walk(const string& destination) override{
		Person::Walk(destination);
		SingSong();
	}

	void SingSong() {
		cout << "Student: " << GetName() << " sings a song: " << FavouriteSong_ << endl;
	}

private:
	const string FavouriteSong_;
};


class Teacher : public Person {
public:

	Teacher(const string& name, const string& subject) : Person(name, "Teacher"), Subject(subject) {}

	void Teach() {
		cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
	}

private:
	const string Subject;
};


class Policeman : public Person {
public:
	Policeman(const string& name) : Person(name, "Policeman") {}

	void Check(Person& person) {
		cout << "Policeman: " << GetName() << " checks " << person.GetJob() << ". " << person.GetJob() << "'s name is: " << person.GetName() << endl;
	}
};


void VisitPlaces(Person& person, vector<string> places) {
	for (auto p : places) {
		person.Walk(p);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}

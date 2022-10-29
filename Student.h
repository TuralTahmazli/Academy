#pragma once
class Student
{
	public:

	Student();
	Student(const char* name, const char* surname);
	~Student();

	size_t getStaticId();
	size_t getId();
	char* getName();
	char* getSurname();

	void setName(const char* name);
	void setSurname(const char* surname);

	void print();

	private:

	static size_t _staticId;
	size_t _id;
	char* _name;
	char* _surname;
};

size_t Student::_staticId = 0;

inline Student::Student()
{
	_id = ++_staticId;
	_name = nullptr;
	_surname = nullptr;
}

inline Student::Student(const char* name, const char* surname)
	: Student()
{
	setName(name);
	setSurname(surname);
}

inline Student::~Student()
{
	delete _name;
	delete _surname;
	_name = _surname = nullptr;
}

inline size_t Student::getStaticId() { return _staticId; }

inline size_t Student::getId() { return _id; }

inline char* Student::getName() { return _name; }

inline char* Student::getSurname() { return _surname; }

inline void Student::setName(const char* name)
{
	if (name == nullptr)
		assert(!"Name can't be null");
	if (_name != nullptr)
		delete _name;
	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}

inline void Student::setSurname(const char* surname)
{
	if (surname == nullptr)
		assert(!"Surname can't be null");
	if (_surname != nullptr)
		delete _surname;
	size_t len = strlen(surname) + 1;
	_surname = new char[len];
	strcpy_s(_surname, len, surname);
}

inline void Student::print()
{
	cout << "===============================" << '\n';
	cout << "Student name: " << (_name ? _name : "Null") << '\n';
	cout << "Student surname: " << (_surname ? _surname : "Null") << '\n';
	cout << "===============================" << '\n';
}
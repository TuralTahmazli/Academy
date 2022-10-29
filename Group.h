#pragma once
class Group
{
	public:

	Group();
	Group(const char* name);
	Group(const char* name, Student** students, size_t length);
	~Group();

	char* getName();
	Student** getStudents();
	size_t getLength();

	void setName(const char* name);
	void setStudents(Student** students, size_t length);
	void setLength(size_t length);

	void print();

	private:

	char* _name;
	Student** _students;
	size_t _len;
};

inline Group::Group()
{
	_name = nullptr;
	_students = nullptr;
	_len = 0;
}

inline Group::Group(const char* name)
	: Group()
{
	setName(name);
}

inline Group::Group(const char* name, Student** students, size_t length)
	: Group(name)
{
	setStudents(students,length);
	setLength(length);
}

inline Group::~Group()
{
	delete _name;
	for (size_t i = 0; i < _len; i++)
	{
		delete _students[i];
	}
	delete[] _students;
	_name = nullptr;
	_students = nullptr;
}

inline char* Group::getName() { return _name; }

inline Student** Group::getStudents() { return _students; }

inline size_t Group::getLength() { return _len; }

inline void Group::setName(const char* name)
{
	if (name == nullptr)
		assert(!"Name can't be null");
	if (_name != nullptr)
		delete _name;
	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}

inline void Group::setStudents(Student** students, size_t length)
{
	if (students)
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < length; j++)
			{
				if (i != j && students[i] == students[j])
					assert(!"You can't add two or more same cars in the car gallery");
			}
		}
	if (_students)
	{
		for (size_t i = 0; i < length; i++)
		{
			delete _students[i];
			_students[i] = nullptr;
		}
		delete[] _students;
		_students = nullptr;
	}
	_students = students;
	setLength(length);
}

inline void Group::setLength(size_t length)
{
	if (length > 0)
	{
		_len = length;
		return;
	}
	assert(!"Length must be greater than 0");
}

inline void Group::print()
{
	cout << "===============================" << '\n';
	cout << "Group name: " << (_name ? _name : "Null") << '\n';
	for (size_t i = 0; i < _len; i++)
	{
		_students[i]->print();
	}
	cout << "===============================" << '\n';
}
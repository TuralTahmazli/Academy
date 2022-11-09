#pragma once
class Group
{
	public:

	Group();
	Group(const char* name);
	Group(const char* name, Student** students, size_t length);
	~Group();

	size_t getId();
	char* getName();
	Student** getStudents();
	size_t getLength();

	void setName(const char* name);
	void setStudents(Student** students, size_t length);
	void setLength(size_t length);

	void appendStudent(Student* student);
	void deleteStudent(Student* student);
	void deleteStudent(Student** students, size_t len, Student* student);
	void deleteStudentById(size_t id);
	Student* getStudentById(size_t id);
	void clearGroup();

	void print();

	private:

	static size_t _staticId;
	size_t _id;
	char* _name;
	Student** _students;
	size_t _len;
};

size_t Group::_staticId = 0;

inline Group::Group()
{
	_id = ++_staticId;
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
	setStudents(students, length);
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

inline size_t Group::getId() { return _id; }

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

inline void Group::appendStudent(Student* student)
{
	if (_students == nullptr)
	{
		_students = new Student * [_len + 1] {student};
		return;
	}
	for (size_t i = 0; i < _len; i++)
	{
		if (_students[i] == student)
			assert(!"Student already exits");
	}
	Student** students = new Student * [_len + 1];
	for (size_t i = 0; i < _len; i++)
	{
		students[i] = _students[i];
	}
	students[_len] = student;
	_len++;
	delete[] _students;
	_students = students;
}

inline void Group::deleteStudent(Student* student)
{
	if (_students == nullptr)
		assert(!"Student not exits");
	bool temp = true;
	for (size_t i = 0; i < _len; i++)
	{
		if (_students[i] == student)
		{
			temp = false;
			delete _students[i];
			_students[i] = nullptr;
			break;
		}
	}
	if (temp)
		assert(!"Student not exits");
	Student** students = new Student * [_len - 1];
	for (size_t i = 0; i < _len - 1; i++)
	{
		if (_students[i] == nullptr)
			temp++;
		students[i] = _students[i + temp];
	}
	_len--;
	delete[] _students;
	_students = students;
}

inline void Group::deleteStudent(Student** students, size_t len, Student* student)
{
	if (students == nullptr)
		assert(!"Student not exits");
	bool temp = true;
	for (size_t i = 0; i < len; i++)
	{
		if (students[i] == student)
		{
			temp = false;
			delete students[i];
			students[i] = nullptr;
			break;
		}
	}
	if (temp)
		assert(!"Student not exits");
	Student** tempstudents = new Student * [len - 1];
	for (size_t i = 0; i < len - 1; i++)
	{
		if (students[i] == nullptr)
			temp++;
		tempstudents[i] = students[i + temp];
	}
	len--;
	delete[] students;
	students = tempstudents;
}

inline void Group::deleteStudentById(size_t id)
{
	if (_students == nullptr)
		assert(!"Student not exits");
	for (size_t i = 0; i < _len; i++)
	{
		if (_students[i]->getId() == id)
			return deleteStudent(_students[i]);
	}
}

inline Student* Group::getStudentById(size_t id)
{
	if (_students == nullptr)
		assert(!"Student not exits");
	for (size_t i = 0; i < _len; i++)
	{
		if (_students[i]->getId() == id)
			return _students[i];
	}
	assert(!"Student not exits");
}

inline void Group::clearGroup()
{
	if (_students == nullptr)
		return;
	for (size_t i = 0; i < _len; i++)
	{
		delete _students[i];
		_students[i] = nullptr;
	}
	delete[] _students;
	_students = nullptr;
	_len = 0;
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
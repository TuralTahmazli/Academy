#pragma once
class Academy
{
	public:

	Academy();
	Academy(const char* name);
	Academy(const char* name, Group** groups, size_t length);
	~Academy();

	char* getName();
	Group** getGroups();
	size_t getLength();

	void setName(const char* name);
	void setGroups(Group** groups, size_t length);
	void setLength(size_t length);

	void print();

	private:

	char* _name;
	Group** _groups;
	size_t _len;
};

inline Academy::Academy()
{
	_name = nullptr;
	_groups = nullptr;
	_len = 0;
}

inline Academy::Academy(const char* name)
	: Academy()
{
	setName(name);
}

inline Academy::Academy(const char* name, Group** groups, size_t length)
	: Academy(name)
{
	setGroups(groups, length);
	setLength(length);
}

inline Academy::~Academy()
{
	delete _name;
	for (size_t i = 0; i < _len; i++)
	{
		delete _groups[i];
	}
	delete[] _groups;
	_name = nullptr;
	_groups = nullptr;
}

inline char* Academy::getName() { return nullptr; }

inline Group** Academy::getGroups() { return nullptr; }

inline size_t Academy::getLength() { return size_t(); }

inline void Academy::setName(const char* name)
{
	if (name == nullptr)
		assert(!"Name can't be null");
	if (_name != nullptr)
		delete _name;
	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}

inline void Academy::setGroups(Group** groups,size_t length)
{
	if (groups)
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < length; j++)
			{
				if (i != j && groups[i] == groups[j])
					assert(!"You can't add two or more same cars in the car gallery");
			}
		}
	if (_groups)
	{
		for (size_t i = 0; i < length; i++)
		{
			delete _groups[i];
			_groups[i] = nullptr;
		}
		delete[] _groups;
		_groups = nullptr;
	}
	_groups = groups;
	setLength(length);
}

inline void Academy::setLength(size_t length)
{
	if (length > 0)
	{
		_len = length;
		return;
	}
	assert(!"Length must be greater than 0");
}

inline void Academy::print()
{
	cout << "===============================" << '\n';
	cout << "Academy name: " << (_name ? _name : "Null") << '\n';
	for (size_t i = 0; i < _len; i++)
	{
		_groups[i]->print();
	}
	cout << "===============================" << '\n';
}
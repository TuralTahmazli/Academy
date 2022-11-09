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

    void appendGroup(Group* group);
    void deleteGroup(Group* group);
    void deleteGroup(Group** groups, size_t len, Group* group);
    void deleteGroupById(size_t id);
    Group* getGroupById(size_t id);
    void clearAcademy();
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

inline void Academy::appendGroup(Group* group)
{
    if (_groups == nullptr)
    {
        _groups = new Group * [_len + 1] {group};
        return;
    }
    for (size_t i = 0; i < _len; i++)
    {
        if (_groups[i] == group)
            assert(!"Group already exits");
    }
    Group** groups = new Group * [_len + 1];
    for (size_t i = 0; i < _len; i++)
    {
        groups[i] = _groups[i];
    }
    groups[_len] = group;
    _len++;
    delete[] _groups;
    _groups = groups;
}

inline void Academy::deleteGroup(Group* group)
{
    if (_groups == nullptr)
        assert(!"Group not exits");
    bool temp = true;
    for (size_t i = 0; i < _len; i++)
    {
        if (_groups[i] == group)
        {
            temp = false;
            delete _groups[i];
            _groups[i] = nullptr;
            break;
        }
    }
    if (temp)
        assert(!"Group not exits");
    Group** groups = new Group * [_len - 1];
    for (size_t i = 0; i < _len - 1; i++)
    {
        if (_groups[i] == nullptr)
            temp++;
        groups[i] = _groups[i + temp];
    }
    _len--;
    delete[] _groups;
    _groups = groups;
}

inline void Academy::deleteGroup(Group** groups, size_t len, Group* group)
{
    if (groups == nullptr)
        assert(!"Group not exits");
    bool temp = true;
    for (size_t i = 0; i < len; i++)
    {
        if (groups[i] == group)
        {
            temp = false;
            delete groups[i];
            groups[i] = nullptr;
            break;
        }
    }
    if (temp)
        assert(!"Group not exits");
    Group** tempgroups = new Group * [len - 1];
    for (size_t i = 0; i < len - 1; i++)
    {
        if (groups[i] == nullptr)
            temp++;
        tempgroups[i] = groups[i + temp];
    }
    len--;
    delete[] groups;
    groups = tempgroups;
}

inline void Academy::deleteGroupById(size_t id)
{
    if (_groups == nullptr)
        assert(!"Group not exits");
    for (size_t i = 0; i < _len; i++)
    {
        if (_groups[i]->getId() == id)
            return deleteGroup(_groups[i]);
    }
}

inline Group* Academy::getGroupById(size_t id)
{
    if (_groups == nullptr)
        assert(!"Group not exits");
    for (size_t i = 0; i < _len; i++)
    {
        if (_groups[i]->getId() == id)
            return _groups[i];
    }
    assert(!"Group not exits");
}

inline void Academy::clearAcademy()
{
    if (_groups == nullptr)
        return;
    for (size_t i = 0; i < _len; i++)
    {
        delete _groups[i];
        _groups[i] = nullptr;
    }
    delete[] _groups;
    _groups = nullptr;
    _len = 0;
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
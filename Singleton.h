#pragma once

template <typename T>
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}

public:
	static T* GetInstance()
	{
		if (nullptr == instance)
		{
			instance = new T();
		}
		return instance;
	}
	static void DestroyInstance()
	{
		if (nullptr != instance)
		{
			delete instance;
			instance = nullptr;
		}
	}

private:
	static T* instance;
};

template<typename T>
T* Singleton<T>::instance = nullptr;
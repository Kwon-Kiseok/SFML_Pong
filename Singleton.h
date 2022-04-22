#pragma once

template <typename T>
class Singleton
{
protected: // private:
	Singleton() {}
	~Singleton() {}
	static T* instance; // ΩÃ±€≈œ ≈¨∑°Ω∫¿« ∞¥√º

public:
	static T* GetInstance()
	{
		if (nullptr == instance)
		{
			instance = new T;
		}
		return instance;
	}
	void DestroyInstance()
	{
		if (nullptr != instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

template<typename T>
T* Singleton<T>::instance = nullptr;
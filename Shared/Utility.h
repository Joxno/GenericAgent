#pragma once
#include <iostream>
#include <functional>
#include <Windows.h>

template <typename T>
struct TypeParser {};

template <typename Ret, typename... Args>
struct TypeParser<Ret(Args...)> {
	static std::function<Ret(Args...)> createFunction(const FARPROC lpfnGetProcessID) {
		return std::function<Ret(Args...)>(reinterpret_cast<Ret(*)(Args...)>(lpfnGetProcessID));
	}
};

template<typename T>
std::function<T> LoadDLLFunction(const HINSTANCE &DLL, const std::string &FuncName)
{
	if (DLL == NULL)
		throw new std::exception("DLL has not been loaded.");

	auto t_Proc = GetProcAddress(DLL, FuncName.c_str());

	if (!t_Proc)
		throw new std::exception( string("Could not load Function: "s + FuncName + " in DLL.").c_str() );
	
	return TypeParser<T>::createFunction(t_Proc);
}

#define DLL_EXPORT __declspec(dllexport)
#define EXTERN_C extern "C"
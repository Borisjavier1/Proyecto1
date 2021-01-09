#pragma once
#include "Libraries.h"
class RuntimeException {
private:
	string message;
public:
	RuntimeException(const string& message) {
		this->message = message;
	}
	string ErrorMessage() const { return this->message; }
};

class InvalidOption : public RuntimeException {
public:
	InvalidOption(const string& error) : RuntimeException(error) {}
};

class ClientNotFound : public RuntimeException {
	public:
	ClientNotFound(const string& error) : RuntimeException(error) {}
};
class EmptyQueue : public RuntimeException {
public:
	EmptyQueue(const string& error) : RuntimeException(error) {}
};

class FileError : public RuntimeException {
public:	FileError(const string& error) : RuntimeException(error) {}

};
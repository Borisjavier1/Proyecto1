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

class EmptyBST : public RuntimeException {
public:
	EmptyBST(const string& error) : RuntimeException(error) {}
};

class EmptyQueue : public RuntimeException {
public:
	EmptyQueue(const string& error) : RuntimeException(error) {}
};

class FileError : public RuntimeException {
public:	
	FileError(const string& error) : RuntimeException(error) {}
};

class invalidData : public RuntimeException {
public:
	invalidData(const string& error) : RuntimeException(error) {}
};
class EmptyVector : public RuntimeException {
public:
	EmptyVector(const string& error) : RuntimeException(error) {}
};
class IndexOverflow : public RuntimeException {
public:
	IndexOverflow(const string& error) : RuntimeException(error) {}
};

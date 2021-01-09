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

	class invalidOption : public RuntimeException {
	public:
		invalidOption(const string& error) : RuntimeException(error) {}
	};

	class clientNotFound : public RuntimeException {
	public:
		clientNotFound(const string& error) : RuntimeException(error) {}
	};

	class emptyQueue : public RuntimeException {
	public:
		emptyQueue(const string& error) : RuntimeException(error) {}
	};

	class FileError : public RuntimeException {
	public:
		FileError(const string& error) : RuntimeException(error) {}
	};
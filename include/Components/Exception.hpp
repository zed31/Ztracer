#ifndef EXCEPTION_HPP__
#define EXCEPTION_HPP__

#include <stdexcept>

namespace Component {

class Exception : public std::exception {
public:
	Exception(const std::string& message) : message_{message} {}
	~Exception() throw() = default;
	inline const char *what() const throw() { return message_.c_str(); }
private:
	const std::string message_;
};

class IllegalIndex : public Exception {
public:
	IllegalIndex(const std::string& message) : Exception{ message } {};
};

} // namespace Component

#endif
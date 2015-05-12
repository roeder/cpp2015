#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>
class Exception	{
private:
	std::string mTag, mProblem;
public:
	Exception();
	Exception(std::string tagString, std::string probString);
	void PrintDebug() const;
	void SetProblem(std::string probString);
	void SetTag(std::string tagString);
};

#endif //EXCEPTIONDEF

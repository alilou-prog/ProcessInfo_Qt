#ifndef __SYSTEM_ANALYSER_H__
#define __SYSTEM_ANALYSER_H__
#include <string>

class QProcess;

class SystemAnalyser
{
    public:
        SystemAnalyser() = default;
        virtual void RunCommand(const char * command);
        virtual std::string output() const;
        virtual ~SystemAnalyser();
    private:
        std::string outputStore;
        void StoreOutput(std::string result);
        QProcess *ps;
	Q_DISABLE_COPY(SystemAnalyser)
};
#endif

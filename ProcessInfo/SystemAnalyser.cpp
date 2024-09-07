#include <iostream>
// #include <array>
#include <string>
#include <memory>
#include "SystemAnalyser.h"
#include <QProcess>
#include <QDebug>

QString getState(QProcess::ProcessState state)
{
    switch(state)
    {
    case QProcess::ProcessState::NotRunning :
        return "Not Running";

    case QProcess::ProcessState::Starting :
        return "Starting";

    case QProcess::ProcessState::Running :
        return "Running";

    default:
        return "";
    }
}
SystemAnalyser::SystemAnalyser()
{
}

void SystemAnalyser::RunCommand(const char * command)
{
    QProcess process;
    QString commandStr(command);

    process.startCommand(commandStr);
    process.waitForFinished();

    QString StdOut = process.readAllStandardOutput();
    // QString StdErr = process.readAllStandardOutput();

    StoreOutput(StdOut.toStdString());
}

void SystemAnalyser::StoreOutput(std::string result)
{
    outputStore = result;
}

std::string SystemAnalyser::output() const
{
    return outputStore;
}

SystemAnalyser::~SystemAnalyser()
{
}

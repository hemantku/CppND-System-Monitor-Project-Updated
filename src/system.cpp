//
// Created by Vineet Ghatge Hemantkumar on 2020-07-05.
//

#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

Processor& System::Cpu() { return this -> cpu_; }

vector<Process>& System::Processes() {
    processes_ = {};
    vector<int> pids = LinuxParser::Pids();
    for (int pid : pids)
    {
        Process p(pid);
        processes_.push_back(p);
    }
    std::sort(processes_.begin(), processes_.end());
    return processes_;
}

std::string System::Kernel() { return LinuxParser::Kernel();}

float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

long int System::UpTime() { return LinuxParser::UpTime(); }
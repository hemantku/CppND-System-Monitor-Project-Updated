//
// Created by Vineet Ghatge Hemantkumar on 2020-07-05.
//
#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid(pid), cpu(Process::CpuUtilization()), command(LinuxParser::Command(pid)){};

int Process::Pid() { return this -> pid; }

float Process::CpuUtilization()
{
    this -> total_time = LinuxParser::ActiveJiffies(this -> pid);
    this -> time_seconds = LinuxParser::UpTime(this -> pid);
    return (float) (this -> total_time/ this -> time_seconds);
}
bool Process::operator<(Process const& a) const {return this -> cpu > a.cpu;}

string Process::Command() { return this -> command; }

string Process::Ram() { return LinuxParser::Ram(this -> pid); }

string Process::User() { return LinuxParser::User(this -> pid); }

long int Process::UpTime() { return LinuxParser::UpTime(this -> pid); }


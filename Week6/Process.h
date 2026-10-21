//
// Created by asher on 10/6/2026.
//

#pragma once
#include <string>



class Process {
public:
    Process(int pid, const std::string& name, const std::string& desc) : pid_(pid), name_(name), desc_(desc){}
    void setName(const std::string& name) { this->name_ = name; }
    const std::string& getName() const { return this->name_; }
    const std::string& getDesc() const { return this->desc_; }
    void setDesc(const std::string& desc) { this->desc_ = desc; }
    void setPid(int pid) { this->pid_ = pid; }
    int getPid() const { return this->pid_; }
    void print()
    {
        std::cout << this->getPid() << ", " <<this->getName() << ", " << this->getDesc() << std::endl;
    }
    bool operator==(const Process& other) const {
        return pid_ == other.pid_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Process& d) {
        return out << d.pid_ << " " << d.name_ << " " << d.desc_;
    }

private:
    int pid_;
    std::string name_;
    std::string desc_;
};
#pragma once

#include <memory>
#include <string>

// Forward-declare manager to avoid circular includes.
class LabManagementSystem;

class Report {
public:
    // Optional constructor takes pointer to system for data access
    explicit Report(LabManagementSystem *system = nullptr);
    virtual ~Report();

    // Subclasses implement actual generation logic
    virtual void generate() = 0;

protected:
    LabManagementSystem *m_system; // non-owning pointer to data source
};

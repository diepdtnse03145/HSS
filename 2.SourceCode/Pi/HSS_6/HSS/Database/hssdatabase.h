#ifndef HSSDATABASE_H
#define HSSDATABASE_H

#include <SQLiteCpp/SQLiteCpp.h>
#include <string>

class HSSDatabase
{
public:
    HSSDatabase();
    bool isUsernamePWDCorrect(const std::string& username,
                              const std::string& pwd);
    bool changePWD(const std::string& username,
                   const std::string& oldpwd,
                   const std::string& newpwd);
    void writeLog(const std::string& log);

    const std::string getAllCameraInfo();
    const std::string getActivityLog();

private:
    SQLite::Database _db;
};

#endif // HSSDATABASE_H
